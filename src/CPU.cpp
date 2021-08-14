#include "CPU.h"

bool fullAdder(bool b1, bool b2, bool& carry)
{
	bool sum = (b1 ^ b2) ^ carry;
	carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
	return sum;
}

std::bitset<16> operator+(std::bitset<16> a, std::bitset<16> b)
{
	bool carry = false;
	std::bitset<16> p;
	for (int i = 0; i < 16; i++)
		p[i] = fullAdder(a[i], b[i], carry);
	return p;
}

CPU::CPU()
{
	reset();
}

void CPU::reset()
{
	RegA = 0;
	RegD = 0;
	PrgCtr = 0;

	RAM.reset();
	ROM.reset();
}

void CPU::loadProgram(std::bitset<16> program[], int p_size)
{
	for (int i = 0; i < p_size; i++)
		ROM.write(i, program[i]);
}

void CPU::setMemory(std::bitset<16> addr, std::bitset<16> value)
{
	RAM.write(addr, value);
}

std::bitset<16> CPU::compute(std::bitset<16> x, std::bitset<16> y, const std::bitset<6> comp)
{
	std::bitset<16> value;
	if (comp[0]) x = 0;
	if (comp[1]) x = ~x;
	if (comp[2]) y = 0;
	if (comp[3]) y = ~y;
	if (comp[4]) value = (x + y);
	else value = (x & y);
	if (comp[5]) value = ~value;

	return value;
}

void CPU::execute() {
	std::bitset<16> instruction = ROM.read(PrgCtr);
	bool at_ins = !instruction.test(15);

	std::bitset<1> a_bit;
	std::bitset<6> comp;
	std::bitset<3> dest, jmp;

	jmp[0] = instruction[0];
	jmp[1] = instruction[1];
	jmp[2] = instruction[2];
	dest[2] = instruction[3];
	dest[1] = instruction[4];
	dest[0] = instruction[5];
	comp[5] = instruction[6];
	comp[4] = instruction[7];
	comp[3] = instruction[8];
	comp[2] = instruction[9];
	comp[1] = instruction[10];
	comp[0] = instruction[11];
	a_bit[0] = instruction[12];

	if (at_ins) {
		RegA = instruction;
		PrgCtr = PrgCtr + 1;
	}
	else {
		std::bitset<16> x = RegD;
		std::bitset<16> y = (!a_bit[0]) ? RegA : RAM.read(RegA);
		std::bitset<16> out = compute(x, y, comp);
		bool zr = out.none();
		bool ng = out.test(15);

		if (dest[0])
			RegA = out;
		if (dest[1])
			RegD = out;
		if (dest[2])
			RAM.write(RegA, out);

		bool jmp_flag = false;
		switch (jmp.to_ulong())
		{
		case 0:
			jmp_flag = false;
			break;
		case 1:
			if (!(zr || ng)) jmp_flag = true;
			break;
		case 2:
			if (zr) jmp_flag = true;
			break;
		case 3:
			if (!ng) jmp_flag = true;
			break;
		case 4:
			if (ng) jmp_flag = true;
			break;
		case 5:
			if (!zr) jmp_flag = true;
			break;
		case 6:
			if (ng || zr) jmp_flag = true;
			break;
		case 7:
			jmp_flag = true;
			break;
		default:
			jmp_flag = false;
			break;
		}

		if (jmp_flag) PrgCtr = RegA;
		else PrgCtr = PrgCtr + 1;
	}

}
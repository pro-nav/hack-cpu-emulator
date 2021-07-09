#include "MEM_RAM.h"

std::bitset<16> SCR_ADDR = 16384;
std::bitset<16> KBD_ADDR = 24576;

MEM_RAM::MEM_RAM()
{
	reset();
}

void MEM_RAM::reset()
{
	for (int i = 0; i < MEM_RAM::RAM_SIZE; i++)
		MEM_RAM::data[i] = 0;
}

void MEM_RAM::write(std::bitset<16> addr, std::bitset<16> value)
{
	MEM_RAM::data[addr.to_ulong()] = value;
}

std::bitset<16> MEM_RAM::read(std::bitset<16> addr)
{
	return MEM_RAM::data[addr.to_ulong()];
}

void MEM_RAM::getSCRdata(std::bitset<16> *scr)
{
	for (int i = 0; i < 8192; i++) {
		scr[i] = data[SCR_ADDR.to_ulong() + i];
	}
}

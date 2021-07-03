#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <bitset>

#include "MEM_RAM.h"
#include "MEM_ROM.h"

bool fullAdder(bool b1, bool b2, bool& carry);

std::bitset<16> operator+(std::bitset<16> a, std::bitset<16> b);

class CPU
{
private:
	std::bitset<16> RegA, RegD, PrgCtr;
	MEM_RAM RAM;
	MEM_ROM ROM;
public:
	CPU();
	void reset();
	void loadProgram(std::bitset<16> program[], int p_size);
	void setMemory(std::bitset<16> addr, std::bitset<16> value);
	std::bitset<16> compute(std::bitset<16> x, std::bitset<16> y, const std::bitset<6> comp);
	void execute();
	void run();
};

#endif // !CPU_H





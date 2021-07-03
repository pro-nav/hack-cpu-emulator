#include "MEM_ROM.h"

MEM_ROM::MEM_ROM()
{ 
	reset();
}

void MEM_ROM::reset()
{
	for (int i = 0; i < MEM_ROM::ROM_SIZE; i++)
		MEM_ROM::data[i] = 0;
}

void MEM_ROM::write(std::bitset<16> addr, std::bitset<16> value)
{
	MEM_ROM::data[addr.to_ulong()] = value;
}

std::bitset<16> MEM_ROM::read(std::bitset<16> addr)
{
	return MEM_ROM::data[addr.to_ulong()];
}


#ifndef MEM_RAM_H
#define MEM_RAM_H

#include <bitset>

extern std::bitset<16> SCR_ADDR;
extern std::bitset<16> KBD_ADDR;

class MEM_RAM {
private:
	static const int RAM_SIZE = 24577;
	std::bitset<16> data[RAM_SIZE];
public:
	MEM_RAM();
	void reset();
	void write(std::bitset<16> addr, std::bitset<16> value);
	std::bitset<16> read(std::bitset<16> addr);
};
#endif // !MEM_RAM_H

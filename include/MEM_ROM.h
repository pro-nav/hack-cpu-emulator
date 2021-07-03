#ifndef MEM_ROM_H
#define MEM_ROM_H

#include <bitset>

class MEM_ROM {
private:
	static const int ROM_SIZE = 1024;
	std::bitset<16> data[ROM_SIZE];
public:
	MEM_ROM();
	void reset();
	void write(std::bitset<16> addr, std::bitset<16> value);
	std::bitset<16> read(std::bitset<16> addr);
};
#endif // !MEM_ROM_H

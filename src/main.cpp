#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
//#include <chrono>

#include "CPU.h"
#include "consoleGUI.h"

int main(int argc, char** argv) {

	std::string filename;

	if (argc > 1) {
		filename = argv[1];
	}
	else {
		std::cerr << "No File Specified." << std::endl;
		return 1;
	}

	std::ifstream file;
	file.open(filename, std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cerr << filename << " not found." << std::endl;
		return 1;
	}

	std::cout << filename << " found. Loading . . . " << std::endl << std::endl;

	std::vector<std::bitset<16>> program;
	std::bitset<16> instruction;
	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		iss >> instruction;
		program.push_back(instruction);
	}

	file.close();

	CPU cpu;
	cpu.loadProgram(&program[0], program.size());

	consoleGUI console;

	//auto tp1 = std::chrono::system_clock::now();
	//auto tp2 = std::chrono::system_clock::now();

	while (true)
	{



		console.draw();
	}


	return 0;
}

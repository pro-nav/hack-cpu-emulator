#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <string>
#include <bitset>
#include <Windows.h>

class consoleGUI{
public:
	int sWidth = 128;
	int sHeight = 40;
	wchar_t* screen = new wchar_t[sWidth * sHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	DWORD dwBytesWritten = 0;

	consoleGUI();
	void draw(std::bitset<16>* scr);
	void writeStr(int x, int y, int c);
	void writeStr(int x, int y, char c);
	//void writeStr(int x, int y, std::bitset<16> b);
	//void writeStr(int x, int y, std::string c);
	int key_press();
};


#endif // !CONSOLEGUI_H

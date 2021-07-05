#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <string>
#include <bitset>
#include <Windows.h>

class consoleGUI{
public:
	int sWidth = 120;
	int sHeight = 40;
	wchar_t* screen = new wchar_t[sWidth * sHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	DWORD dwBytesWritten = 0;

	consoleGUI();
	void draw();
	void writeStr(int x, int y, std::string c);
	void writeStr(int x, int y, std::bitset<16> b);

};


#endif // !CONSOLEGUI_H

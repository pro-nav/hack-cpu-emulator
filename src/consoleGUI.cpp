#include "consoleGUI.h"


consoleGUI::consoleGUI()
{
	SetConsoleActiveScreenBuffer(hConsole);
	for (int i = 0; i < sWidth * sHeight; i++)
		screen[i] = ' ';
}

void consoleGUI::draw()
{
	WriteConsoleOutputCharacterW(hConsole, screen, sWidth * sHeight, { 0 ,0 }, &dwBytesWritten);
}

void consoleGUI::writeStr(int x, int y, std::string c)
{
	for (size_t i = 0; i < c.size(); i++)
	{
		screen[x * sWidth + y + i] = c[i];
	}
}

void consoleGUI::writeStr(int x, int y, std::bitset<16> b)
{
	std::string c = b.to_string();
	for (size_t i = 0; i < c.size(); i++)
	{
		screen[x * sWidth + y + i] = c[i];
	}
}

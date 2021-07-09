#include "consoleGUI.h"


consoleGUI::consoleGUI()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleActiveScreenBuffer(hConsole);
	for (int i = 0; i < sWidth * sHeight; i++)
		screen[i] = ' ';
}

void consoleGUI::draw(std::bitset<16>* scr)
{
	for (int i = 0; i < sWidth * sHeight; i++) {
		screen[i] = (char)(scr[(i / sWidth) + (i % sWidth)][0]+85);
	}

	WriteConsoleOutputCharacterW(hConsole, screen, sWidth * sHeight, { 0 ,0 }, &dwBytesWritten);
}

//void consoleGUI::writeStr(int x, int y, std::bitset<16> b)
//{
//	std::string c = b.to_string();
//	for (size_t i = 0; i < c.size(); i++)
//	{
//		screen[x * sHeight + y + i] = c[i];
//	}
//}

//void consoleGUI::writeStr(int x, int y, std::string c)
//{
//	for (size_t i = 0; i < c.size(); i++)
//	{
//		screen[x * sHeight + y + i] = c[i];
//	}
//}

void consoleGUI::writeStr(int x, int y, int c)
{
	screen[(x * sWidth) + y] = c;
}

void consoleGUI::writeStr(int x, int y, char c)
{
	screen[x * sWidth + y] = c;
}

int consoleGUI::key_press() { 
	KEY_EVENT_RECORD keyevent;
	INPUT_RECORD irec;
	DWORD events;
	while (true) {
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &irec, 1, &events);
		if (irec.EventType == KEY_EVENT && ((KEY_EVENT_RECORD&)irec.Event).bKeyDown) {
			keyevent = (KEY_EVENT_RECORD&)irec.Event;
			const int ca = (int)keyevent.uChar.AsciiChar;
			const int cv = (int)keyevent.wVirtualKeyCode;
			const int key = ca == 0 ? -cv : ca + (ca > 0 ? 0 : 256);
			return key;
		}      
	}
}


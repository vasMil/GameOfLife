#pragma once
#include <windows.h>
#include <array>

struct terminalDimensions {
	int rows;
	int columns;
};

class Utils
{
public:
	static void resetCursorPosWindows();
	static void ShowConsoleCursor(bool showFlag);
	static terminalDimensions getTerminalDimensions();
};


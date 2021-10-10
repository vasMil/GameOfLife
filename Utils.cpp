#include "Utils.h"

void Utils::resetCursorPosWindows() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(hConsole, pos);
}

void Utils::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

terminalDimensions Utils::getTerminalDimensions() {
    terminalDimensions tD;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    tD.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    tD.columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    
    return tD;
}
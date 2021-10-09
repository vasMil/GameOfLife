#include <windows.h>
#include "Grid.h"
#include "Pixel.h"

int main(int argc, char** argv) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;


	Grid* grid = new Grid(rows, columns);
    for (int i = 0; i < 100; i++) {
        // system("cls");
        grid->displayGrid();
    }
    return 0;
}
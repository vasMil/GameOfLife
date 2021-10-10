#include <windows.h>
#include "Utils.h"
#include "Grid.h"
#include "Pixel.h"

int main(int argc, char** argv) {
    // Wait for the user to resize the terminal window
    std::cout << "Resize the window to the size you want the Game of Life to be displayed on" << std::endl;
    system("pause");
    system("cls");

    // Lock the terminal size, so the user may not resize it as the game runs

    // Hide the cursor that blinks on the terminal for better visuals
    Utils::ShowConsoleCursor(false);

    // Get the terminal dimensions
    terminalDimensions window = Utils::getTerminalDimensions();
    // Create a grid for those dimensions
	Grid* grid = new Grid(window.rows, window.columns/2);
    while (1) {
        grid->displayGrid();
    }
        
    return 0;
}
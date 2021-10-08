#include "Grid.h"

Grid::Grid(int dimX, int dimY) {
	this->dimX = dimX;
	this->dimY = dimY;

	int i = 0, j = 0;
	for (i = 0; i < dimX; i++) {
		std::vector<Pixel*> temp;
		for (j = 0; j < dimY; j++) {
			if (i != j) {
				temp.push_back(new Pixel(0));
			}
			else {
				temp.push_back(new Pixel(1));
			}
		}
		this->grid.push_back(temp);
	}
}

void Grid::displayGrid() {
	int i = 0, j = 0;
	for (i = 0; i < this->dimX; i++) {
		for (j = 0; j < this->dimY; j++) {
			this->grid[i][j]->getState() ? std::cout << '\xDB' : std::cout << " ";
		}
		std::cout << std::endl;
	}
}
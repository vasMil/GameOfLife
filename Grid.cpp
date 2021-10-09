#include "Grid.h"

Grid::Grid(int dimX, int dimY) {
	this->dimX = dimX;
	this->dimY = dimY;

	auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());

	int i = 0, j = 0;
	for (i = 0; i < dimX; i++) {
		std::vector<Pixel*> temp;
		for (j = 0; j < dimY; j++) {
			if (gen()) {
				temp.push_back(new Pixel(0));
			}
			else {
				temp.push_back(new Pixel(1));
			}
		}
		this->grid.push_back(temp);
	}

	for (i = 0; i < dimX; i++) {
		for (j = 0; j < dimY; j++) {
			setupNeighbourhood(this->grid[i][j], i, j);
		}
	}
}

void Grid::displayGrid() {
	int i = 0, j = 0;
	for (i = 0; i < this->dimX; i++) {
		for (j = 0; j < this->dimY; j++) {
			this->grid[i][j]->getState() ? std::cout << '\xDB' : std::cout << " ";
		}
		if (i == this->dimX - 1) {
			Utils::resetCursorPosWindows();
		}
		else {
			std::cout << std::endl;
		}
	}
	this->preStep();
	this->advance();
}

void Grid::setupNeighbourhood(Pixel* px, int posX, int posY) {
	for (int i : {-1,0,1}) {
		std::vector<Pixel*> neighbourhoodRow;
		for (int j : {-1, 0, 1}) {
			neighbourhoodRow.push_back(this->getPixelIfExists(posX + i, posY + j));
		}
		px->neighbourhood.push_back(neighbourhoodRow);
	}
}

Pixel* Grid::getPixelIfExists(int posX, int posY) {
	if (posX < 0 || posX >= this->dimX || posY < 0 || posY >= this->dimY) {
		return nullptr;
	}
	return this->grid[posX][posY];
}

void Grid::preStep() {
	for (int i = 0; i < this->dimX; i++) {
		for (int j = 0; j < this->dimY; j++) {
			this->grid[i][j]->updateNextState();
		}
	}
}

void Grid::advance() {
	for (int i = 0; i < this->dimX; i++) {
		for (int j = 0; j < this->dimY; j++) {
			this->grid[i][j]->advance();
		}
	}
}
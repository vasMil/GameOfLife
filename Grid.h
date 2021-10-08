#pragma once
#include <iostream>
#include <vector>
#include "Pixel.h"

class Grid
{
private:
	int dimX, dimY;
	std::vector<std::vector<Pixel*>> grid;

public:
	Grid(int dimX, int dimY);
	void displayGrid();
	void setupNeighbourhood(Pixel* px, int posX, int posY);
	Pixel* getPixelIfExists(int posX, int posY);
};


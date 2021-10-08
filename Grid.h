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
	void setupNeighbours();
	void displayGrid();
};


#pragma once
#include <iostream>
#include <random>
#include <vector>
#include <functional>
#include "Pixel.h"

class Grid
{
private:
	int dimX, dimY;
	std::vector<std::vector<Pixel*>> grid;
	void preStep();

public:
	Grid(int dimX, int dimY);
	void displayGrid();
	void setupNeighbourhood(Pixel* px, int posX, int posY);
	Pixel* getPixelIfExists(int posX, int posY);
	void advance();
};


#pragma once
#include <stdexcept>
#include <vector>

class Pixel
{
private:
	int state;

public:
	std::vector<std::vector<Pixel*>> neighbourhood;

	Pixel(int state);
	void updateState();
	int getState();

	// Testing
	void setRightmostNeighbour();
};


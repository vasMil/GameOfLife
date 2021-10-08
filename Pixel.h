#pragma once
#include <stdexcept>
#include <vector>

class Pixel
{
private:
	int state;
	std::vector<std::vector<Pixel*>> neighbourhood;

public:
	Pixel(int state);
	void updateState();
	void setNeighbourhood(std::vector<Pixel*>* neighbourhood);
	int getState();
};


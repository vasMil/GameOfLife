#pragma once
#include <stdexcept>
#include <vector>

class Pixel
{
private:
	int state;
	int next_state;

	int sumNeighbourStates();

public:
	std::vector<std::vector<Pixel*>> neighbourhood;

	Pixel(int state);
	void updateNextState();
	int getState();
	void advance();
};


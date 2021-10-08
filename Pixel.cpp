#include "Pixel.h"

Pixel::Pixel(int state) {
	this->state = state;
}

int Pixel::getState() {
	return this->state;
}

void Pixel::setRightmostNeighbour() {
	this->neighbourhood[0][2]->updateState();
}

void Pixel::updateState() {
	this->state = 1;
}
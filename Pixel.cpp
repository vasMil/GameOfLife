#include "Pixel.h"

Pixel::Pixel(int state) {
	this->state = state;
	this->next_state = state;	
}

int Pixel::getState() {
	return this->state;
}

void Pixel::updateNextState() {
	if (this->state == 1 && (this->sumNeighbourStates() < 2 || this->sumNeighbourStates() > 3)) {
		this->next_state = 0;
	}
	else if (this->state == 1 && (this->sumNeighbourStates() == 2 || this->sumNeighbourStates() == 3)) {
		this->next_state = 1;
	}
	else if (this->state == 0 && this->sumNeighbourStates() == 3) {
		this->next_state = 1;
	}
	else {
		this->next_state = this->state;
	}
}

int Pixel::sumNeighbourStates() {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->neighbourhood[i][j] != nullptr && (i != 1 || j != 1)) {
				sum += this->neighbourhood[i][j]->getState();
			}
		}
	}
	return sum;
}

void Pixel::advance() {
	this->state = this->next_state;
	this->next_state = 0; // Redundant
}
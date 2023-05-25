#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "vec.h"
#include "observer.h"

class Card {
	std::vector<Vec> cards;
//	unsigned seed;
//	std::vector<Observer*> players;

	public:
//	Card(unsigned seed, std::vector<Observer*> players);
Card();
void shuffle(unsigned seed);
	int deal(std::vector<Observer*> players);
	void printCards();
	~Card();
};
#endif



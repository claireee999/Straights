#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "subject.h"
#include "card.h"
#include "observer.h"
#include <algorithm>
class Vec;

class Game: public Subject {
	Card c;
	unsigned seed;
	std::vector<Observer*> p;
	int count;
	std::vector<int> clubs;
	std::vector<int> diamonds;
	std::vector<int> hearts;
	std::vector<int> spades;


	public:
	Game(unsigned seed);
	void setPlayers(std::vector<Observer*> players);
	void startGame();
	void printDeck();
	void addToTable(Vec c);
	void printTable();
	void playCard(int n);
	void result();
	void rageQuit();
	void quitGame();
	~Game();
};

#endif




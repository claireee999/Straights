#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "observer.h"
#include "vec.h"
#include "game.h"

class humanPlayer: public Observer {
	std::vector<Vec> cards;
	std::vector<Vec> discards;
	Game *subject;

	public:
	humanPlayer (Game *o);
	void addCard(Vec c) override;
	bool notify(Vec& card, std::vector<int> c,std::vector<int> d, std::vector<int> h,std::vector<int> s) override;
	void deleteCard(Vec c);
	int calcPoints() override;
	~humanPlayer();
};
#endif


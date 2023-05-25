#ifndef __COMPUTERPLAYER_H__
#define __COMPUTERPLAYER_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "vec.h"
#include "game.h"

class computerPlayer: public Observer {
	std::vector<Vec> cards;
	std::vector<Vec> discards;
	Game *subject;

public:
	computerPlayer (Game *o);
	void addCard(Vec c) override;
bool notify(Vec& card, std::vector<int> c,std::vector<int> d, std::vector<int> h,std::vector<int> s) override;
void deleteCard(Vec c);
int calcPoints() override;
	~computerPlayer();

};
#endif

#include "computerPlayer.h"

computerPlayer::computerPlayer (Game *o): subject{o} { subject->attach( this );}

void computerPlayer::addCard(Vec c) {
	cards.emplace_back(c.x, c.y);
}

void computerPlayer::deleteCard(Vec c){
	//discards.emplace_back(c);
	int i = 0;
	for (auto n :cards) {
		if (n.x == c.x && n.y == c.y) break;
		i++;
	}
	cards.erase(cards.begin()+i);
}

bool findLegal(int n, std::vector<int> x){
	if (x.size() >0) {
		if ((n == x[0] - 1)||(n == x[x.size() -1] +1)) {
			return true;
		} 
	} else if (n == 7) return true;
	return false;
}

bool computerPlayer::notify(Vec& card, std::vector<int>c, std::vector<int> d, std::vector<int> h,std::vector<int> s){
	std::cout <<"Your hand:";
	for (auto n: cards) n.printVec();
	std::cout<<std::endl;
	std::cout <<"Legal play:";
	std::vector<Vec> legalplay;
	if(s.size() == 0) {
		Vec s{7,'S'};
		legalplay.emplace_back(s);
	} else {
		for (auto n : cards) {
			bool found = false;
			if (n.y == 'C')
				found = findLegal(n.x, c);
			else if (n.y == 'D')
				found = findLegal(n.x, d);
			else if(n.y == 'H')
				found = findLegal(n.x, h);
			else  found = findLegal(n.x, s);
			if (found) legalplay.emplace_back(n);
		}
	}
	for (auto n:legalplay) n.printVec();
	std::cout<<std::endl;
	if (legalplay.size() > 0) {
		card = legalplay[0];
		deleteCard(legalplay[0]);
		return true;
	} else {
		card = cards[0];
		discards.emplace_back(card);
		deleteCard(cards[0]);
		return false;
	}
}

int computerPlayer::calcPoints() {
	int points = 0;
	for (auto n :discards){
		n.printVec();
		points += n.x;
	}
	return points;
}


computerPlayer::~computerPlayer(){
	subject->detach( this );
}



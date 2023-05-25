#include "card.h"

Card::Card() {
	for (int j = 1;j<= 4; j++) {
		char cc;
		if (j == 1) cc = 'C';
		else if (j == 2) cc = 'D';
		else if (j == 3) cc = 'H';
		else cc = 'S';
		for(int i = 1; i <=13;i++){
			cards.emplace_back(i, cc);
		}
	}
}

void Card::shuffle(unsigned seed){
	//	std::default_random_engine rng{seed};
	std::shuffle( cards.begin(), cards.end(), std::default_random_engine(seed) );
}

int  Card::deal(std::vector<Observer*> players){
	int f=0;
	int j = 0;
	for (std::size_t k = 0; k < players.size(); ++k){
		for (int i = 1; i<= 13; i++) {
			players[k]->addCard(cards[j]);
			if(cards[j].x == 7 && cards[j].y =='S') f=k+1;
			j++;
		}
	}
	return f;
}

void Card::printCards() {
	int count = 1;
	for (std::size_t i = 0; i < cards.size(); ++i){
		cards[i].printVec();
		if (count == 13 ) {
			std::cout << std::endl;
			count = 1;
		} else count++;

	}
}

Card::~Card(){}



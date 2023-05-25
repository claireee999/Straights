#include "humanPlayer.h"


humanPlayer::humanPlayer(Game *o): subject{o} { subject->attach( this );}

void humanPlayer::addCard(Vec c) {
	cards.emplace_back(c.x, c.y);
}

void humanPlayer::deleteCard(Vec c){
	discards.emplace_back(c);
	int i = 0;
	for (auto n :cards) {
		if (n.x == c.x && n.y == c.y) break;
		i++;
	}	
	cards.erase(cards.begin()+i);
}

bool findLegall(int n, std::vector<int> x){
  if ((n == x[0] - 1)||(n == x[x.size() -1] +1)) {
  return true;
  }
  return false;
  }

bool verify(std::vector<Vec> l, std::string ss){
	for(auto n: l) {
		char a;
		if (n.x == 1) a = 65;
		else if (n.x == 10) a = 84;
		else if (n.x == 11) a = 74;
		else if (n.x == 12) a = 81;
		else if (n.x == 13) a = 85;
		else a = n.x +'0';
		char b = n.y;
		std::string c(1,a);
		std::string d(1,b);
		std::string e = c+d;	
		if (e == ss) return true;
	}
	return false;
}

Vec becomeVec(std::string ss){
	const char *p = ss.c_str();
	int i = 0;
	if (p[0] == 74) i = 11;
	else if (p[0] == 65) i = 1;
	else if (p[0] == 84) i = 10;
	else if (p[0] == 81) i = 12;
	else if (p[0] == 85) i = 13;
	else i = p[0] -'0';		
	Vec v{i,p[1]};
	return v;
}

bool humanPlayer::notify(Vec& card, std::vector<int> c,std::vector<int> d, std::vector<int> h,std::vector<int> s){
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
				found = findLegall(n.x, c);
			else if (n.y == 'D')
				found = findLegall(n.x, d);
			else if(n.y == 'H')
				found = findLegall(n.x, h);
			else  found = findLegall(n.x, s);
			if (found) legalplay.emplace_back(n);
		}
	}
	for (auto n:legalplay) n.printVec();
	std::cout<<std::endl;

	while(true){
		std::string command;
		getline(std::cin, command);
		if (command.compare("deck")==0) {
			subject->printDeck();
		}
		else if (command.compare("quit")==0) subject->quitGame();
		else if(command.compare("ragequit") == 0) subject->rageQuit();
		else {
			std::istringstream s{command};
			std::string ss;
			s >> ss;
			if (legalplay.size () > 0 && ss=="discard"){
				std::cout <<"You have a legal play. You may not discard."<<std::endl;
			} else if (legalplay.size() == 0 &&ss == "discard"){ 
				s>>ss;
				card = becomeVec(ss);
				 deleteCard(card);
				return false;
			} else if (ss=="play"){
				s>>ss;
				bool legal = verify(legalplay, ss);
				if (legal) {
					card = becomeVec(ss);
				deleteCard(card);
					return true;
				} else {
					std::cout<<"This is not a legal play."<<std::endl;
				}
			}
		}
	}
}

int humanPlayer::calcPoints() {
	int points = 0;
	for (auto n :discards){
		n.printVec();
		points += n.x;
	}
	return points;
}
humanPlayer::~humanPlayer() {
	subject->detach( this );
}


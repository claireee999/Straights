#include "game.h"

Game::Game(unsigned seed): seed{seed}{
	count = 0;
}

void Game::setPlayers(std::vector<Observer*> players) {
p = players;
}

void Game::startGame(){
	c.shuffle(seed);
	int f = c.deal(p);
	std::cout << "A new round begins. It’s Player"<< f  << "’s turn to play." << std::endl;
	int i = f;
	while(count < 52 && i <=4) {	
		playCard(i);
		if (i == 4) i = 1; 
		else i++;
		count++;
	} 
	result();
}

void Game::printDeck(){
	c.printCards();
}


void Game::addToTable(Vec c) {
	if(c.y == 'C') {
		clubs.emplace_back(c.x);
		sort(clubs.begin(),clubs.end());
	} else if (c.y == 'D') {
		diamonds.emplace_back(c.x);
		sort(diamonds.begin(),diamonds.end());
	}else if (c.y == 'H') {
		hearts.emplace_back(c.x);
		sort(hearts.begin(),hearts.end());
	} else {
		spades.emplace_back(c.x);
		sort(spades.begin(),spades.end());
	}
}

void printC(int n) {
	if (n == 1) std::cout<< "A";
	else if (n == 10) std::cout<< "T";
	else if (n == 11) std::cout<< "J";
	else if (n == 12) std::cout<< "Q";
	else if (n == 13) std::cout<< "K";
	else std::cout<< n;
}

void Game::printTable() {
	std::cout << "Cards on the table:"<<std::endl;
	std::cout << "Clubs:";
	for (auto n : clubs) {
		std::cout <<" ";
       	printC(n);
	}
	std::cout <<  std::endl;
	std::cout << "Diamonds:";
	for (auto n : diamonds){
		std::cout <<" ";
		printC(n);
	}
	std::cout  << std::endl;
	std::cout << "Hearts:";
	for (auto n : hearts){
		std::cout <<" ";
	       	printC(n);
	}
	std::cout  << std::endl;
	std::cout << "Spades:";
	for (auto n : spades){
		std::cout <<" ";
       	 printC(n);
	}
	std::cout  << std::endl;
}

//ask the player n to play a card
void Game::playCard(int n) {
	printTable();
	Vec c;
	bool play = notifyObserver(n,c,clubs,diamonds,hearts,spades);
	if (play) {
		addToTable(c);
		std::cout << "Player" <<n << " plays";
	}
	else std::cout << "Player" << n <<" discards";
	c.printVec();
	std::cout << "."<<std::endl;
}

void Game::result(){
	bool end = resultObservers();
	if (!end){
	       count = 0;	
		startGame();
	}
	else quitGame();
}

void Game::quitGame() {
}

void Game::rageQuit() {
}

Game::~Game(){}



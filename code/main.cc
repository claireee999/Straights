#include <iostream>
#include <vector>
#include <memory>
#include "observer.h"
#include "game.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

int main (int argc, char * argv[]) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
	if ( argc > 1 ) {
		try {
			seed = std::stoi( std::string{ argv[1] } );
		} catch( std::invalid_argument & e ) {
			std::cerr << e.what() << std::endl;
			return 1;
		} catch( std::out_of_range & e ) {
			std::cerr << e.what() << std::endl;
			return -1;
		} // catch
	} // if

	std::vector<Observer*> o;
	Game g{seed};
	for(int i = 1;i<= 4;++i) {
		std::cout << "Is Player"<<i <<" a human (h) or a computer (c)?" << std::endl;
		char p;
		std::cin >> p;
		if(p == 'h'){
			Observer *ob = new humanPlayer{&g};
			o.emplace_back(ob);
		}else if(p == 'c'){
			Observer *ob = new computerPlayer{&g};
			o.emplace_back(ob);								}
	}
	g.setPlayers(o);	
	g.startGame();
	//for (std::size_t i = 0; i < o.size(); ++i) delete o[i];
}

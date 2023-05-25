#include "subject.h"

void Subject::attach(Observer *o) { observers.emplace_back(o); }

void Subject::detach(Observer *o) {
	for (auto it = observers.begin(); it != observers.end(); ) {
		if (*it == o) it = observers.erase(it);
		else ++it;
	}
}

bool Subject::notifyObserver(int n, Vec& card, std::vector<int>& c,std::vector<int>& d, std::vector<int>& h,std::vector<int>& s) {
	return observers[n-1]->notify(card, c, d, h, s);
}

bool Subject::resultObservers() {
	for (std::size_t i = 0; i < observers.size(); ++i) {
		std::cout<<"Player" << i+1 << "'discards:";
		int newscore = observers[i]->calcPoints();
		std::cout<<std::endl;
		std::cout << "Player" << i+1 << "'score: " << scores[i] << " + " << newscore << " = "<< scores[i] + newscore <<std::endl; 
		scores[i]+= newscore;
	}

	bool end = false;
	for (int i = 0; i < 4; ++i) {
		if (scores[i] >= 80) end = true;
	}
	if (end){
		for (int i = 0; i< 4;++i) {
			if (scores[i] <= scores[0] && scores[i] <= scores[1] && scores[i] <= scores[2] && scores[i] <= scores[3]) 
				std::cout<< "Player" << i+1 <<" wins!"<<std::endl;
		}
		return true;
	}
	return false;
}



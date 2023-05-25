#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include<vector>
#include "vec.h"
class Subject;

class Observer {
	public:
		virtual void addCard(Vec c) =0;
		virtual bool notify(Vec &card, std::vector<int> c,std::vector<int> d, std::vector<int> h,std::vector<int> s) = 0;
		virtual int calcPoints()= 0;
		virtual ~Observer() = default;
};
#endif


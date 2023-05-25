#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <vector>
#include "vec.h"
#include "observer.h"

class Subject {
 std::vector<Observer*> observers;
 int scores[4] = {0};
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  bool notifyObserver(int n, Vec& card, std::vector<int>& c,std::vector<int>& d, std::vector<int>& h,std::vector<int>& s) ;
  bool resultObservers();
  virtual ~Subject() = default;
};

#endif

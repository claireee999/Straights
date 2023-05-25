#include "vec.h"
Vec::Vec() { x= 0; y = ' ';}
Vec::Vec( int x, char y ) : x{x}, y{y} {}

void Vec::printVec() {
         if(x == 1)  std::cout <<" "<< 'A';
                        else if (x == 10) std::cout <<" " <<'T';
                        else if (x == 11) std::cout <<" "<< 'J';
                        else if (x == 12) std::cout <<" "<< 'Q';
                        else if (x == 13) std::cout <<" "<< 'K';
         else std::cout <<" "<< x;
         std::cout << y;
}


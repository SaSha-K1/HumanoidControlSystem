#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include "includes.h"


class ExceptEqualOrSubZerro {
public:
   ExceptEqualOrSubZerro(dbl& a1,  dbl& a2,  dbl& a3,  dbl& a4) {
      std::cout << "\t EXCPTN: at least one among entered values isn't correct because <= 0.\n Was entered: "
         << a1 << ",  " << a2 << ",  " << a3 << ",  " << a4 << ". \n";
   }
};


#endif //EXCEPTIONS_H
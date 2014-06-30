#ifndef TRI_COORD_H
#define TRI_COORD_H

#include "typedefinitions.h"

   //класс использую в качестве: 1) координат точки,  2) смещений точки
struct TriCoord {  // в "typedefinitions.h" есть строка:  "typedef TriCoord Point;"  лишь для пущей понятности и красноречивости
public:
   TriCoord (dbl x = 0, dbl y = 0, dbl z = 0) : x(x), y(y), z(z) {}   ///@@@ ?: "= 0.0"   ///@@@ may be "TriCoord::x" is needed

   dbl x;
   dbl y;
   dbl z;
};


#endif   //TRI_COORD_H
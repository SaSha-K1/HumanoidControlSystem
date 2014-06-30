#ifndef TRI_COORD_H
#define TRI_COORD_H

#include "typedefinitions.h"

   //класс использую в качестве: 1) координат точки,  2) смещений точки
/*typedef*/ class TriCoord {  // в "includes.h" есть строка:  "typedef TriCoord Point;"  лишь для пущей понятности и красноречивости
public:
   TriCoord (dbl x = 0, dbl y = 0, dbl z = 0) : x(x), y(y), z(z) {}   ///@@@ ?: "= 0.0"   ///@@@ may be "TriCoord::x" is needed
// Решил, что код ниже - лишнее, т.к. этот класс всегда агрегируется. Только лишние сложности с доступом получаются (но пока не удаляю)
//   void setValues(double x, double y, double z);
//   double* getValues() const;
//   double getX() const { return x_; }
//   double getY() const { return y_; }
//   double getZ() const { return z_; }
//private:
// файл ".cpp" выключил из проекта

   dbl x;
   dbl y;
   dbl z;
};


#endif   //TRI_COORD_H
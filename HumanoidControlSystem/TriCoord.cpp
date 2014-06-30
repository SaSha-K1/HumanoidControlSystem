#include "TriCoord.h"


void TriCoord::setValues(double x, double y, double z) {
   x_ = x;
   y_ = y;
   z_ = z;
}

double* TriCoord::getValues() const {
   double a[3] = { x_, y_, z_ };
   return a;
}
#ifndef TRI_COORD_H
#define TRI_COORD_H

#include "typedefinitions.h"

   //����� ��������� � ��������: 1) ��������� �����,  2) �������� �����
/*typedef*/ class TriCoord {  // � "includes.h" ���� ������:  "typedef TriCoord Point;"  ���� ��� ����� ���������� � ���������������
public:
   TriCoord (dbl x = 0, dbl y = 0, dbl z = 0) : x(x), y(y), z(z) {}   ///@@@ ?: "= 0.0"   ///@@@ may be "TriCoord::x" is needed
// �����, ��� ��� ���� - ������, �.�. ���� ����� ������ ������������. ������ ������ ��������� � �������� ���������� (�� ���� �� ������)
//   void setValues(double x, double y, double z);
//   double* getValues() const;
//   double getX() const { return x_; }
//   double getY() const { return y_; }
//   double getZ() const { return z_; }
//private:
// ���� ".cpp" �������� �� �������

   dbl x;
   dbl y;
   dbl z;
};


#endif   //TRI_COORD_H
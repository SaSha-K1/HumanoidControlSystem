#ifndef TRI_COORD_H
#define TRI_COORD_H

#include "typedefinitions.h"

   //����� ��������� � ��������: 1) ��������� �����,  2) �������� �����
struct TriCoord {  // � "typedefinitions.h" ���� ������:  "typedef TriCoord Point;"  ���� ��� ����� ���������� � ���������������
public:
   TriCoord (dbl x = 0, dbl y = 0, dbl z = 0) : x(x), y(y), z(z) {}   ///@@@ ?: "= 0.0"   ///@@@ may be "TriCoord::x" is needed

   dbl x;
   dbl y;
   dbl z;
};


#endif   //TRI_COORD_H
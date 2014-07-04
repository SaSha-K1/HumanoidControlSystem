#ifndef MACRO_ELEM_H
#define MACRO_ELEM_H


#include "includes.h"
#include "Element.h"


struct RelativePosition;
struct TriAngles;
struct MECouplingAxis;


class MacroElem : public Element {
public:
   MacroElem(Element* pEl0);
      //dbl x, dbl y, dbl z,    //<- TriCoord   //DEL! �� �����, �.�. � C-tor ��������� ������ ������� ��-� ("�������. �����-�" �� ����� ������)
      //dbl a, dbl b, dbl g);   //<- TriAngles

   //MacroElem(void) {};
   //MacroElem(Element* el0 = nullptr,
   //   dbl x = 0.0, dbl y = 0.0, dbl z = 0.0,    //<- TriCoord
   //   dbl a = 0.0, dbl b = 0.0, dbl g = 0.0);   //<- TriAngles
   ~MacroElem();
   void addElem(Element*);

private:
   struct ConstituentElemData;   // ������ ������������� ��-�� (�/ �������)
   std::vector<ConstituentElemData*> constitElDatas_; //������� ��������� ������� ��-� 
   std::vector<MECouplingAxis*> mECouplingAxises_;   // - ��� ���������� �������-��

   void computeGeom();
   void computePhys();
};


// STRUCTures:
struct TriAngles {   // ��������� ��� ��������� �� 3 ����� ������ (�/ ����������� ��������� � ������-��). �� ��������� `TriCoord`, ..
   //.. ����� �� �������� ��-�� ��� ����������, ������� ��� ������� x, y, z.
   double a = 0;   //
   double b = 0;   // - ���� ������
   double g = 0;   //
};

struct RelativePosition {                 ///@@@ �������� � "����������� � �������� ������������" � �������� �������� ���� ������
   TriCoord localOriginCoords;    // - ���������� ����� ������ ��������� ��������� �� ��-�� ���-�� ����� �� ����� ..
                                 //.. �������� ��-�� ( `elements[0]` ).
   TriAngles triAngs;
   
   RelativePosition(dbl x, dbl y, dbl z, dbl a, dbl b, dbl g) 
      /*: localOriginCoords.x(x), localOriginCoords.y(y), localOriginCoords.z(z),*/  ///@@@ �������� � ������ ����-��� C-tor'� ������ ...
      /*triAngs.a(a), triAngs.b(b), triAngs.g(g) {}*/                                   ///... ���������� � ����� ��������� ��./struct'��.
   {
      localOriginCoords.x = x;
      localOriginCoords.y = y;
      localOriginCoords.z = z;
      triAngs.a = a;
      triAngs.b = b;
      triAngs.g = g;
   }
};

struct MacroElem::ConstituentElemData {
   Element* element;  
   RelativePosition* relPosition; // - ������������� ��������� ��-�� � �������-�� ���-�� �������� (0-��) ��-��.

   ConstituentElemData(Element* el, RelativePosition* rp)
      : element(el), relPosition(rp) {}
   ~ConstituentElemData() {   //D-tor �����, �.�. `relPosition` �������� ptr �� obj ������ `RelativePosition`, �� ..
      delete relPosition;     //.. lifetime ����� obj-�� ������ ���� == lifetime'� ���������� obj-�� 'ConstituentElemData'
   }
};

struct MECouplingAxis { // - ��� ���������� ������������� (��� ��������� �� ���� - ������ � 2-������ ..
                           //.. �������, Re-�������� ��� ������ ��������.
   //Element** elemPtrPtr; // - ptr to corresponding `elements[i]` (��� ������ ��-��)    // ������� ptr �� ��-� �������, ������, �����, �.�. ��� ���� ��������� ��� �-��, ������, ����� ���� ��������
   uns numberOfEl;   // � ������� � �������, � ���. ������� corresponding `elements[i]` (������ �� ��� ��������� ����� � ���� ���-��)
   CouplingAxis relativeAxisPos; // - �������.�����-� ��� (� "����� ����������") � �� �������������
   MacroElem* coupledMacroElem = nullptr;  // - ���������� �� ������ ��� �������-�.

   MECouplingAxis(uns noe, CouplingAxis ca, MacroElem* ptrME) 
   : numberOfEl(noe), relativeAxisPos(ca), coupledMacroElem(ptrME) {}
};


#endif   //MACRO_ELEM_H
#ifndef ELEMENT_H
#define ELEMENT_H


#include "includes.h"
#include "TriCoord.h"

//2 ��������� �������, �.�. � ������ obj'�, � �� ptr'�:
//struct Geometry;     // - ����. �-��
struct Geometry {
   double l = 0;  //�� OX
   double w = 0;  //�� OY
   double h = 0;  //�� OZ
};

//struct Physics;      // - �����. ���-��
struct Physics {
   double m = 0;
   Point cm;     // - ����� ���� ��������
};

struct CouplingAxis;   // - ��� ����������
class MacroElem;


class Element {
public:
   Element (/*Geometry:*/ dbl length, dbl width, dbl height, 
            /*Physics:*/ dbl mass, dbl x, dbl y, dbl z,
            /*CouplingAxis:*/ std::vector<CouplingAxis> *couplAxPtr);   // ����� �� ������� min 2 C-tor'� � ����� �����-���, ����� ..
                                                                        //.. cre-�� `vector<CouplingAxis>` �������� � ���������� � ..
                                                                        //.. C-tor ptr �� ����.
   //Element();  //�������� �/������������, �� ���� ��������
   ~Element();
   ///@@@ �������� ����������� ��� Copy C-tor � �������� `=` ��-�� ����, ��� ���� `couplAx` �������� ptr, � �� obj.

   //���������:
   dbl getGeomL() const;
   dbl getGeomW() const;
   dbl getGeomH() const;
   dbl getPhysM() const;
   //Point* getPhysCM() const;   //��������� ptr, ������� ������������, � ����� ������� ������� obj `phys.cm` �� ����, ��� ..
                                 //.. ���� ����� ������ ����� �������, �� ��� � �����, ����� ����� ������, �������? �.�.�. ..
                                 //.. ������� ���� ����� get-������ ��� ����. ����������
   dbl getPhysCmX() const;
   dbl getPhysCmY() const;
   dbl getPhysCmZ() const;
   
   //�� ���� ������� `friend`-�� C-tor (����-� ������� ������� ��� �����.��������)
   //friend MacroElem::MacroElem(Element*); // ��� ��������������� MacroElem ����� ������ � ������� `couplAx`. ���� �� ��������..
                                          //.. ����������� ������������ �� ���� ���� �����.���� (�.�. ����� �������� �� ����� ..
                                          //.. ������� [������ �� ��������] � ��������� ������ ���� MacroElem'�, ���������� �� ..
                                          //.. �����-� � �� MacroElem'�), �� ����� ������ ����� `friend` C-tor'�. (���� ..
                                          //.. ����� ��� bad practice). ��������� ... �� ����������.
   uns getCouplAxSize() const;
   
   // ����� ��� ������� ���� �� ������� ����� obj'�� `CouplingAxis` ������ C-tor'� `MacroElem`. � ��� ������ ������ �� ���� � ������, ..
   //.. �� ��� ����� ���� �����, ��� `new` � ����� ������, � `delete` � ������ (������ ��� � ������ �������). ������� ������ �������� obj:
   CouplingAxis getCouplAx(uns noea) const;


protected:
   Geometry geom_;
   Physics  phys_;

private:
   std::vector<CouplingAxis> * couplAx_;   ///@@@ 1) ��� ������������ �� `Element` ��� ���� �������� � `MacroElem` ..
                                          //.. ����������� ���������. �� ���� ������� �������� ������������ ..
                                          //.. ��� ��� ������ �� ������-�� BaseElement, � ���.��� ����� ����.
                                 ///@@@ 2) �������� �����������, ��� ������ "����������" ��� "���������". ������ ���, ����� �������, ..
                                 //.. ��� ��� �������, ���� ��������� obj ������ `Element`. �� ���� - ���� ������ ��������-�� ..
                                 //.. ���� ������ � �� � D-tor'� ����� ���� ����� ������ ������ ���������� obj-�� ������ `Element`.
};


// STRUCTures:
struct CouplingAxis {  // - ��� ����������
   Axis baseAxis;          // - ���, ���-�� ������� ���������� �����-� ��� CouplingAxis
   TriCoord shiftFromOrigin;  // - �������� "����� ����������"* ���-�� ����� ������ ��������� ��-�� (*- "����� ����������" - ..
                              //.. ��� ����� �� ��� ����������, ������������� ���������� ������������ �������, ..
                              //.. ��������������� ���. ��������� ��-�� ����� �� 3�� �����-���: ��� ����������, ..
                              //.. ���� ����� � �������-���� ����������� ���� ���������� ��������� ��-���)
};



#endif   //ELEMENT_H
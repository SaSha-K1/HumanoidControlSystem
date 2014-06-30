#include "MacroElem.h"


MacroElem::MacroElem (Element* pEl0)
               //dbl x, dbl y, dbl z,    //<- TriCoord   //DEL! �� �����, �.�. � C-tor ��������� ������ ������� ��-� ("�������. �����-�" �� ����� ������)
               //dbl a, dbl b, dbl g)    //<- TriAngles 
               : Element( pEl0->getGeomL(), pEl0->getGeomW(), pEl0->getGeomH(), pEl0->getPhysM(),
                          pEl0->getPhysCmX(), pEl0->getPhysCmY(), pEl0->getPhysCmZ(), nullptr) {
                          //(pEl0->getPhysCM())->x, (pEl0->getPhysCM())->y, (pEl0->getPhysCM())->z, nullptr ) {   //DEL!

               //: Element() {   //��������� ������������ ����� C-tor � �����.����-�� ���-���
   //Geom.l = pEl0->getGeomL(), Geom.w = pEl0->getGeomW(), Geom.h = pEl0->getGeomH();
   //Phys.m = pEl0->getPhysM(), Phys.cm = *(pEl0->getPhysCM());

   RelativePosition* ptrRP = new RelativePosition(0, 0, 0, 0, 0, 0); //(x,y,z,a,b,g)   ///������ ����� ����� ������ � ������ nullptr ������
   //ConstituentElemData &refCED = *(new ConstituentElemData(el0, ptrRP)); //��� ����� ���������� ����� ����� ��� ������������� ptr'�
   ConstituentElemData* ptrCED = new ConstituentElemData(pEl0, ptrRP);
   constitElDatas_.push_back(ptrCED);

   //uns numberOfElAxises = pEl0->getCouplAxSize();
   for (uns i = 0; i < pEl0->getCouplAxSize(); ++i) { ///@@@ ?: ��� ��������: ����� get.. ����� ����������� ����.��������, ��� ������ �������?
      //MECouplingAxis* ptrMECA = new MECouplingAxis(&(constitElDatas[0]->element), ... , nullptr);   //DEL!
      MECouplingAxis* ptrMECA = new MECouplingAxis(0, pEl0->getCouplAx(0+i), nullptr); //��� ��� ���������, �.�. � ���� C-tor'� �������� ..
                                                                                      //.. ������ � 0-�� ��-���, ���. ��������� ������� ..
                                                                                     //.. �, �����-���, �� MacroElem'� === �� 0-�� Element'�
      mECouplingAxises_.push_back(ptrMECA);   ///@@@ check `push_back()` ��������� � �����? (�.�. ������ ����������� ����� ������ 0?)
   }
    
}

MacroElem::~MacroElem() {
   for (auto it : constitElDatas_)  ///@@@ � ������� ���� auto& (��������, ����� `&`)
      delete it;     ///@@@ check `it` ����� ��� ��-�� �������.

   for (auto it : mECouplingAxises_)
      delete it;
}

void MacroElem::computeGeom() {
   ///@@@ Re-������!
}

void MacroElem::computePhys() {
   ///@@@ Re-������!
}

void MacroElem::addElem(Element*){
   ///@@@ Re-������!

   computeGeom();  /// !!! ��������
   computePhys();  /// !!! ��������
}
#include "Element.h"
#include "Exceptions.h"


Element::Element (/*Geometry:*/ dbl length, dbl width, dbl height,
                  /*Physics:*/ dbl mass, dbl x, dbl y, dbl z,
                  /*CouplingAxis:*/ std::vector<CouplingAxis> *couplAxPtr) {
   if (length <= 0 || width <= 0 || height <= 0 || mass <= 0)
      throw ExceptEqualOrSubZerro(length, width, height, mass);
   else {
      geom_.l = length,  geom_.w = width,  geom_.h = height;
      phys_.m = mass;
      //phys.cm =  *(new Point(x, y, z)); ///@@@ 1) ��������, ��� �������� ��� ����������� obj
                                          ///@@@ 2) ������� `new` (����� ����� `delete` or overloaded `=`, ��������������� obj (if poss.))
      phys_.cm.x = x,  phys_.cm.y = y,  phys_.cm.z = z;
      couplAx_ = couplAxPtr;
   }
}

Element::~Element() {
   delete couplAx_;
}

dbl Element::getGeomL() const { return geom_.l; }
dbl Element::getGeomW() const { return geom_.w; }
dbl Element::getGeomH() const { return geom_.h; }
dbl Element::getPhysM() const { return phys_.m; }
//Point* Element::getPhysCM() const { return &(phys.cm); }  //const-����� �� ����� ���������� ptr. ��������� ��.� ��������� � Element.h
dbl Element::getPhysCmX() const { return phys_.cm.x; }
dbl Element::getPhysCmY() const { return phys_.cm.y; }
dbl Element::getPhysCmZ() const { return phys_.cm.z; }

uns Element::getCouplAxSize() const { return couplAx_->size(); }

CouplingAxis Element::getCouplAx(uns noea) const {
   CouplingAxis ca((*couplAx_)[noea]);  //�������, ��� ������� Copy-C-tor
   return ca;
}
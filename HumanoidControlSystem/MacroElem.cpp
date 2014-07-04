#include "MacroElem.h"


MacroElem::MacroElem (Element* pEl0)
               //dbl x, dbl y, dbl z,    //<- TriCoord   //DEL! не нужно, т.к. в C-tor передаЄтс€ только базовый эл-т ("относит. полож-е" не имеет смысла)
               //dbl a, dbl b, dbl g)    //<- TriAngles 
               : Element( pEl0->getGeomL(), pEl0->getGeomW(), pEl0->getGeomH(), pEl0->getPhysM(),
                          pEl0->getPhysCmX(), pEl0->getPhysCmY(), pEl0->getPhysCmZ(), nullptr) {
                          //(pEl0->getPhysCM())->x, (pEl0->getPhysCM())->y, (pEl0->getPhysCM())->z, nullptr ) {   //DEL!

               //: Element() {   //экономнее использовать сразу C-tor с конкр.знач-ми пар-ров
   //Geom.l = pEl0->getGeomL(), Geom.w = pEl0->getGeomW(), Geom.h = pEl0->getGeomH();
   //Phys.m = pEl0->getPhysM(), Phys.cm = *(pEl0->getPhysCM());

   RelativePosition* ptrRP = new RelativePosition(0, 0, 0, 0, 0, 0); //(x,y,z,a,b,g)   ///вместо этого можно просто в вектор nullptr ложить
   //ConstituentElemData &refCED = *(new ConstituentElemData(el0, ptrRP)); //так потом невозможно вз€ть адрес дл€ инициализации ptr'а
   ConstituentElemData* ptrCED = new ConstituentElemData(pEl0, ptrRP);
   constitElDatas_.push_back(ptrCED);

   //uns numberOfElAxises = pEl0->getCouplAxSize();
   for (uns i = 0; i < pEl0->getCouplAxSize(); ++i) { ///@@@ ?: как устроено: метод get.. будет выполн€тьс€ кажд.итерацию, или только однажды?
      //MECouplingAxis* ptrMECA = new MECouplingAxis(&(constitElDatas[0]->element), ... , nullptr);   //DEL!
      MECouplingAxis* ptrMECA = new MECouplingAxis(0, pEl0->getCouplAx(0+i), nullptr); //тут без хитростей, т.к. в этом C-tor'е работаем ..
                                                                                      //.. только с 0-ым эл-том, кот. считаетс€ базовым ..
                                                                                     //.. и, соотв-нно, —  MacroElem'а === —  0-го Element'а
      mECouplingAxises_.push_back(ptrMECA);   ///@@@ check `push_back()` вставл€ет в конец? (т.е. первый вставленный имеет индекс 0?)
   }
    
}

MacroElem::~MacroElem() {
   for (auto it : constitElDatas_)  ///@@@ в примере было auto& (почитать, зачем `&`)
      delete it;     ///@@@ check `it` имеет тип эл-та вектора.

   for (auto it : mECouplingAxises_)
      delete it;
}

void MacroElem::computeGeom() {
   ///@@@ Re-зовать!
}

void MacroElem::computePhys() {
   ///@@@ Re-зовать!
}

void MacroElem::addElem(Element*){
   ///@@@ Re-зовать!

   computeGeom();  /// !!! ƒописать
   computePhys();  /// !!! ƒописать
}
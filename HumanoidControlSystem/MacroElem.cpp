#include "MacroElem.h"


MacroElem::MacroElem (Element* pEl0)
               : Element( pEl0->getGeomL(), pEl0->getGeomW(), pEl0->getGeomH(), pEl0->getPhysM(),
                          pEl0->getPhysCmX(), pEl0->getPhysCmY(), pEl0->getPhysCmZ(), nullptr) {

   RelativePosition* ptrRP = new RelativePosition(0, 0, 0, 0, 0, 0); //(x,y,z,a,b,g)   ///вместо этого можно просто в вектор nullptr ложить
   //ConstituentElemData &refCED = *(new ConstituentElemData(el0, ptrRP)); //так потом невозможно вз€ть адрес дл€ инициализации ptr'а
   ConstituentElemData* ptrCED = new ConstituentElemData(pEl0, ptrRP);
   constitElDatas_.push_back(ptrCED);

   //uns numberOfElAxises = pEl0->getCouplAxSize();
   for (uns i = 0; i < pEl0->getCouplAxSize(); ++i) { ///@@@ ?: как устроено: метод get.. будет выполн€тьс€ кажд.итерацию, или только однажды?
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
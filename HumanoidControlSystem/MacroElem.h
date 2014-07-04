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
      //dbl x, dbl y, dbl z,    //<- TriCoord   //DEL! не нужно, т.к. в C-tor передаЄтс€ только базовый эл-т ("относит. полож-е" не имеет смысла)
      //dbl a, dbl b, dbl g);   //<- TriAngles

   //MacroElem(void) {};
   //MacroElem(Element* el0 = nullptr,
   //   dbl x = 0.0, dbl y = 0.0, dbl z = 0.0,    //<- TriCoord
   //   dbl a = 0.0, dbl b = 0.0, dbl g = 0.0);   //<- TriAngles
   ~MacroElem();
   void addElem(Element*);

private:
   struct ConstituentElemData;   // данные составл€ющего эл-та (д/ вектора)
   std::vector<ConstituentElemData*> constitElDatas_; //базовым считаетс€ нулевой эл-т 
   std::vector<MECouplingAxis*> mECouplingAxises_;   // - оси сопр€жени€ ћакроЁл-та

   void computeGeom();
   void computePhys();
};


// STRUCTures:
struct TriAngles {   // использую как структуру из 3 углов Ёйлера (д/ определени€ положени€ в простр-ве). Ќе использую `TriCoord`, ..
   //.. чтобы не путатьс€ из-за имЄн переменных, которые там названы x, y, z.
   double a = 0;   //
   double b = 0;   // - углы Ёйлера
   double g = 0;   //
};

struct RelativePosition {                 ///@@@ почитать о " ватернионы и вращение пространства" и возможно заменить углы Ёйлера
   TriCoord localOriginCoords;    // - координаты точки начала координат локальной —  эл-та отн-но такой же точки ..
                                 //.. базового эл-та ( `elements[0]` ).
   TriAngles triAngs;
   
   RelativePosition(dbl x, dbl y, dbl z, dbl a, dbl b, dbl g) 
      /*: localOriginCoords.x(x), localOriginCoords.y(y), localOriginCoords.z(z),*/  ///@@@ возможно в списке иниц-ции C-tor'а нельз€ ...
      /*triAngs.a(a), triAngs.b(b), triAngs.g(g) {}*/                                   ///... обращатьс€ к пол€м вложенных кл./struct'ур.
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
   RelativePosition* relPosition; // - относительное положение эл-та в ћакроЁл-те отн-но базового (0-го) эл-та.

   ConstituentElemData(Element* el, RelativePosition* rp)
      : element(el), relPosition(rp) {}
   ~ConstituentElemData() {   //D-tor нужен, т.к. `relPosition` содержит ptr на obj класса `RelativePosition`, но ..
      delete relPosition;     //.. lifetime этого obj-та должно быть == lifetime'у вмещающего obj-та 'ConstituentElemData'
   }
};

struct MECouplingAxis { // - ќсь сопр€жени€ ћакроЁлемента (эта структура по сути - строка в 2-мерном ..
                           //.. массиве, Re-зованном как вектор структур.
   //Element** elemPtrPtr; // - ptr to corresponding `elements[i]` (ось какого эл-та)    // хранить ptr на эл-т вектора, видимо, хрень, т.к. при авто изменении его р-ра, адреса, вроде тоже мен€ютс€
   uns numberOfEl;   // є позиции в векторе, в кот. записан corresponding `elements[i]` (данные по оси каоторого пишем в этой стр-ре)
   CouplingAxis relativeAxisPos; // - относит.полож-е оси (и "точки сопр€жени€") в —  ћакроЁлемента
   MacroElem* coupledMacroElem = nullptr;  // - сопр€жЄнный по данной оси ћакроЁл-т.

   MECouplingAxis(uns noe, CouplingAxis ca, MacroElem* ptrME) 
   : numberOfEl(noe), relativeAxisPos(ca), coupledMacroElem(ptrME) {}
};


#endif   //MACRO_ELEM_H
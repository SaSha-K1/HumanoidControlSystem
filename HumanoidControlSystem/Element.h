#ifndef ELEMENT_H
#define ELEMENT_H


#include "includes.h"
#include "TriCoord.h"

//2 Структуры вначале, т.к. в классе obj'ы, а не ptr'ы:
//struct Geometry;     // - Геом. р-ры
struct Geometry {
   double l = 0;  //по OX
   double w = 0;  //по OY
   double h = 0;  //по OZ
};

//struct Physics;      // - Физич. пар-ры
struct Physics {
   double m = 0;
   Point cm;     // - Центр масс элемента
};

struct CouplingAxis;   // - Ось сопряжения
class MacroElem;


class Element {
public:
   Element (/*Geometry:*/ dbl length, dbl width, dbl height, 
            /*Physics:*/ dbl mass, dbl x, dbl y, dbl z,
            /*CouplingAxis:*/ std::vector<CouplingAxis> *couplAxPtr);   // чтобы не плодить min 2 C-tor'а с кучей парам-ров, решил ..
                                                                        //.. cre-ть `vector<CouplingAxis>` отдельно и передавать в ..
                                                                        //.. C-tor ptr на него.
   //Element();  //добавлял д/наследования, но пока обошёлся
   ~Element();
   ///@@@ Возможно понадобится ещё Copy C-tor и оператор `=` из-за того, что поле `couplAx` содержит ptr, а не obj.

   //Интерфейс:
   dbl getGeomL() const;
   dbl getGeomW() const;
   dbl getGeomH() const;
   dbl getPhysM() const;
   //Point* getPhysCM() const;   //возвращая ptr, нарушаю инкапсуляцию, а иначе целиком вернуть obj `phys.cm` не знаю, как ..
                                 //.. ведь можно только копию вернуть, но как её потом, когда сниму данные, удалить? х.е.з. ..
                                 //.. Поэтому пока ввожу get-методы для кажд. координаты
   dbl getPhysCmX() const;
   dbl getPhysCmY() const;
   dbl getPhysCmZ() const;
   
   //не могу сделать `friend`-ом C-tor (КОМП-р требует указать тип возвр.значения)
   //friend MacroElem::MacroElem(Element*); // при конструировании MacroElem нужен доступ к вектору `couplAx`. Дабы не городить..
                                          //.. конструкции вытаскивания из него всей необх.инфы (т.к. нужно пройтись по всему ..
                                          //.. вектору [размер не известен] и заполнить вектор осей MacroElem'а, пересчитав их ..
                                          //.. полож-е в СК MacroElem'а), то решил выдать права `friend` C-tor'у. (хотя ..
                                          //.. вроде как bad practice). Посмотрим ... НЕ получилось.
   uns getCouplAxSize() const;
   
   // Вроде как удобнее было бы создать копию obj'та `CouplingAxis` отдать C-tor'у `MacroElem`. А тот просто слизал бы инфу и удалил, ..
   //.. НО это вроде ваще негуд, что `new` в одном методе, а `delete` в другом (причём ещё и разных классов). Поэтому создаю стековый obj:
   CouplingAxis getCouplAx(uns noea) const;


protected:
   Geometry geom_;
   Physics  phys_;

private:
   std::vector<CouplingAxis> * couplAx_;   ///@@@ 1) при наследовании от `Element` это поле зависнет в `MacroElem` ..
                                          //.. виртуальным паразитом. По этой причине возможно унаследовать ..
                                          //.. оба эти класса от какого-то BaseElement, в кот.нет этого поля.
                                 ///@@@ 2) Возможно неправильно, что вместо "композиции" тут "агрегация". Сделал это, чтобы удобнее, ..
                                 //.. как мне кажется, было создавать obj класса `Element`. Но цена - этот вектор теоретич-ки ..
                                 //.. если забыть о нём в D-tor'е будет жить после сметри самого вмещающего obj-та класса `Element`.
};


// STRUCTures:
struct CouplingAxis {  // - Ось сопряжения
   Axis baseAxis;          // - ось, отн-но которой определяем полож-е оси CouplingAxis
   TriCoord shiftFromOrigin;  // - смещение "точки сопряжения"* отн-но точки начала координат эл-та (*- "точка сопряжения" - ..
                              //.. это точка на оси сопряжения, расположенная посередине стыковочного размера, ..
                              //.. сонаправленного оси. Стыковать эл-ты будем по 3ём парам-рам: оси сопряжения, ..
                              //.. этой точке и относит-ному направлению осей сопряжения стыкуемых эл-тов)
};



#endif   //ELEMENT_H
#ifndef CONNECTION_H
#define CONNECTION_H


#include "includes.h"


struct Amplitude;
struct EngineParametres;
class MacroElem;


// STRUCTures:    // вынужден определять тут (впереди), т.к. содержу в классе не ptr'ы, а obj-ты
struct Amplitude {
   dbl min;
   dbl max;
   //Amplitude(dbl mi, dbl ma) : min(mi), max(ma) {};    //C-tor пока не пригодился
};

struct EngineParametres {
   Amplitude ampl;
   // пока только например пишу (узнать, какие параметры серво нужны)
   dbl I;   //сила тока
   dbl U;   //напряжение
   dbl P;   //мощность
   //...
};


class Connection {
public:
   Connection(MacroElem*, MacroElem*);
   void reset();  // - занять стартовое положение
   void takeMinPos();
   void takeMaxPos();
   void takePos(dbl);
   void stop();
   //...

private:
   struct ConstituentMacroElemData;   // данные составляющего МакроЭл-та (д/ вектора)
   std::vector<ConstituentMacroElemData*> constitMElDatas_; // - массив ptr'ов на МакроЭл-ты участники соед-ния. //Возможно стоит ..
                                                            //.. соблюдать опред.порядок эл-тов (напр., от туловища к концам конечностей).
   const dbl startAngle_ = 0;    // - стартовое значение угла м/у МакроЭл-тами данн. соединения (т.е. угол, соотв-щий 0-му полож-ю серво)
   dbl currentAngle_ = 0;     // - тек.знач-е угла
   EngineParametres engParams_;  // - параметры серво
   Amplitude ampl_;// = engParams_.ampl;  // - крайние положения соединения (чаще будут == амплитуде серво, но не обязательно (конструкция))
};

struct ConstituentMacroElemData {
   MacroElem* mElem;
   uns axisIndex;    // - индекс в векторе `mECouplingAxis_`, соответств-щий оси, по которой данн.сопряжение
   bool couplingDirection;    // - сонаправлены ли базовые оси стыковки, или обратнонаправлены (вместе с этим имеем полную инфу, ..
                              //.. позволяющую однозначно определить соединение в пространстве.
};



#endif   //CONNECTION_H
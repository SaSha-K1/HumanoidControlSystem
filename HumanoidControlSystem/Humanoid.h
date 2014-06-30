///@@@ ѕредположительно это класс наивысшего уровн€ абстракции. “.е. тут собираем руки,ноги,... или кинематические цепи (как решим с ..
///.. предыдущим уровнем абстракции) в единое тело. » тут определ€ем методы разного уровн€ дл€ управлени€ им. “.е. начина€ от "согнуть ..
///.. правую ногу в колене на +10 градусов" и заканчива€ (мечты))) "пробежать к объекту ј, вз€ть его, принести в точку Ѕ, положить ..
///.. внутрь объекта ¬ (типа €щик), станцевать gangnam style".


#ifndef HUMANOID_H
#define HUMANOID_H


#include "includes.h"
#include "CinematicChain.h"
#include "Arm.h"
//#include "Leg.h"
//#include "Head.h"
//#include "Tail.h"

struct staticPose;   // - структура набора значений положений каждого серво, определ€ющего конкр. статичную позу


class Humanoid {
public:
   Humanoid(CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*);   //2x руки, 2х ноги, голова, туловище
   ///@@@ ѕредполагаю тут большое кол-во методов-команд роботу разного уровн€: ..
   ///.. 1 ур - (1сустав) локоть прав. руки согнуть на +10 градусов;    //нечто вроде armR_->elbow.bend(10);
   ///.. 2 ур - (1кин.цепь) подн€ть лев.руку вверх;                     //нечто вроде armL_->up();
   ///.. 3 ур - (сложн.движени€ в статике - позы из вектора `poses_`) развести руки в стороны;  //armsToTheSide();
   ///..                                   ноги на ширине плеч;            //feetShoulderWidthApart();
   ///..
   ///.. 4 ур - (комплексные движени€ в динамике) идти вперЄд              //go(direction d);
   ///..                                          повернутьс€ кругом       //aboutTurn();
   ///..                                          бежать к заданной точке  //run(checkPoint cp);
   ///..
   ///.. 5 ур - (интеллектуальные комманды) вз€ть предмет         //takeObj(object A)
   ///..                                    перенести предмет ј в точку Ѕ  //bringObj(object A, aim a);
   ///..                                    прибежать ко мне (учитыва€ преп€тстви€) //runToMe();
   ///..                                    победить робота ’     //sparWith(object X);
   ///..                                    search for shit       //searchForShit();

private:
   std::vector<CinematicChain*> body_; // - массив ptr'ов на составл€ющие тело кинем.цепи
   
   CinematicChain* head_; // = body_[0];
   CinematicChain* trunk_; // = body_[1];
   CinematicChain* armL_; // = body_[2];
   CinematicChain* armR_; // = body_[3];
   CinematicChain* legL_; // = body_[4];
   CinematicChain* legR_; // = body_[5];

   std::vector<staticPose*> poses_;
};



#endif   //HUMANOID_H
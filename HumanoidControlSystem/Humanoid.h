///@@@ ���������������� ��� ����� ���������� ������ ����������. �.�. ��� �������� ����,����,... ��� �������������� ���� (��� ����� � ..
///.. ���������� ������� ����������) � ������ ����. � ��� ���������� ������ ������� ������ ��� ���������� ��. �.�. ������� �� "������� ..
///.. ������ ���� � ������ �� +10 ��������" � ���������� (�����))) "��������� � ������� �, ����� ���, �������� � ����� �, �������� ..
///.. ������ ������� � (���� ����), ���������� gangnam style".


#ifndef HUMANOID_H
#define HUMANOID_H


#include "includes.h"
#include "CinematicChain.h"
#include "Arm.h"
//#include "Leg.h"
//#include "Head.h"
//#include "Tail.h"

struct staticPose;   // - ��������� ������ �������� ��������� ������� �����, ������������� �����. ��������� ����


class Humanoid {
public:
   Humanoid(CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*, CinematicChain*);   //2x ����, 2� ����, ������, ��������
   ///@@@ ����������� ��� ������� ���-�� �������-������ ������ ������� ������: ..
   ///.. 1 �� - (1������) ������ ����. ���� ������� �� +10 ��������;    //����� ����� armR_->elbow.bend(10);
   ///.. 2 �� - (1���.����) ������� ���.���� �����;                     //����� ����� armL_->up();
   ///.. 3 �� - (�����.�������� � ������� - ���� �� ������� `poses_`) �������� ���� � �������;  //armsToTheSide();
   ///..                                   ���� �� ������ ����;            //feetShoulderWidthApart();
   ///..
   ///.. 4 �� - (����������� �������� � ��������) ���� �����              //go(direction d);
   ///..                                          ����������� ������       //aboutTurn();
   ///..                                          ������ � �������� �����  //run(checkPoint cp);
   ///..
   ///.. 5 �� - (���������������� ��������) ����� �������         //takeObj(object A)
   ///..                                    ��������� ������� � � ����� �  //bringObj(object A, aim a);
   ///..                                    ��������� �� ��� (�������� �����������) //runToMe();
   ///..                                    �������� ������ �     //sparWith(object X);
   ///..                                    search for shit       //searchForShit();

private:
   std::vector<CinematicChain*> body_; // - ������ ptr'�� �� ������������ ���� �����.����
   
   CinematicChain* head_; // = body_[0];
   CinematicChain* trunk_; // = body_[1];
   CinematicChain* armL_; // = body_[2];
   CinematicChain* armR_; // = body_[3];
   CinematicChain* legL_; // = body_[4];
   CinematicChain* legR_; // = body_[5];

   std::vector<staticPose*> poses_;
};



#endif   //HUMANOID_H
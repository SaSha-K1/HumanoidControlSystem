///@@@ ���� �� �����, ���� �� ����� � ��������� ��������� ������� ��� ������ ���������.����� (���, ���, ������). ..
///.. ���� � ���, ��� ����� �������� ��������� � �������� �����������, �.�. ������������� �� ����.
///.. �, ���� ���� ������ ��� ������, �� ���� � ���, ��� ����� ����������� �������� � ����� ������� ������� ���������� ..
///.. ���� "��������� ���� � �����", "������� ����� ����� �����", �� ����� ������� ���� ������� �������� ����� ���� ..
///.. �.�., ��� ����� - ������� �������, ���������� �� ������ ����. � �������� ���������� �������� �������������� ���� � ..
///.. ���������� "����", "����", "������", ..., � �� ���������� � "������", "������", ... ��� ��������������� � ������� ..
///.. `Humanoid`, �.�. � �������� �����, � `Humanoid`� �� ����� ������� �������� �� ������ ����������� � ���������� ..
///.. ��������. � �������� ����� �� ����� �� ����, �� ������ ����� ���������� � ���� � ������ ������ ���������� ����������� ..
///.. �������� ���������. ���� ����� ��� ����.


#ifndef ARM_H
#define ARM_H


#include "includes.h"
#include "CinematicChain.h"


class Arm : public CinematicChain {
public:
   Arm(Connection*);
   

private:
   std::vector<Connection*> connections_; // - ������ ptr'�� �� ������������ ���� ����� (`Connections`)

};



#endif   //ARM_H
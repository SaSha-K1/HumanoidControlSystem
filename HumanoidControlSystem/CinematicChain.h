#ifndef CINEMATIC_CHAIN_H
#define CINEMATIC_CHAIN_H


#include "includes.h"

class Connection;


class CinematicChain {
public:
   CinematicChain(Connection*);
   void addConnection(Connection*);
   void reset();  // - ������ ��������� ���������
   void takePos(uns, dbl); // - ������ ��������� (������ ������� � ������� `connections_`,  ����)

private:
   std::vector<Connection*> connections_; // - ������ ptr'�� �� ������������ ���� ����� (`Connections`)
  
};



#endif   //CINEMATIC_CHAIN_H
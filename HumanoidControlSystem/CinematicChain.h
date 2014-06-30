#ifndef CINEMATIC_CHAIN_H
#define CINEMATIC_CHAIN_H


#include "includes.h"

class Connection;


class CinematicChain {
public:
   CinematicChain(Connection*);
   void addConnection(Connection*);
   void reset();  // - занять стартовое положение
   void takePos(uns, dbl); // - занять положение (индекс сустава в векторе `connections_`,  угол)

private:
   std::vector<Connection*> connections_; // - массив ptr'ов на составляющие цепь связи (`Connections`)
  
};



#endif   //CINEMATIC_CHAIN_H
#ifndef CONNECTION_H
#define CONNECTION_H


#include "includes.h"


struct Amplitude;
struct EngineParametres;
class MacroElem;


// STRUCTures:    // �������� ���������� ��� (�������), �.�. ������� � ������ �� ptr'�, � obj-��
struct Amplitude {
   dbl min;
   dbl max;
   //Amplitude(dbl mi, dbl ma) : min(mi), max(ma) {};    //C-tor ���� �� ����������
};

struct EngineParametres {
   Amplitude ampl;
   // ���� ������ �������� ���� (������, ����� ��������� ����� �����)
   dbl I;   //���� ����
   dbl U;   //����������
   dbl P;   //��������
   //...
};


class Connection {
public:
   Connection(MacroElem*, MacroElem*);
   void reset();  // - ������ ��������� ���������
   void takeMinPos();
   void takeMaxPos();
   void takePos(dbl);
   void stop();
   //...

private:
   struct ConstituentMacroElemData;   // ������ ������������� �������-�� (�/ �������)
   std::vector<ConstituentMacroElemData*> constitMElDatas_; // - ������ ptr'�� �� �������-�� ��������� ����-���. //�������� ����� ..
                                                            //.. ��������� �����.������� ��-��� (����., �� �������� � ������ �����������).
   const dbl startAngle_ = 0;    // - ��������� �������� ���� �/� �������-���� ����. ���������� (�.�. ����, �����-��� 0-�� �����-� �����)
   dbl currentAngle_ = 0;     // - ���.����-� ����
   EngineParametres engParams_;  // - ��������� �����
   Amplitude ampl_;// = engParams_.ampl;  // - ������� ��������� ���������� (���� ����� == ��������� �����, �� �� ����������� (�����������))
};

struct ConstituentMacroElemData {
   MacroElem* mElem;
   uns axisIndex;    // - ������ � ������� `mECouplingAxis_`, ����������-��� ���, �� ������� ����.����������
   bool couplingDirection;    // - ������������ �� ������� ��� ��������, ��� ����������������� (������ � ���� ����� ������ ����, ..
                              //.. ����������� ���������� ���������� ���������� � ������������.
};



#endif   //CONNECTION_H
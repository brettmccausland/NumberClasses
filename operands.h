#ifndef OPERANDS
#define OPERANDS
//#include "fstream"
//#include "iostream"
#include "token.h"
//#include "fractions.h"
//#include "mixed.h"
using namespace std;
//------------------------------
//
// if can be reduced to whole number return token pointer to num
// else return token pointer to fraction
// friend token* operator + (const fraction d1,const Num d2);
//-------------------------------
class Num:public virtual token
{

    public:
         Num();
         //Num(const Num& copyconstruct);//doesnt work
         Num(int value);//c
         virtual ~Num();//c
         int getNum() const;
         void setnum(int value);

         Num& operator = (const Num& R2);
         //-----------------------------------------------------------
         friend ostream& operator<<(ostream& out,Num& print);//link?

         friend Num operator + (const Num d1, const Num d2);
         friend Num operator - (const Num d1, const Num d2);
         friend Num operator * (const Num d1, const Num d2);
          double getdouble();
        //--------------------------------------
    protected:
    int num;
};
double Num::getdouble()
{
    double r= num;
    return r;
}

Num operator+(const Num d1, const Num d2)
{
 return Num(d1.num+d2.num);
}
//-----------------------------------------
Num operator-(const Num d1, const Num d2)
{
 return Num(d1.num-d2.num);
}

//-----------------------------------------
Num operator*(const Num d1, const Num d2)
{
 return Num(d1.num*d2.num);
}

Num& Num::operator = (const Num& R2)
{
    this->num=R2.num;
    return *this;
}

//-----------friend operators-----------------------
ostream& operator<<(ostream& out,Num& print)
{
  out<<print.getNum();
  return out;
}
Num::Num()//:token()
{
    num=0;
}
Num::Num(int value)
{
    num=value;
}
Num::~Num()
{
   num=0;
}
int Num::getNum()const
{
    return num;
}
void Num:: setnum(int value)
{
    num=value;
}

#endif // OPERANDS


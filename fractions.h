#ifndef FRACTIONS
#define FRACTIONS
//#include "token.h"
//#include <iostream>
using namespace std;
class fraction:public virtual token
{
public:
    friend class Num;
    fraction();
    fraction(int N, int D);
     fraction(int N);
     fraction(const fraction& copyconstruct);
    virtual~fraction();

      void setnumerator(int N);
      void setdenom(int d);
      void setfraction(int n,int d=1);
      int getnumerator() const;
      int getdenom() const;
     // void reduce();
     friend ostream& operator<<(ostream& out,fraction& print);
     fraction& operator = (const fraction& R2);
     void Print();
    int gcd(int p, int q);
    double getdouble();

protected:
    int denom;
    int num;
};
double fraction::getdouble()
{
    return (this->getnumerator() / this->getdenom());
}

fraction::fraction(const fraction &copyconstruct)
{
    denom=copyconstruct.getdenom();
    num=copyconstruct.getnumerator();
}
fraction::fraction(int N,int D)
{
    num=N;
    denom=D;
}
fraction::fraction(int N)
{
    num=N;
    denom=1;
}
fraction::~fraction()
{
    denom=0;
    num=0;
}
void fraction::setnumerator(int N) // check
{
   num=N;
}

void fraction::setdenom(int D)
{
    denom=D;
}

void fraction:: setfraction(int N,int D)
{
    num=N;
    denom=D;
}
int fraction::getnumerator() const //check
{
  return(num);
}
int fraction::getdenom() const
{
  return(denom);
}
fraction& fraction::operator = (const fraction& R2)
{
    this->num=R2.num;
    this->denom=R2.denom;
    return *this;
}
ostream& operator<<(ostream& out,fraction& print)
{
    out<<print.getnumerator()<<"/"<<print.getdenom();
    return out;
}

void fraction::Print()
{
   cout<<getnumerator()<<"/"<<getdenom()<<endl;
}

int fraction::gcd(int p, int q)
{
    return !q ? p : gcd(q,p%q);
}

#endif // FRACTIONS


#ifndef MIXED
#define MIXED
//#include "token.h"
#include "operands.h"
#include "fractions.h"



class mixed : public virtual fraction, public virtual Num
{
public:
    //friend class fraction;
    mixed();
    mixed(int W,int N,int D);
    mixed(Num& mynum,fraction& myfrac);
    ~mixed();
    fraction& getIPF()const;
    fraction& getfrac()const;
    Num &getwholeNum() const;


    friend token* operator + (const fraction& d1,const Num& d2);
    friend token* operator + (const Num& d2,const fraction& d1);
     friend token* operator + (const mixed& md2,const mixed& md1);
     friend token* operator + (const fraction& R1,const fraction& R2);

    friend token* operator - (const fraction& d1,const Num& d2);
    friend token* operator - (const Num& d2,const fraction& d1);
    friend token* operator -(const mixed& md2,const mixed& md1);
     friend token* operator - (const fraction& R1,const fraction& R2);

    friend token* operator * (const Num& d2,const fraction& d1);
    friend token* operator * (const fraction& d1,const Num& d2);
    friend token* operator *(const mixed& md2,const mixed& md1);

   friend token* operator / (const Num& d1, const Num& d2);
   friend token* operator / (const Num& d2,const fraction& d1);
   friend token* operator / (const fraction& d1,const Num& d2);
   friend token* operator / (const mixed& md2,const mixed& md1);

   // fraction on fraction
   friend token* operator / (const fraction& R1,const fraction& R2);


   friend token* operator * (const fraction& R1,const fraction& R2);

   // num on num
   friend ostream& operator<<(ostream& out,mixed& print);

protected:
    Num* whole;
    fraction* frac;
};


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
token* operator + (const fraction& R1,const fraction& R2)// mix only
{

       int d1,d2,n1,n2,n3,d3;
       d1=R1.getdenom();
       d2=R2.getdenom();
       n1=R1.getnumerator();
       n2=R2.getnumerator();
       d3=(d1*d2);
       n1=(n1*d2);
       n2=(n2*d1);
       n3=(n1+n2);
       if(!(n3%d3))
       {
           //make whole number
            Num* ptr = new Num(n3/d3);
           // return prt;
            fraction* frac= new fraction();
            token* themix= new mixed(*ptr,*frac);
            return themix;
       }
       else
       {
           if(n3>d3)
           {
                int whole= n3/ d3;
                int fracnum= n3 % d3;
                token* ptr= new mixed (whole,fracnum,d3);
                return ptr;
           }
           else
           {
               fraction* ptr= new fraction(n3,d3);
               //return ptr;
               Num* numptr = new Num();
               token* themix= new mixed(*numptr,*ptr);
               return themix;
           }
       }


}
token* operator + (const fraction& d1, const Num& d2)
{
    signed int holder;
    holder=d1.getdenom()*d2.getNum();
    holder=d1.getnumerator()+holder;
    if(!(holder % d1.getdenom()))
    {

        holder=holder/d1.getdenom();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
          if (holder>d1.getdenom())
          {
              int whole= holder/ d1.getdenom();
              int fracnum= holder % d1.getdenom();
              token* ptr= new mixed (whole,fracnum,d1.getdenom());
              return ptr;
          }
          else
          {
              token* ptr= new fraction(holder,d1.getdenom());
              //ptr reduce
              return ptr;
          }

    }
}
token* operator + (const mixed& md2,const mixed& md1)
{
    fraction R1=md2.getIPF();
    fraction R2 =md1.getIPF();


           int d1,d2,n1,n2,n3,d3;
           d1=R1.getdenom();
           d2=R2.getdenom();
           n1=R1.getnumerator();
           n2=R2.getnumerator();
           d3=(d1*d2);
           n1=(n1*d2);
           n2=(n2*d1);
           n3=(n1+n2);
           if(!(n3%d3))
           {
               //make whole number
                Num* ptr = new Num(n3/d3);
               // return prt;
                fraction* frac= new fraction();
                token* themix= new mixed(*ptr,*frac);
                return themix;
           }
           else
           {
               if(n3>d3)
               {
                    int whole= n3/ d3;
                    int fracnum= n3 % d3;
                    token* ptr= new mixed (whole,fracnum,d3);
                    return ptr;
               }
               else
               {
                   fraction* ptr= new fraction(n3,d3);
                   //return ptr;
                   Num* numptr = new Num();
                   token* themix= new mixed(*numptr,*ptr);
                   return themix;
               }
           }


}
token* operator + ( const Num& d2,const fraction& d1) // always fraction
{
    signed int holder;
    holder=d1.getdenom()*d2.getNum();
    holder=d1.getnumerator()+holder;

              token* ptr= new fraction(holder,d1.getdenom());
              //ptr reduce
              return ptr;


}
//token* operator + ( const Num d2,const fraction d1)
//{
//    signed int holder;
//    holder=d1.getdenom()*d2.getNum();
//    holder=d1.getnumerator()+holder;
//    if(!(holder % d1.getdenom()))
//    {
//        //cout<<"returned num"<<endl;
//        holder=holder/d1.getdenom();
//        token* ptr = new Num(holder);
//        return ptr;
//    }
//    else
//    {
//          if (holder>d1.getdenom())
//          {
//              int whole= holder/ d1.getdenom();
//              int fracnum= holder % d1.getdenom();
//              token* ptr= new mixed (whole,fracnum,d1.getdenom());
//              return ptr;
//          }
//          else
//          {
//              token* ptr= new fraction(holder,d1.getdenom());
//              //ptr reduce
//              return ptr;
//          }

//    }
//}
//---------------------------------------------------------
token* operator - (const fraction& d1, const Num& d2)
{
    signed int holder;
    holder=d1.getdenom()*d2.getNum();
    holder=d1.getnumerator()-holder;
    if(!(holder % d1.getdenom()))
    {
        holder=holder/d1.getdenom();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
          if (holder>d1.getdenom())
          {
              int whole= holder/ d1.getdenom();
              int fracnum= holder % d1.getdenom();
              token* ptr= new mixed (whole,fracnum,d1.getdenom());
              return ptr;
          }
          else
          {
              token* ptr= new fraction(holder,d1.getdenom());
              //ptr reduce
              return ptr;
          }

    }
}
token* operator - (const fraction& R1,const fraction& R2) // mix only
{

        int d1,d2,n1,n2,n3,d3;

        d1=R1.getdenom();
        d2=R2.getdenom();
        n1=R1.getnumerator();
        n2=R2.getnumerator();
        d3=(d1*d2);
        n1=(n1*d2);
        n2=(n2*d1);
        n3=(n1-n2);
        if(!(n3%d3))
        {
            //make whole number
             Num* ptr = new Num(n3/d3);
            // return prt;
             fraction* frac= new fraction();
             token* themix= new mixed(*ptr,*frac);
             return themix;
        }
        else
        {
            if(n3>d3)
            {
                 int whole= n3/ d3;
                 int fracnum= n3 % d3;
                 token* ptr= new mixed (whole,fracnum,d3);
                 return ptr;
            }
            else
            {
                fraction* ptr= new fraction(n3,d3);
                //return ptr;
                Num* numptr = new Num();
                token* themix= new mixed(*numptr,*ptr);
                return themix;
            }
        }
}

token* operator - (const Num& d2,const fraction& d1)
{
    int holder;
    holder=d1.getdenom()*d2.getNum();
    holder=holder-d1.getnumerator();
    if(!(holder % d1.getdenom()))
    {
        holder=holder/d1.getdenom();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
        // if improper construct a improper fraction
        token* ptr= new fraction(holder,d1.getdenom());
        //ptr reduce
        return ptr;
    }
}
token* operator - (const mixed& md2,const mixed& md1)
{
    fraction R1=md2.getIPF();
    fraction R2=md1.getIPF();


            int d1,d2,n1,n2,n3,d3;

            d1=R1.getdenom();
            d2=R2.getdenom();
            n1=R1.getnumerator();
            n2=R2.getnumerator();
            d3=(d1*d2);
            n1=(n1*d2);
            n2=(n2*d1);
            n3=(n1-n2);
            if(!(n3%d3))
            {
                //make whole number
                 Num* ptr = new Num(n3/d3);
                // return prt;
                 fraction* frac= new fraction();
                 token* themix= new mixed(*ptr,*frac);
                 return themix;
            }
            else
            {
                if(n3>d3)
                {
                     int whole= n3/ d3;
                     int fracnum= n3 % d3;
                     token* ptr= new mixed (whole,fracnum,d3);
                     return ptr;
                }
                else
                {
                    fraction* ptr= new fraction(n3,d3);
                    //return ptr;
                    Num* numptr = new Num();
                    token* themix= new mixed(*numptr,*ptr);
                    return themix;
                }
            }
}
//--------------------------------------------------------------------

//*********************************************************************

//-----------------------------------------
//Num operator*(const Num d1, const Num d2)
//{
// return Num(d1.num*d2.num);
//}
token* operator * (const mixed& md2,const mixed& md1)
{
    int hd1,hd2,hn1,hn2,hn3,hd3;

    hd1=md1.getdenom();
    hd2=md2.getdenom();
    hn1=md1.getnumerator();
    hn2=md2.getnumerator();
    hd3=(hd1*hd2);
    hn3=(hn1*hn2);
    if(!(hn3%hd3))
    {
        Num* ptr = new Num(hn3/hd3);
       fraction* frac= new fraction();
        mixed* themix=new mixed(*ptr,*frac);
        return themix;
    }
    else
    {
        if(hn3>hd3)
        {
           //make whole number
           Num* ptr = new Num(hn3/hd3);
           // return prt;
           fraction* frac= new fraction();
           token* themix= new mixed(*ptr,*frac);
           return themix;
        }
        else
        {
            fraction* f= new fraction (hn3,hd3);
            //return ptr;
            Num* numptr = new Num();
            token* themix= new mixed(*numptr,*f);
            return themix;
        }
    }
}


token* operator * (const Num& d2,const fraction& d1)
{
    int holder;
    holder=d1.getnumerator()*d2.getNum();
    if(!(holder % d1.getdenom()))
    {
        holder=holder/d1.getdenom();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
          if (holder>d1.getdenom())
          {
              int whole= holder/ d1.getdenom();
              int fracnum= holder % d1.getdenom();
              token* ptr= new mixed (whole,fracnum,d1.getdenom());
              return ptr;
          }
          else
          {
              token* ptr= new fraction(holder,d1.getdenom());
              //ptr reduce
              return ptr;
          }

    }
}
token* operator * (const fraction& R1,const fraction& R2)//mixed only
{

        int d1,d2,n1,n2,n3,d3;

        d1=R1.getdenom();
        d2=R2.getdenom();
        n1=R1.getnumerator();
        n2=R2.getnumerator();
        d3=(d1*d2);
        n3=(n1*n2);
        if(!(n3%d3))
        {
            token* ptr = new Num(n3/d3);
            return ptr;
        }
        else
        {
            if(n3>d3)
            {
               //make whole number
               Num* ptr = new Num(n3/d3);
               // return prt;
               fraction* frac= new fraction();
               token* themix= new mixed(*ptr,*frac);
               return themix;
            }
            else
            {
                fraction* ptr= new fraction(n3,d3);
                //return ptr;
                Num* numptr = new Num();
                token* themix= new mixed(*numptr,*ptr);
                return themix;
            }
        }
}
token* operator * (const fraction& d1,const Num& d2)
{
    int holder;
    holder=d1.getnumerator()*d2.getNum();
    if(!(holder % d1.getdenom()))
    {
        holder=holder/d1.getdenom();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
          if (holder>d1.getdenom())
          {
              int whole= holder/ d1.getdenom();
              int fracnum= holder % d1.getdenom();
              token* ptr= new mixed (whole,fracnum,d1.getdenom());
              return ptr;
          }
          else
          {
              token* ptr= new fraction(holder,d1.getdenom());
              //ptr reduce
              return ptr;
          }

    }
}
//*********************************************************************
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
token* operator / (const fraction& d1,const Num& d2)
{
    int holder;
    holder=d1.getdenom()*d2.getNum();
    if(!(holder % d1.getnumerator()))
    {
        holder=holder/d1.getnumerator();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
         // if improper construct a improper fraction
        token* ptr= new fraction(holder,d1.getnumerator());
        //ptr reduce
        return ptr;
    }
}
token* operator / (const Num& d2,const fraction& d1)
{
    int holder;
    holder=d1.getdenom()*d2.getNum();
    if(!(holder % d1.getnumerator()))
    {
        holder=holder/d1.getnumerator();
        token* ptr = new Num(holder);
        return ptr;
    }
    else
    {
         // if improper construct a improper fraction
        token* ptr= new fraction(holder,d1.getnumerator());
        //ptr reduce
        return ptr;
    }
}
token* operator/ (const Num& d1, const Num& d2)
{
     if(!(d1.getNum()%d2.getNum()))
     {
         token* ptr = new Num(d1.getNum() / d2.getNum());
         return ptr;
     }
     else
     {
         if (d2.getNum() > d1.getNum())
         {
             int whole= d2.getNum()/ d1.getNum();
             int fracnum= d2.getNum() % d1.getNum();
             token* ptr= new mixed (whole,fracnum,d1.getNum());
             return ptr;
         }
         else
         {
             token* ptr= new fraction(d1.getNum(),d2.getNum());
             //ptr reduce
             return ptr;
         }

     }
}
// ------fraction on fraction------
token* operator / (const fraction& R1,const fraction& R2) //mix only
{

        int d1,d2,n1,n2,n3,d3;

        d1=R1.getdenom();
        d2=R2.getnumerator();
        n1=R1.getnumerator();
        n2=R2.getdenom();
        d3=(d1*d2);
        n3=(n1*n2);
        if(!(n3%d3))
        {
           //make whole number
            Num* ptr = new Num(n3/d3);
           // return prt;
           fraction* frac= new fraction();
            token* themix= new mixed(*ptr,*frac);
            return themix;
        }
        else
        {
            if(n3>d3)
            {
                 int whole= n3/ d3;
                 int fracnum= n3 % d3;
                 token* ptr= new mixed (whole,fracnum,d3);
                 return ptr;
            }
            else
            {
                fraction* ptr= new fraction(n3,d3);
                //return ptr;
                Num* numptr = new Num();
                token* themix= new mixed(*numptr,*ptr);
                return themix;


            }
        }
}
token* operator / (const mixed& md2,const mixed& md1)
{
    fraction R1=md2.getIPF();
     fraction R2= md1.getIPF();


            int d1,d2,n1,n2,n3,d3;

            d1=R1.getdenom();
            d2=R2.getnumerator();
            n1=R1.getnumerator();
            n2=R2.getdenom();
            d3=(d1*d2);
            n3=(n1*n2);
            if(!(n3%d3))
            {
               //make whole number
                Num* ptr = new Num(n3/d3);
               // return prt;
               fraction* frac= new fraction();
                mixed* themix= new mixed(*ptr,*frac);
                return themix;
            }
            else
            {
                if(n3>d3)
                {
                     int whole= n3/ d3;
                     int fracnum= n3 % d3;
                     mixed* ptr= new mixed (whole,fracnum,d3);
                     return ptr;
                }
                else
                {
                    fraction* ptr= new fraction(n3,d3);
                    //return ptr;
                    Num* numptr = new Num();
                    mixed* themix= new mixed(*numptr,*ptr);
                    return themix;


                }
            }
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//---------------------------------------------
mixed::mixed(Num &mynum, fraction &myfrac)
{
    whole=new Num(mynum.getNum());
    frac=new fraction(myfrac.getnumerator(),myfrac.getdenom());
}
mixed::mixed()
{
    whole=new Num();
    frac=new fraction();
}
mixed::mixed(int W,int N,int D)
{
    whole=new Num(W);
    frac=new fraction(N,D);
}
mixed::~mixed()
{

}
fraction& mixed::getfrac() const
{
  return *frac;
}
Num& mixed::getwholeNum() const
{
    return *whole;
}
fraction& mixed::getIPF()const
{
    //frac4= dynamic_cast<fraction*>(anwser);
    fraction* myreturn=dynamic_cast<fraction*> (*whole+*frac);
    return *myreturn;
}
ostream& operator<<(ostream& out,mixed& print)
{
    out<<print.getNum()<<" "<< print.getfrac();
    return out;
}

#endif // MIXED


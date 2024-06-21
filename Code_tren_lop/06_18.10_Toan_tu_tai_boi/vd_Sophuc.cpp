#include <iostream>
#include <math.h>
using namespace std;
class Sophuc
{
private:
float a,b;
public:
Sophuc(float x = 0.0, float y = 0.0);
void Xuat();
Sophuc operator -();
Sophuc operator +(Sophuc c2);
Sophuc operator -(Sophuc c2);
};
Sophuc::Sophuc(float x,float y)
{
a = x;
b = y;
}
void Sophuc::Xuat()
{ if (b>=0)
cout<<a<<" + "<<b<<"i"<<endl;
else
cout<<a<<b<<"i"<<endl;
}
Sophuc Sophuc::operator -() //toan tu - de lay lien hiep cua so phuc
{
Sophuc c;
c.a = a;
c.b = -b;
return c;
}
Sophuc Sophuc::operator +(Sophuc c2)
{
Sophuc c;
c.a= a + c2.a ;
c.b= b + c2.b ;
return c;
}
Sophuc Sophuc::operator -(Sophuc c2)
{
Sophuc c;
c.a= a - c2.a ;
c.b= b - c2.b ;
return c;
}
//tuong tu cho toan tu *, /13
int main()
{
Sophuc c1, c2(2.5,4.6),c3(3.7,4.9), c4, c5(2,6);
cout<<"c1 = ";
c1.Xuat();
cout<<"c2 = ";
c2.Xuat();
cout<<"c3 = ";
c3.Xuat();
cout<<"c4 = ";
c4.Xuat();
c1 = c2 + c3;
//c1 = c2.operator +(c3);
cout<<endl<<"c1 = c2 + c3 = ";
c1.Xuat();
c4 = -c2;
cout<<"c4 = ";
c4.Xuat();
c1 = c2 -c3;
return 0;
}

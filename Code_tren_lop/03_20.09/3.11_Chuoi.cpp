#include <iostream>
#include<string.h>
using namespace std;
class Chuoi{
	char str[100]; //cach khai bao chuoi cua ngon ngu C
	int n; //kich thuoc chuoi
	public:
	Chuoi();
	Chuoi(char st[]);
	void nhap();
	void hienthi();
	char phantu(int i); //tra ve ky tu thu i cua chuoi
	Chuoi noi(Chuoi ob2); //ket noi 2 chuoi
};Chuoi::Chuoi() //ham tao mac dinh
{}
Chuoi::Chuoi(char st[]) //ham tao khoi gan chuoi
{
strcpy(str,st); //loi khi go str = st
}
void Chuoi::nhap()
{
cout<<"\n Nhap chuoi:";
gets(str);
n = strlen(str);
}
void Chuoi::hienthi()
{
cout<<str<<endl;
}
char Chuoi::phantu(int i)
{
if (i<0 || i >= n)
return -1;
return str[i];
}
Chuoi Chuoi::noi(Chuoi ob2)
{Chuoi ob; //loi khi go ob = str + ob2.str;
strcpy(ob.str,str);
strcat(ob.str,ob2.str); //noi xong 2 chuoi
ob.n = strlen(ob.str);
return ob;
}
int main()
{
Chuoi ob1("Khoa"),ob2("CNTT"),ob3;
ob3 = ob1.noi(ob2);
cout<<"\n ob1 = ";ob1.hienthi();
cout<<"\n ob2 = ";ob2.hienthi();
cout<<"\n ob3 = ";ob3.hienthi();
cout<<"\nPhan tu thu 5 cua ob3 la: "<<ob3.phantu(4);
ob1.nhap();
ob2.nhap();
ob3= ob1.noi(ob2);
cout<<"\n ob1 = ";ob1.hienthi();
cout<<"\n ob2 = ";ob2.hienthi();
cout<<"\n ob3 = ";ob3.hienthi();
cout<<"\nPhan tu thu 5 cua ob3 la: "<<ob3.phantu(4);
return 0;
}
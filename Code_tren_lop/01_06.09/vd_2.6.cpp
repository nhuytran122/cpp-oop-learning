#include <iomanip>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct TS
{
char ht[20]; //string ht
long sobd;
float td; //tong diem
};
void nhap(TS *ts, int n)
{for (int i=0;i<n;++i)
{
cin.ignore();
cout<<"\n Thi sinh thu "<<i+1<<endl;
cout<<"\n Ho ten: ";
cin.get(ts[i].ht,20);
cout<<"so bao danh: ";
cin>>ts[i].sobd;
cout<<"tong diem: ";
cin>>ts[i].td;
}
}
void sapxep(TS *ts, int n)
{ for (int i=0;i<n-1;++i)
for (int j=i+1;j<n;++j)
if (ts[i].td<ts[j].td)
{
TS tg=ts[i];
ts[i]=ts[j];
ts[j]=tg;
}
}
void xuat(TS *ts, int n)
{ for (int i=0;i<n;++i)
cout<<ts[i].ht<<setw(6)<<ts[i].td<<endl;
}
int main(void)
{
TS *ts;
int n;
cout<<"\nNhap so thi sinh n = ";
cin>>n;
ts = new TS[n];
if (ts == NULL)
{
cout << "\n Loi cap phat vung nho";
exit(1);
}
nhap(ts,n);
sapxep(ts,n);
cout<<"\nDanh sach sau khi sap xep: "<<endl;
xuat(ts,n);
delete ts;
return 0;
}

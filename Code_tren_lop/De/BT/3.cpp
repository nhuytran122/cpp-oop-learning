#include<bits/stdc++.h>
using namespace std;

class Nguoi{
 private:
 	  string hodem,ten;
 	  int d,m,y;
 public:
 	void Nhap_Nguoi();
 	void Xuat_Nguoi();
 	string get_hodem();
 	string get_ten();
 	int operator > (Nguoi a);
 };
 
 void Nguoi::Nhap_Nguoi(){
 	cout<<"Nhap ho dem: ";
 fflush(stdin);
 getline(cin,hodem);
 cout<<"Nhap ten: ";
 fflush(stdin);
 getline(cin,ten);
 cout <<"nhap ngay thang nam sinh: ";
    cin>>d>>m>>y;
 }
 
 void Nguoi::Xuat_Nguoi(){
 cout<<setw(12)<<left<<hodem<<
	   setw(20)<<left<<ten<<
	   setw(10)<<left<<d<<m<<y;
 }
 string Nguoi::get_hodem(){
 return hodem;}
 string Nguoi::get_ten(){
 return ten;}
 
 int Nguoi::operator>(Nguoi a)
{
	if(ten>a.ten) return 1;
	if ((ten==a.ten) and (hodem>a.hodem) )return 1;

	return 0;
	}
	
class Sinhvien:public Nguoi{
	private:
	  	string MSV;
	  	float DTB;
  	public:
	  	void Nhap_Sinhvien(){
	  		Nhap_Nguoi();
			 cout<<"Nhap ma sinh vien: ";
			 fflush(stdin);
			 getline(cin,MSV);
			 cout<<"Nhap Diem trung binh: ";
			 cin>>DTB;
		  }
	  	void Xuat_Sinhvien(){
	  		Xuat_Nguoi();
		   	cout<<setw(20)<<left<<MSV<<
		  	setw(10)<<left<<DTB;
		}
	  	float getDtb(){
	  		return DTB;
	  	}
};
	
 
class Quanly{
	private:
		int n;
		Sinhvien sv[200];
		
	public:
		void Nhap_ds();
		void Sapxep_Hienthi();
		void In_DTB();
		void getDsDtbmax();
		float getDtbmax();
};


void Quanly::Nhap_ds(){
	do {
		cout<<"Nhap so luong sinh vien: ";
		cin >> n;
	}while(n<0 or n>200);
	cin.ignore(1);
	cout<<"Nhap thong tin cho sinh vien :"<<endl;
	for( int i=0;i<n;i++){
	   cout <<"Nhap thong tin sinh vien thu ["<<i+1<<"]:"<<endl;
	       sv[i].Nhap_Sinhvien();
		   }
} 

void Quanly::Sapxep_Hienthi()
{
	for (int i=0;i<n;i++) {
	    for (int j=i+1;j<n;j++){
		    if (sv[i]>sv[j]){
		    	   Sinhvien temp=sv[i];
		    	   sv[i]=sv[j];
		    	   sv[j]=temp; }
		}
	}
 cout<<"\n Danh sach sau khi sap xep theo ten :"<<endl;
	 cout << setw(12)<<left<<"Ho dem"<<
		  setw(20)<<left<<" ten"<<
		  setw(10)<<left<<"Ngay sinh"<<
		  setw(10)<<left<<"MSV"<<
		  setw(20)<<left<<"DTB";
	for(int i=0;i<n;i++){
	sv[i].Xuat_Sinhvien();
	cout<<endl;
	}
	
	float Dtbmax = sv[0].getDtb();
	for (int i=0;i<n;i++){
        if (sv[i].getDtb() > Dtbmax)
     		Dtbmax = sv[i].getDtb();
	}
    cout<<"\n Danh sach sinh vien co diem trung binh lon nhat :"<<endl;
	cout << setw(12)<<left<<"Ho dem"<<
		  setw(20)<<left<<" ten"<<
		  setw(10)<<left<<"Ngay sinh"<<
		  setw(10)<<left<<"MSV"<<
		  setw(20)<<left<<"DTB";
	for (int i=0;i<n;i++){
	if(sv[i].getDtb() == Dtbmax){
	sv[i].Xuat_Sinhvien();
	cout<<endl;
	}
}
}

int main(){
  Quanly ob;
  ob.Nhap_ds();
  ob.Sapxep_Hienthi();
  return 0;
}

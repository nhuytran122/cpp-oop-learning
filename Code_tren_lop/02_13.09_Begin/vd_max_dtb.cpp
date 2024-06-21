#include<bits/stdc++.h>
using namespace std;
class Sinhvien{
private:
	string masv, ht;
	float dtb;

public:
	void nhap(); 
	void xuat(); 
	float getDtb();

};

void Sinhvien::nhap(){
	cout<<"\n Nhap ma sv: "; 
	getline(cin, masv);
	cout<<"\n Nhap ho ten sv: ";
	getline(cin, ht);
	cout<<"\n Diem trung binh: ";
	cin>>dtb;
	cin.ignore();
}
void Sinhvien::xuat(){
	cout<<setw(10)<<masv
	<<setw(30)<<ht
	<<setw(5)<<dtb<<endl; 
}

float Sinhvien::getDtb(){
	return dtb;
}

int main(){ 
	Sinhvien sv[50];
	int i,n;
	cout<<"\n Nhap so sinh vien: ";
	cin>>n; cin.ignore();
	for (i = 0; i<n; i++)
		sv[i].nhap(); 

	cout<<"\nDanh sach sinh vien :\n";
	
	for (i=0; i<n ; i++)
		sv[i].xuat();
	
	float dtbmax = sv[0].getDtb();
	
	for (i=0; i<n ; i++){
		if(sv[i].getDtb() > dtbmax){
			dtbmax = sv[i].getDtb();
		}
	}
	cout << "SV co DTB max: \n";
	for (i=0; i<n ; i++){
		if(dtbmax == sv[i].getDtb()){
			sv[i].xuat();
		}
	}
	return 0;
}

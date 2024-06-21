#include<bits/stdc++.h>
using namespace std;
class Sinhvien{
private:
	string masv, ht;
	float dtb;

public:
	void nhap(); 
	void xuat(); 
	friend ostream& operator << (ostream&Out, Sinhvien);
	friend istream& operator >> (istream&In, Sinhvien&);
	int operator >= (Sinhvien s2);
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

ostream& operator << (ostream& out, Sinhvien a){
	out << setw(10) << a.masv
	<< setw(30) << a.ht
	<< setw(5) << a.dtb << endl; 
	return out;
}

istream& operator >> (istream& in, Sinhvien &a){
	cout<<"\n Nhap ma sv: "; 
	getline(in, a.masv);
	cout<<"\n Nhap ho ten sv: ";
	getline(in, a.ht);
	cout<<"\n Diem trung binh: ";
	in>>a.dtb;
	in.ignore();
	return in;
}

int Sinhvien::operator >= (Sinhvien s2){
	return (dtb >= s2.dtb);
}

class Quanly{
	private:
		Sinhvien sv[50];
		int n;
	public:
		void nhap_sv();
		void in_sv();
};

void Quanly::nhap_sv(){
	cout<<"\n Nhap so sinh vien: ";
	cin>>n;
	cin.ignore();
	for (int i = 0;i<n;i++){
		cout << "\n Thong tin SV thu " << i+1 << ": ";
		cin >> sv[i];
	}
}

void Quanly::in_sv(){
	cout << "\nDanh sach sinh vien sap xep tang dan theo DTB :\n";
    for(int i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (sv[i] >= sv[j]){
	            Sinhvien tmp = sv[i];
	            sv[i] = sv[j];
	            sv[j] = tmp;
        	}
		}
	}
	for (int i=0; i < n ; i++)
		cout << sv[i];
}


int main(){ 
	Quanly ob;
	ob.nhap_sv();
	ob.in_sv();
}


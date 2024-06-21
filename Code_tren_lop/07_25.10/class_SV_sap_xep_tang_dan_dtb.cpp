// 	Xoa cac SV co DTB <= 5, in ra danh sach sau khi xoa
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
//	int operator <= (Sinhvien s2);
	~Sinhvien(){}
	int getDTB(){
		return dtb;
	}
	
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
	cout << " Nhap ma sv: "; 
	getline(in, a.masv);
	cout << "\n Nhap ho ten sv: ";
	getline(in, a.ht);
	cout << "\n Diem trung binh: ";
	in >> a.dtb;
	in.ignore();
	return in;
}

int Sinhvien::operator >= (Sinhvien s2){
	return (dtb >= s2.dtb);
}

////Sx giam dan
//int Sinhvien::operator <= (Sinhvien s2){
//	return (dtb <= s2.dtb);
//}

int main(){ 
	Sinhvien sv[50];
	int i, n;
	cout << "\n Nhap so sinh vien: ";
	cin >> n; cin.ignore();
	for (i = 0; i<n; i++){
		cout << "\n SV thu " << i+1 << ":\n";
		cin >> sv[i]; 
	}
		
	cout<<"\nDanh sach sinh vien :\n";
	
	for (i=0; i<n ; i++)
		cout << sv[i];
	
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
	for (i=0; i<n ; i++)
		cout << sv[i];
	
	cout << "\nXoa cac sinh vien co DTB <= 5:\n";
	for (i=0; i<n ; i++){
		if(sv[i].getDTB() <= 5){
			delete sv[i];
		}
	}
	for (i=0; i<n ; i++)
		cout << sv[i];
	
	return 0;
}


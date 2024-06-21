#include<bits/stdc++.h>
using namespace std;

class SV{
	private:
		string msv, ht;
		float dtb;
	public:
		float getDTB(){
			return dtb;
		}
		
		void Nhap(){
			cout << "Nhap MSV: ";
			getline(cin, msv);
			cout << "Nhap ho ten: ";
			getline(cin, ht);
			cout << "Nhap dtb: ";
			cin >> dtb;
			cin.ignore();
		}
		
		void Xuat(){
			cout << setw(10) << msv
				<< setw(25) << ht
				<< setw(25) << dtb << endl;
		}
};

class Quanly{
	private:
		int n;
		SV sv[50];
	public:
		void nhap_sv();
		void in_sv();
};

void Quanly::nhap_sv(){
	cout << "\nNhap so SV: ";
	cin >> n;
	cin.ignore();
	for(int i = 0; i<n; i++){
		cout << "\nNhap thong tin SV thu " << i+1 <<":\n";
		sv[i].Nhap();
	}
}

void Quanly::in_sv(){
	float max = sv[0].getDTB();
	for(int i=1; i<n; i++){
		if(max < sv[i].getDTB())
			max = sv[i].getDTB();
	}
	
	cout << "\nDanh sach SV co dtb cao nhat: \n";
	cout << setw(10) << " MSV"
		<< setw(30) << " Ho va ten"
		<< setw(20) << "Diem trung binh\n"; 
	for(int i=0; i<n; i++)
		if(sv[i].getDTB() == max)
			sv[i].Xuat();	
	
}

int main(){
	Quanly ob;
	ob.nhap_sv();
	ob.in_sv();
	return 0;
	
}


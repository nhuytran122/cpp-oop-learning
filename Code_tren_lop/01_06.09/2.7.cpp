#include<bits/stdc++.h>
using namespace std;
struct SV{
    string MSV, ten, lop;
    float dtb;
};

void Nhap(SV *sv, int n){
    for (int i = 0; i<n; i++){
    	int j = i+1;    	
        cout << "\nSinh vien thu " << j <<": \n";
        cout<< "Ma sinh vien: ";
        getline(cin, sv[i].MSV);
        cout<< "Ten: ";
        getline(cin, sv[i].ten);
        cout<< "Lop: ";
        getline(cin, sv[i].lop);
        cout << "Diem trung binh: ";
        cin >> sv[i].dtb;
        cin.ignore();
    }
}

void Sapxep(SV *sv, int n){
    for(int i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (sv[i].dtb < sv[j].dtb){
            SV tmp = sv[i];
            sv[i] = sv[j];
            sv[j] = tmp;
        	}
		}
	}
}

void Xuat(SV *sv, int n){
    for (int i = 0; i<n; i++){
		
		cout << i << ". " << sv[i].MSV << setw(10) << sv[i].ten << setw(6)<< sv[i].lop << setw(6) << sv[i].dtb << endl;
	}
}

int main(){
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	cin.ignore();
	SV *sv = new SV[n];
	if (sv == NULL){
		cout << "\nLoi cap phat vung nho!";
		exit(1);
	}
	Nhap(sv, n);
	Sapxep(sv, n);
	cout << "\nDanh sach sau khi sap xep theo DTB: " << endl;
	Xuat(sv, n);
	delete sv;
}

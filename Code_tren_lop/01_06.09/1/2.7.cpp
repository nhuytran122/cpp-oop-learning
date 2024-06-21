#include<bits/stdc++.h>
using namespace std;
struct SV{
    string MSV, ten, lop;
    float dtb;
};

void Nhap(SV *sv, int n){
    for (int i=0;i<n;i++){ 
		cin.ignore(); 
        cout<<"Sinh vien thu "<<i+1<<": \n";
        cout<<"Ma sinh vien: ";
        getline(cin, sv[i].MSV);
        cout<<"Ten: ";
        getline(cin, sv[i].ten);
        cout<<"Lop: ";
        getline(cin, sv[i].lop);
        cout<<"Diem trung binh: ";
        cin>>sv[i].dtb;
    }
}

void Sapxep(SV *sv, int n){
    for(int i=0;i<n-1;i++)
	{
        for (int j=i+1;j<n;j++)
		{
            if (sv[i].dtb < sv[j].dtb)
			{
            SV tmp = sv[i];
            sv[i] = sv[j];
            sv[j] = tmp;
        	}
		}
	}
}

void Xuat(SV *sv, int n){
    for (int i=0;i<n;i++){
		cout<<sv[i].MSV<<setw(6)<<sv[i].ten<<setw(6)<<sv[i].lop<<setw(6)<<sv[i].dtb<<endl;
	}
}

int main(){
	int n;
	cout << "So sinh vien: ";
	cin >> n;
	SV *sv = new SV[n];
	if (sv == NULL){
		cout << "\nLoi cap phat vung nho";
		exit(1);
	}
	Nhap(sv, n);
	Sapxep(sv, n);
	cout << "Danh sach sau khi sap xep : " << endl;
	Xuat(sv, n);
	delete sv;
}

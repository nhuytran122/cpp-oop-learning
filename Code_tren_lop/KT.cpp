#include<bits/stdc++.h>
using namespace std;

class Computer{
	private:
		string ma, hsx;
		int nam;
		float gia;
	public:
		string getMa(){
			return ma;
		}
		string getHang(){
			return hsx;
		}
		int getNam(){
			return nam;
		}
		float getGia(){
			return gia;
		};
		void NhapC(){
			cout << "\nNhap ma may tinh: "; getline(cin, ma);
			cout << "Nhap hang san xuat: "; getline(cin, hsx);
			cout << "Nhap nam san xuat: "; cin >> nam;
			cout << "Nhap gia ban: "; cin >> gia;
		}
		void XuatC(){
			cout << ma
				<< setw(10) << hsx
				<< setw(20) << nam
				<< setw(20) << gia;
		}
};

class Laptop : public Computer{
	private:
		float cn, day, s;
		string hdh;
	public:
		float getCn(){
			return cn;
		}
		float getDay(){
			return day;
		}
		float getS(){
			return s;
		}
		string getHdh(){
			return hdh;
		}
		
		float getGtcl(){
			float gtcl;
			int namsd = 2022 - this->getNam();
			if(getHdh() == "Windows"){
				gtcl = this->getGia() - namsd * 0.1 * namsd*getGia();
			}
			else{
				gtcl = this->getGia() - namsd * 0.05 * this->getGia();
			}
			return gtcl;
		}
		
		void nhap(){
			NhapC();
			cout << "Nhap can nang (g): "; cin >> cn;
			cout << "Nhap do day (mm): "; cin >> day;
			cout << "Nhap kich thuoc man hinh: "; cin >> s; cin.ignore();
			cout << "Nhap he dieu hanh: "; getline(cin, hdh);
		}
		void xuat(){
			XuatC();
			cout << setw(22) << cn
				<< setw(20) << day
				<< setw(20) << s
				<< setw(20) << 2022 - this->getNam()
				<< setw(20) << getGtcl() << endl;
		}
		bool operator > (Laptop ob){
			if (getGtcl() > ob.getGtcl()) return true;
			return false;
		}
};

int main(){
	Laptop a[50];
	int n;
	cout << "\n\tNhap so luong may tinh xach tay: "; cin >> n; cin.ignore();
	for(int i = 0; i<n; i++){
		a[i].nhap();
	}
	
	for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                Laptop tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;        
            }
        }
    }
    
    cout << "\nDanh sach Laptop sap xep theo tieu chi tang dan theo gia tri con lai: \n";
    cout << "Ma MT"
		<< setw(10) << "Hang SX"
		<< setw(22) << "Nam SX"
		<< setw(20) << "Gia ban"
		<< setw(20) << "Can nang"
		<< setw(20) << "Do day" 
		<< setw(20) << "Kich thuoc"
		<< setw(20) << "So nam su dung"
		<< setw(20) << "Gia tri con lai" << endl;
    for(int i = 0; i<n; i++){
    	a[i].xuat();
	}
	
	int nMax = 2022 - a[0].getNam();
	for (int i = 0; i<n ; i++){
		int y = 2022 - a[i].getNam();
		if(y > nMax){
			nMax = y;
		}
	}
	
	cout << "\nDanh sach laptop co so nam su dung nhieu nhat: \n";
    cout << "Ma MT"
		<< setw(10) << "Hang SX"
		<< setw(22) << "Nam SX"
		<< setw(20) << "Gia ban"
		<< setw(20) << "Can nang"
		<< setw(20) << "Do day" 
		<< setw(20) << "Kich thuoc"
		<< setw(20) << "So nam su dung"
		<< setw(20) << "Gia tri con lai" << endl;
		
	int cnt = 0;
	for (int i=0; i<n; i++){
		int y = 2022 - a[i].getNam();
		if(nMax == y){
			a[i].xuat();
			cnt++;
		}
	}
	cout << "\nCo " << cnt << " laptop co so nam su dung nhieu nhat";
	
}



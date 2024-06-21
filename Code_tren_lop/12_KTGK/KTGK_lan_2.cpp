#include<bits/stdc++.h>
using namespace std;

class Computer{
	private:
		string mamt, hangsx;
		int namsx;
		float giaban;
	public:
		string getMa();
		string getHang();
		int getNam();
		float getGia();
		void Nhap();
		void Xuat();
};

string Computer::getMa(){
	return mamt;
}

string Computer::getHang(){
	return hangsx;
}

int Computer::getNam(){
	return namsx;
}

float Computer::getGia(){
	return giaban;
}

void Computer::Nhap(){
	cout << "\nNhap ma may tinh: "; getline(cin, mamt);
	cout << "Nhap hang san xuat: "; getline(cin, hangsx);
	cout << "Nhap nam san xuat: "; cin >> namsx;
	cout << "Nhap gia ban: "; cin >> giaban;
}

void Computer::Xuat(){
	cout << mamt
		<< setw(10) << hangsx
		<< setw(20) << namsx
		<< setw(20) << giaban;
}

class Laptop:public Computer{
	private:
		float weight, thickness, size;
		string Os;
	public:
		float getW();
		float getT();
		float getS();
		string getOs();
		
		float getGTCL(){
			float re_val = 0;
			if(getOs() == "Windows"){
				re_val = abs(getGia() - getY_used()*0.1*getGia());
			}
			else{
				re_val = abs(getGia() - getY_used()*0.05*getGia());
			}
			
			/* bo abs ben tren
			if (re_val < 0){
				re_val = 0;}*/
			return re_val;
		}
		
		int getY_used(){
			return 2022 - getNam();
		}
		void nhap();
		void xuat();
		bool operator > (Laptop ob2);
};

float Laptop::getW(){return weight;}
float Laptop::getT(){return thickness;}
float Laptop::getS(){	return size;}
string Laptop::getOs(){	return Os;}

void Laptop::nhap(){
	Computer::Nhap();
	cout << "Nhap can nang (g): "; cin >> weight;
	cout << "Nhap do day (mm): "; cin >> thickness;
	cout << "Nhap kich thuoc man hinh: "; cin >> size;
	cin.ignore();
	cout << "Nhap he dieu hanh: "; getline(cin, Os);
}

void Laptop::xuat(){
	Computer::Xuat();
	cout << setw(20) << weight
		<< setw(20) << thickness
		<< setw(20) << size
		<< setw(20) << getY_used()
		<< setw(20) << getGTCL() << endl;
		
}

bool Laptop::operator > (Laptop ob2){
	return getGTCL() > ob2.getGTCL();
}

int main(){
	Laptop ob[50];
	int i, n;
	cout << "\n\tNhap so luong may tinh xach tay: "; cin >> n; cin.ignore();
	for(i = 0; i<n; i++){
		ob[i].nhap();
	}
	
	// Sap xep
	for(i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ob[i] > ob[j]){
                Laptop tmp = ob[i];
                ob[i] = ob[j];
                ob[j] = tmp;        
            }
        }
    }
    
    cout << "\n\tDanh sach Laptop sap xep tang dan theo gia tri con lai: \n";
    cout << "Ma MT"
		<< setw(10) << "Hang SX"
		<< setw(20) << "Nam SX"
		<< setw(20) << "Gia ban"
		<< setw(20) << "Can nang"
		<< setw(20) << "Do day" 
		<< setw(20) << "Kich thuoc"
		<< setw(20) << "So nam su dung"
		<< setw(20) << "Gia tri con lai" << endl;
    for(i = 0; i<n; i++){
    	ob[i].xuat();
	}
	
	//Lay max
	
	int yMax = ob[0].getY_used();
	for (i=0; i<n ; i++){
		if(ob[i].getY_used() > yMax){
			yMax = ob[i].getY_used();
		}
	}
	
	int cnt = 0;
	for(i = 0; i<n; i++){
		if(ob[i].getY_used() == yMax){
			cnt++;
		}
	}
	
	cout << "\n\tCo " << cnt << " laptop co so nam su dung nhieu nhat";
	cout << "\nDanh sach do la: \n";
    cout << "Ma MT"
		<< setw(10) << "Hang SX"
		<< setw(20) << "Nam SX"
		<< setw(20) << "Gia ban"
		<< setw(20) << "Can nang"
		<< setw(20) << "Do day" 
		<< setw(20) << "Kich thuoc"
		<< setw(20) << "So nam su dung"
		<< setw(20) << "Gia tri con lai" << endl;
	for (i=0; i<n; i++){
		if(yMax == ob[i].getY_used()){
			ob[i].xuat();
		}
	}
	
}



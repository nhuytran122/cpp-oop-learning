/*int nhuan();
int ngaythang();
Date cong1ngay();
Date congkngay(int k);
*/
#include<bits/stdc++.h>
using namespace std;

class Date{
	private:
		int dd, mm, yy;
	public:
		void Nhap();
		void Xuat();
		void Tang1Ngay();
		void TangkNgay(int k);
		int Kc2Ngay(Date);
};

int KTra(int dd, int mm, int yy){
	if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
		if(dd <= 0 || dd >= 32){
			return -1;
		}
	}
	else if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
		if(dd <= 0 || dd >= 31){
			return -1;
		}
	}
	else if(mm == 2){
		if((yy % 400 == 0) || (yy % 4 == 0) && (yy % 100 != 0)){
			if(dd <= 0 || dd > 29){
				return -1;
			}
		}
		else{
			if(dd <= 0 || dd > 28){
				return -1;
			}
		}
	}
	else{
		return -1;
	}
}

void Date::Nhap(){
	do{
		cout << "\tNhap ngay: "; cin >> dd;
		cout << "\tNhap thang: "; cin >> mm;
		cout << "\tNhap nam: "; cin >> yy;
		if(KTra(dd, mm, yy) == -1) cout << "\tDu lieu khong hop le!\n";
	}while (KTra(dd, mm, yy) == -1); 
	
}

void Date::Xuat(){
	cout <<"\t===>  " << dd << "/" << mm << "/" << yy << endl;
}

int DayMax (int mm, int yy){
	switch(mm){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
		break;
		
		case 4: case 6: case 9: case 11:
		return 30;
		break;
		
		case 2:
			return((yy % 400 == 0 || yy % 4 == 0 && yy % 100 != 0))?29:28;
		default:
			return -1;
        }
}

int KTLoaiNgay(int dd, int mm, int yy){
	int nct = DayMax(mm, yy);
	if(dd == nct){
		//31/12/20xx
		if(mm == 12){
			return 3;
		}else{	
			//Cuoi thang	
			return 2;
		}
	}else{
	// Giua nam, thang
		return 1;
	}
}

void Date::Tang1Ngay(){
	int ktNgay = KTLoaiNgay(dd, mm, yy);
	if(ktNgay == 3){
		dd = 1;
		mm = 1;
		yy++;
	}
	else if(ktNgay == 2){
		dd = 1;
		mm++;
	}
	else if(ktNgay == 1){
		dd++;
	}
}

void Date::TangkNgay(int k){
	int ktloaiNgay = KTLoaiNgay(dd, mm, yy);
	int dMax = DayMax(mm, yy);
	if(ktloaiNgay == 3){
		yy++;
		dd = k;
		mm = 1;
	}
	//Cuoi thang
	else if(ktloaiNgay == 2){
		mm++;
		dd = k;
	}
	//Khong phai cuoi thang
	else if(ktloaiNgay == 1){
		int ddk = dd + k;
				
		// Giua nam, gan cuoi thang
		if(ddk >  dMax && mm != 12){
			dd = ddk - dMax;
			mm++;
		}
		//VD: 25/8/2022 + 6days = 31 = dMax(t8)
		else if(ddk == dMax && mm != 12){
			dd = 1;
			mm++;
		}	
		// Gan cuoi nam
		else if(ddk >  dMax && mm == 12){
			dd = ddk - dMax;
			mm = 1;
			yy++;
		}
		//VD: 25/12/2022 + 6days = 31 = dMax(t12)
		else if(ddk == dMax && mm == 12){
			dd = 1;
			mm = 1;
			yy++;
		}
				
		// Giua nam, khong gan cuoi thang
		else if(ddk <  dMax){
			dd = ddk;
		}
	}
}

int Date::Kc2Ngay(Date d2){
	int s = 0;
	int d = d2.dd, m = d2.mm, y = d2.yy, dMax;
	while(yy >= y){
		if(yy == y && mm == m){
			s += dd - d;
			break;
		}
		else{
			dMax = DayMax(m, y);
			if(dMax == 30){
				s += 30 - d;
			}
			else if(dMax == 31){
				s += 31 - d;
			}
			else if(dMax == 29){
				s += 29 - d;
			}
			else if(dMax == 28) s += 28 - d;
				
			}
		m++; d = 0;
		if(m == 13){
			y++;
			m = 1;
		}
	}		
	return s;
}

int main(){
	Date d, d1, d2;
	int lc, lc1, k, day1, day2;
	d.Nhap();
	d.Xuat();
	while(1){
		cout << "\n\t\t1. Nhap 1 de nhap doi tuong ngay.\n";
		cout << "\t\t2. Nhap 2 de tang doi tuong ngay len 1 ngay.\n";
		cout << "\t\t3. Nhap 3 de tang doi tuong ngay len k ngay.\n";
		cout << "\t\t4. Nhap 4 de tinh khoang cach giua 2 doi tuong ngay.\n";
		cout << "\t\t5. Nhap 0 de ket thuc.\n";
		
		cout << "\n\t\t\tNhap lua chon: "; cin >> lc;
		if(lc == 1){
			d.Nhap();
			d.Xuat();
		}
		else if(lc == 2){
			d.Tang1Ngay();
			d.Xuat();
		}
		else if(lc == 3){
			cout << "\tNhap k: "; cin >> k;
			d.TangkNgay(k);
			d.Xuat();
		}
		else if(lc == 4){
				cout << "\t\tNhap 5 neu ban muon nhap doi tuong thu nhat > doi tuong thu 2\n";
				cout << "\t\tNhap 6 neu ban muon nhap doi tuong thu nhat < doi tuong thu 2\n";
				cout << "\t\tLua chon: ";cin >> lc1;
				if (lc1 == 5){
					cout << "\n\tNhap doi tuong ngay thu nhat: \n"; d1.Nhap();
					cout << "\tNhap doi tuong ngay thu hai: \n"; d2.Nhap();
					cout << "\tKet qua: " << d1.Kc2Ngay(d2) << " ngay\n";
				}
				else if(lc1 == 6){
					cout << "\tNhap doi tuong ngay thu nhat: \n"; d1.Nhap();
					cout << "\tNhap doi tuong ngay thu hai: \n"; d2.Nhap();
					cout << "\tKet qua: " << d2.Kc2Ngay(d1) << " ngay\n";
				}			
		}
		else if(lc == 0) break;
	}	
}



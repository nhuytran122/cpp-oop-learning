#include<bits/stdc++.h>
using namespace std;
class ChuyenXe{
	protected:
		string ma, taixe, soxe;
		long long doanhthu;
		
	public:
		void Nhap();
		void Xuat();
		long long getDoanhThu(){
			return doanhthu;
		}
};

void ChuyenXe::Nhap(){
	cout << "\tNhap ma so chuyen: "; getline(cin, ma);
	cout << "\tNhap ho ten tai xe: "; getline(cin, taixe);
	cout << "\tNhap so xe: "; getline(cin, soxe);
	cout << "\tNhap doanh thu: "; cin >> doanhthu;
	cin.ignore();
}

void ChuyenXe::Xuat(){
	cout << "\tMa so chuyen: " << ma << endl;
	cout << "\tTen tai xe: " << taixe << endl;
	cout << "\tSo xe: " << soxe << endl;
	cout << "\tDoanh thu: " << doanhthu << endl;
}

class NgoaiThanh : public ChuyenXe{
	private:
		string noiden;
		int songay;
	public:
		void Nhap(){
			ChuyenXe::Nhap();
			cout << "\tNhap noi den: "; getline(cin, noiden);
			cout << "\tNhap so ngay di duoc: "; cin >> songay;
			cin.ignore();
		}
		
		void Xuat(){
			ChuyenXe::Xuat();
			cout << "\tNoi den: " << noiden << endl;
			cout << "\tSo ngay di duoc: " << songay << endl;
		}
};

class NoiThanh : public ChuyenXe{
	private: 
		int sotuyen, km;
	public:
		void Nhap(){
			ChuyenXe::Nhap();
			cout << "\tNhap so tuyen: "; cin >> sotuyen;
			cout << "\tNhap so km di duoc: "; cin >> km;
			cin.ignore();
		}
		void Xuat(){
			ChuyenXe::Xuat();
			cout << "\tSo tuyen: " << sotuyen << endl;
			cout << "\tSo km di duoc: " << km << endl;
		}
};

int main(){
	NgoaiThanh a[50];
	NoiThanh b[50];
	int n, m;
	cout << "\tNhap so chuyen xe ngoai thanh: "; cin >> n;
	cout << "\tNhap so chuyen xe noi thanh: "; cin >> m;
	cin.ignore();
	cout << "\n\t\t\tNGOAI THANH:";
	for(int i=0; i<n; i++){
		cout << "\n\tCHUYEN THU " << i+1 << ": " << endl;
		a[i].Nhap();
	}
	
	cout << "\n\t\t\tNOI THANH:";
	for(int i=0; i<m; i++){
		cout << "\n\tCHUYEN THU " << i+1 << ": " << endl;
		b[i].Nhap();
	}
	
	cout << "\n\t\t\tDANH SACH CAC CHUYEN XE NGOAI THANH:";
	for(int i=0; i<n; i++){
		cout << "\n\t\tCHUYEN THU " << i+1 << ": " << endl;
		a[i].Xuat();
	}
	
	cout << "\n\t\t\tDANH SACH CAC CHUYEN XE NOI THANH:";
	for(int i=0; i<m; i++){
		cout << "\n\t\tCHUYEN THU " << i+1 << ": " << endl;
		b[i].Xuat();
	}
	
	long long s1 = 0, s2 = 0;
	
	for(int i=0; i<n; i++){
		s1 += a[i].getDoanhThu();
	}
	
	for(int i=0; i<m; i++){
		s2 += b[i].getDoanhThu();
	}
	
	cout << "\t\t\tTONG DOANH THU CUA CAC CHUYEN XE NGOAI THANH: " << s1 << endl;
	cout << "\t\t\tTONG DOANH THU CUA CAC CHUYEN XE NOI THANH: " << s2 << endl;
	
}

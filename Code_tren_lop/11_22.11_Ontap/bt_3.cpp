#include<bits/stdc++.h>
using namespace std;
class Date {
	private:
	int d, m, y;
	public:
		Date() {};
		Date(int d, int m, int y){
			this -> d = d;
			this -> m = m;
			this -> y = y;
		}
		
		void nhap_date(){
			cout << "\nNhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
			cin.ignore();
		}
		
		void xuat_date(){
			cout << d << "/" << m << "/" << y;
		}
		bool operator > (Date ob);
};

bool Date::operator > (Date ob){
	if (y > ob.y) return true;
	if (y == ob.y and m > ob.m) return true;
	if (y == ob.y and m == ob.m and d > ob.d) return true;
	return false;
}

class Person{
	private:
		string ho, ten;
		Date ngaysinh;
	public:
		Person() {};
		Person(string h, string t, Date ns){
			ho = h;
			ten = t;
			ngaysinh = ns;
		}
		
		void Nhap(){
			cout << "\nNhap ho: "; getline(cin, ho);
			cout << "Nhap ten: "; getline(cin, ten);
			cout << "Nhap ngay sinh: "; ngaysinh.nhap_date();
		}
		
		void Xuat(){
			cout << "\n\nHo: " << ho;
			cout << "\nTen: " << ten;
			cout << "\nNgay sinh: "; ngaysinh.xuat_date();
		}
		
		void set_ho(string h) { ho = h; }
		string get_ho() { return ho; }
		void set_ten(string t) { ten = t; }
		string get_ten() { return ten; }
		void set_ngaysinh(Date ns) { ngaysinh = ns; }
		Date get_ngaysinh() { return ngaysinh; }
};

class Student : public Person {
	private:
		string ma_sv, sdt;
		float dtb;
	public:
		Student() {};
		Student(string h, string t, Date ns, string ma, string dt, float tb) : Person {h, t, ns}{
			ma_sv = ma;
			sdt = dt;
			dtb = tb;
		}
		
		void nhap(){
			Nhap();
			cout << "Nhap MSV: "; getline(cin, ma_sv);
			cout << "Nhap SDT: "; getline(cin, sdt);
			cout << "Nhap DTB: "; cin >> dtb;
			cin.ignore();
		}
		
		void xuat(){
			Xuat();
			cout << "\nMSV: " << ma_sv;
			cout << "\nSDT: " << sdt;
			cout << "\nDTB: " << dtb;
		}
		void set_masv(string ms) { ma_sv = ms; }
		string get_masv() const { return ma_sv; }
		void set_sdt(string _phone) { this -> sdt = _phone; }
		string get_sdt() const { return sdt; }
		void set_dtb(float tb) { this -> dtb = tb; }
		float gettb() { return dtb; }
		bool operator > (Student ob);
		bool operator >= (Student ob);
		bool operator < (Student ob);
		void set_Student();
		void print_Student();
};

bool Student::operator > (Student ob) {
	return (get_ngaysinh() > ob.get_ngaysinh());
}

bool Student::operator >= (Student ob) {
	return (this -> gettb() >= ob.gettb());
}

bool Student::operator < (Student ob) {
	if (this -> get_ten() < ob.get_ten()) return true;
	else if (this -> get_ten() == ob.get_ten()) {
		if (this -> get_ho() < ob.get_ho())
			return true;
		return false;
	}
	return false;
}

int main(){
	Student sv[100], tmp;
	int n, i;
	cout << "\nNhap so luong SV: "; cin >> n; cin.ignore();
	for(i = 0; i<n; i++){
		sv[i].nhap();
	}
	
	cout << "\n\n\t\tDANH SACH SV THEO THU TU TANG DAN THEO TEN VA HO DEM:\n \n";
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(sv[i] < sv[j]){
                tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;        
            }
        }
    }

	for (i=0; i<n; i++){
		sv[i].xuat();
	}
	
	// ------------------------------------------------------------------------------------
	cout << "\n\n\t\tDANH SACH SV THEO THU TU GIAM DAN CUA DIEM TRUNG BINH:\n\n";
	for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(sv[i] >= sv[j]){
                tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;        
            }
        }
    }
    
    for (i=0; i<n; i++){
		sv[i].xuat();
	}
	
	//--------------------------------------------------------------------------
    cout << "\n\n\t\tVI THU CUA CAC SV THEO DTB:\n\n";
	for (i=0; i<n; i++){
		cout << i+1
			<< setw(20) << sv[i].get_masv()
			<< setw(10) << sv[i].get_ho()
			<< setw(20) << sv[i].get_ten()
			<< setw(20) << sv[i].gettb() << endl;
	}
	
	//-------------------------------------------------------------------------------------
//	cout << "\n\n\t\tDANH SACH SV SINH SAU NGAY 20/5/2000:\n\n";
//	for (i=0; i<n; i++){
//		if(cmp3(sv[i], "20/05/2000"))
//			sv[i].Xuat();
//	}
    
	
	//-------------------------------------------------------------------------
	float dtbMax = sv[0].gettb();
	
	for(i=0; i<n ; i++){
		if(sv[i].gettb() >= dtbMax){
			dtbMax = sv[i].gettb();
		}
	}
	cout << "\n\n\t\tSV co DTB max: \n\n";
	cout << "MSV"
		<< setw(10) << "HO DEM"
		<< setw(20) << "TEN"
		<< setw(20) << "NGAY SINH"
		<< setw(20) << "SDT"
		<< setw(20) << "DTB" << endl;
	for(i=0; i<n ; i++){
		if(dtbMax == sv[i].gettb()){
			sv[i].xuat();
		}
	}
	
	//-------------------------------------------------------------------------
	string id;
    bool ch = false;
    cout << "\n\n\t\tTIM KIEM THEO MA SINH VIEN: \n";
    cout << "\nNhap MSV muon tim: "; getline(cin, id);
    for(i=0; i<n; i++){
        if(sv[i].get_masv() == id){
            ch = true;
            sv[i].xuat();
        }
    }
    if(ch == false) cout << "\nKhong tim thay SV co MSV " << id;
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Sinhvien{
	private:
		string msv, hodem, ten, ns, sdt;
		float dtb;
	public:
		Sinhvien(){
			msv = hodem = ten = ns = sdt = "";
			dtb = 0.0;
		}
		Sinhvien(string ma, string ho, string Ten, string Ns, string Sdt, float diem){
			msv = ma;
			hodem = ho;
			ten = Ten;
			ns = Ns;
			sdt = Sdt;
			dtb = diem;
		}
		
		void Nhap(){
			cout << "\n\nNhap MSV: "; getline(cin, msv);
			cout << "Nhap ho dem: "; getline(cin, hodem);
			cout << "Nhap ten: "; getline(cin, ten);
			cout << "Nhap ngay sinh (dd/mm/yy): "; getline(cin, ns);
			cout << "Nhap SDT: "; getline(cin, sdt);
			cout << "Nhap DTB: "; cin >> dtb;
			cin.ignore();
		}
		
		void Xuat(){
			cout << msv
				<< setw(10) << hodem
				<< setw(20) << ten
				<< setw(20) << ns
				<< setw(20) << sdt
				<< setw(20) << dtb << endl;
		}
		
		string getTen(){
			return ten;
		}
		
		string getHo(){
			return hodem;
		}
		
		string getMsv(){
			return msv;
		}
		
		float getDtb(){
			return dtb;
		}
		
		string getNs(){
			return ns;
		}
	
	    bool operator >= (Sinhvien b){
	    	return dtb >= b.dtb;
		}
		
		bool operator < (Sinhvien b){
			if(ten != b.ten) return ten < b.ten;
			return hodem < b.hodem;
		}
		
	    bool operator > (Sinhvien b){
	        string s1 = ns, s2 = b.ns;
			int t1 = (s1[0] - '0') * 10 + s1[1] - '0', ng1 = (s1[3] - '0') * 10 + s1[4] - '0', n1 = stoi(s1.substr(6));
			int t2 = (s2[0] - '0') * 10 + s2[1] - '0', ng2 = (s2[3] - '0') * 10 + s2[4] - '0', n2 = stoi(s2.substr(6));
	        if(n1 != n2) return n1 > n2;
			if(t1 != n2) return t1 > t2;
			return ng1 > ng2;
	    }
};

// bool cmp (Sinhvien a, Sinhvien b){
// 	if(a.getTen() != b.getTen()) return a.getTen() < b.getTen();
// 	return a.getHo() < b.getHo();
// }

// bool cmp2 (Sinhvien a, Sinhvien b){
//     return a.getDtb() >= b.getDtb();
// }

// bool cmp3 (Sinhvien a, string ns2){
// 	string s1 = a.getNs(), s2 = ns2;
// 	int t1 = (s1[0] - '0') * 10 + s1[1] - '0', ng1 = (s1[3] - '0') * 10 + s1[4] - '0', n1 = stoi(s1.substr(6));
// 	int t2 = (s2[0] - '0') * 10 + s2[1] - '0', ng2 = (s2[3] - '0') * 10 + s2[4] - '0', n2 = stoi(s2.substr(6));
//     if(n1 != n2) return n1 > n2;
// 	if(t1 != n2) return t1 > t2;
// 	return ng1 > ng2;
// }

int main(){
	Sinhvien sv[100], tmp;
	int n, i;
	cout << "\nNhap so luong SV: "; cin >> n; cin.ignore();
	for(i = 0; i<n; i++){
		sv[i].Nhap();
	}
	
	cout << "\n\n\t\tDANH SACH SV THEO THU TU TANG DAN THEO TEN VA HO DEM:\n \n";
//    for(int i = 0; i < n - 1; i++){
//        for(int j = i + 1; j < n; j++){
//            if(sv[i] < sv[j]){
//                tmp = sv[i];
//                sv[i] = sv[j];
//                sv[j] = tmp;        
//            }
//        }
//    }
	sort(sv, sv+n, cmp);
	cout << "MSV"
		<< setw(10) << "HO DEM"
		<< setw(20) << "TEN"
		<< setw(20) << "NGAY SINH"
		<< setw(20) << "SDT"
		<< setw(20) << "DTB" << endl;
	for (i=0; i<n; i++){
		sv[i].Xuat();
	}
	
	// ------------------------------------------------------------------------------------
	cout << "\n\n\t\tDANH SACH SV THEO THU TU GIAM DAN CUA DIEM TRUNG BINH:\n\n";
	sort(sv, sv+n, cmp2);
	cout << "MSV"
		<< setw(10) << "HO DEM"
		<< setw(20) << "TEN"
		<< setw(20) << "NGAY SINH"
		<< setw(20) << "SDT"
		<< setw(20) << "DTB" << endl;
	for (i=0; i<n; i++){
		sv[i].Xuat();
	}
	
	//--------------------------------------------------------------------------
    cout << "\n\n\t\tVI THU CUA CAC SV THEO DTB:\n\n";
    cout << "VI THU"
		<< setw(15) << "MSV"
		<< setw(10) << "HO DEM"
		<< setw(20) << "TEN"
		<< setw(20) << "DTB" << endl;
	for (i=0; i<n; i++){
		cout << i+1
			<< setw(20) << sv[i].getMsv()
			<< setw(10) << sv[i].getHo()
			<< setw(20) << sv[i].getTen()
			<< setw(20) << sv[i].getDtb() << endl;
	}
	
	//-------------------------------------------------------------------------------------
	cout << "\n\n\t\tDANH SACH SV SINH SAU NGAY 20/5/2000:\n\n";
	cout << "MSV"
		<< setw(10) << "HO DEM"
		<< setw(20) << "TEN"
		<< setw(20) << "NGAY SINH"
		<< setw(20) << "SDT"
		<< setw(20) << "DTB" << endl;
	for (i=0; i<n; i++){
		if(cmp3(sv[i], "20/05/2000"))
			sv[i].Xuat();
	}
    
	
	//-------------------------------------------------------------------------
	float dtbMax = sv[0].getDtb();
	
	for(i=0; i<n ; i++){
		if(sv[i].getDtb() >= dtbMax){
			dtbMax = sv[i].getDtb();
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
		if(dtbMax == sv[i].getDtb()){
			sv[i].Xuat();
		}
	}
	
	//-------------------------------------------------------------------------
	string id;
    bool ch = false;
    cout << "\n\n\t\tTIM KIEM THEO MA SINH VIEN: \n";
    cout << "\nNhap MSV muon tim: "; getline(cin, id);
    for(i=0; i<n; i++){
        if(sv[i].getMsv() == id){
            ch = true;
            sv[i].Xuat();
        }
    }
    if(ch == false) cout << "\nKhong tim thay SV co MSV " << id;
    
    return 0;
    
}

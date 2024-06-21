// > : giam dan
// < tang dan
// PHAN BIET CACH DUNG HAM CUA CLASS VA HAM FRIEND CUA CLASS TRONG HAM MAIN:
/*-- HAM CUA CLASS: ten_bien.ten_ham();
  -- HAM FRIEND CUA CLASS: ten_ham(ten bien);

//01. Ham khoi tao khong co gia tri tham so
//02. Khai bao 1 object (khong truyen gtri tham so)
//03. Gom cac objects thanh 1 mang de lam viec
//04. Nap chong toan tu (nhap/ xuat object voi cin/ cout)
//05. Chuan hoa ngay sinh theo dang dd/mm/yy
//6. Tao bien static de tang tu dong cac loai bien dem
/*-> Khai bao int ten class::dem = 0; ben ngoai
  ->Khai bao static int dem; o public
  -> O ham nhap du lieu, them: dem++ vao <bien dem o day la bien dem de tang tu dong theo stt)*/ 
//7. Ham friend nhap, in cua class (neu can): khong phai ham cua class hien tai, nhung co the truy cap cac thuoc tinh private cua class
/* -> Khai bao o class hien tai o vung public theo dang: kieu tra ve (hoac void) ten_ham (<&>ten class hien tai)
   -> Khi tao ham: ten_ham (ten_class tham_so_truyen <tam thoi>){
        + De goi den thuoc tinh cua class: tham_so_truyen.ten thuoc tinh
   }
   -> O ham main: 
   + Khai bao doi tuong: Ten_class ten_bien;
   + Ten_ham_friend (bien); 
!!! Doi voi ham cua class thi chi can goi ten thuoc tinh
*/
//7.2 Ham nhap, in cua class
//8. Getter: de lay thuoc tinh private cua class
// a. Ham getter nam ben trong class o dang public va khong can truyen tham so khi khai bao
// b. Ham setter nam ben trong class o dang public va can phai truyen kieu data khi 
//khai bao, cung nhu khi tao ham cung can phai truyen gia tri tham so de set
//9. Sap xep
// a. C1
// b. C2
//10. Liet ke theo yeu cau dau vao duoc nhap tu ban phim
//11. Ham lay ten
//12. Ham lay tu viet tac: vd : Cong nghe thong tin -> CNTT
//13. Sap xep theo ten
//14. Chuan hoa ma theo dang: SV06
#include<bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string ma, ten, lop, ns;
        float gpa;
    public:
    	//01.
        SinhVien();

        //6
        static int cnt;

        //04.
        friend istream& operator >> (istream &in, SinhVien& a){
            //6.
			cnt++;
            //14. De chuan theo dang SV06
            string s = to_string(cnt);
            if(s.size() < 2) s = "0" + s;
            a.ma = "SV" + s;
			in.ignore();
		    getline(in, a.ten);
			in >> a.lop >> a.ns >> a.gpa;
			return in;	
		}
        friend ostream& operator << (ostream &out, SinhVien a);

        //7.
        friend void nhap (SinhVien&);
        friend void in (SinhVien);
        
        //7.2.
        void nhap();
        void xuat();

        //8. ; dung trong 9 (C1)
        string getlop(){
            return this->lop;
        }
        
        string getTen(){
            return this->ten;
        }

        //9.
        /*b: bool operator < (SinhVien another){
        	return this->lop < another.lop;
		}*/
        
};

//1.
SinhVien::SinhVien(){
	ma = ten = lop = ns = "";
	gpa = 0;
}

//6.
int SinhVien::cnt = 0;

//04.
ostream& operator << (ostream &out, SinhVien a){
    //05. 12/02/2003
    //   0123456789
    if (a.ns[2] != '/') a.ns = "0" + a.ns;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ns[5] != '/') a.ns.insert(3, "0");
	cout << a.ma << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed <<setprecision(2) << a.gpa << endl;
	return out;
}

//7. Ham friend nhap, in cua class (neu can)
/*-> Khi tao ham: void<kieu tra ve> ten_ham (ten_class tham_so_truyen <tam thoi de dung trong ham>){
        + De goi den thuoc tinh cua ham: tham_so_truyen.ten thuoc tinh*/
void nhap(SinhVien &a){
    //Neu can cho mac dinh:
	//a.ma = "21T1020105";
	getline(cin, a.ten);

//05. (ham nay y het ham tren, day chi la bo sung theo y cua ham friend)
	cin >> a.lop >> a.ns >> a.gpa;
	if (a.ns[2] != '/') a.ns = "0" + a.ns;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ns[5] != '/') a.ns.insert(3, "0");
}

void in(SinhVien a){
	cout << a.ma << " " << a.ten << " " <<  a.lop << " " <<  a.ns << " " << fixed << setprecision(2) << " "   << a.gpa << endl;
}

//7.2. Ham nhap, in cua class
void SinhVien::nhap(){
    getline(cin, ten);
	cin >> lop >> ns >> gpa;
}

void SinhVien::xuat(){
    cout << ma << " " << ten << " " <<  lop << " " <<  ns << " " << fixed << setprecision(2) << " "   << gpa << endl;
}

//9. a(C1)
//9.1 Sap xep tang dan theo lop
bool cmpLop(SinhVien a, SinhVien b){
    return a.getlop() < b.getlop();
}

//9.2 Sap xep giam dan theo lop
bool cmp2(SinhVien a, SinhVien b){
    return a.getlop() > b.getlop();
}

//12. (trong ham in, truyen chuan(thu muon viet tat))
string chuan(string bm){
	string res = "";
	stringstream ss(bm);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}
//11.
string getname(string name){
	string res, token;
	stringstream ss(name);
	while(ss >> token){
		//lay token cuoi cung
		res = token;
	}
	return res;
}

//13. Sap xep theo ten (ten da duoc tach o 11.)
bool cmpTen(SinhVien a, SinhVien b){
	if(getname(a.getTen()) != getname(b.getTen()))
		return getname(a.getTen()) < getname(b.getTen());
	return a.getTen() < b.getTen();
}

int main(){
	//02. Khai bao 1 object khong truyen gia tri tham so
	SinhVien a;

    //7. Ham friend nhap, in cua class (neu can)
    nhap(a);
    in(a);
    
    //7.2 Ham nhap, in cua class
    /*int n; cin >> n;
    SinhVien c[n];
    for(int i = 0; i < n; i++){
        c[i].nhap();
    }

    for(SinhVien x : c){
        c.xuat();
    }*/
    

    //03.
    int N; cin >> N;
    SinhVien b[N];
    
    //04.
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }

    for(int i = 0; i < N; i++){
        cout << b[i];
    }

    //9. a(C1)
    sort(b, b+N, cmpLop);
    //9.
    /*b: sort(b, b+n);*/

    //10. Nhap so luong can truy van
    //VD1: Liet ke SV theo lop:
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        cout << "DANH SACH SINH VIEN LOP " << s << ": \n";
        for(SinhVien x : b){
            if(x.getlop() == s){
                cout << x;
            }
        }    
    }
    /*C2
    int n; cin >> n;
    map <string, vector<SinhVien>> mp;
    for(int i = 0; i < n; i++){
    	SinhVien tmp; cin >> tmp;
    	mp[tmp.getlop()].push_back(tmp);
    
    }
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        cout << "DANH SACH SINH VIEN LOP " << s << ": \n";
        for(SinhVien x: mp[s]){
        	cout << x;
		} 
    }*/

    //VD2: Liet ke SV theo ma:
    int n; cin >> n;
    map <int, vector<SinhVien>> mp;
    for(int i = 0; i < n; i++){
    	SinhVien tmp; cin >> tmp;
    	//stoi: chuyen chuoi thanh so
    	//substr(vi tri bat dau lay, do dai ki tu can lay)
    	mp[stoi(tmp.getlop().substr(1, 2))].push_back(tmp);
    
    }
    int p; cin >> p;
    cin.ignore();
    while(p--){
        int nam; cin >> nam;
        cout << "DANH SACH SINH VIEN KHOA " << nam << ": \n";
		for(SinhVien x : mp[nam % 100]){
			cout << x;
		}
    }

    //VD3: Liet ke SV theo nganh
    
    /*void vietHoa(string &s){
        for(char &x : s){
            x = toupper(x);
        }
    }

    //Ke toan ==> KT
    string Convert(string s){
        stringstream ss(s);
        vector<string> v;
        string tmp, res = "";
        while(ss >> tmp) v.push_back(tmp);
        for(int i = 0; i < 2; i++){
            res += toupper(v[i][0]);
        }
        return res;
    }

    //Trong ham main()
    /*    int n; cin >> n;
        map <string, vector<SinhVien>> mp;
        for(int i = 0; i < n; i++){
            SinhVien tmp; 
            cin >> tmp;
            
            //substr(vi tri bat dau lay, do dai ki tu can lay)
            mp[tmp.getMa().substr(5, 2)].push_back(tmp);
        
        }
        int q; cin >> q;
        cin.ignore();
        while(q--){
            string nganh; getline(cin, nganh);
            vietHoa(nganh);
            cout << "DANH SACH SINH VIEN NGANH " << nganh << ": \n";
            string ng = Convert(nganh);
            if(ng == "CN" || ng == "AT"){
                for(SinhVien x : mp[ng]){
                    if(x.getMa().find("E") != string :: npos){
                        cout << x;	
                    }
                }
            }
            else 	
                for(SinhVien x : mp[ng]){
                    cout << x;
                }
        }
    */
    
}

/*Viet chuong trinh khai bao lop SV gom cac thong tin: msv, 
ho ten, lop, gpa. Ham khoi tao khong co gia tri tham so, gan cac gia tri o trang thai mac dinh
Yeu cau su dung chong toan tu nhap va xuat de nhap doi tuong voi cin va in ra voi cout
Doc thong tin N thi sinh tu ban phim (khong co ma sv) va in ra lan luot man hinh moi dong 1 SV 
theo dung thu tu ban dau. Trong do ma sv duoc tao ra theo quy tac them ma B20DCCN sau do gia tri 
nguyen tu dong tang tu 001 (toi da la 099). Ngay sinh duoc chuan hoa ve dang dd/mm/yy
-- Input: Dongdau ghi so SV (0 < N < 50)
Moi SV ghi tren 4 dong thong tin. Trong do
    + Ho ten: <= 30 chu cai chua duoc chuan hoa
    + Ngay sinh co du 3 phan ngay thang nam nhung co the chua dung chuan dd/mm/yy
    + Diem GPA dam bao trong thang 4 voi nhieu nhat 2 so sau dau phay
    + Sap xep danh sach giam dan theo diem gpa

*/

#include<bits/stdc++.h>
using namespace std;

class SinhVien{
    private:
        string ma, ten, lop, ns;
        float gpa;
    public:
        SinhVien(){
            ma = ten = lop = ns = "";
            gpa = 0;
        }
        static int cnt;
        friend istream& operator >> (istream &in, SinhVien& a){
			cnt++;
			string tmp = to_string(cnt);
			tmp = string(3 - tmp.size(), '0') + tmp;
			a.ma = "B20DCCN" + tmp;
			in.ignore();
		    getline(in, a.ten);
			in >> a.lop >> a.ns >> a.gpa;
			return in;	
		}
		friend ostream& operator << (ostream &out, SinhVien a);

        float getGPA(){
            return this->gpa;
        }
    
};

int SinhVien::cnt = 0;

/*string chuan(string name){
	stringstream ss(name);
	string res = "";
	string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i = 1; i < token.length(); i++) res += tolower(token[i]);
		res += " ";
	}
	res.erase(res.length() - 1);
	return res;
}
*/

void XoaSpaceThua(string &s){
	while(s[s.length()-1]==' '){
		s.erase(s.length()-1, 1);
	}
	
    while(s[0] == ' '){
        for(int i = 0; i < s.length(); i++){
            s[i] = s[i+1];
        }
    }
    int i = 0;
	while (i<s.length()){
		if ((s[i]==' ') && (s[i+1]==' ')){
            int size = s.length();
			for (int j = i+1; j < size; j++){
				s[j] = s[j+1];
			}
		}
		else i++;
	}
}

void ChuanHoa (string &s){
	for(int i=0; i < s.length(); i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		
	}
	
	for(int i=0; i < s.length(); i++){
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] -= 32;

		if(s[i] ==' ') s[i+1]-= 32;	
	}
}

ostream& operator << (ostream &out, SinhVien a){
    if (a.ns[2] != '/') a.ns = "0" + a.ns;
	//insert(chi so vi tri muon insert, chuoi muon insert)
	if(a.ns[5] != '/') a.ns.insert(3, "0");
    ChuanHoa(a.ten);
    XoaSpaceThua(a.ten);
	cout << a.ma << " " << a.ten << " " << a.lop << " " << a.ns << " " << fixed <<setprecision(2) << a.gpa << endl;
	return out;
}

//9.2 Sap xep giam dan theo GPA
bool cmp(SinhVien a, SinhVien b){
    return a.getGPA() > b.getGPA();
}


int main(){
    int N; cin >> N;
    SinhVien a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    sort(a, a+N, cmp);
    for(int i = 0; i < N; i++){
        cout << a[i];
    }

}

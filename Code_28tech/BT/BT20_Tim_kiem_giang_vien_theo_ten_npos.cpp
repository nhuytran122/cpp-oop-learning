/*Thông tin về giảng viên Khoa CNTT ban đầu chỉ có họ tên và Bộ môn. Mã giảng viên sẽ
tự động điền tăng dần, tính từ GV01.
Hãy tìm kiếm giảng viên theo tên (yêu cầu tìm gần đúng – tức là trong tên giảng viên
xuất hiện từ hoặc cụm từ khóa, không phân biệt chữ hoa chữ thường).
--Input
Dòng đầu ghi số giảng viên.
Mỗi giảng viên ghi trên 2 dòng gồm họ tên (không quá 50 ký tự) và Bộ môn (không quá
30 ký tự).
Tiếp theo là một dòng ghi số Q là số truy vấn.
Mỗi truy vấn là một từ khóa cần tìm.
--Output
Danh sách các giảng viên tìm được theo từ khóa, trong đó mỗi giảng viên ghi trên một
dòng. Mã được tự động điền theo thứ tự nhập, bộ môn được viết tắt theo các chữ cái đầu
của từng từ và ở dạng in hoa.
Thứ tự giảng viên của mỗi bộ môn được liệt kê theo đúng thứ tự ban đầu.*/

#include <bits/stdc++.h>
using namespace std;
//lay tu viet tat
string chuan(string bm){
	string res = "";
	stringstream ss(bm);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
	}
	return res;
}

class GiangVien{
    private:
        string ten, bm, ma;
        static int cnt;
    public:
        void nhap();
		void in();
		string getTen(){
			return ten;
		}
		string getMa(){
			return ma;
		}
};

int GiangVien::cnt = 0;

void GiangVien::nhap(){
	cnt++;
	string s = to_string(cnt);
	if(s.size() < 2) s = "0" + s;
	ma = "GV" + s;
	getline(cin, ten);
	getline(cin, bm);
}
 
void GiangVien::in(){
	cout << ma << " " << ten << " " << chuan(bm) << endl;
}

bool tim(string name, string word){
	for(char &x : name) x = tolower(x);
	for(char &x : word) x = tolower(x);
	//find là phương thức tìm vị trí xuất hiện của một chuỗi con 
	//trong chuỗi hiện tại. Phương thức này trả về hằng số string::npos nếu không tìm thấy.
	return name.find(word) != string::npos;
}
 
int main(){
	int n; cin >> n;
	scanf("\n");
	GiangVien a[n];
	for(int i = 0; i < n; i++){
		a[i].nhap();
	}
	int q; cin >> q;
	while(q--){
		string s;
		cin >> s;
		cout << "DANH SACH GIANG VIEN THEO TU KHOA " << s << ": \n";
		for(GiangVien x : a){
			if(tim(x.getTen(), s)){
				x.in();
			}
		}
	}
}
 
//3
//Nguyen Manh Son
//Cong nghe phan mem
//Vu Hoai Nam
//Khoa hoc may tinh
//Dang Minh Tuan
//An toan thong tin
//1
//aN

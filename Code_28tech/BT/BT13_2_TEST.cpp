// > : giam dan
// < tang dan
/*Thong tin cua 1 NV gom: <nhu bai 17>
Ma nv bat dau tu 0001
Viet chuong trinh nhap DS NV (khong nhap ma) trong do su dung chong toan tu nhap xuat, sau do sap sep theo thu tu 
ngay sinh tu gia nhat den tre nhat va in ra man hinh DS doi tuong NV da sap xep
-- Input: dong dau ghi so N la so NV (<=40). Moi NV ghi tren 6 dong
Su dung main co san
3
Nguyen Van A
Nam
10/22/1982
Mo Lao - Ha Dong - Ha Noi
8333012345
31/12/2013
Ly Thi B
Nu
10/15/1988
Mo Lao - Ha Dong - Ha Noi
8333012346
22/08/2011
Hoang Thi C
Nu
04/02/1981
Mo Lao - Ha Dong - Ha Noi
833301237
22/08/2011

=>
00003 Hoang Thi C Nu 04/02/1981 Mo Lao - Ha Dong - Ha Noi 833301237 22/08/2011
00001 Nguyen Van A Nam 10/22/1982 Mo Lao - Ha Dong - Ha Noi 8333012345 31/12/2013
00002 Ly Thi B Nu 10/15/1988 Mo Lao - Ha Dong - Ha Noi 8333012346 22/08/2011
*/

#include<bits/stdc++.h>
using namespace std;
class NhanVien{
    private:
        string ten, gt, ns, diachi, mst, ngayki;
        int ma;
    public:
        static int cnt;
        friend istream& operator >> (istream &in, NhanVien& a){
            cnt++;
            a.ma = cnt;
            in.ignore();
            getline(in, a.ten);
            in >> a.gt >> a.ns;
            in.ignore();
            getline(in, a.diachi);
            in >> a.mst >> a.ngayki;
            return in;
        }
		friend ostream& operator << (ostream &out, NhanVien a);
		friend bool operator < (NhanVien a, NhanVien b){
			string s1 = a.ns, s2 = b.ns;
			//02/12/2003
			//11/21/2002
			int t1 = (s1[0] - '0') * 10 + s1[1] - '0', ng1 = (s1[3] - '0') * 10 + s1[4] - '0', n1 = stoi(s1.substr(6));
			int t2 = (s2[0] - '0') * 10 + s2[1] - '0', ng2 = (s2[3] - '0') * 10 + s2[4] - '0', n2 = stoi(s2.substr(6));
			if(n1 != n2) return n1 < n2;
			if(t1 != n2) return t1 < t2;
			return ng1 < ng2;
		}	
};

int NhanVien::cnt = 0;

ostream& operator << (ostream &out, NhanVien a){
    out << setfill('0') << setw(5) << a.ma << " " << a.ten << " " << a.gt << " " <<  a.ns << " " << a.diachi << " " << a.mst << " " << a.ngayki << endl;
    return out;
}

void Sapxep(NhanVien a[], int n){
	sort(a, a+n);
}

int main(){
	NhanVien ds[50];
	int N, i;
	cin >> N;
	for(int i = 0; i < N; i++) cin >> ds[i];
	Sapxep(ds, N);
	for(int i = 0; i < N; i++){
		cout << ds[i];
	}
	return 0;
}

// https://blog.luyencode.net/bai-tap-lap-trinh-huong-doi-tuong/
#include <bits/stdc++.h>
using namespace std;
 
class Date{
	protected:
	    int day, month, year;
	 
	public:
	    Date(){
	        day = month = year = 0;
	    }
	    
	    ~Date(){
	        day = month = year = 0;
	    }
	    
	    void input(){
	        cout << "Nhap Ngay: ";
	        cin >> day;
	        cout << "Nhap Thang: ";
	        cin >> month;
	        cout << "Nhap Nam: ";
	        cin >> year;
	    }
	    
	    void output(){
	        cout << "Ngay / Thang / Nam: " << day << "/" << month << "/" << year << endl;
	    }
};

class Vemaybay{
	protected:
	    string tenchuyen;
	    Date ngaybay;
	    int giave;
	 
	public:
	    Vemaybay(){
	        tenchuyen = "";
	        giave = 0;
	    }
	    
	    ~Vemaybay(){
	        tenchuyen = "";
	        giave = 0;
	    }
	    
	    void input(){
	        cin.ignore();
	        cout << "Nhap Ten Chuyen: "; getline(cin, tenchuyen);
	        cout << "Nhap Ngay Bay: " << endl;
	        ngaybay.input();
	        cout << "Nhap Gia Ve: "; cin >> giave;
	    }
	    
	    void output(){
	        cout << "Ten Chuyen: " << tenchuyen << endl;
	        cout << "Ngay Bay: " << endl << "\t";
	        ngaybay.output();
	        cout << "Gia Ve: " << giave << endl;
	    }
	    
	    int getgiave(){
	        return giave;
	    }
};
 
class Nguoi{
	protected:
	    string hoten, gioitinh;
	    int tuoi;
	 
	public:
	    Nguoi(){
	        hoten = gioitinh = "";
	        tuoi = 0;
	    }
	    
	    ~Nguoi(){
	        hoten = gioitinh = "";
	        tuoi = 0;
	    }
	    
	    void input(){
	        cin.ignore();
	        cout << "Nhap Ho Ten: "; getline(cin, hoten);
	        cout << "Nhap Gioi Tinh: "; getline(cin, gioitinh);
	        cout << "Nhap Tuoi: "; cin >> tuoi;
	    }
	    void output(){
	        cout << "Ho Ten: " << hoten << endl;
	        cout << "Gioi Tinh: " << gioitinh << endl;
	        cout << "Tuoi: " << tuoi << endl;
	    }
};
 
class Hanhkhach : public Nguoi{
	protected:
	    int soluong;
	    //Vemaybay *ve;
	    Vemaybay ve[1000];
	    int tongtien;
	 
	public:
	    Hanhkhach(){
	        soluong = 0;
	        //this->ve = new Vemaybay[this->soluong];
	        ve[soluong];
	        tongtien = 0;
	    }
	    
	    ~Hanhkhach(){
	        soluong = 0;
	        delete []ve;
	        tongtien = 0;
	    }
	    
	    void input(){
	        Nguoi::input();
	        cout << "Nhap So Luong Ve Hanh Khach Da Mua: "; cin >> soluong;
	        //ve = new Vemaybay[this->soluong];
	        ve[soluong];
	        for(int i = 0; i < soluong; i++){
	            ve[i].input();
	            tongtien += ve[i].getgiave();
	        }
	    }
	    
	    void output(){
	        cout << "- Thong Tin Khach Hang: " << endl;
	        Nguoi::output();
	        cout << "- Thong Tin Chuyen Bay: " << endl;
	        for (int i = 0; i < soluong; i++){
	            ve[i].output();
	            cout << endl;
	        }
	        
	        cout << "==> Tong Tien = " << tongtien;
	        cout << endl;
	    }
	 
	    int operator < (Hanhkhach &obj){
	        return tongtien < obj.tongtien;
	    }
};
 
void swap(Hanhkhach &a, Hanhkhach &b){
    Hanhkhach temp = a;
    a = b;
    b = temp;
}
 
void Bubblesort(Hanhkhach arr[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(){
    cout << "Nhap So Luong Khach Hang: "; int n; cin >> n;
    Hanhkhach *arr = new Hanhkhach[n];
    for (int i = 0; i < n; i++) arr[i].input();
    cout << endl << endl << "Output" << endl << endl;
    for (int i = 0; i < n; i++){
        arr[i].output();
        cout << endl << "------------------" << endl << endl;
    }
 
    cout << "After Sort: " << endl;
    Bubblesort(arr, n);
    for (int i = 0; i < n; ++i){
        arr[i].output();
        cout << endl << "------------------" << endl << endl;
    }
    return 0;
}

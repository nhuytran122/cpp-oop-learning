#include<bits/stdc++.h>
using namespace std;

class Media{
    private:
        string mapt, namxb;
        float giaban;
    public:
    	Media();
        Media(string ma, string nam, float gia);
        void Nhap();
        void Xuat();
        string getMapt();
        string getNamxb();
        float getGiaban();
        
        void setMa(string ma);
        void setNamxb(string n);
        void setGia(float gia);
};

Media::Media(){
}

Media::Media(string ma, string nam, float gia){
    mapt = ma;
    namxb = nam;
    giaban = gia;
}

void Media::Nhap(){
    cout << "\nNhap ma phuong tien: "; getline(cin, mapt);
    cout << "Nhap nam xuat ban: "; cin >> namxb;
    cin.ignore();
    cout << "Nhap gia ban: "; cin >> giaban;
    cin.ignore();
}

void Media::Xuat(){
    cout << endl << mapt << "\t" << namxb << "\t" << giaban << "\t";
}

string Media::getMapt(){ return mapt; }
string Media::getNamxb(){ return namxb; }
float Media::getGiaban(){ return giaban; }

void Media::setMa(string ma){ mapt = ma; }
void Media::setNamxb(string n){	namxb = n; }
void Media::setGia(float gia){ giaban = gia;}

class Book:public Media{
    private:
        string tensach, tacgia;
        int sotrang;
    public:
        Book();
        Book(string ma, string nam, float gia, string ten, string tg, int trang);
        string getTensach(){ return tensach; }
        string getTacgia(){ return tacgia; }
        int getSotrang(){ return sotrang; }

        void nhap();
        void xuat();
        bool operator > (Book b);
        
        void setTensach(string ten){
        	tensach = ten;
		}
		
		void setTg(string tg){
			tacgia = tg;
		}
		
		void setSotrang(int p){
			sotrang = p;
		}
};

Book::Book(){}
Book::Book(string ma, string nam, float gia, string ten, string tg, int trang):Media(ma, nam, gia)
{
    tensach = ten;
    tacgia = tg;
    sotrang = trang;
}

void Book::nhap(){
    Media::Nhap();
    cout << "Nhap ten sach: "; getline(cin, tensach);
    cout << "Nhap tac gia: "; getline(cin, tacgia);
    cout << "Nhap so trang: "; cin >> sotrang;
    cin.ignore();
}

void Book::xuat(){
    Media::Xuat();
    cout << tensach << "\t" << tacgia << "\t" << sotrang;
}

bool Book::operator > (Book b){
    return sotrang > b.sotrang;
}

//void Xoa(Book a[], int &n, int vt){
//	for(int i = vt+1; i<n; i++){
//		a[i-1] = a[i];
//	}
//	n--;
//}

void Xoa(Book a[], int &n, int vt){
	for(int i = vt; i<n-1; i++){
		a[i] = a[i+1];
	}
	n--;
}

int main(){
    int n, s1 = 0;
    double s2 = 0;
    string tg;
    Book b[200];
    cout << "\nNhap so luong sach: "; cin >> n;
    cin.ignore();
    for(int i = 0; i<n; i++){
        b[i].nhap();
    }

    for(int i = 0; i < n-1; i++){
        for (int j = i+1 ; j < n; j++){
            if (b[i] > b[j]){
	            Book tmp = b[i];
	            b[i] = b[j];
	            b[j] = tmp;
        	}
		}
	}

    for(int i=0; i<n; i++){
        s1 += b[i].getSotrang();
        s2 += b[i].getGiaban();
    }
	cout << "\n\tDANH SACH CAC CUON SACH TANG DAN THEO SO TRANG: \n";
	for (int i=0; i<n ; i++)
		b[i].xuat();
		
    cout << "\n\nTong so trang cua cac cuon sach: " << s1;
    cout << "\nTong gia tri cua cac cuon sach: " << s2 << endl;

    cout << "\nNhap ten tac gia muon xoa cac cuon sach cua tac gia do: "; getline(cin, tg);
    for(int i=0; i<n; i++){
        if(b[i].getTacgia() == tg){
            Xoa(b, n, i);
            i--;
        }
    }

    cout << "\n\tDanh sach sau khi xoa: ";
    for (int i=0; i<n ; i++)
		b[i].xuat();
	
}

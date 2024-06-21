#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class Hinhtron{
	private:
		float x, y, R;
	public:
		Hinhtron(){
			x = y = R = 0;
		}
		
		void Nhap(){
			cout << "Nhap toa do tam cua hinh tron:";
			cout << "\nx: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			cout << "Nhap ban kinh R: ";
			cin >> R;
		}
		
		void Xuat(){
			cout << "(" << x << ";" << y << ")" << "; R: " << R << endl;
		}
		
		float getX(){
			return x;
		}
		
		float getY(){
			return y;
		}
};

class Quanly{
	private:
		Hinhtron ht[100];
		int N;
	public:
		Quanly(){
		}
		
		void nhap();
		void xuat();
		
		
};

void Quanly::nhap(){
	N = 0;
	char ch;
	do{
		cout << "\nNhap thong tin NV thu " << N+1 <<":\n";
		ht[N].Nhap();
		N++;
		ch = getch();
	}
	while(ch != 27);
}

void Quanly::xuat(){
	cout << "\n";
	for(int i=0; i<N; i++){
		ht[i].Xuat();
	}
	cout << "\nCac duong tron co tam nam tren truc hoanh: \n";
	for(int i=0; i<N; i++){
		if(ht[i].getY() == 0){
			ht[i].Xuat();
		}
	}
}



int main(){
	Quanly ob1;
	ob1.nhap();
	ob1.xuat();
}

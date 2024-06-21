#include<bits/stdc++.h>
using namespace std;

void Nhap(int *a, int n){
	cout << "Nhap cac phan tu cua mang 1 chieu: ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}

void Nhap(int b[][40], int &row, int &col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << "Vi tri " << "[" << i << "]" << "[" << j << "]" << ": ";
			cin >> b[i][j];
		}
	}		
}

void XuatMang(int b[][40], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
        	cout << b[i][j] << " ";	
		}
        cout << endl;
    }
}

int* Plus(int *a, int *b, int n, int m, int k){
	int *c = new int [n];
	if(n == m){
		for(int i = 0; i<n; i++){
   			c[i] = a[i] + b[i];
  		}
	}
	//Size cua mang a > mang b
	else if(n>m){
		for(int i = 0; i<m; i++){
		   	c[i] = a[i] + b[i];
		}
		for(int i = m; i<n; i++){
		   	c[i] = a[i];
		}
	}
	//Size cua mang b > mang a
	else if(m>n){
		for(int i = 0; i<n; i++){
		   	c[i] = a[i] + b[i];
		}
		for(int i = n; i<m; i++){
		   	c[i] = b[i];
		}
	}
	return c;
}

void Plus(int a[][40], int b[][40], int c[][40], int row, int col){
	for (int i = 0; i<row; i++){
        for (int j = 0; j<col; j++){
        	c[i][j] = a[i][j] + b[i][j];	
		}
    }
}

int main(){
	int n, m, k;
	cout << "CONG 2 MANG 1 CHIEU: \n";
	cout << "Nhap kich thuoc cua mang 1 chieu thu nhat: "; cin >> n;
	cout << "Nhap kich thuoc cua mang 1 chieu thu hai: "; cin >> m;
	int *a = new int [n];
	int *b = new int [m];
	k = n>m ? n:m;
	int *c = new int [k];
	Nhap(a, n);
	Nhap(b, m);
	c = Plus(a, b, n, m, k);
	cout << "KET QUA PHEP CONG 2 MANG 1 CHIEU: \n";
	for(int i = 0; i < k; i++){
		cout << c[i] << " ";
	}
	
	int row1, col1, row2, col2;
	int mt1[40][40], mt2[40][40], mt[40][40];
	cout << "\n\nCONG 2 MANG 2 CHIEU: ";
	do{
		cout << "\nNhap kich thuoc cua mang 2 chieu thu nhat: \n"; 
		cout << "Nhap so hang: "; cin >> row1;
		cout << "Nhap so cot: "; cin >> col1;

		cout << "\nNhap kich thuoc cua mang 2 chieu thu hai: \n"; 
		cout << "Nhap so hang: "; cin >> row2;
		cout << "Nhap so cot: "; cin >> col2;
		
		if(row1 != row2 || col1 != col2) cout << "2 mang phai co cung kich thuoc!\n";
	} while (row1 != row2 || col1 != col2);
	cout << "Nhap du lieu cho mang thu 1:\n";
	Nhap(mt1, row1, col1);
	cout << "\nNhap du lieu cho mang thu 2:\n";
	Nhap(mt2, row2, col2);
	
	Plus(mt1, mt2, mt, row1, col1);
	
	cout << "\nKET QUA PHEP CONG 2 MANG 2 CHIEU: \n";
	XuatMang(mt, row1, col1);
	delete a, b, c;
	return 0;
}


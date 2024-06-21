#include<bits/stdc++.h>
using namespace std;

void Nhap(int *a, int n){
	cout << "Cac phan tu cua mang 1 chieu: ";
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
}

void Nhap(int b[][20], int &h, int &c){
	cout << "So hang: "; cin >> h;
	cout << "So cot: "; cin >> c;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < c; j++){
			cout << "[" << i << "]" << "[" << j << "]" << ": ";
			cin >> b[i][j];
		}
	}		
}

void XuatMang(int b[][20], int h, int c){
    for (int i = 0; i < h; i++){
        for (int j = 0; j < c; j++){
        	cout << b[i][j] << " ";	
		}
        cout << endl;
    }
}

int* Cong(int *a, int *b, int n, int m, int k){
	int *c = new int [n];
	if(n == m){
		for(int i = 0; i<n; i++){
   			c[i] = a[i] + b[i];
  		}
	}
	
	else if(n>m){
		for(int i = 0; i<m; i++){
		   	c[i] = a[i] + b[i];
		}
		for(int i = m; i<n; i++){
		   	c[i] = a[i];
		}
	}
	
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

void Cong(int a[][20], int b[][20], int c[][20], int h1, int c1){
	for (int i = 0; i<h1; i++){
        for (int j = 0; j<c1; j++){
        	c[i][j] = a[i][j] + b[i][j];	
		}
    }
}

int main(){
	int n, m, k;
	cout << "CONG 2 MANG 1 CHIEU: \n";
	cout << "Kich thuoc cua mang 1 chieu thu nhat: "; cin >> n;
	cout << "Kich thuoc cua mang 1 chieu thu hai: "; cin >> m;
	int *a = new int [n];
	int *b = new int [m];
	if(n>m) k = n;
	else k = m;
	int *c = new int [k];
	Nhap(a, n);
	Nhap(b, m);
	c = Cong(a, b, n, m, k);
	cout << "KET QUA: \n";
	for(int i = 0; i < k; i++){
		cout << c[i] << " ";
	}
	int h1, c1, h2, c2;
	int mt1[20][20], mt2[20][20], mt[20][20];
	cout << "\n\nCONG 2 MANG 2 CHIEU: ";
	do{
		cout << "\nKich thuoc cua mang 2 chieu thu nhat: \n"; Nhap(mt1, h1, c1);
		cout << "\nKich thuoc cua mang 2 chieu thu hai: \n"; Nhap(mt2, h2, c2);
	} while (h1 != h2 || c1 != c2);
	Cong(mt1, mt2, mt, h1, c1);
	cout << "KET QUA: \n";
	XuatMang(mt, h1, c1);
	delete a, b, c;
	return 0;
}


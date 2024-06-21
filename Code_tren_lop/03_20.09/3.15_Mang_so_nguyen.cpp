#include<bits/stdc++.h>
using namespace std;

class Mang{
    private:
        int size;
        int *A;
    public:
        void nhap();
        void xuat();
        Mang Tong(Mang a2);
};

void Mang::nhap(){
    cout << "\tNhap kich thuoc cua Mang (size>0): "; 
    cin >> size;
    A = new int[size];
    if (A == NULL){
        cout<<"\n Loi cap phat bo nho!";
        return;
    }
    cout << "\tNhap cac phan tu cua mang: ";
    for(int i=0; i<size; i++){
        cout << "\n A[" << i << "]: ";
        cin >> A[i];
    }
}

void Mang::xuat(){
    for(int i=0; i<size; i++){
        cout << A[i] << " ";
    }
}

Mang Mang::Tong(Mang a2){
    Mang s;
    if (size!= a2.size) //kiem tra kich thuoc
    {   cout<<"\n 2 mang khong cung kich thuoc";
        exit(1);
    }
    s.A = new int [size];
    if (s.A == NULL){
        cout<<"\n Loi cap phat bo nho!";
        exit(1);
    }
	
    for(int i = 0; i<size; i++){
   		s.A[i] = A[i] + a2.A[i];
  	}
    s.size = size; //gan kich thuoc cua mang s la size (BAT BUOC PHAI CO)

	// s.size = size > a2.size ? size : a2.size;
	// for(int i = 0; i<size; i++){
   	// 	s.A[i] = A[i] + a2.A[i];
  	// }
  	
  	// if(size > a2.size){
	// 	for(int i = a2.size; i < size; i++){
	// 	   	s.A[i] = A[i];
	// 	}
	// }
	// else{
	// 	for(int i = size; i < a2.size; i++){
	// 	   	s.A[i] = a2.A[i];
	// 	}
	// }
	return s;
}

int main(){
   Mang a, a1, a2 ,s;
   cout << "\tNhap mang a:\n";   
   a.nhap();
   cout << "\tMang da nhap: ";
   a.xuat();
   cout << "\n\n\tTONG CUA 2 MANG: \n";
   cout << "\tNhap mang thu nhat: \n";
   a1.nhap();
   cout << "\tNhap mang thu hai: \n";
   a2.nhap();
   s = a1.Tong(a2);
   cout << "\t==> KET QUA: "; s.xuat();
   
}

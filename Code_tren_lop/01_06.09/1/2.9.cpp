#include<bits/stdc++.h>
using namespace std;
void Gpt (float a, float b){
    if(a == 0){
        cout << "Khong phai la phuong trinh bac nhat! Phuong trinh vo nghiem\n";
    }
    else{
        cout << "x = " << -b/a;
    }
}

void Gpt (float a, float b, float c){
    float delta, x1, x2, x;
    delta = b*b-(4*a*c);
	if(delta > 0){
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		cout << "x1 = " << fixed << setprecision(2) << x1;
        cout<< "\nx2 = " << fixed << setprecision(2) << x2;
	}else if(delta<0)
		cout << "No solution";
	else{	
	    x = -b/2*a;
        cout<<"x = " << fixed << setprecision(2) << x;
    }
}
int main(){
    float a, b, c;
    cout << "He so a, b, c: "; 
    cin >> a >> b >> c;
    cout << "\nNghiem cua phuong trinh bac nhat ax + b = 0: \n"; Gpt(a, b);
    cout << "\nNghiem cua phuong trinh bac hai ax^2 + bx + c = 0: \n"; Gpt(a, b, c);
}

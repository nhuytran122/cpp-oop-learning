#include<bits/stdc++.h>
using namespace std;

float Gpt (float a, float b){
   return -b/a;
}

float Gpt (float a, float b, float c, float &x1, float &x2){
    float delta = b*b-(4*a*c);
	if(delta > 0){
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		return 2;
	}else if(delta == 0){
		x1 = x2 = -b/2*a;
        return 1;
    }
	else{	
		x1 = x2 = 0;
	    return 0;
    }
}
int main(){
    float a, b, c, x1, x2;
    cout << "Nhap he so a, b, c: "; 
    cin >> a >> b >> c;
    cout << "\nKET QUA GIAI PHUONG TRINH BAC NHAT ax + b = 0: x = ";
    if(a == 0 && b == 0) cout << "Phuong trinh co vo so nghiem\n";
    else if(a == 0 && b != 0) cout << "Phuong trinh co vo nghiem\n";
    else if(a != 0) cout << "x = " << Gpt(a, b);
    
    
    float x = Gpt(a, b, c, x1, x2);
    cout << "\n\nKET QUA GIAI PHUONG TRINH BAC HAI ax^2 + bx + c = 0: \n";
    if(x == 2) {
    	cout << "Phuong trinh co 2 nghiem phan biet: " << "x1 = " << fixed << setprecision(2) << x1 << "; x2 = " << fixed << setprecision(2) << x2;
    }
    else if(x == 1){
        cout << "Phuong trinh co nghiem kep x1 = x2 = "  << fixed << setprecision(2) << x1;
    }
    else{
        cout << "Phuong trinh vo nghiem";
    }
    return 0;
}

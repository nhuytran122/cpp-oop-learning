#include<bits/stdc++.h>
using namespace std;

float Area(float a, float b, float c, float &s){
	if(a+b>c && b+c>a && a+c>b){
		float p = (a+b+c)/2;
	    s = sqrt(p* (p-a) * (p-b) * (p-c));
	    return 1;
	}
	else {
		return 0;
	} 
}

float Area(float x, float y){
    return x * y;
}

float Area (float r){
    return 3.14 * r * r;
}

int main(){
    float a, b, c, x,y, r, s;
    cout << "Nhap do dai 3 canh cua tam giac: "; cin >> a >> b >> c;
    do{
        cout << "Nhap chieu dai, rong cua hinh chu nhat: "; cin >> x >> y;
    }
    while(x < 0 || y < 0 );
    cout << "Nhap ban kinh hinh tron: "; cin >> r;
    cout << "\nKET QUA: \n";
    cout << "Dien tich tam giac: " ;
	if(Area(a, b, c, s)) cout << s << endl;
	else cout << "Day khong phai la hinh tam giac\n";
    cout << "Dien tich hinh chu nhat: " << Area(x, y) << endl;
    cout << "Dien tich hinh tron: " << Area(r) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

float Area(float a, float b, float c, float &s){
	float p = (a+b+c)/2;
	s = sqrt(p* (p-a) * (p-b) * (p-c));
	return s;
}
	

float Area(float x, float y){
    return x * y;
}

float Area (float r){
    return 3.14 * r * r;
}

int main(){
    float a, b, c, x,y, r, s;
    cout << "Do dai 3 canh cua tam giac: "; cin >> a >> b >> c;
    cout << "Chieu dai, rong cua hinh chu nhat: "; cin >> x >> y;
    cout << "Ban kinh hinh tron: "; cin >> r;
    cout << "\nKet qua: \n";
    cout << "Dien tich tam giac: " ;
	cout << Area(a, b, c, s)  << endl;
    cout << "Dien tich hinh chu nhat: " << Area(x, y) << endl;
    cout << "Dien tich hinh tron: " << Area(r) << endl;
    return 0;
}

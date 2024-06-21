#include<bits/stdc++.h>
using namespace std;

class Xe{
    protected:
        string ten, loaixe;
        int giothue;
    public:
    	Xe();
    	Xe(string ht, string lx, int g);
        virtual void Xuat();
        virtual float tienThue(){
        	return 0;
		}
};

Xe::Xe(){}
Xe::Xe(string ht, string lx, int g){
	ten = ht;
	loaixe = lx;
	giothue = g;
}

void Xe::Xuat(){
    cout << "\n\nHo ten nguoi thue: " << ten;
    cout << "\nSo gio thue: " << giothue; 
    cout << "\nLoai xe: " << loaixe;
}

class Xedap : public Xe{
    public:
    	Xedap();
    	Xedap(string ht, string lx, int g);
        void xuat();
        float tienThue();

};
Xedap::Xedap(void){}

Xedap::Xedap(string ht, string lx, int g) : Xe(ht, lx, g){
}

void Xedap::xuat(){
	Xe::Xuat();
}

float Xedap::tienThue(){
	if(giothue > 1)
        return float(30000) + 20000*(giothue-1);
    else return float(30000);
}

class Xemay : public Xe{
    private:
        int bienso;
    public:
    	Xemay();
    	Xemay(string ht, string lx, int g, int bs);
    	void xuat();
        float tienThue();
};

Xemay::Xemay(){}

Xemay::Xemay(string ht, string lx, int g, int bs) : Xe(ht, lx, g){
	bienso = bs;
}

float Xemay::tienThue(){
    if(loaixe == "100") return float(15000)*giothue;
    else return float(20000)*giothue;
}

void Xemay::xuat(){
	Xe::Xuat();
	cout << setw(10) << bienso << setw(10);
}

int main(){
	Xe *DS[100];
	int n, tl, g;
	string ht, lx;
	cout << "\nNhap tong so xe cho thue: "; cin >> n;
	for(int i=0; i<n; i++){
		cout << "\n1 - Xe dap; 2 - Xe may: "; cin >> tl; cin.ignore();
		cout << "\nHo ten: "; getline(cin, ht);
		cout << "So gio thue: "; cin >> g; cin.ignore();
		cout << "Loai xe: "; getline(cin, lx);
		
		switch(tl){
			case 1:{
				Xedap *p = new Xedap(ht, lx, g);
				DS[i] = p;
				break;
			}
			
			case 2:{
				int bs;
				cout << "Bien so xe: "; cin >> bs;
				Xemay *p = new Xemay(ht, lx, g, bs);
				DS[i] = p;
				break;
			}
		}
	}
	
	cout << "\nDanh sach cac xe da thue: \n";
	for(int i=0; i<n; i++){
		DS[i]->Xuat();
		cout << setw(10) << DS[i]->tienThue() << endl;
	}
    return 0;
}   


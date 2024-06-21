//vi du 2 ve phuong thuc ao (BT 5.11)
#include <iostream>
using namespace std;

class danhmuc{
	private:
		string nhande, tacgia;
	protected:
		int tk; 
	public:
		void nhap();
		void xuat();
		int get_tk();
		string get_tg();
		virtual int khenthuong(){
			return 0;
		}	
};

void danhmuc::nhap(){
	cout << "Nhap nhan de: "; cin.ignore(); getline(cin, nhande);
	cout << "Nhap tac gia: "; cin.ignore(); getline(cin, tacgia);
	cout << "Nhap so lan tham khao: "; cin >> tk;
}

void danhmuc::xuat(){
	cout<<"Nhan de: "<<nhande<<" \n";
	cout<<"Tac gia: "<<tacgia<<"\n";
	cout<<"So lan tham khao: "<<tk;
}

int danhmuc::get_tk(){ 
	return tk; 
}

string danhmuc::get_tg(){ 
	return tacgia;
}

class sach: public danhmuc{
	private:
		string nxb;
		int version;
	public:
		void nhap_sach();
		void xuat_sach();
		int khenthuong();
};
void sach::nhap_sach(){
	nhap();
	cout<<"Nha xuat ban: "; cin.ignore(); getline(cin, nxb);
	cout<<"Lan in thu: ";
	cin>>version;
}
void sach::xuat_sach(){
	xuat();
	cout<<"Nha xuat ban: " <<nxb;
	cout<<"Lan in thu: "<<version;
}
int sach::khenthuong(){ 
	return tk > 20; 
}

class tapchi: public danhmuc{
	private:
		string ten_tc;
		int so_tc;
	public:
		void nhap_tc();
		void xuat_tc();
		int khenthuong();
};
void tapchi::nhap_tc(){
	nhap();
	cout<<" Ten tap chi: "; cin.ignore(); getline(cin, ten_tc);
	cout<<" So tap chi: "; cin>>so_tc;
}
void tapchi::xuat_tc(){
	xuat();
	cout<<"Ten tap chi: "<<ten_tc;
	cout<<"So tap chi: "<<so_tc;
}
int tapchi::khenthuong(){ 
	return tk>10;
}
int main(){
	danhmuc *DS[100];
	int i, n, tl;
	cout << "Nhap so luong n (bao gom sach va tap chi): ";
	cin >> n;
	for (i=0; i<n; i++){
		cout << "Nhap loai danh muc: 1 - sach, 2 - tap chi: ";
		cin >> tl;
		if (tl == 1){
			sach *p = new sach;
			p->nhap_sach();
			DS[i] = p;
		}
		else{
			tapchi *p = new tapchi;
			p->nhap_tc();
			DS[i]=p;
		}
	}
	
	int max = DS[0]->get_tk();
	//Tim max cua tham khao
	for (i=0; i<n; i++)
		if (max < DS[i]->get_tk())
			max = DS[i]->get_tk();
	
	//In danh muc co tham khao la max
	cout<<"\n Danh muc (sach hoac tap chi) co tham khao max: "<<endl;
	for (i=0; i<n; i++)
		if (max == DS[i]->get_tk())
			DS[i]->xuat();
			
	//In tac gia co danh muc duoc khen thuong
	cout<<"\n Danh sach tac gia duoc khen thuong: "<<endl;
	for (i=0; i<n; i++)
		if (DS[i]->khenthuong() == 1)
			cout << DS[i]->get_tg() << endl;
	return 0;
}



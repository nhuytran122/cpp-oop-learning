#include<bits/stdc++.h>
using namespace std;

class Date{
	private:
		int d, m, y;
	public:
		Date(){
		}
		
		Date(int d, int m, int y){
			this->d = d;
			this->m = m;
			this->y = y;
		}
		
		bool operator > (Date ob);
};

bool Date::operator > (Date ob){
	if(y > ob.y) return true;
	if(y == ob.y && m > ob.m) return true;
	if(y == ob.y && m == ob.m && d > ob.d) return true;
	return false;
}

class Person{
	private:
		string ho, ten;
		Date ngaysinh;
	public:
		Person(){
		}
		
		Person(string h, string t, Date ns){
			ho = h;
			ten = t;
			ngaysinh = ns;
		}
		
		void setHo(string h){
			ho = h;
		}
		string getHo(){
			return ho;
		}
		
		void setTen(string t){
			ten = t;
		}
		string getTen(){
			return ten;
		}
		
		void setNs(Date ns){
			ngaysinh = ns;
		}
		Date getNs(){
			return ngaysinh;
		}
};

class Student : public Person{
	private:
		string msv, sdt;
		float dtb;
	public:
		Student(){
		}
		
		Student(string h, string t, Date ns, string ma, string dt, float tb) : Person(h, t, ns){
			msv = ma;
			sdt = dt;
			dtb = tb;
		}
		
		void setMsv(string ms){
			msv = ms;
		}
		string getMsv() const{
			return msv;
		}
		
		void setSdt(string dt){
			sdt = dt;
		}
		string getSdt() const{
			return sdt;
		}
		
		void setDtb(float tb){
			dtb = tb;
		}
		float getDtb(){
			return dtb;
		}
		
		bool operator > (Student ob);
		bool operator >= (Student ob);
		bool operator < (Student ob);
		
		void setStudent();
		void print_Student();	
};

bool Student::operator > (Student ob){
	return getNs() > ob.getNs();
}

bool Student::operator >= (Student ob){
	return getDtb() > ob.getDtb();
}

bool Student::operator < (Student ob){
	if(getTen() < ob.getTen()) return true;
	else if(getTen() == ob.getTen()){
		if(getHo() < ob.getHo()) return true;
	return false;
	}
}

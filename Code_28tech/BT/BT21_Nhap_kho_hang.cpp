#include<bits/stdc++.h>
using namespace std;

string Mahang(string s){
	stringstream ss(s);
	vector<string> v;
	string tmp, res = "";
	while(ss >> tmp) v.push_back(tmp);
	for(int i = 0; i < 2; i++){
		res += toupper(v[i][0]);
	}
	return res;
}

class Mathang{
    private:
        string ten, ma;
        int sl;
        double dongia, chietkhau, tienchietkhau, S;
    public:
        friend istream& operator >> (istream &in, Mathang& a);
		friend ostream& operator << (ostream &out, Mathang a);

};

istream& operator >> (istream &in, Mathang& a){

    getline(in, a.ten);
	in >> a.sl;
	in >> a.dongia;
	in.ignore();
	return in;
}

ostream& operator << (ostream &out, Mathang a){
    if(a.sl < 5) a.chietkhau = 0;
    else if (a.sl >=5 && a.sl < 8) a.chietkhau = 0.01;
    else if (a.sl >=8 && a.sl <= 10) a.chietkhau = 0.02;
    else if(a.sl > 10) a.chietkhau = 0.05;
    a.tienchietkhau = a.dongia * a.sl * a.chietkhau;
    a.S = a.dongia * a.sl - a.tienchietkhau;
    map<string, int> mp;
    /*cnt++;
	string s = to_string(cnt);
	if(s.size() < 2) s = "0" + s;
	ma = "GV" + s;*/
    string res = Mahang(a.ten);
    cout << "Mp[res]:" << mp[res] << endl;
    mp[res]++;
    cout << "Mp[res] sau khi ++:" << mp[res] << endl;
    //if(a.ma.size() < 2) a.ma = res + "0" + a.ma;
    int cnt = mp[res];
    string s = to_string(cnt);
    if(mp.find(res) == mp.end()){
            a.ma = res + "0" + s;
            cout << a.ma <<  " " << a.ten << " " << (size_t)a.tienchietkhau << " " << (size_t)a.S << endl;
    }
    else {
        if(s.size() < 2){
            a.ma = res + "0" + s;
        } 
        else a.ma = res + s;
        cout << a.ma << " " << a.ten << " " << (size_t)a.tienchietkhau << " " <<(size_t)a.S << endl;
    }
    
    
    /*string username;
		cin >> username;
		//Khong tim thay ten trung:
		if(mp.find(username) == mp.end()){
			cout << username << endl;
		}
		else{
			cout << username << mp[username] << endl;
		}
		mp[username]++;*/
	return out;

}

int main(){
    int N; cin >> N;
    cin.ignore();
    Mathang a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cout << a[i];
    }
}

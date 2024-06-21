#include<bits/stdc++.h>
using namespace std;

class Idol{
public:
    Idol(){}

    Idol(const string &ht, int t, bool ida = false)
        : ho_ten(ht), tuoi(t), indate(ida)
    {}

/*C2:    Idol(string ht, bool ida = false){
        ho_ten = ht;
        indate = ida;
    }
*/
    void Hen_ho(){
        if(tuoi > 34){
            indate = true;
        }
        
    }

    void cong_khai(){
        cout << ho_ten << " " << (indate ? "hen ho" : "doc than") << endl; 
    }

    string dien_xuat(string vai_dien){

        return "" ;
    }

private:
    string ho_ten;
    bool indate;
    int tuoi;
};

class Celeb{
};

int main(){
    //Cap phat dong:
    Idol *Lun = new Idol("Deng Lun", 29, false);
    Lun->dien_xuat("Xu Feng");
    Lun->Hen_ho();
    Lun->cong_khai();
    return 0;
}
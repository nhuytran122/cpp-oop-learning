#include<bits/stdc++.h>
using namespace std;

class Celeb{
public:
    Celeb(){}

    Celeb(const string &ht, int t, bool inda = false)
        : ho_ten(ht), tuoi(t), indate(inda)
    {}

    void Hen_ho(){
        if(tuoi > 34){
            indate = true;
        }
        
    }

    void cong_khai(){
        cout << ho_ten << " " << (indate ? "hen ho" : "doc than") << endl; 
    }

    string Dien_xuat(string vai_dien){

        return "" ;
    }

private:
    string ho_ten;
    bool indate;
    int tuoi;
};

class Idol : public Celeb{
    public:
        Idol(const string &ht, int t, bool inda = false)
        : Celeb(ht, t, inda)
    {}

    void Hot_fan(){

    }
};

class Actor : public Celeb{
    public:
        Actor(const string &ht, int t, bool inda = false)
        : Celeb(ht, t, inda)
    {}

    void Acting(){}
};

/*Multi-level inheritance:
 class Idol_Singing : public Idol{

};*/

int main(){
    //Cap phat dong:
    Actor *Lun = new Actor("Deng Lun", 29, false);
    Lun->Dien_xuat("Xu Feng");
    Lun->Hen_ho();
    Lun->cong_khai();
    Lun->Acting();
    return 0;
}
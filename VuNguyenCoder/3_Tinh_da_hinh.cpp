#include<bits/stdc++.h>
using namespace std;

class Celeb{
public:
    Celeb(const string &ht, int t, bool inda = false)
        : ho_ten(ht), tuoi(t), indate(inda)
    {}

    //VIRTUAL: key word dam bao in ra dung hanh vi cua Object do
    virtual string Dien_xuat(string vai_dien){
        return "Da tung dien vai .... (celeb)";
    }

    void Hen_ho(){
        if(tuoi > 34){
            indate = true;
        }   
    }

    void cong_khai(){
        cout << ho_ten << " " << (indate ? "hen ho" : "doc than") << endl; 
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

    string Dien_xuat(string vai_dien){
        return "Da tung dien vai (idol)";
    }
};

class Actor : public Celeb{
    public:
        Actor(const string &ht, int t, bool inda = false)
        : Celeb(ht, t, inda)
    {}

    string Dien_xuat(string vai_dien){
        return "Da tung dien vai (actor)";
    }

};

int main(){
    //Cap phat dong:
    Celeb *Lun = new Actor("Deng Lun", 29, false);
    cout << Lun->Dien_xuat("Xu Feng");
    
    return 0;
}
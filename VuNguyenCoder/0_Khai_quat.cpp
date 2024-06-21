#include<bits/stdc++.h>
using namespace std;

class Idol{
public:
    string ho_ten;

    Idol(){}

    Idol(const string &ht, bool ida = false)
        : ho_ten(ht), indate(ida)
    {}

    /*C2:    Idol(string ht, bool ida = false){
        ho_ten = ht;
        indate = ida;
    }
*/
    //Disconstructor:
    ~Idol(){
        cout << "Chia tay " << ho_ten << endl;
    }

    void Act(){
    }

    string dien_xuat(string vai_dien){
        return "" ;
    }

private:
    bool indate;
};

class Celeb{
};

int main(){
    /* Cap phat tinh: (cuoi chuong trinh, se tu dong thu hoi)
    Idol Lun;*/

    //Cap phat dong:
    Idol *Lun = new Idol("Deng Lun");
    //Idol *Lun = new Idol("Deng Lun", false);
    //Lun->ho_ten = "Deng Lun";
    //Lun->indate = false;
    Lun->dien_xuat("Xu Feng");
    //Xoa object:
    delete Lun;


    Idol *YangMi = new Idol;

    Celeb *Haein = new Celeb;
    return 0;
}
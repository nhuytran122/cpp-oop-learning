//https://youtu.be/77R2fu0m8ug
/*1 diem dich vu can quan ly thong tin cho thue xe dap va xe may.
    + Voi xe dap can luu ho ten nguoi thue, tien thue xe dap duoc tinh nhu sau: 10 000 (dong) cho gio dau tien, 8000 cho moi gio tiep theo.
    + Voi moi xe may can luu ho ten nguoi thue, so gio thue, loai xe (100 phan khoi, 250 phan khoi), bien so. Tien thue xe may duoc tinh nhu sau:
        - Doi voi gio dau tien, loai xe 100 phan khoi tinh 150 000;
        loai xe 250 phan khoi tinh 200 000.
        - Doi voi nhung gio tiep theo tinh 100 000 cho ca 2 loai xe may
Viet chuong trinh xay dung cac lop can thiet sau do nhap danh sach cac thong tin thue xe dap va xe may, sau do xuat ra cac thong tin sau:
    a. Xuat tat ca cac thong tin thue xe (ca so tien thue tuong ung).
    b. Tinh tong so tien cho thue xe dap va xe may.
    c. Xuat tat ca cac thong tin lien quan den viec thue xe dap
    d. Tinh tong so tien cho thue xe may loai 250 phan khoi
*/
#include<bits/stdc++.h>
using namespace std;

// khai báo lớp cha: class XE
class XE{
    protected:
        string HoTenNguoiThue;
        float SoGioThue;
    public:
        void NhapThongTin(){
            while (getchar() != '\n'); // xóa bộ nhớ đệm trước khi nhập chuỗi
            cout << "\nNhap ho ten nguoi thue: ";
            getline(cin, HoTenNguoiThue);
            cout << "\nNhap so gio thue: ";
            cin >> SoGioThue;
        }
        void XuatThongTin(){
            cout << "\nHo ten nguoi thue: " << HoTenNguoiThue;
            cout << "\nSo gio thue: " << SoGioThue;
        }
};

// khai báo lớp con: class XEDAP kế thừa lại class XE
class XEDAP : public XE{
    private:
    public:
        float TinhTienThueXe(){
            return 10000 + ((SoGioThue - 1) * 8000);
        }
};


// khai báo lớp con: class XEMAY kế thừa lại class XE
class XEMAY : public XE{
    private:
        int LoaiXe;
        string BienSo;
    public:
        void NhapThongTin(){
            XE::NhapThongTin();
            cout << "\nNhap loai xe can thue (100 - 250 phan khoi): ";
            cin >> LoaiXe;
            while (getchar() != '\n'); // xóa bộ nhớ đệm trước khi nhập chuỗi
            cout << "\nNhap bien so: ";
            getline(cin, BienSo);
        }
        void XuatThongTin(){
            XE::XuatThongTin();
            cout << "\nLoai xe: " << LoaiXe;
            cout << "\nBien so: " << BienSo;
        }
        float TinhTienThueXe(){
            float s = 0;
            if (LoaiXe == 100){
                s = 150000;
            }
            else{
                s = 200000;
            }
            return s + ((SoGioThue - 1) * 100000);
        }

        // GETTER - LOẠI XE
        int Getter_LoaiXe(){
            return LoaiXe;
        }
        void Setter_LoaiXe(int LOAIXE){
            LoaiXe = LOAIXE;
        }

};

// phương thức xuất tất cả thông tin thuê xe
void Xuat_Tat_Ca_Thong_Tin_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m){
	int dem = 1;
	cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
	// xuất danh sách xe đạp
	for (int i = 0; i < n; i++){
		cout << "\n\tTHONG TIN THUE XE DAP THU " << dem++ << endl;
		ds_xedap[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe();

	}

	cout << "\n\n\t\t DANH SACH THUE XE MAY\n";
	// xuất danh sách xe máy
	for (int i = 0; i < m; i++){
		cout << "\n\tTHONG TIN THUE MAY THU " << dem++ << endl;
		ds_xemay[i].XuatThongTin();
		cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe();
	}
}

// phương thức tính tổng tiền thuê xe đạp và xe máy
float Tinh_Tong_Tien_Thue_Xe(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m){
	float tong = 0;
	// duyệt danh sách xe đạp
	for (int i = 0; i < n; i++){		
		tong += ds_xedap[i].TinhTienThueXe();

	}

	// duyệt danh sách xe máy
	for (int i = 0; i < m; i++){		
		tong += ds_xemay[i].TinhTienThueXe();
	}
	return tong;
}
// hàm quản lý các loại xe
void Menu(XEDAP ds_xedap[], int n, XEMAY ds_xemay[], int m){
	int luachon;
	while (true){
		system("cls");
		cout << "\n\n\t\t ====== QUAN LY XE ======";
		cout << "\n\t1. Nhap danh sach thue xe dap va xe may";
		cout << "\n\t2. Xuat tat ca thong tin thue xe";
		cout << "\n\t3. Tinh tong so tien cho thue xe dap va xe may";
		cout << "\n\t4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap";
		cout << "\n\t5. Tinh tong so tien cho thue xe may loai 250 phan khoi";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== END ============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1){
			int chon;
			while (true){
				system("cls");
				cout << "\n1. Thue XE DAP";
				cout << "\n2. Thue XE MAY";
				cout << "\n0. Ket thuc";

				cout << "\nNhap loai xe muon thue: ";
				cin >> chon;

				if (chon == 1){
					XEDAP x;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE DAP\n";
					x.NhapThongTin();
					ds_xedap[n] = x;
					n++;
				}
				else if (chon == 2){
					XEMAY x;
					cout << "\n\n\t\t NHAP THONG TIN THUE XE MAY\n";
					x.NhapThongTin();
					ds_xemay[m] = x;
					m++;
				}
				
				else{
					
					break;
				}
			}
		}
		else if (luachon == 2){
			Xuat_Tat_Ca_Thong_Tin_Thue_Xe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 3){
			cout << "\n\n\t\tTONG TIEN THUE XE: " << (size_t)Tinh_Tong_Tien_Thue_Xe(ds_xedap, n, ds_xemay, m);
			system("pause");
		}
		else if (luachon == 4){
			cout << "\n\n\t\t DANH SACH THUE XE DAP\n";
			// xuất danh sách xe đạp
			for (int i = 0; i < n; i++)
			{
				cout << "\n\tTHONG TIN THUE XE DAP THU " << i + 1 << endl;
				ds_xedap[i].XuatThongTin();
				cout << "\nTien thue: " << (size_t)ds_xedap[i].TinhTienThueXe();
			}
			system("pause");
		}
		else if (luachon == 5){
			int dem = 0;
			cout << "\n\n\t\t DANH SACH THUE XE MAY LOAI 250 PHAN KHOI\n";
			// duyệt danh sách xe máy
			for (int i = 0; i < m; i++)
			{
				if (ds_xemay[i].Getter_LoaiXe() == 250)
				{
					cout << "\n\tTHONG TIN THUE MAY THU " << ++dem << endl;
					ds_xemay[i].XuatThongTin();
					cout << "\nTien thue: " << (size_t)ds_xemay[i].TinhTienThueXe();
				}				
			}
			system("pause");
		}
		else
		{
			break;
		}
	}
}


int main(){
	XEDAP ds_xedap[100];
	int n = 0;
	XEMAY ds_xemay[100];
	int m = 0;
	Menu(ds_xedap, n, ds_xemay, m);

	system("pause");
	return 0;
}
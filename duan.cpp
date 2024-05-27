#include <iostream>
#include <string>
#include <vector>
using namespace std;

class sinhvien {
private:
    static int stt;
    string hoten, ngaysinh, mssv;
    string lop, sodienthoai;
public:
    friend class lop;

    sinhvien();
    void nhapsvcholop();
    void nhap1sv();
    void xuat1sv();
};

int sinhvien::stt=0;

sinhvien::sinhvien(){
    hoten = "";
    ngaysinh = "";
    mssv = "";
    sodienthoai = "";
}

void sinhvien::nhapsvcholop(){
    cin.ignore();
    cout<<"Nhap ho ten: ";
    getline(cin, hoten);
    cout<<"Nhap ma so sinh vien: "; cin>>mssv;
}

void sinhvien::nhap1sv(){
    cin.ignore();
    cout<<"Nhap ho ten: ";
    getline(cin, hoten);
    cout<<"Nhap ma so sinh vien: "; cin>>mssv;
    cout<<"Nhap lop: "; cin>>lop;
    cout<<"Nhap ngay sinh: "; cin>>ngaysinh;
    cout<<"Nhap so dien thoai: "; cin>>sodienthoai;
    cout << endl;
}

void sinhvien::xuat1sv(){
    cout<<"--------Thong tin sinh vien----------"<<endl;
    cout<<"Ho ten: "<<hoten<<endl;
    cout<<"Ma so sinh vien: "<<mssv<<endl;
    cout<<"Hoc lop: "<<lop<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"So dien thoai: "<<sodienthoai<<endl;
    cout << endl;
}

class lop{
private:
    sinhvien *dssv; 
    int ssv; 
public:
    lop(int ssv);
    ~lop(); 
    void nhaplop();
    void xuatlop();
};

lop::lop(int ssv){
    this->ssv = ssv;
    dssv = new sinhvien[this->ssv];
}

lop::~lop(){
    delete[] dssv;
}

void lop::nhaplop(){
    for(int i=0;i<ssv;i++){
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
        dssv[i].nhapsvcholop();
        cout << endl;
    }
}

void lop::xuatlop(){
    cout<<"Danh sach sinh vien lop: "<<endl;
    cout<<"STT"<<" "<<"Ma so sinh vien"<<" "<<"Ho va ten"<<endl;
    for(int i=0;i<ssv;i++){
        ++sinhvien::stt;
        cout<<sinhvien::stt<<"   "<<dssv[i].mssv<<"    "<<dssv[i].hoten<<endl;
    }
    cout << endl;
}

class hocphan {
	private: 
	string tenhocphan, giaovien;
	int mahocphan, sotinchi;
	
	public:
		hocphan(string ten, string gv, int mahp, int stc) 
		{
			tenhocphan = ten;
			giaovien = gv;
			mahocphan = mahp;
			sotinchi = stc;
		}
		
        void hienthithongtin() {
			cout<<"Ten hoc phan: "<< tenhocphan<<endl;
			cout<<"Giao vien: " <<giaovien<<endl;
			cout<<"Ma hoc phan: "<<mahocphan<<endl;
			cout<<"So tin chi: " <<sotinchi<<endl;
			cout << endl;
		}
};

class Diem {
private:
    struct HocPhan {
        string tenhocphan;
        float diemChuyenCan;
        float diemGiuaKy;
        float diemCuoiKy;
        float heSoChuyenCan;
        float heSoGiuaKy;
        float heSoCuoiKy;

        void nhap() {
            cin.ignore();
            cout<<"Nhap ten mon hoc: ";
            getline(cin, tenhocphan);
            cout<<"Nhap diem chuyen can: ";
            cin>>diemChuyenCan;
            cout<<"Nhap he so chuyen can: ";
            cin>>heSoChuyenCan;
            cout<<"Nhap diem giua ky: ";
            cin>>diemGiuaKy;
            cout<<"Nhap he so giua ky: ";
            cin>>heSoGiuaKy;
            cout<<"Nhap diem cuoi ky: ";
            cin>>diemCuoiKy;
            cout<<"Nhap he so cuoi ky: ";
            cin>>heSoCuoiKy;
        }

        void xuat() {
            cout<<"Ten hoc phan: "<<tenhocphan<<endl;
            cout<<"Diem chuyen can: "<<diemChuyenCan<<endl;
            cout<<"Diem giua ky: "<<diemGiuaKy<<endl;
            cout<<"Diem cuoi ky: "<<diemCuoiKy<<endl;
            float diemTrungBinh = diemChuyenCan * heSoChuyenCan + diemGiuaKy * heSoGiuaKy + diemCuoiKy * heSoCuoiKy;
            cout<<"Diem trung binh: " <<diemTrungBinh<< endl;
        }
    };
    HocPhan *danhsachDiem;
    int sohocphan;
public:
    Diem(int shp);
    ~Diem();
    void nhapDiem();
    void xuatDiem();
};

Diem::Diem(int shp){
    sohocphan = shp;
    danhsachDiem = new HocPhan[sohocphan];
}

Diem::~Diem(){
    delete[] danhsachDiem;
}

void Diem::nhapDiem(){
    for (int i = 0; i < sohocphan; i++) {
        cout << "Nhap ket qua hoc phan thu " << i + 1 << ":" << endl;
        danhsachDiem[i].nhap();
        cout << endl;
    }
}

void Diem::xuatDiem(){
    for (int i = 0; i < sohocphan; i++) {
        cout << "Ket qua hoc phan thu " << i + 1 << ":" << endl;
        danhsachDiem[i].xuat();
        cout << endl;
    }
}

void nhapslhp(int &slhp){
    cout<<"Nhap so luong hoc phan: ";
    cin>>slhp;
}

void nhapsosinhvien(int &ssv){
    cout<<"Nhap so sinh vien cua lop: ";
    cin>>ssv;
}

int main(){
    while(true){
        int choice;
        cout<<"------------------- Quan li sinh vien -------------------"<<endl;
        cout<<"Chon yeu cau muon thuc hien: "<<endl;
        cout<<"Nhap thong tin va xuat thong 1 sinh vien ( Nhap 1 )"<<endl;
        cout<<"Nhap thong tin va xuat danh sach 1 lop ( Nhap 2 )"<<endl;
        cout<<"Nhap thong tin hoc phan va xuat danh sach thong tin hoc phan ( Nhap 3 )"<<endl;
        cout<<"Nhap diem hoc phan va xuat diem hoc phan ( Nhap 4 )"<<endl;
        cout<<"Hay nhap o day: "; cin>>choice;
        switch(choice){
        case 1: {
            sinhvien x;
            x.nhap1sv();
            x.xuat1sv();
            break;
        }
        case 2: {
            int ssv;
            nhapsosinhvien(ssv);
            lop lop23KTMT(ssv);
            lop23KTMT.nhaplop();
            lop23KTMT.xuatlop();
            break;
        }
        case 3: {
            vector<hocphan> Danhsachhocphan; // khai bao 1 vector de chua danh sach doi tuong hocphan
            int soluonghocphan;
            nhapslhp(soluonghocphan);
			cin.ignore();
            for(int i = 0; i < soluonghocphan; i++) // vong lap de nhap thong tin cho tung mon hoc
            {
                string tenhocphan; // khai bao cac bien de luu cac ten , giao vien , ma hoc phan , so tin chi cho moi lan lap 
                string giaovien;
                int mahocphan;
                int sotinchi;
                cout <<"Nhap thong tin hoc phan " << i+1 << ":" << endl;
                cout <<"Nhap ten hoc phan: "; // nhap chi tiet cho tung mon 
                getline(cin,tenhocphan);
                cout <<"Nhap ten giao vien: "; 
                getline(cin,giaovien);
                cout <<"Nhap ma hoc phan: "; cin >> mahocphan;
                cout <<"Nhap so tin chi: "; cin >> sotinchi;
                cin.ignore();
                
                Danhsachhocphan.push_back(hocphan(tenhocphan,giaovien,mahocphan,sotinchi)); // tao 1 doi tuong hocphan moi voi ... r them cac doi tuong do vao cuoi vector Danhsachhocphan.
                cout << endl;
            }
            cout << endl;
            cout <<"Danh sach cac hoc phan da nhap: "<< endl;
            for(auto &hocphan : Danhsachhocphan) // su dung vong lap for-each de duyet qua tung doi tuong hocphan trong vector Danhsachhocphan
            { 
                hocphan.hienthithongtin(); 
            }
            break;
        }
        case 4: {
            int soluonghocphan;
            nhapslhp(soluonghocphan);
            Diem diem(soluonghocphan);
            diem.nhapDiem();
            cout << endl;
            diem.xuatDiem();
            break;
        }
        default:
            cout<<"Lua chon khong hop le ! Moi ban chon lai."<<endl;
        }
    }
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

class sinhvien
{
	private:
		string MaSV;
		string HoTen;
		string GioiTinh;
		int NamSinh;
		string MaLop;
	public:
		void NhapSV();
		void XuatSV();
		void SuaSV();
		string Getter_MaLop();
		string Getter_HoTen();
		sinhvien();
		~sinhvien();
};

string sinhvien::Getter_MaLop()
{
	return MaLop;
}
string sinhvien::Getter_HoTen()
{
	return HoTen;
}
void sinhvien::NhapSV()
{
	while (getchar() != '\n');
	cout << "\nNhap ma sinh vien: ";
	getline(cin, MaSV);
	while (getchar() != '\n');
	cout << "\nNhap ho ten: ";
	getline(cin, HoTen);
	cout << "\nNhap nam sinh: ";
	cin >> NamSinh;
	while (getchar() != '\n');
	cout << "\nNhap gioi tinh: ";
	getline(cin, GioiTinh);
	while (getchar() != '\n');
	cout << "\nNhap ma lop: ";
	getline(cin,MaLop );
}
void sinhvien::XuatSV()
{
	cout << "\nMa sinh vien: "<<MaSV;
	cout << "\nHo ten: " << HoTen;
	cout << "\nNam sinh: " << NamSinh;
	cout << "\nGioi tinh: " << GioiTinh;
	cout << "\nMa lop: " << MaLop;
}
void sinhvien::SuaSV()
{
	string MaSVtam;
	string HoTentam;
	string GioiTinhtam;
	int NamSinhtam;
	string MaLoptam;
	cout <<"\nThong tin sinh vien"<<endl;
	cout << "\nMa sinh vien: "<<MaSV;
	cout << "\nHo ten: " << HoTen;
	cout << "\nNam sinh: " << NamSinh;
	cout << "\nGioi tinh: " << GioiTinh;
	cout << "\nMa lop: " << MaLop;
	cout<< "HIEU CHINH THONG TIN";
	while (getchar() != '\n');
	cout << "\nNhap ma sinh vien: ";
	getline(cin, MaSVtam);
	while (getchar() != '\n');
	cout << "\nNhap ho ten: ";
	getline(cin, HoTentam);
	cout << "\nNhap nam sinh: ";
	cin >> NamSinhtam;
	while (getchar() != '\n');
	cout << "\nNhap gioi tinh: ";
	getline(cin, GioiTinhtam);
	while (getchar() != '\n');
	cout << "\nNhap ma lop: ";
	getline(cin,MaLoptam );
	MaSV = MaSVtam;
	HoTen = HoTentam;
	GioiTinh = GioiTinhtam;
	NamSinh = NamSinhtam;
	MaLop = MaLoptam;
}
sinhvien::sinhvien()
{
}
sinhvien::~sinhvien()
{
}
class QuanLySV
{
	private:
		int n; //soluongsinvien
		sinhvien *sv , temp;
	public:
		void NhapDS();
		bool TimSV_Ten(int &vitri);
		void XuatDS();
		void XoaSV(int vitri);
		QuanLySV();
		~QuanLySV();
		int Getter_n();
		sinhvien Getter_sv();
};
sinhvien QuanLySV::Getter_sv()
{
	return *sv;
}
int QuanLySV::Getter_n()
{
	return n;
}
void QuanLySV::NhapDS()
{
	int a;
	cout<<"\nSo luong sinh vien:";
	cin>>a;
	int j= n;
	n=n+a;
	sv= new sinhvien[n];
	for(int i=j;i<n;i++)
	{
		cout<<"\nNhap thong tin sinh vien thu "<<i+1<<endl;
		sv[i].NhapSV();
	}
}
bool QuanLySV::TimSV_Ten(int &vitri)
{
	string tam;
	cout<<"\nNhap ten sinh vien can tim: ";
	while (getchar() != '\n');
	getline(cin, tam);
	for(int i=0;i<n;i++)
	{
		if(tam ==sv[i].Getter_HoTen())
		{
			cout<<"\nThong tin sinh vien can tim: "<< endl;
			sv[i].XuatSV();
			return true;
			vitri=i;
			break;
		}
	}
	return false;
}
void QuanLySV::XoaSV(int vitri)
{
	int j = n;
	temp=sv[vitri]; 
	sv[vitri]=sv[n-1];
	n=n-1;
	sv = new sinhvien[n];
	fflush(stdin);
	cout<<"\nDanh sach sinh vien sau khi xoa: "<<endl;
	for(int i=j;i<n;i++)
	{
		cout<<"\nThong tin sinh vien thu "<<i+1<<endl;
		sv[i].XuatSV();
	}
}
void QuanLySV::XuatDS()
{
	cout<<"\nDanh sach sinh vien: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\nThong tin sinh vien thu "<<i+1<<endl;
		sv[i].XuatSV();
	}
}
QuanLySV::QuanLySV()
{
}
QuanLySV::~QuanLySV()
{
}

class Lop
{
	private:
		string malop;
		string TenLop;
		string GVCN;
		int SiSo;
		QuanLySV k;
	public:
		void TaoLopMoi();
		void XemTTLop();
		void XemDSLop();
		Lop()
		{
		}
		~Lop()
		{
		}
};
void Lop::TaoLopMoi()
{
	while (getchar() != '\n');
	cout << "\nNhap ma lop: ";
	getline(cin, malop);
	while (getchar() != '\n');
	cout << "\nNhap ten lop: ";
	getline(cin, TenLop);
	while (getchar() != '\n');
	cout << "\nNhap ten giao vien chu nhiem: ";
	getline(cin, GVCN);
	cout<<"\nNhap si so lop:";
	cin>>SiSo;
}
void Lop::XemTTLop()
{
	cout<<"\nThong tin lop: "<<endl;
	cout<<"\nMa lop: "<<malop;
	cout<<"\nTen lop: "<<TenLop;
	cout<<"\nGiao vien chu nhiem: "<<GVCN;
	cout<<"\nSi so: "<<SiSo<<endl;
}
void Lop::XemDSLop()
{
	cout<<"\nDanh sach lop: ";
	k.XuatDS();
}

void Menu(QuanLySV t, Lop danh_sach_Lop[])
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t\t==========GIOI HAN QUYEN NANG============\n";
		cout << "\n1. Nhap thong tin sinh vien";
		cout << "\n2. Tim sinh vien bang ten";
		cout << "\n3. Xem thong tin sinh vien";
		cout << "\n4. Xoa sinh vien";
		cout << "\n5. Sua thong tin sinh vien";
		cout << "\n6. Xuat danh sach sinh vien";
		cout << "\n7. Tao lop moi";
		cout << "\n8. Xem thong tin lop";
		cout << "\n9. Xem danh sach lop";
		cout << "\n0. Ket thuc chuong trinh";
		cout << "\n\t\t==========END============\n";

		cout << "\n\nNhap lua chon: ";
		cin >> luachon;

		
	
		if (luachon == 1)
		{
			cout << "\n\n\t\t NHAP THONG TIN SINH VIEN\n";
			t.NhapDS();
		}
		else if (luachon == 0)
		{
			break;
		}
		/*else if (luachon == 2)
		{
			NhanVienGiaoHang nv_giao_hang;
			cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG\n";
			nv_giao_hang.nhapthongtin();
			ds_nv_giao_hang[n] = nv_giao_hang;
			n++;
		}
		else if (luachon == 3)
		{
			NhanVienXeOm nv_xe_om;
			cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN XE OM\n";
			nv_xe_om.nhapthongtin();
			ds_nv_xe_om[l] = nv_xe_om;
			l++;
		}
		else if (luachon == 4)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC\n";
			for (int i = 0; i < m; i++)
			{
				cout << "\nTHONG TIN NHAN VIEN SUA ONG NUOC THU " << i + 1;
				ds_nv_sua_ong_nuoc[i].xuatthongtin();
			}
			cout << "\n\tTONG TIEN LUONG CUA NHAN VIEN SUA ONG NUOC: " << (size_t)tong_tien_luong_nv_sua_ong_nuoc(ds_nv_sua_ong_nuoc, m);
			cout << endl;
			system("pause");
		}
		else if (luachon == 5)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN SUA GIAO HANG\n";
			for (int i = 0; i < n; i++)
			{
				cout << "\nTHONG TIN NHAN VIEN GIAO HANG THU " << i + 1;
				ds_nv_giao_hang[i].xuatthongtin();
			}
			cout << "\n\tTONG TIEN LUONG CUA NHAN VIEN GIAO HANG: " << (size_t)tong_tien_luong_nv_giao_hang(ds_nv_giao_hang, n);
			cout << endl;
			system("pause");
		}
		else if (luachon == 6)
		{
			cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM\n";
			for (int i = 0; i < l; i++)
			{
				cout << "\nTHONG TIN NHAN VIEN XE OM THU " << i + 1;
				ds_nv_xe_om[i].xuatthongtin();
			}
			cout << "\n\tTONG TIEN LUONG CUA NHAN VIEN XE OM: " << (size_t)tong_tien_luong_nv_xe_om(ds_nv_xe_om, l);
			cout << endl;
			system("pause");
		}
		else if (luachon == 7)
		{
			cout << "\n\t\tTONG TIEN LUONG CUA BA LOAI NHAn VIEN: " << (size_t)(tong_tien_luong_nv_sua_ong_nuoc(ds_nv_sua_ong_nuoc, m) + tong_tien_luong_nv_giao_hang(ds_nv_giao_hang, n) + tong_tien_luong_nv_xe_om(ds_nv_xe_om, l));
			system("pause"); 
		}
		if (luachon < 1 || luachon>7)
		{
			cout << "\n\tLUA CHON KHONG HOP LE. VUI LONG KIEM TRA LAI.\n\n" << endl;
			system("pause");
		}*/
		
	}
}

int main()
{
	QuanLySV t;
	Lop x;
	Menu(t,x);
	system("pause");
	reutrn 0;
}




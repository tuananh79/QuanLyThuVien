#include<iostream>
#include<fstream>
#include<math.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<string.h>
#include<iomanip>
#define MAXNODE 5000
const int SoNgayMuonMax = 7;
using namespace std;
const int MienGiaTriNgauNhien = 30000;
const int MaxNodes = 10000;
static bool* MangRandom = new bool[MienGiaTriNgauNhien];
int SoLuongDocGia=0;
int BoxMenu[4]={3,48,6,17}; //toa do hop menu x1,x2,y1,y2
int BoxMain[4]={53,158,6,32};
int BoxTB[4]={3,48,21,32};
int BoxHuongDan[4]={2,158,35,40};
const int MaxBox=BoxMain[2]+3+19; // so luong toi da dong cua Boxmain
int toadoX =55;
int toadoY=5;
int toadoX1 =52;
int toadoY1=4;
struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

struct DanhMucSach
{
	string MaSach;
	int TrangThai;// 0: cho muon dc, 1: da cho muon
	string ViTri;
};
struct NODE_LIST
{
	DanhMucSach data;
	struct NODE_LIST* next;
};
struct LIST_DMS
{
	NODE_LIST* First;
	NODE_LIST* Last;
};
struct DauSach
{
	string MaDauSach;
	string TenSach;
	int SoTrang;
	string TacGia;
	int NamXuatBan;
	string TheLoai;
	int SoLuongSach;
	int SoLanMuon;
	LIST_DMS List_DMS;
};	
struct MCONTRO
{
	int n;
	DauSach* nDS[MaxNodes]; // nodes là mãng con tro
};

struct MuonTra 
{
	string MaSach;
	Date NgayMuon;
	Date NgayTra;
	int TrangThai; // trang thai =0 la sach dang muon (chua tra), =1 la da tra
};
struct NODE_LIST_MUONTRA
{
	MuonTra data;
	struct NODE_LIST_MUONTRA* next;

};
struct LIST_MUONTRA
{
	NODE_LIST_MUONTRA* First;
	NODE_LIST_MUONTRA* Last;
};
struct TheDocGia
{
	int MaThe; //DoubleList_MuonTra
	string Ho;
	string Ten;
	string Phai;
	int TrangThai; //trang thai cua the 1 : la dang hoat dong , 0: la bi khoa
	int SoLuongSachDangMuon;
	LIST_MUONTRA List_MuonTra;
};
struct NODE_TREE
{
	TheDocGia thedocgia;
	NODE_TREE* left;
	NODE_TREE* right;
};
typedef NODE_TREE* TREE_TDG;


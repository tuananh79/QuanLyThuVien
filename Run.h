#include"KhaiBao.h"
#include"DoHoa.h"
#include"XuLy.h"
#include"XuLyNhapXuat.h"
#include"XuLyDeBai.h"
#include"ClearMemory.h";
#include"SaveFile.h"
#include"LoadFile.h"

void SetUp()
{
	LOGO();
	gotoXY(70,2);
	HCNText(1, 3, 159, 39, 248);
	for (int i = 1; i < 160; i++)
	{
		SetBGColor(248);
		gotoXY(i, 33);
		cout<<" ";
	}
	gotoXY(3,20);  
	textcolor(244);
	SetBGColor(7);
	cout<<"Thong bao\n";
	for(int i=4;i<33;i++)
	{
		SetBGColor(248);
		gotoXY(50,i);
		cout<<" ";
	}
	gotoXY(1,19);
	SetBGColor(248);
	cout<<"                                                 ";
	HighLight();
	gotoXY(BoxHuongDan[0]+1,BoxHuongDan[2]-1);
	cout<<"Huong dan";
	Normal();
	HDMainMenu();
}
char mainMENU[2][100]= {
"  1. Sach     ",
"  2. Doc gia  ",
};
char MENUSach[5][100]={
"1. Nhap dau sach",
"2. In danh sach dau sach theo the loai",
"3. Tim sach",
"4. Sach duoc muon nhieu nhat",
"5. Hieu chinh thong tin sach"
};

char MENUDocGia[4][100]={
"1. The doc gia",
"2. Muon sach",
"3. Tra sach",
"4. Danh sach doc gia muon sach qua han"
};
char MENUTheDocGia[4][100]={
"1. Them the doc gia",
"2. Xem thong tin doc gia",
"3. Hieu chinh the doc gia",
"4. Xoa the doc gia"
};
void inmanhinhmenu(char menu[][100],int so_item)
{
	int x=BoxMenu[0]+5;
	int y=BoxMenu[2];
	for (int i = 0; i < so_item; i++)
	{
		gotoXY(x,y++);
		cout << menu[i];
	}
}
int Menu(char menu[][100],int so_item) 
{	
	int chon = 0;
	int i;  
	for (i = 0; i < so_item; i++)
	{
		gotoXY(BoxMenu[0]+5, BoxMenu[2] + i);
		cout << menu[i];
	}
	// thanh sang nam o dau tien
	HighLight();
	gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
	cout << menu[chon];
	Normal();
	char kytu;
	
	do {
		kytu = getch();
		if (kytu == 224) kytu = getch();
		switch (kytu) {
		case 72:if (chon + 1 > 1)//len
			{
				Normal();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				chon--;
				HighLight();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				Normal();
			}
				   break;
		case 80:if (chon + 1 < so_item)//xuong
			{
				Normal();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				chon++;
				HighLight();
				gotoXY(BoxMenu[0]+5, BoxMenu[2] + chon);
				cout << menu[chon];
				Normal();
			}
					break;
		case 13: //enter
			{
				XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
				return chon + 1;
			}
		case 27://esc
			{
				return 0;
			}
		}  // end switch
	} while (1);
}	

void RunMENU(TREE_TDG &t, MCONTRO &DauS )
{
	do
	{		ShowCur(0);
			XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
			int chon=Menu(mainMENU,2);
			switch(chon)
			{
				case 1:// sach
					{
						int tam=1;
						do
						{
							int chon1=Menu(MENUSach,5);
							switch(chon1)
							{
								case 1:
									{
										inmanhinhmenu(MENUSach,5);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										ThemMotDauSach(DauS,toadoX,toadoY);
										HDMainMenu();
										break;
									}
								case 2:
									{
										inmanhinhmenu(MENUSach,5);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										XuatDSTheoTungTheLoai(DauS,54,5);
										HDMainMenu();
										break;
									}
								case 3:
									{
										inmanhinhmenu(MENUSach,5);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										TimSach(DauS);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										HDMainMenu();
										break;
									}
								case 4:
									{	inmanhinhmenu(MENUSach,5);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										Xuat10SachCoSoLuongMuonMax(DauS, 54, 5);
										HDMainMenu();
										break;
									}
								case 5:
									{		inmanhinhmenu(MENUSach,5);
											SuaThongTinSach(DauS);
											XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
											HDMainMenu();
											break;
									}
								case 0: {
									tam=0;break;
								}
							}
						}while(tam==1);break;
					}
				case 2://doc gia
					{
						int tam=1;
						do
						{
							int chon2=Menu(MENUDocGia,4);
							switch(chon2)
							{
								case 1:
									{
										int tam=1;
										do
										{
											int chon3=Menu(MENUTheDocGia,4);
											switch(chon3)
											{
												case 1: {
													inmanhinhmenu(MENUTheDocGia,4);
													XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
													HDThemDocGia();
													int i=1;
													do
													{
														ThemTheDocGia(t,Random(),i);
													}while(i==1);
													XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
													HDMainMenu();
													break;
												}
												case 2:
												{
													inmanhinhmenu(MENUTheDocGia,4);
													XemFullTheDocGia(t,DauS);
													XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
													HDMainMenu();
													break;
												} 
												case 3:
												{
													inmanhinhmenu(MENUTheDocGia,4);
													SuaThongTinDocGia(t);
													XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
													HDMainMenu();
													break;
												}
												case 4:
												{
													inmanhinhmenu(MENUTheDocGia,4);
													XoaDocGia(t);
													XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
													HDMainMenu();
													break;
												}
												case 0: 
												{
													XoaManHinh(BoxMenu[0],BoxMenu[1],BoxMenu[2],BoxMenu[3]);
													tam=0;break;
												}
										}
										}while(tam==1);break;
									}
								case 2:
									{
										inmanhinhmenu(MENUDocGia,4);
										MuonSach(t, DauS);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										HDMainMenu();
										break;
									}
								case 3:
									{
										inmanhinhmenu(MENUDocGia,4);
										TraSach(t,DauS);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										HDMainMenu();
										break;
									}
								case 4:
									{
										inmanhinhmenu(MENUDocGia,4);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										HDXemDocGiaMuonSachQuaHan();
										DanhSachDocGiaMuonSachQuaHan( t);
										XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
										HDMainMenu();
										break;
									}
								case 0:tam=0 ;break;
							}
						}while(tam==1);break;
					} 
				case 0: 
				{   
					Save(t,DauS);
					DeleteMemory(t, DauS);
					return;
				}
			} 
	}while(1);
}
void Khoitao(MCONTRO &DauS, TREE_TDG &t)
{
	resizeConsole(1280,1024); 
	DauS.n = 0;
	t = NULL;
	Load(DauS, t);
	Date NgayHienTai;
	LayNgayHienTai(NgayHienTai);
	KiemTraQuaHan(t, NgayHienTai);

}


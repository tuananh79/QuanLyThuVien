void gotoXY(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
} 
int whereX( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int whereY( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void textcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Normal () {
	textcolor(0);
	SetBGColor(7);
}
void LOGO () {
	textcolor(44);
	SetBGColor(11);
}
void HighLight () {
	textcolor(0);
	SetBGColor(59);
}
void Error () {
	textcolor(12);
	SetBGColor(7);
}
void HeadTable()
{
	textcolor(228);
	SetBGColor(186);
}
void BodyTable()
{
	textcolor(0);
	SetBGColor(238);
}
void HCNText(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		SetBGColor(mau);
		cout << " ";
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		SetBGColor(mau);
		cout << " ";
		
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		SetBGColor(mau);
		cout << " ";
		
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		SetBGColor(mau);
		cout << " ";
	}
}
void XoaManHinhTimKiem()
{
	Normal();
	for(int i=9;i<32;i++)
	{
		gotoXY(BoxMain[0],i);
		cout<<"                                                                                                        ";
	}
}
void XoaManHinh(int X1, int X2, int Y1, int Y2)
{
	Normal();
	int x=X2-X1;
	for (int i = Y1; i < Y2; i++)
	{
		gotoXY(X1,i);
		cout<<string(x,' ');;
	}
}
string CanDeuChuoi(string str, int ChieuRong)
{
	if (str.empty())
	{
		return str;
	}
	else if (str.length() > ChieuRong)
	{
		return str;
	}
	else if((ChieuRong - str.length()) % 2==0)
	{
		return string((ChieuRong - str.length()) / 2, ' ') + str + string((ChieuRong - str.length()) / 2, ' ');
	}
	else if((ChieuRong - str.length()) % 2!=0)
	{
		return string((ChieuRong - str.length()) / 2, ' ') + str + string((ChieuRong - str.length()) / 2+1, ' ');
	}
}
void GiaoDienThemDocGia()
{
	gotoXY(70, 8);
	cout << "Ma The:";
	gotoXY(70, 11);
	cout << "Nhap Ho:";
	gotoXY(70, 14);
	cout << "Nhap Ten:";
	gotoXY(70, 17);
	cout << "Chon Phai:";
	gotoXY(100, 17);
	cout << "Nam";
	gotoXY(115,  17);
	cout << "Nu";
	gotoXY(100,  20);
	cout << "Dang Ki";
	gotoXY(115,  20);
	cout << "Thoat";

}
void ThongBao(char *s)
{
	gotoXY(BoxTB[0],BoxTB[2]);
	Error();
	cout<<CanDeuChuoi(s,45);
	getch();
	XoaManHinh(BoxTB[0], BoxTB[1], BoxTB[2],BoxTB[3]);
	Normal();
}
void GiaoDienXuatTheDocGia(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 84;
	
	HeadTable();
	gotoXY(toadoX + 1, toadoY);
	cout<<"                                                                                    ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<" Ma The                  Ho va Ten                  Phai    Trang Thai    So Sach   ";
	gotoXY(toadoX + 1, toadoY + 2);
	cout<<"                                                                         Dang Muon  ";
	BodyTable();
	//gach |
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 10 || i == toadoX + 50 || i == toadoX + 60 || i == toadoX + 72)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;// dau |
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	// gach -
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 10 || i == toadoX + 50 || i == toadoX + 60 || i == toadoX + 72)
				cout << (char)197; 
			else
				cout << (char)196; 
		}
	}
	Normal();
}
void GiaoDienTimkiemTheDocGia()
{
	Normal();
	gotoXY(BoxMain[0]+10,BoxMain[2]);
	textcolor(3);
	cout<<"Search : ";
	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable();
	cout <<"     Ma Doc Gia     "<<char(179)<<"                     Ho Ten                  ";
	Normal();
}
void GiaoDienXuatDanhSachMuon(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;
	
	HeadTable();
	gotoXY(toadoX+1,toadoY);
	cout<<"                                                                                                   ";
	gotoXY(toadoX + 1, toadoY + 1);
	cout<<"      Ma Sach                       Ten Sach                      Ngay Muon          Trang Thai    ";
	gotoXY(toadoX+1,toadoY+2);
	cout<<"                                                                                                   ";
	Normal();


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 20 || i == toadoX + 61 || i == toadoX + 81)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j < toadoY + 3)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179; // |
			}
		}
		else
		{
			for (int j = toadoY+3; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				BodyTable();
				cout<<" ";
			}
		}
	}
	// gach ngang
	for (int j = 5; j < chieucao; j = j + 2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 20 || i == toadoX + 61 || i == toadoX + 81 )
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}
void GiaoDienTimkiemSach()
{
	Normal();
	gotoXY(BoxMain[0]+10,BoxMain[2]);
	textcolor(3);
	cout<<"Search : ";
	gotoXY(BoxMain[0]+10,BoxMain[2]+2);
	HeadTable();
	cout <<"     Ma Sach        "<<char(179)<<"                  Ten Sach                   ";
	Normal();
}
void GiaoDienMuonSach()
{
	gotoXY(BoxMain[0]+5,BoxMain[2]);
	cout<< "Ma Sach: ";
	gotoXY(BoxMain[0]+5,BoxMain[2]+3);
	cout<< "Ten Sach: ";
	gotoXY(BoxMain[0]+5,BoxMain[2]+6);
	cout<< "Tac Gia: ";
	gotoXY(BoxMain[0]+5,BoxMain[2]+9);
	cout<< "Ngay / Thang / Nam  :";
	gotoXY(BoxMain[0]+30,BoxMain[2]+12);
	cout<< "Xac Nhan";
	gotoXY(BoxMain[0]+45,BoxMain[2]+12);
	cout<< "Thoat";
}
void VeKhung(int x,int y,int width,int height,bool draw)
{if (draw){
		//ve truoc 4 goc
		//ve goc tren ben trai
		gotoXY(x, y);
		cout << char(218);
		//ve goc tren ben phai
		gotoXY(x + width, y);
		cout << char(191);
		//ve goc duoi ben trai
		gotoXY(x, y + height);
		cout << char(192);
		//ve goc duoi ben phai
		gotoXY(x + width, y + height);
		cout << char(217);

		//ve chieu ngang ben tren
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << char(196);
		}
		//ve chieu ngang ben duoi 
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+height);
			cout << char(196);
		}
		//ve chieu doc ben trai
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << char(179);
		}
		//ve chieu doc ben phai 
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+width, i);
			cout << char(179);
		}
	}
	else {
		gotoXY(x, y);
		cout << " ";
		
		gotoXY(x + width, y);
		cout << " ";
		
		gotoXY(x, y + height);
		cout << " ";
		
		gotoXY(x + width, y + height);
		cout << " ";

		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << " ";
		}
		
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y + height);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x + width, i);
			cout << " ";
		}

	}
}
void VeKhung1(int x,int y,int width,int height,bool draw)
{if (draw){
		//ve truoc 4 goc
		//ve goc tren ben trai
		gotoXY(x, y);
		cout << char(218);
		//ve goc tren ben phai
		gotoXY(x + width, y);
		cout << char(191);
		//ve goc duoi ben trai
		gotoXY(x, y + height);
		cout << char(192);
		//ve goc duoi ben phai
		gotoXY(x + width, y + height);
		cout << char(217);

		//ve chieu ngang ben tren
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << char(196);
		}
		//ve chieu ngang ben duoi 
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+height);
			cout << char(196);
		}
		//ve chieu doc ben trai
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << char(179);
		}
		//cot 1
		gotoXY(x, y+5);
		cout << char(195);
		gotoXY(x+80, y+5);
		cout << char(180);
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+5);
			cout << char(196);
		}
		//ve chieu doc ben phai 
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+width, i);
			cout << char(179);
		}
	}
	else {
		gotoXY(x, y);
		cout << " ";
		
		gotoXY(x + width, y);
		cout << " ";
		
		gotoXY(x, y + height);
		cout << " ";
		
		gotoXY(x + width, y + height);
		cout << " ";

		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << " ";
		}
		
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y + height);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x + width, i);
			cout << " ";
		}

	}
}
void VeKhung2(int x,int y,int width,int height,bool draw)
{
		if (draw){
	
		//ve truoc 4 goc
		//ve goc tren ben trai
		gotoXY(x, y);
		cout << char(218);
		//ve goc tren ben phai
		gotoXY(x + width, y);
		cout << char(191);
		//ve goc duoi ben trai
		gotoXY(x, y + height);
		cout << char(192);
		//ve goc duoi ben phai
		gotoXY(x + width, y + height);
		cout << char(217);
		//ve chieu ngang ben tren
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << char(196);
		}
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+3);
			cout << char(196);
		}
		
		//ve chieu ngang ben duoi 
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+height);
			cout << char(196);
		}
		//ve chieu doc ben trai
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << char(179);
		}
		//ve chieu doc ben phai 
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+width, i);
			cout << char(179);
		}
		//cot 1
			gotoXY(x+12,y);
			cout<<char(194);
			gotoXY(x+12,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+12, i);
			cout << char(179);
		}
		//cot 2
			gotoXY(x+35,y);
			cout<<char(194);
			gotoXY(x+35,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+35, i);
			cout << char(179);
		}
		//cot 3
		gotoXY(x+42,y);
			cout<<char(194);
			gotoXY(x+42,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+42, i);
			cout << char(179);
		}
		//cot 4
		gotoXY(x+69,y);
			cout<<char(194);
			gotoXY(x+69,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+69, i);
			cout << char(179);
		}
		//cot 5
		gotoXY(x+80,y);
			cout<<char(194);
			gotoXY(x+80,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+80, i);
			cout << char(179);
		}
		//cot 6
		gotoXY(x+92,y);
			cout<<char(194);
			gotoXY(x+92,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+92, i);
			cout << char(179);
		}
	}


	else {
		gotoXY(x, y);
		cout << " ";
		
		gotoXY(x + width, y);
		cout << " ";
		
		gotoXY(x, y + height);
		cout << " ";
		
		gotoXY(x + width, y + height);
		cout << " ";

		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << " ";
		}
		
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y + height);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x + width, i);
			cout << " ";
		}

	}
}
void VeKhung3(int x,int y,int width,int height,bool draw)
{
		if (draw){
	
		//ve truoc 4 goc
		//ve goc tren ben trai
		gotoXY(x, y);
		cout << char(218);
		//ve goc tren ben phai
		gotoXY(x + width, y);
		cout << char(191);
		//ve goc duoi ben trai
		gotoXY(x, y + height);
		cout << char(192);
		//ve goc duoi ben phai
		gotoXY(x + width, y + height);
		cout << char(217);
		//ve chieu ngang ben tren
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << char(196);
		}
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+3);
			cout << char(196);
		}
		
		//ve chieu ngang ben duoi 
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y+height);
			cout << char(196);
		}
		//ve chieu doc ben trai
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << char(179);
		}
		//ve chieu doc ben phai 
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+width, i);
			cout << char(179);
		}
		//cot 1
			gotoXY(x+12,y);
			cout<<char(194);
			gotoXY(x+12,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+12, i);
			cout << char(179);
		}
		//cot 2
			gotoXY(x+50,y);
			cout<<char(194);
			gotoXY(x+50,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+50, i);
			cout << char(179);
		}
		//cot 3
		gotoXY(x+60,y);
			cout<<char(194);
			gotoXY(x+60,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+60, i);
			cout << char(179);
		}
		//cot 4
		gotoXY(x+92,y);
			cout<<char(194);
			gotoXY(x+92,y+height);
			cout<<char(193);
			for (int i = y + 1; i < (y + height); i++){
			gotoXY(x+92, i);
			cout << char(179);
		}

	}


	else {
		gotoXY(x, y);
		cout << " ";
		
		gotoXY(x + width, y);
		cout << " ";
		
		gotoXY(x, y + height);
		cout << " ";
		
		gotoXY(x + width, y + height);
		cout << " ";

		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y);
			cout << " ";
		}
		
		for (int i = x + 1; i < (x + width); i++){
			gotoXY(i, y + height);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x, i);
			cout << " ";
		}
		
		for (int i = y + 1; i < (y + height); i++){
			gotoXY(x + width, i);
			cout << " ";
		}

	}
}
void GiaoDienInTheoTheLoai()
{
	VeKhung1(64,8,80,20,true);
	gotoXY(100,11);
	cout<<"THE LOAI";
	
}
void GiaoDienThemDauSach(int toadoX, int toadoY)
{
	gotoXY(toadoX, toadoY + 1);
	cout << "Ma Dau Sach:";
	gotoXY(toadoX, toadoY + 4);
	cout << "Ten Sach:";
	gotoXY(toadoX, toadoY + 7);
	cout << "So Trang:";
	gotoXY(toadoX, toadoY + 10);
	cout << "Tac Gia:";
	gotoXY(toadoX, toadoY + 13);
	cout << "Nam Xuat Ban:";
	gotoXY(toadoX, toadoY + 16);
	cout << "The Loai:";
	gotoXY(toadoX, toadoY + 19);
	cout << "Vi Tri:";
	gotoXY(toadoX, toadoY + 22);
	cout << "So Luong:";
	gotoXY(toadoX + 30, toadoY + 25);
	cout << "Xac Nhan";
	gotoXY(toadoX + 60, toadoY + 25);
	cout << "Cancel";
}
void GiaoDienThemDauSach1(int toadoX, int toadoY)
{
	gotoXY(toadoX, toadoY + 1);
	cout << "Ma Dau Sach:";
	gotoXY(toadoX, toadoY + 4);
	cout << "Ten Sach:";
	gotoXY(toadoX, toadoY + 7);
	cout << "So Trang:";
	gotoXY(toadoX, toadoY + 10);
	cout << "Tac Gia:";
	gotoXY(toadoX, toadoY + 13);
	cout << "Nam Xuat Ban:";
	gotoXY(toadoX, toadoY + 16);
	cout << "The Loai:";
	gotoXY(toadoX, toadoY + 19);
	cout << "Vi Tri:";
	gotoXY(toadoX, toadoY + 22);
	cout << "So Luong:";
}
void GiaoDenXuatDauSachTheoTheLoai(int toadoX1,int toadoY1)
{
	
	VeKhung2(toadoX1,toadoY1,101,26,true);
	gotoXY(toadoX1+4,toadoY1+1);
	cout<<"IBSN";
	gotoXY(toadoX1+18,toadoY1+1);
	cout<<"Ten Sach";
	gotoXY(toadoX1+38,toadoY1+1);
	cout<<"So";
	gotoXY(toadoX1+37,toadoY1+2);
	cout<<"Trang";
	gotoXY(toadoX1+52,toadoY1+1);
	cout<<"Tac Gia";
	gotoXY(toadoX1+74,toadoY1+1);
	cout<<"Nam ";
	gotoXY(toadoX1+84,toadoY1+1);
	cout<<"Vi Tri ";
	gotoXY(toadoX1+93,toadoY1+1);
	cout<<"So Luong";
	gotoXY(toadoX1+50,toadoY1+27);
	cout<<"<<   >>";

}
void GiaoDienXuat10Sach(int toadoX,int toadoY)
{
	VeKhung3(toadoX1,toadoY1,106,26,true);
	gotoXY(toadoX1+4,toadoY1+1);
	cout<<"IBSN";
	gotoXY(toadoX1+18,toadoY1+1);
	cout<<"Ten Sach";
	gotoXY(toadoX1+52,toadoY1+1);
	cout<<"So Trang";
	gotoXY(toadoX1+72,toadoY1+1);
	cout<<"Tac Gia";
	gotoXY(toadoX1+94,toadoY1+1);
	cout<<"So Lan Muon ";
	
}
void GiaoDienTimSach(int toadoX, int toadoY, int n)
{
	int x=BoxMain[0]+5;
	int y= BoxMain[2]-2;
	int chieucao =  n*2;
	int chieudai = 60;
	Normal();
	gotoXY(x+10,y+toadoY+chieucao/2-4);
	cout<<"<<";
	gotoXY(x+80,y+toadoY+chieucao/2-4);
	cout<<">>";
	HeadTable();
	gotoXY(toadoX + 1, toadoY );
	cout<<"        Ma sach              trang thai          vi tri     ";
	BodyTable();
	
	for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
	{
		if (i == toadoX + 26 || i == toadoX + 43 )
		{
			for (int j = toadoY; j < chieucao + toadoY ; j++)
			{
				gotoXY(i, j);
				if (j < toadoY +1)
				{
					HeadTable();
				}
				else
					BodyTable();
				cout << (char)179;
			}
		}
		else
		{
			for (int j = toadoY+1; j < chieucao + toadoY ; j++)
			{
				gotoXY(i, j);
				cout<<" ";
			}
		}
	}
	for (int j = 2; j < chieucao; j +=2)
	{
		for (int i = toadoX+1; i < chieudai + toadoX+1; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX + 26 || i == toadoX +43 )
				cout << (char)197;
			else
				cout << (char)196;
		}
	}
}
void XoaManHinhTimKiemSach()
{
	Normal();
	for(int i=BoxMain[2]+3;i<BoxMain[3];i++)
	{
		gotoXY(BoxMain[0]+6,i);
		cout<<"                                                                                  ";
	}
}
void HDMainMenu()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter : de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc : de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut mui ten len xuong : de dieu khien thanh sang";
}
void HDThemDocGia()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter : de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten len, xuong, trai, phai : de dieu khien thanh sang";
}
void HDXemThongTinDocGia()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter : de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc : de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+3);
	cout<<"Nut mui ten len, xuong : de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nhap ma doc gia de Search";
}
void HDXemThongTinSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter : de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc : de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+3);
	cout<<"Nut mui ten len, xuong : de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nhap ten sach de Search";
}
void HDMuonSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Buoc 1: Nhap ma sach can muon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Buoc 2: Nhap ngay thang nam";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Enter : de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+3);
	cout<<"Nut Esc : de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+4);
	cout<<"Nut mui ten trai, phai de dieu khien thang sang";
}
void HDTraSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Enter : de chon (co the chon nhieu sach cung luc)";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten len, xuong, trai, phai : de dieu khien thanh sang";
}
void HDXemDocGiaMuonSachQuaHan()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Esc : de thoat";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de lat trang";
}
void HDNhapDauSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten len, xuong: de nhap";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Enter: de chon";
}
void HDNhapDauSach1()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten len, xuong: de nhap";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut mui ten trai, phai : de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut Enter: de chon";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+3);
	cout<<"Nut ESC: de thoat";
}
void HDXuatDauSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten len, xuong: de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Enter: de chon";	
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nut mui ten trai, phai : de lat trang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+3);
	cout<<"Nut Esc : de thoat";
}
void HDTimSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten len, xuong: de dieu khien thanh sang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Enter: de chon";	
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+2);
	cout<<"Nhap ten sach de tim kiem ";	
}
void HD10Sach()
{	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut Esc: de thoat";
}
void HDInSach()
{
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
	cout<<"Nut mui ten trai, phai : de lat trang";
	gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
	cout<<"Nut Esc : de thoat";
}

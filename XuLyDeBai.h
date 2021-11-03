
void LayThongTinDocGia(TREE_TDG t, int MaThe, TREE_TDG &tam)
{
	if (t == NULL)
	{
		return;
	}
	else if (t->thedocgia.MaThe == MaThe)
	{
		tam = t;
		return;
	}
	else if (MaThe > t->thedocgia.MaThe)
	{

		LayThongTinDocGia(t->right, MaThe, tam);
	}
	else
	{
		LayThongTinDocGia(t->left, MaThe, tam);
	}
}
bool LayThongTinSach(MCONTRO DauS, string masach, DauSach *&DauSTam,NODE_LIST *&tam)
{
	if (DauS.n==0)
	{
		return false;
	}
	for(int i=0;i<DauS.n;i++)
	{
		if (TachLayMaDauSach(masach) == DauS.nDS[i]->MaDauSach)
		{
			for (NODE_LIST* k = DauS.nDS[i]->List_DMS.First; k != NULL; k = k->next)
			{
				if (masach == k->data.MaSach)
				{
					DauSTam = DauS.nDS[i];
					tam=k;
					return true;
				}
			}
		}
	}
	return false;
}
bool NhapDocGia(string & Ho, string & Ten, string & Phai) 
{
	ShowCur(1);
	int pointer1 =11; 
	GiaoDienThemDocGia();

	while (true)
	{
		if (pointer1 == 11) // nhap ho
		{
			gotoXY(100, pointer1);
			XuLyNhap_Chu(Ho, 100, pointer1,30); 
			if (pointer1 < 11)
			{
				pointer1 = 20;
			}
		}
		else if (pointer1 == 14) // nhap ten
		{
			gotoXY(100 + Ten.length(), pointer1);
			XuLyNhap_Chu(Ten, 100, pointer1, 8);
		}
		else if (pointer1 == 17) // gioi tinh
		{
			ChonPhai( Phai, pointer1);
		}
		else if (pointer1 == 20) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = 100;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (!Ho.empty() && !Ten.empty() && !Phai.empty() && pointer2 == 100)
						{
							DinhDangChuoi(Ho);
							DinhDangChuoi(Ten);
							return true;
						}
						else if (pointer2 == 115)
						{
							return false;
						}
						else
						{
							ThongBao("Vui long dien day du thong tin");
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							Normal();
							gotoXY(115, 20);
							cout << "Thoat";
							gotoXY(100, 20);
							cout << "Dang Ki";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							Normal();
							gotoXY(115, 20);
							cout << "Thoat";
							gotoXY(100, 20);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = 11;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 115)
							{
								pointer2 = 100;
							}
							else
								pointer2 = 115;
						}
						else if (c == 77)
						{
							if (pointer2 == 100)
							{
								pointer2 = 115;
							}
							else
								pointer2 = 100;
						}
						gotoXY(pointer2, 20);
					}
				}

				HighLight();
				gotoXY(pointer2, pointer1);
				if (pointer2 == 100)
				{
					cout << "Dang Ki";
					Normal();
					gotoXY(115, 20);
					cout << "Thoat";
				}
				else if (pointer2 == 115)
				{
					cout << "Thoat";
					Normal();
					gotoXY(100, 20);
					cout << "Dang Ki";
				}
			}
		}
	}
}
void ThemTheDocGia(TREE_TDG & t, int mathe, int &i)
{
		if (t == NULL)
		{
			// Full doc gia
			if (SoLuongDocGia == MienGiaTriNgauNhien)
			{
				i=0;
				return ;
			}
		
			NODE_TREE* p = new NODE_TREE;
			p->thedocgia.MaThe = mathe;
			
			gotoXY(100, 8);
			cout << p->thedocgia.MaThe;
			
			if (!NhapDocGia(p->thedocgia.Ho, p->thedocgia.Ten, p->thedocgia.Phai))
			{
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
				i=0;
				return ;
			}
	
			SoLuongDocGia++;
	
			p->thedocgia.SoLuongSachDangMuon = 0;
			p->thedocgia.TrangThai = 1;
	
			p->thedocgia.List_MuonTra.First=NULL;
			//p->next=NULL;
			p->left = NULL;
			p->right = NULL;
			t = p;
			ThongBao("Them doc gia thanh cong");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		}
		else
		{
			if (t->thedocgia.MaThe > mathe)
			{
				ThemTheDocGia(t->left, mathe,i);
			}
			else if (t->thedocgia.MaThe < mathe)
			{
				ThemTheDocGia(t->right, mathe,i);
			}
		}
}

void XuLyPhim( char c, int a[] , int &madocgia,string &x, int &vitri, int &n  ,int toadoY ,int &pointer , int i, bool &key)
{
	if(c == 8)
	{
		if(x.length() > 0)
			{
				x.erase(x.begin() + x.length() - 1);
				gotoXY(BoxMain[0]+20, BoxMain[2]);
				cout <<"                             ";
				gotoXY(BoxMain[0]+20, BoxMain[2]);
				cout << x;
				madocgia = atoi(x.c_str());
				if(x.length()==0)
				vitri=0;
				return;
			}
	} 
	else if(c == 13) //enter
	{
		madocgia=a[i];
		x=ChuyenSoSangString(madocgia);
		key=false;	
		return;
		
	}
	else if(c == 27) // Esc
	{	
			madocgia=0;
			key=false;	
			return;
	} 
	else if(c == -32)						
	{
		c = getch(); 
		
			if(c == 72) // len
			{
				if(pointer>toadoY)
				{
					pointer--;
				}
				else if(pointer==toadoY && vitri>0)
				{
					vitri--;
					XoaManHinhTimKiem();
					
				}
				return;
			} 
			else if(c == 80) //xuong
			{
				if(vitri>n-21 &&vitri<n-1)
				{
					if(i>n-2) return;
					else 
					{
						if(pointer<MaxBox)
						{
							pointer++;
						}
						else if(pointer==MaxBox && vitri<n-21)
						{
							vitri++;
							XoaManHinhTimKiem();
						}
						return;
					}
		
				}
				else if (vitri==n-1) return;
				else if(pointer<MaxBox)
				{
					pointer++;
				}
				else if(pointer==MaxBox && vitri<n-20)
				{
					vitri++;
					XoaManHinhTimKiem();
				}
				return;
			}
	}

}
void SapXepMangTheoMaDocGia(string str[], int a[], int n) 
{
	if(n==0)
	{
		return;
	}
	else
	{
		int tam1;
		string tam2;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					tam1=a[i]; tam2=str[i];
					a[i]=a[j]; str[i]=str[j];
					a[j]=tam1; str[j]=tam2;
				}
			}
		}
		
	}
}
bool SearchViTri(string str[], int a[], int n,int madocgia, int &vitri)// tra ve vitri cua phan tu dau tien lon hon madocgia
{
	int j;
	if(ChuyenSoSangString(madocgia).length()>0)
	{
		for(int i=0;i<n;i++)
		{
			j=ChuyenSoSangString(a[i]).find(ChuyenSoSangString(madocgia));
			if(j>-1)
			{
				vitri=i;
				return true;
			}
		}
		ThongBao("Ma doc gia khong ton tai");
	}
	vitri=0;
	return false;
}
void XuatMaDocDocGia(TREE_TDG &t, int &madocgia, int flag)
{
	int toadoX= BoxMain[0]+10;
	int toadoY = BoxMain[2]+3;//vi tri bat dau xuat du lieu;
	int pointer=toadoY;
	GiaoDienTimkiemTheDocGia();
	int *a=new int[SoLuongDocGia];
	int n = 0;
	madocgia=0;
	int madocgia1=madocgia;
	string *str=new string[SoLuongDocGia];
	if (flag == 1) // lay het
	{
		LayMaDocGia(t, str, a, n);
	}
	else if (flag == 2)// lay the doc gia dang hoat dong
	{
		LayMaDocGiaDeXoa(t, str, a, n);
	}
	else if (flag == 3)//lay the doc gia co muon sach
	{
		LayMaDocGiaDeTra(t, str, a, n);
	}
	else if (flag == 4)//lay the doc gia dang hoat dong 
	{
		LayMaDocGiaDeMuon(t, str, a, n);
	}
	else if (flag == 5) //lay cac doc gia da muon sach
	{
		LayMaDocGiaDaMuonSach(t, str, a, n);
	}
	SapXepMangTheoMaDocGia(str, a, n) ;
	char c;
	string x;
	int i=0;
	int vitri=0;
	bool key=true; 
	
	do
	{
		if(n==0) 
		{
			ThongBao("Khong co doc gia nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		}
		else
		{
			if(madocgia1==madocgia)
			{
			
				vitri=vitri;
			}
			else
			{
				if(x.length()>0)
				{
					if(SearchViTri(str, a, n,madocgia,vitri)==false)
					{
						x.erase(x.begin() + x.length() - 1);
						gotoXY(BoxMain[0]+20, BoxMain[2]);
						cout <<"                             ";
						gotoXY(BoxMain[0]+20, BoxMain[2]);
						cout << x;
						madocgia = atoi(x.c_str());
						SearchViTri(str, a, n,madocgia,vitri);
					}
					else
					{
							SearchViTri(str, a, n,madocgia,vitri);
							pointer=toadoY;
							madocgia1=madocgia;
							XoaManHinhTimKiem();
					}
				}
			}
			BodyTable();
			for(int i=vitri;i<n;i++)
			{
				if((i-(vitri))==20) break;
				gotoXY(BoxMain[0] +10 , toadoY+i-(vitri));
				cout<<CanDeuChuoi(ChuyenSoSangString(a[i]),20)<<char(179)<<CanDeuChuoi(str[i],45);
			}
			gotoXY(BoxMain[0]+10,pointer);
			HighLight();
			cout<<CanDeuChuoi(ChuyenSoSangString(a[pointer-(BoxMain[2]+3)+vitri]),20)<<char(179)<<CanDeuChuoi(str[pointer-(BoxMain[2]+3)+vitri],45);
			i=pointer-(BoxMain[2]+3)+vitri;
			Normal();
			gotoXY(BoxMain[0]+20+x.length(),BoxMain[2]);
			ShowCur(1);
			if(kbhit)
			{
				//ShowCur(0);
				c=getch();
				if((c >= 48 && c <= 57) && x.length() < 5)
				{
					
						x.insert(x.begin() + x.length(), c);
						gotoXY(toadoX+10,BoxMain[2]);
						cout << x;
						madocgia = atoi(x.c_str());
					
				}
				else
				{
					XuLyPhim( c , a , madocgia , x , vitri , n, toadoY , pointer , i ,key);
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]a;
	delete[]str;
	ShowCur(0);
}

void XemFullTheDocGia(TREE_TDG t, MCONTRO DauS)
{
	while(true)
		{
			int MaDocGia=0;
			XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
			HDXemThongTinDocGia();
			XuatMaDocDocGia(t, MaDocGia, 1);//
			if (MaDocGia == 0)
			{
				return;
			}
			TREE_TDG tam = NULL;
			LayThongTinDocGia( t,MaDocGia, tam);//
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
			gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]);
			cout<<"Nut Esc : de thoat";
			gotoXY(BoxHuongDan[0]+12,BoxHuongDan[2]+1);
			cout<<"Cac nut con lai : de quay lai";
			GiaoDienXuatTheDocGia(BoxMain[0]+3, BoxMain[2]+2, 1);
			HighLight();
			Xuat1DocGia( tam, BoxMain[0]+3, BoxMain[2]+2);//
			gotoXY(90, 17);
			cout << "DANH SACH SACH MUON ";
			GiaoDienXuatDanhSachMuon(55, 21, tam->thedocgia.SoLuongSachDangMuon);
			XuatDanhSachMuonCua1DocGia(DauS, tam, 55, 21);//
			char c;
			if(kbhit)
			{
				c=getch();
				switch(c)
				{
					case 27: 
					{
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						return;
					}
					default :
						{
							break;
						}
				}
			}
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		}
	
}
void XoaNode2Con(TREE_TDG &tam, TREE_TDG &t)
{
	if (t->left != NULL)
	{
		XoaNode2Con(tam, t->left);
	}
	else 
	{
		tam->thedocgia = t->thedocgia; 
		tam= t; 
		t = t->right;
	}
}
void XuLyXoa(TREE_TDG &t,int x)
{
	if (x > t->thedocgia.MaThe)
	{
		XuLyXoa(t->right, x);
	}
	else if (x < t->thedocgia.MaThe)
	{
		XuLyXoa(t->left, x);
	}
	else
	{
		TREE_TDG tam = t;
		if (t->left == NULL)
		{
			t = t->right;
		}
		else if (t->right == NULL)
		{
			t = t->left;
		}
		else if (t->left != NULL && t->right != NULL)
		{
			XoaNode2Con(tam, t->right);
		}
		MangRandom[x] = false;
		delete tam;
	}
}
void XoaDocGia(TREE_TDG &t)
{
	while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinDocGia();
		int MaDocGia=0;
		XuatMaDocDocGia(t, MaDocGia, 2);
		if (MaDocGia == 0)
		{
			return;
		}
		TREE_TDG tam = NULL;
		LayThongTinDocGia(t, MaDocGia, tam);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDThemDocGia();
		GiaoDienXuatTheDocGia(BoxMain[0]+3, BoxMain[2]+5, 1);
		Xuat1DocGia( tam, BoxMain[0]+3, BoxMain[2]+5);
		int pointer=100;
		char c;
		
		while (true)
		{
			gotoXY(100, 25);
			cout << "  Xoa The  ";
			gotoXY(110, 25);
			Normal();
			cout << "  Tro Lai  ";
			if (kbhit())
			{
				c = getch();
				if (c == -32)
				{
					c = getch();
					if( c == 77) //sang phai
					{
						if(pointer == 100)
						{
							pointer= 110;
						}
						else
							pointer = 100;
					}
					else if(c == 75) //qua trai
					{
						if(pointer == 110)
							pointer=100;
						else
							pointer=110;
					}
				}
				else if (c == 13)
				{
					switch (pointer)
					{
						case 100:// xoa the
						{
							XuLyXoa(t, tam->thedocgia.MaThe);
							SoLuongDocGia--;
							ThongBao("Xoa Thanh Cong");
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
						case 110:// tro lai
						{
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							goto a;
						}
					}
				}
			}
			gotoXY(pointer, 25);
			HighLight();
			switch (pointer)
			{
			case 100:
				cout << "  Xoa The  ";
				break;
			case 110:
				cout << "  Tro Lai  ";
				break;
			}
			Sleep(100);
			Normal();
		}
	}
		
}
void SuaThongTinDocGia(TREE_TDG &t)
{
	while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDXemThongTinDocGia();
		int MaDocGia=0;
		XuatMaDocDocGia(t, MaDocGia, 1);
		if (MaDocGia == 0)
		{
			return;
		}
		TREE_TDG tam = NULL;
		LayThongTinDocGia(t, MaDocGia, tam);
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	  	HDThemDocGia();
		// luu lai cac gia tri
		string TenTam, PhaiTam, HoTam;
		TenTam = tam->thedocgia.Ten;
		HoTam = tam->thedocgia.Ho;
		PhaiTam = tam->thedocgia.Phai;
		int pointer = 11;
		char c;
		GiaoDienThemDocGia();
		gotoXY(100,  20);
		cout << "Cap Nhat";
		gotoXY(100,8);
		cout << tam->thedocgia.MaThe;
		gotoXY(100, pointer );
		cout << tam->thedocgia.Ho;
		gotoXY(100, pointer+3);
		cout << tam->thedocgia.Ten;
		if(tam->thedocgia.Phai=="Nam")
		{
			gotoXY(100,pointer+6);
			HighLight();
			cout<<"Nam";
		}
		else
		{
			gotoXY(115,pointer+6);
			HighLight();
			cout<<"Nu";
		}
		Normal();
		ShowCur(1);
		pointer = 11;
		while (true)
		{
			if (pointer == 11) // nhap ho
			{
				gotoXY(100+tam->thedocgia.Ho.length(), pointer);
				XuLyNhap_Chu(tam->thedocgia.Ho, 100, pointer,30); 
				if (pointer < 11)
				{
					pointer = 20;
				}
			}
			else if (pointer == 14) // nhap ten
			{
				gotoXY(100 + tam->thedocgia.Ten.length(), pointer);
				XuLyNhap_Chu(tam->thedocgia.Ten, 100, pointer, 8);
			}
			else if (pointer == 17) // gioi tinh
			{
				ChonPhai( tam->thedocgia.Phai, pointer);
			}
			else if (pointer == 20) // Cap nhat hoac huy
			{
				ShowCur(0);
				int pointer2 = 100;
				while (true)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 13)
						{
							if (!tam->thedocgia.Ho.empty() && !tam->thedocgia.Ten.empty() && !tam->thedocgia.Phai.empty() && pointer2 == 100)
							{
								DinhDangChuoi(tam->thedocgia.Ho);
								DinhDangChuoi(tam->thedocgia.Ten);
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else if (pointer2 == 115)
							{
								tam->thedocgia.Ho = HoTam;
								tam->thedocgia.Ten = TenTam;
								tam->thedocgia.Phai = PhaiTam;
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else
							{
								ThongBao("Vui long dien day du thong tin");
							}
						}
						else if (c == -32)
						{
							c = getch();
							if (c == 72)
							{
								Normal();
								gotoXY(115, 20);
								cout << "Thoat";
								gotoXY(100, 20);
								cout << "Cap nhat";
								pointer = pointer - 3;
								break;
							}
							else if (c == 80)
							{
								Normal();
								gotoXY(115, 20);
								cout << "Thoat";
								gotoXY(100, 20);
								cout << "Cap nhat";
								ShowCur(1);
								pointer = 11;
								break;
							}
							else if (c == 75)
							{
								if (pointer2 == 115)
								{
									pointer2 = 100;
								}
								else
									pointer2 = 115;
							}
							else if (c == 77)
							{
								if (pointer2 == 100)
								{
									pointer2 = 115;
								}
								else
									pointer2 = 100;
							}
							gotoXY(pointer2, 20);
						}
					}
					HighLight();
					//textcolor(28);
					gotoXY(pointer2, pointer);
					if (pointer2 == 100)
					{
						cout << "Cap nhat";
						Normal();
						gotoXY(115, 20);
						cout << "Thoat";
					}
					else if (pointer2 == 115)
					{
						cout << "Thoat";
						Normal();
						gotoXY(100, 20);
						cout << "Cap nhat";
					}
				}
			}
		}
		
	}
}
void XuLyMuonSach(TREE_TDG& t,DauSach *DauSTam,NODE_LIST *s,Date Ngay)
{
	t->thedocgia.SoLuongSachDangMuon++;
	s->data.TrangThai = 1;
	DauSTam->SoLanMuon++;
	NODE_LIST_MUONTRA* p = new NODE_LIST_MUONTRA;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return;
	}
	p->data.MaSach = s->data.MaSach;
	p->data.NgayMuon=Ngay;
	p->data.NgayTra.Ngay = 0;;
	p->data.NgayTra.Thang = 0;
	p->data.NgayTra.Nam = 0;
	p->data.TrangThai = 0;
	p->next = NULL;
	

	if (t->thedocgia.List_MuonTra.First == NULL)
	{
		t->thedocgia.List_MuonTra.First = p;
		t->thedocgia.List_MuonTra.Last = p;
	}
	else
	{
		t->thedocgia.List_MuonTra.Last->next = p;
		//p->left = t->thedocgia.List_MuonTra.Last;
		t->thedocgia.List_MuonTra.Last = p;
	}
}
 void MuonSach(TREE_TDG &t, MCONTRO &DauS)
 {
 	if (DauS.n == 0)
	{
		ThongBao("Thu Vien Hien Dang Trong!!");
		return;
	}
	bool KT = false; // kiem tra tat ca cac sach da cho muon chua
	for (int i = 0; i < DauS.n; i++)
	{
		for (NODE_LIST* k = DauS.nDS[i]->List_DMS.First; k != NULL; k = k->next)
		{
			if (k->data.TrangThai == 0)
			{
				KT = true;
				break;
			}
		}
		if (KT == true)
		{
			break;
		}
	}
	int MaDocGia=0;
	char c;
	TREE_TDG tam=NULL;
	DauSach* DauSTam=NULL;
	NODE_LIST* Sachtam;
	Date NgayHienTai;
	LayNgayHienTai(NgayHienTai);
	int Namtam=NgayHienTai.Nam;
	int Ngaytam=NgayHienTai.Ngay;
	int Thangtam=NgayHienTai.Thang;
	a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDXemThongTinDocGia();
	XuatMaDocDocGia(t, MaDocGia, 4);
	if (MaDocGia == 0)
	{
		return;
	}
	ShowCur(1);
	LayThongTinDocGia(t, MaDocGia, tam);                               
	b:XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDMuonSach();
	GiaoDienMuonSach();
	gotoXY(85,20);
	cout<<"Cac Cuon Sach "<<tam->thedocgia.Ho<<" "<<tam->thedocgia.Ten<<" Dang Muon";
	GiaoDienXuatDanhSachMuon(55, 22, tam->thedocgia.SoLuongSachDangMuon);
	XuatDanhSachMuonCua1DocGia(DauS, tam, 55, 22);
	Normal();
	gotoXY(BoxMain[0]+32,BoxMain[2]+9);
	cout<<"    /      /       ";
	gotoXY(BoxMain[0]+32,BoxMain[2]+9);
	cout<<NgayHienTai.Ngay;
	gotoXY(BoxMain[0]+39,BoxMain[2]+9);
	cout<<NgayHienTai.Thang;
	gotoXY(BoxMain[0]+46,BoxMain[2]+9);
	cout<<NgayHienTai.Nam;
	string MaSach;
	gotoXY(BoxMain[0]+21,BoxMain[2]);
	XuLyNhap_MaSach(MaSach) ;
	if (MaSach.empty())
		{
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			goto a;
		}
	if(LayThongTinSach(DauS,MaSach,DauSTam,Sachtam)==true)
	{
		if(Sachtam->data.TrangThai==0)
		{
			gotoXY(BoxMain[0]+21,BoxMain[2]+3);
			cout<<DauSTam->TenSach;
			gotoXY(BoxMain[0]+21,BoxMain[2]+6);
			cout<<DauSTam->TacGia;
			gotoXY(BoxMain[0]+32,BoxMain[2]+9);
			cout<<"    /      /       ";
			c:LayNgayHienTai(NgayHienTai);
			gotoXY(BoxMain[0]+32,BoxMain[2]+9);
			cout<<"  ";
			gotoXY(BoxMain[0]+32,BoxMain[2]+9);
			cout<<NgayHienTai.Ngay;
			gotoXY(BoxMain[0]+39,BoxMain[2]+9);
			cout<<"  ";
			gotoXY(BoxMain[0]+39,BoxMain[2]+9);
			cout<<NgayHienTai.Thang;
			gotoXY(BoxMain[0]+46,BoxMain[2]+9);
			cout<<NgayHienTai.Nam;
			int pointer = BoxMain[2]+9;
			int toadoX = BoxMain[0]+32;
			while(true)
			{
				ShowCur(1);
			
				while(pointer==BoxMain[2]+9)
				{
					if(toadoX==BoxMain[0]+32) 
					{
						gotoXY(toadoX+ChuyenSoSangString(NgayHienTai.Ngay).length(), pointer);
						XuLyNhap_NgayThangNam(NgayHienTai.Ngay, toadoX, pointer, 1);
					}
					else if(toadoX==BoxMain[0]+39)
					{
						gotoXY(toadoX+ChuyenSoSangString(NgayHienTai.Thang).length(), pointer);
						XuLyNhap_NgayThangNam(NgayHienTai.Thang, toadoX, pointer, 1);
					}
					else if(toadoX==BoxMain[0]+46)
					{
						gotoXY(toadoX+ChuyenSoSangString(NgayHienTai.Nam).length(), pointer);
						XuLyNhap_NgayThangNam(NgayHienTai.Nam, toadoX, pointer, 2);
					}
				}
				if(NgayHienTai.Nam>Namtam || NgayHienTai.Nam==Namtam && NgayHienTai.Thang>Thangtam || NgayHienTai.Nam==Namtam && NgayHienTai.Thang==Thangtam && NgayHienTai.Ngay>Ngaytam)
				{
					ThongBao("Ngay Thang Nam Khong Hop Le !!");
					goto c;
				}
				else
				{
					if(KTNgayHopLe(NgayHienTai.Ngay,NgayHienTai.Thang,NgayHienTai.Nam)==false)
					{
						ThongBao("Ngay Thang Nam Khong Hop Le !!");
						goto c;
					}
				}
				if(pointer == BoxMain[2]+12)
				{
					ShowCur(0);
					int pointer2 = BoxMain[0]+30;
					while (true)
					{
						if (kbhit())
						{
							char c = getch();
							if (c == 13)
							{
								if (pointer2 == BoxMain[0]+30)
								{
									XuLyMuonSach(tam, DauSTam,Sachtam,NgayHienTai);
									ThongBao("Muon sach thang cong");
									XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
									return;
								}
								else if (pointer2 == BoxMain[0]+45)
								{
									XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
									return;
								}
							}
							else if (c == -32)
							{
								c = getch();
								if (c == 72)
								{
									Normal();
									gotoXY(BoxMain[0]+30,BoxMain[2]+12);
									cout << "Xac Nhan";
									gotoXY(BoxMain[0]+45,BoxMain[2]+12);
									cout << "Thoat";
									pointer = pointer - 3;
									break;
								}
								else if (c == 80)
								{
									Normal();
									gotoXY(BoxMain[0]+30,BoxMain[2]+12);
									cout << "Xac Nhan";
									gotoXY(BoxMain[0]+45,BoxMain[2]+12);
									cout << "Thoat";
									pointer = pointer - 3;
									break;
								}
								else if (c == 75)
								{
									if (pointer2 == BoxMain[0]+45)
									{
										pointer2 = BoxMain[0]+30;
									}
									else
										pointer2 = BoxMain[0]+45;
								}
								else if (c == 77)
								{
									if (pointer2 == BoxMain[0]+30)
									{
										pointer2 = BoxMain[0]+45;
									}
									else
										pointer2 = BoxMain[0]+30;
								}
								gotoXY(pointer2, BoxMain[2]+12);
							}
						}
						HighLight();
						gotoXY(pointer2, pointer);
						if (pointer2 == BoxMain[0]+30)
						{
							cout << "Xac Nhan";
							Normal();
							gotoXY(BoxMain[0]+45, BoxMain[2]+12);
							cout << "Thoat";
						}
						else if (pointer2 == BoxMain[0]+45)
						{
							cout << "Thoat";
							Normal();
							gotoXY(BoxMain[0]+30, BoxMain[2]+12);
							cout << "Xac Nhan";
						}
					}
				}
			}
		}
		else
		{
			ThongBao("Sach da duoc muon");
			goto b;
		}
	}
	else
	{
		ThongBao("Ma sach khong ton tai");
		goto b;
	}
 }
void XuLiTraSach(MuonTra & Mt, MCONTRO & DauS)
{
	for (int i = 0; i < DauS.n; i++)
	{
		if (TachLayMaDauSach(Mt.MaSach) == DauS.nDS[i]->MaDauSach)
		{
			for (NODE_LIST* k = DauS.nDS[i]->List_DMS.First; k != NULL; k = k->next)
			{
				if (Mt.MaSach == k->data.MaSach)
				{
					if (Mt.TrangThai == 1)
					{
						k->data.TrangThai = 0;
					}
					else if (Mt.TrangThai == 2|| Mt.TrangThai == 3)
					{
						k->data.TrangThai = 2;
					}
					break;
				}
			}
			break;
		}
	}
} 
 void TraSach(TREE_TDG &t, MCONTRO & DauS)
{
	int toadoX=BoxMain[0];
	int toadoY=BoxMain[2]+10;
	int MaDocGia=0;
	TREE_TDG tam=NULL;
	DauSach* DauSTam=NULL;
	NODE_LIST* Sachtam;
	Date NgayHienTai;
	LayNgayHienTai(NgayHienTai);
	a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDXemThongTinDocGia();
	XuatMaDocDocGia(t, MaDocGia, 3);
	if (MaDocGia == 0)
	{
		return;
	}
	LayThongTinDocGia(t, MaDocGia, tam);                               
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDTraSach();
	
	// kt sach da chon chua
	bool ktChon[3]{false};
	 
	NODE_LIST_MUONTRA* Mt[3];
	int dem = 0;

	NODE_LIST_MUONTRA* MTtam[3];
	int z = 0;
	//kiem tra sl sach doc gia muon
	for (NODE_LIST_MUONTRA* k = tam->thedocgia.List_MuonTra.First; k != NULL; k = k->next)
	{
		if (k->data.TrangThai == 0) // sach dang dc muon
		{
			MTtam[z++] = k;
		}
	}

	int pointer1 = toadoY + 4;
	int pointer2 = 100;
	char c;
	GiaoDienXuatDanhSachMuon(toadoX ,toadoY, tam->thedocgia.SoLuongSachDangMuon);
	XuatDanhSachMuonCua1DocGia(DauS, tam, toadoX, toadoY);
	Normal();
	gotoXY(51, toadoY - 6);
	cout<<CanDeuChuoi("Doc Gia:" + tam->thedocgia.Ho + " " + tam->thedocgia.Ten, 100);
	gotoXY(51, toadoY-3 );
	cout<<CanDeuChuoi("Danh Sach Cac Sach Dang Muon ", 100);
	
	while (true)
	{
		gotoXY(100, toadoY + 11);
		cout << "Xac Nhan";
		gotoXY(120, toadoY + 11);
		cout << "Tro Lai";
		BodyTable();
		XuatDanhSachMuonCua1DocGia(DauS, tam, toadoX, toadoY);
		int j = tam->thedocgia.SoLuongSachDangMuon * 2;

		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer1 == toadoY + 4)
					{
						pointer1 = toadoY + 10;
					}
					else if (pointer1 == toadoY + 10)
					{
						pointer1 = toadoY + 4 + j - 2;
					}
					else
						pointer1 = pointer1 - 2;
				}
				else if (c == 80)
				{
					if (pointer1 == toadoY + 4 + j - 2)
					{
						pointer1 = toadoY + 10;
					}
					else if (pointer1 == toadoY + 10)
					{
						pointer1 = toadoY + 4;
					}
					else
						pointer1 = pointer1 + 2;
				}
				else if (c == 75 && pointer1 == toadoY + 10)
				{
					if (pointer2 == 120)
					{
						pointer2 = 100;
					}
					else
						pointer2 = 120;
				}
				else if (c == 77 && pointer1 == toadoY + 10)
				{
					if (pointer2 == 100)
					{
						pointer2 = 120;
					}
					else
						pointer2 = 100;
				}
			}
			else if (c == 13)
			{
				if (pointer1 == toadoY + 4)
				{
					if (ktChon[0] == false)
					{
						Mt[dem++] = MTtam[0];
						gotoXY(toadoX + 100, toadoY+4);
						cout << "<-";
						ktChon[0] = true;
					}
					else
					{
						gotoXY(toadoX + 100, toadoY + 4);
						
						cout << "<-";
						ktChon[0] = false;
						// xoa 1 sach ra khoi mang MT
						for (int i = 0; i < dem; i++)
						{
							if (Mt[i]->data.MaSach == MTtam[0]->data.MaSach)
							{
								for (int j = i; j < dem - 1; j++)
								{
									Mt[j] = Mt[j + 1];
								}
								dem--;
							}
						}
					}

				}
				else if (pointer1 == toadoY + 6)
				{
					if (ktChon[1] == false)
					{
						Mt[dem++] = MTtam[1];
						gotoXY(toadoX + 100, toadoY + 6);
						
						cout << "<-";
						ktChon[1] = true;
					}
					else
					{
						gotoXY(toadoX + 100, toadoY + 6);
						
						cout << "<-";
						ktChon[1] = false;
						// xoa 1 sach ra khoi mang MT
						for (int i = 0; i < dem; i++)
						{
							if (Mt[i]->data.MaSach == MTtam[1]->data.MaSach)
							{
								for (int j = i; j < dem - 1; j++)
								{
									Mt[j] = Mt[j + 1];
								}
							}
							dem--;
						}
					}

				}
				else if (pointer1 == toadoY + 8)
				{

					if (ktChon[2] == false)
					{
						Mt[dem++] = MTtam[2];
						gotoXY(toadoX + 100, toadoY+8);
						
						cout << "<-";
						ktChon[2] = true;
					}
					else
					{
						gotoXY(toadoX + 100, toadoY + 8);
						
						cout << " ";
						ktChon[2] = false;
						// xoa 1 sach ra khoi mang MT
						for (int i = 0; i < dem; i++)
						{
							if (Mt[i]->data.MaSach == MTtam[2]->data.MaSach)
							{
								for (int j = i; j < dem; j++)
								{
									Mt[j] = Mt[j + 1];
								}
							}
							dem--;
						}
					}
				}
				else if (pointer1 == toadoY + 10)
				{
					switch (pointer2)
					{
					case 100: // xac nhan
					{
						if (dem > 0)
						{
								for (int i = 0; i < dem; i++)
								{
									Mt[i]->data.TrangThai = 1;
									LayNgayHienTai(Mt[i]->data.NgayTra);
								}
								for (int i = 0; i < dem; i++)
								{
									XuLiTraSach(Mt[i]->data, DauS);
									tam->thedocgia.SoLuongSachDangMuon--;
								}
								Date NgayHienTai;
								LayNgayHienTai(NgayHienTai);
								KiemTraQuaHan1DocGia(tam, NgayHienTai);
								ThongBao("Tra Sach Thanh Cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								return;
						}
						else
						{
							break;
						}
					}
					case 120: // cancel
					{
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						goto a;
						return;
					}
					}
				}
			}
		}
		HighLight();
		if (pointer1 == toadoY + 4)
		{
			Xuat1SachMuonCua1DocGia(DauS,MTtam[0]->data, toadoX, pointer1);
		}
		else if (pointer1 == toadoY + 6)
		{
			Xuat1SachMuonCua1DocGia(DauS,MTtam[1]->data, toadoX, pointer1);
		}
		else if (pointer1 == toadoY + 8)
		{
			Xuat1SachMuonCua1DocGia(DauS,MTtam[2]->data, toadoX, pointer1);
		}
		else if (pointer1 == toadoY + 10)
		{
			HighLight();
			gotoXY(pointer2, toadoY + 11);
			switch (pointer2)
			{
			case 100:
				cout << "Xac Nhan";
				break;
			case 120:
				cout << "Tro Lai";
				break;
			}
		}
		Normal();
		Sleep(100);
	}
}

void DanhSachDocGiaMuonSachQuaHan(TREE_TDG t)
{
	int *a=new int[SoLuongDocGia];
	int n = 0;
	int trang = 1;
	int sotrang = 1;
	int phantutrang=10;
	TREE_TDG tam = NULL;
	LayMaDocGiaMuonSachQuaHan( t, a, n);
	if(n==0)
	{
		ThongBao("Khong Co Doc Gia Nao Muon Sach Qua Han!");
		return;
	}
	if( n%10==0)
	{
		sotrang= n/10;
	}
	else
	{
		sotrang= n/10+1;
	}
	if(n<=10)
	{
		GiaoDienXuatTheDocGia(BoxMain[0]+6, BoxMain[2], n);
		for(int i=0;i<n;i++)
		{
			LayThongTinDocGia(t, a[i], tam);
			Xuat1DocGia(tam,BoxMain[0]+6, BoxMain[2]+(i*2));
		}
	}
	else
	{
		GiaoDienXuatTheDocGia(BoxMain[0]+6, BoxMain[2], 10);
		for(int i=0;i<10;i++)
		{
			LayThongTinDocGia(t, a[i], tam);
			Xuat1DocGia(tam,BoxMain[0]+6, BoxMain[2]+(i*2));
		}
	}
	gotoXY(85,BoxMain[2]-2);
	cout<<"DANH SACH CAC DOC GIA MUON SACH QUA HAN";
	gotoXY(100,31);
	cout<<"<< "<<trang<<" >>";
	char c;
	while(true)
	{
		if(kbhit)
		{
			c=getch();
			if(c == -32)
			{
				c=getch();
				if(c == 77) // qua phai
				{
					if(sotrang>1 && trang<sotrang)
					{
						phantutrang = n-trang*10;
						if(phantutrang>=10)
						{
							phantutrang=10;
						}
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienXuatTheDocGia(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10;i<trang*10+phantutrang;i++)
						{
							LayThongTinDocGia(t, a[i], tam);
							Xuat1DocGia(tam,BoxMain[0]+6, BoxMain[2]+((i-(trang*10))*2));
						}
						trang++;
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
				else  if(c==75)// qua trai
				{
					if(trang>1)
					{
						phantutrang=10;
						trang--;
						XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
						GiaoDienXuatTheDocGia(BoxMain[0]+6, BoxMain[2],phantutrang);
						for(int i=trang*10-10;i<trang*10;i++)
						{
							LayThongTinDocGia(t, a[i], tam);
							Xuat1DocGia(tam,BoxMain[0]+6, BoxMain[2]+((i-(trang*10-10))*2));
						}
					}
					gotoXY(100,31);
					cout<<"<< "<<trang<<" >>";
				}
			}
			else if(c==27)
			{
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	Normal();
}

bool KTMaTrung(MCONTRO DauS, string MaDauSach)
{
	for (int i = 0; i < DauS.n ; i++)
	{
		if (DauS.nDS[i]->MaDauSach == MaDauSach)
		{
			return true;
		}
	}
	return false;
}
bool KTTenSach(string TenSach)
{
	for (int i = 0; i < TenSach.length(); i++)
	{
		if ((TenSach[i] >= 65 && TenSach[i] <= 90) || (TenSach[i] >= 97 && TenSach[i] <= 122))
		{
			return true;
		}
	}
	return false;
}
void ThemSachTuDong(MCONTRO &DauS, string MaSach, string ViTri)
{
	NODE_LIST* p = new NODE_LIST;//danh muc sach
	if(p==NULL)
	{
		ThongBao("Cap nhat thai bai!");
		return;
	}
	p->data.MaSach = MaSach;
	p->data.TrangThai = 0;//chua muon
	p->data.ViTri = ViTri;
	p->next = NULL;
	if (DauS.n[DauS.nDS]->List_DMS.First == NULL)
	{
		DauS.n[DauS.nDS]->List_DMS.First = DauS.nDS[DauS.n]->List_DMS.Last = p;
	}
	else
	{
		DauS.nDS[DauS.n]->List_DMS.Last->next=p;
		DauS.nDS[DauS.n]->List_DMS.Last = p;
	}

}

bool NhapDauSach(MCONTRO & DauS, string & ViTri, int toadoX, int toadoY)
{
	HDNhapDauSach();
	GiaoDienThemDauSach(toadoX,toadoY);
	DauS.nDS[DauS.n]->NamXuatBan = 2021;
	DauS.nDS[DauS.n]->SoTrang = 0;
	DauS.nDS[DauS.n]->SoLuongSach = 0;
	DauS.nDS[DauS.n]->SoLanMuon = 0;
	gotoXY(toadoX + 20, toadoY+13);
	cout << DauS.nDS[DauS.n]->NamXuatBan;
	gotoXY(toadoX + 20, toadoY + 7);
	cout << DauS.nDS[DauS.n]->SoTrang;
	gotoXY(toadoX + 20, toadoY + 22);
	cout << DauS.nDS[DauS.n]->SoLuongSach;

	char c;
	int pointer1 = toadoY;//5
	int pointer2 = toadoX + 30;
	ShowCur(1);
	while (true)
	{
		if (pointer1 == toadoY) // ma dau sach 
		{
			gotoXY(toadoX + 20 + DauS.nDS[DauS.n]->MaDauSach.length(), pointer1 + 1 );// khi vao o nhap ma sach thi con nhay se ve ki tu cuoi cua chuoi nhap khi nhan len xuong
			XuLyNhap_MaDauSach(DauS.nDS[DauS.n]->MaDauSach, toadoX + 20, pointer1);
			
			if (pointer1 < toadoY)//poi <5
			{
				pointer1 = toadoY + 24;//khi nay nhan mui ten len se quay xuong cuoi cho them
			}
			
			if (DauS.nDS[DauS.n]->MaDauSach.empty())
			{
				gotoXY(toadoX + 80, toadoY + 1);
				cout << "Ma Dau Sach Rong";
			}
			else if (KTMaTrung(DauS, DauS.nDS[DauS.n]->MaDauSach))
			{
				gotoXY(toadoX + 80, toadoY + 1);
				cout << "Ma Dau Sach Trung";
			}
			else
			{
				//ko co thong bao nhap loi
				gotoXY(toadoX + 80, toadoY + 1);
				cout << "                 ";
			}
		}
		else if (pointer1 == toadoY+3) // ten sach
		{
			gotoXY(toadoX + 20 + DauS.nDS[DauS.n]->TenSach.length(), pointer1 + 1);	
			XuLyNhap_TenSach1(DauS.nDS[DauS.n]->TenSach, toadoX + 20, pointer1,40);
			if (DauS.nDS[DauS.n]->TenSach.empty())
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "Ten Sach Rong";
			}
			else if (!KTTenSach(DauS.nDS[DauS.n]->TenSach))
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "Ten Khong Hop Le";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "                 ";
			}
		}
		else if (pointer1 == toadoY + 6) // so trang
		{
			gotoXY(toadoX + 20 + DemChuSo(DauS.nDS[DauS.n]->SoTrang), pointer1 + 1);
			XuLyNhap_So(DauS.nDS[DauS.n]->SoTrang, toadoX + 20, pointer1);
			if (DauS.nDS[DauS.n]->SoTrang <= 0)
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "So Trang Phai >0";
			}
			else if (DauS.nDS[DauS.n]->SoTrang > 10000)
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "So Trang <10000";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "                ";
			}
		}
		else if (pointer1 == toadoY + 9)// tac gia
		{
			gotoXY(toadoX + 20 + DauS.nDS[DauS.n]->TacGia.length(), pointer1 + 1);
			XuLyNhap_Chu(DauS.nDS[DauS.n]->TacGia, toadoX + 20, pointer1,25);
			if (DauS.nDS[DauS.n]->TacGia.empty())
			{
				gotoXY(toadoX + 80, toadoY + 10);
				cout << "Tac Gia Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 10);
				cout << "            ";
			}
		}
		else if (pointer1 == toadoY + 12) // nam
		{
			gotoXY(toadoX + 20 + DemChuSo(DauS.nDS[DauS.n]->NamXuatBan), pointer1 + 1);
			XuLyNhap_So(DauS.nDS[DauS.n]->NamXuatBan, toadoX + 20, pointer1);
			if (DauS.nDS[DauS.n]->NamXuatBan > 2021 || DauS.nDS[DauS.n]->NamXuatBan < 1000)
			{
				gotoXY(toadoX + 80, toadoY + 13);
				cout << "Nam K Hop Le";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 13);
				cout << "             ";
			}
		}
		else if (pointer1 == toadoY + 15) // the loai
		{
			gotoXY(toadoX + 20 + DauS.nDS[DauS.n]->TheLoai.length(), pointer1 + 1);
			XuLyNhap_Chu(DauS.nDS[DauS.n]->TheLoai, toadoX + 20, pointer1,20);
			if (DauS.nDS[DauS.n]->TheLoai.empty())
			{
				gotoXY(toadoX + 80, toadoY + 16);
				cout << "The Loai Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 16);
				cout << "              ";
			}
		}
		else if (pointer1 == toadoY + 18) // vi tri
		{
			gotoXY(toadoX + 20 + ViTri.length(), pointer1 + 1);
			XuLyNhap_ViTri(ViTri, toadoX + 20, pointer1,20);
			if (ViTri.empty())
			{
				gotoXY(toadoX + 80, toadoY + 19);
				cout << "Vi Tri Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 19);
				cout << "           ";
			}
		}
		else if (pointer1 == toadoY + 21) //so luong
		{
			gotoXY(toadoX + 20 + DemChuSo(DauS.nDS[DauS.n]->SoLuongSach), pointer1 + 1);
			XuLyNhap_So(DauS.nDS[DauS.n]->SoLuongSach, toadoX + 20, pointer1);
			if (DauS.nDS[DauS.n]->SoLuongSach <= 0)
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "So Luong >0";
			}
			else if (DauS.nDS[DauS.n]->SoLuongSach > 9999)
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "So Luong <10000";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "                  ";
			}
		}
		else if (pointer1 == toadoY + 24)//xac nhan
		{
			ShowCur(0);
			HighLight();
			gotoXY(toadoX + 30, toadoY + 25);
			cout << "Xac Nhan";
			Normal();//tranh thanh sang o cancel
			while (true)
			{
				if (kbhit())
				{
					c = getch();
					if (c == 13)//enter
					{
						//nhan enter them
						if (!DauS.nDS[DauS.n]->MaDauSach.empty() && 
							!KTMaTrung(DauS, DauS.nDS[DauS.n]->MaDauSach) && 
							!DauS.nDS[DauS.n]->TheLoai.empty() && 
							!DauS.nDS[DauS.n]->TacGia.empty() && 
							KTTenSach(DauS.nDS[DauS.n]->TenSach)&&
							!DauS.nDS[DauS.n]->TenSach.empty() && 
							(999< DauS.nDS[DauS.n]->NamXuatBan&&DauS.nDS[DauS.n]->NamXuatBan < 2020) &&
							(10000 > DauS.nDS[DauS.n]->SoLuongSach && DauS.nDS[DauS.n]->SoLuongSach > 0) &&
							(10000 > DauS.nDS[DauS.n]->SoTrang && DauS.nDS[DauS.n]->SoTrang) > 0 &&
							!ViTri.empty() && 
							pointer2 == toadoX + 30)
						{
							DinhDangChuoi(DauS.nDS[DauS.n]->TheLoai);
							DinhDangChuoi(DauS.nDS[DauS.n]->TacGia);
							DinhDangChuoi(DauS.nDS[DauS.n]->TenSach);
							DinhDangChuoi(ViTri);
							ShowCur(0);
							return true;
						}
						//nhan enter huy
						else if (pointer2 == toadoX + 60)
						{
							ShowCur(0);
							XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
							XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
							return false;
							
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)//len
						{
							textcolor(0);
							gotoXY(toadoX + 60, toadoY + 25);
							cout << "Cancel";
							gotoXY(toadoX + 30, toadoY + 25);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = pointer1 - 3;//poin la cho nhap vi tri
							break;
						}
						else if (c == 80)//xuong	
						{
							textcolor(0);
							gotoXY(toadoX + 60, toadoY + 25);
							cout << "Cancel";
							gotoXY(toadoX + 30, toadoY + 25);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = toadoY;//quay lai ma dau sach
							break;
						}
						//di chuyen sang them hoac cancel
						else if (c == 75)//trai
						{
							if (pointer2 == toadoX + 60)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 60;
						}
						else if (c == 77)//phai
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 60;
							}
							else
								pointer2 = toadoX + 30;
						}
					}
				}

				if (pointer2 == toadoX + 30)//them
				{
					textcolor(0);
					gotoXY(toadoX + 60, toadoY + 25);
					cout << "Cancel";
					HighLight();
					gotoXY(toadoX + 30, toadoY + 25);
					cout << "Xac Nhan";
					Normal();
				}
				else if (pointer2 == toadoX + 60)//cancel
				{
					textcolor(0);
					gotoXY(toadoX + 30, toadoY + 25);
					cout << "Xac Nhan";
					HighLight();
					gotoXY(toadoX + 60, toadoY + 25);
					cout << "Cancel";
					Normal();
				}
				Sleep(100);
			}
		}
	}
XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
}
void ThemMotDauSach(MCONTRO & DauS, int toadoX, int toadoY)
{
	if (DauS.n == 10000)
	{
		ThongBao("Loi! Bo nho da day");
		return;
	}
	string vitri;
	DauS.nDS[DauS.n] = new DauSach;
	if (DauS.nDS[DauS.n] == NULL)//loi cap phat
	{
		cout << "\a";
		return;
	}
	if (!NhapDauSach(DauS, vitri, toadoX, toadoY))
	{
		delete DauS.nDS[DauS.n];
		return;
	}
	//khoi tao cho First va Last
	DauS.nDS[DauS.n]->List_DMS.First = NULL;
	DauS.nDS[DauS.n]->List_DMS.Last = NULL;
	for (int i = 1; i <= DauS.nDS[DauS.n]->SoLuongSach ; i++)
	{
		ThemSachTuDong(DauS, NoiChuoi(DauS.nDS[DauS.n]->MaDauSach,i),NoiChuoi(vitri,i));
	}
	DauS.n++;
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	ThongBao("Them Dau Sach Thanh Cong!");
}
bool LayTheLoai(MCONTRO DauS,string theloai[],int SoLuong[],int h,int i)
{
	for (int j = 0; j < h; j++)//j tu 0 den h la so phan tu trong mang hien tai (h thay doi)
	{
		if (DauS.nDS[i]->TheLoai == theloai[j])//lay the loai trong DauS voi the loai co trong mang the loai
		{
			SoLuong[j]++;//dem so luong sach thu j co trung the loai
			return false;
		}
	}
	return true;
}
void XuatDanhSachDauSachCua1TheLoai(MCONTRO DauS,string TheLoai,int SoLuong,int h,int toadoX1,int toadoY1)
{	
	int page=1;
	SapXepTheoTenSach(DauS);
	XoaManHinh(BoxMain[0],BoxMain[1]+1,BoxMain[2]-1,BoxMain[3]+1);
	int sumpage=0;
	int i=0;
	char c;
	int k[100];
	k[0]=0;
	int dem =0;
	GiaoDenXuatDauSachTheoTheLoai(toadoX1,toadoY1);
	if (SoLuong<=11)
	{
		sumpage=1;
	}
	else
	{
		sumpage=SoLuong/11+1;
	}
	a:	for(i;i<DauS.n;i++)
	{		
		if (DauS.nDS[i]->TheLoai == TheLoai) 
		{	
			//sl sach qua 10 tang page de sang trang	
			if(dem>10) 
			{
				k[page]=i;//lay sach thu 12 (k[1]=11)
				break;
			}			
			{		
			gotoXY(toadoX1 + 2, toadoY1 + 4 + dem * 2);
			cout << DauS.nDS[i]->MaDauSach;
			gotoXY(toadoX1 + 13, toadoY1 + 4 + dem * 2);
			cout<<DauS.nDS[i]->TenSach;
			gotoXY(toadoX1 + 38, toadoY1 + 4 + dem * 2);
			cout<< DauS.nDS[i]->SoTrang;
			gotoXY(toadoX1 + 48, toadoY1 + 4 + dem * 2);
			cout<<DauS.nDS[i]->TacGia;
			gotoXY(toadoX1 + 74, toadoY1 + 4 + dem * 2);
			cout<<DauS.nDS[i]->NamXuatBan;
			gotoXY(toadoX1 + 82, toadoY1 + 4 + dem * 2);
			cout<<DauS.nDS[i]->List_DMS.First->data.ViTri;
			gotoXY(toadoX1 + 95, toadoY1 + 4 + dem * 2);
			cout<<DauS.nDS[i]->SoLuongSach;
			gotoXY(toadoX1+53,toadoY1+27);
			cout<<page;
			dem++;
			}
		} 
	}	
	
	while(true)
	{
		if(kbhit())
		{
			c=getch();
			if(c==77 && page<sumpage)//phai
			{	page++;
				dem=0;
				XoaManHinh(BoxMain[0],BoxMain[1]+1,BoxMain[2]-1,BoxMain[3]+1);
				GiaoDenXuatDauSachTheoTheLoai(toadoX1,toadoY1);
				goto a;//tiep tuc duyet vong for voi i=10 
				
			}
			if(c==75 && page>1)//trai
			{	
				page--;
				dem=0;
				XoaManHinh(BoxMain[0],BoxMain[1]+1,BoxMain[2]-1,BoxMain[3]+1);
				GiaoDenXuatDauSachTheoTheLoai(toadoX1,toadoY1);
				if(page==1) // neu la trang dau thi xuat tu 0
				{
					i=k[0];
				}
				else i=k[page-1]; // neu ko la trang dau				
				goto a;				
			}	
			if (c==27) return;//ESC
		}
	}
	
}
void XuatDSTheoTungTheLoai(MCONTRO &DauS, int toadoX1, int toadoY1)
{	
	if (DauS.n == 0)		
	{
		ThongBao("THU VIEN TRONG!!");
		return;
	}
	SapXepTheoTheLoai(DauS);
	string TheLoai[100];//chua the loai 
	int SoLuong[100];//sl sach chung the loai
	//lay ten cac the loai dua vao mang TheLoai
	TheLoai[0] = DauS.nDS[0]->TheLoai;
	int h = 1;// so luong pt mang the loai
	for (int i = 0; i < DauS.n; i++)
	{
		if (LayTheLoai(DauS,TheLoai,SoLuong,h,i))// the loai khong trung trong mang TheLoai
		{
			TheLoai[h++] = DauS.nDS[i]->TheLoai;
			
		}
	}
	char c;
	a:HDXuatDauSach();
	GiaoDienInTheoTheLoai();
	
	for (int i = 0; i <h; i++)
	{
		gotoXY(100, i + 15);
		cout << TheLoai[i];
	}
	HighLight();
	gotoXY(100,15);
	cout<<TheLoai[0];
	Normal();
	ShowCur(0);
	int ptr1=100;
	int ptr2=15;

while (true)
	{
		if (kbhit())
		{
			c=getch();
			if (c==72) //len
			{
				if (ptr2==15)
					{
						//khi dang o dau thi nhan phim len se nhay xuong cuoi
						gotoXY(ptr1,ptr2);
						cout<<TheLoai[ptr2-15];//the loai thu 0
						ptr2=ptr2+h-1;//ptr2 la toa do cua the loai cuoi cung
						gotoXY(ptr1,ptr2);
						HighLight();
						cout<<TheLoai[ptr2-15];//the loai cuoi cung Theloai[h-1]
						Normal();
					}
				else
				{
					gotoXY(ptr1,ptr2);
					cout<<TheLoai[ptr2-15];// xuat ten the loai truoc khi nhan phim len
					ptr2--;
					gotoXY(ptr1,ptr2);
					HighLight();
					cout<<TheLoai[ptr2-15];//xuat the loai sau khi nhan phim len
					Normal();
				}
					
			}
			if(c==80)	//xuong
			{
				if(ptr2==15+h-1)//neu thanh sang dang o vi tri cuoi cung thi se nhay len the loai dau tien
				{
					gotoXY(ptr1,ptr2);
					cout<<TheLoai[ptr2-15];//xuat ra ten the loai cuoi cung
					ptr2=ptr2-h+1;
					HighLight();
					gotoXY(ptr1,ptr2);
					cout<<TheLoai[ptr2-15];//xuat ra the loai thu 0
					Normal();
				}
				else
				{
					gotoXY(ptr1,ptr2);
					cout<<TheLoai[ptr2-15];//xuat the loai truoc khi nhan phim xuong se mat thanh sang
					ptr2++;
					HighLight();
					gotoXY(ptr1,ptr2);
					cout<<TheLoai[ptr2-15];//xuat the loai ++ va se hien thanh sang
					Normal();
				}
			}
			else if(c==13)//enter
			{
			XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
			HDInSach();
			XuatDanhSachDauSachCua1TheLoai(DauS,TheLoai[ptr2-15],SoLuong[ptr2-15],h,toadoX1,toadoY1);//soluong thu ptr2-15 co cung the loai
			XoaManHinh(BoxMain[0],BoxMain[1]+1,BoxMain[2]-1,BoxMain[3]+1);
			goto a;
			}
			else if(c==27) //ESC
			{
				XoaManHinh(BoxMain[0],BoxMain[1]+1,BoxMain[2]-1,BoxMain[3]+1);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
				break;
			}
		}
	}
}
///////////////10 sach
bool KTMax(DauSach max[], string str, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (max[i].MaDauSach == str)
		{
			return false;
		}
	}
	return true;
}
void Xuat10DauSach(DauSach DauS[],int toadoX, int toadoY)
{
	HD10Sach();
	GiaoDienXuat10Sach(toadoX,toadoY);
	for(int i=0;i<10;i++)
	{
		if(DauS[i].SoLanMuon !=0)
		{
		gotoXY(toadoX + 1, toadoY + 4 + i * 2);
		cout << DauS[i].MaDauSach;
		gotoXY(toadoX + 16, toadoY + 4 + i * 2);
		cout << DauS[i].TenSach;
		gotoXY(toadoX + 53, toadoY + 4 + i * 2);
		cout << ChuyenSoSangString(DauS[i].SoTrang);
		gotoXY(toadoX + 67, toadoY + 4 + i * 2);
		cout << DauS[i].TacGia;
		gotoXY(toadoX + 97, toadoY + 4 + i * 2);
		cout << ChuyenSoSangString(DauS[i].SoLanMuon);
		}
	
	}
}
void Xuat10SachCoSoLuongMuonMax(MCONTRO &DauS, int toadoX, int toadoY)
{
	SapXepTheoTenSach(DauS);
	static DauSach MaxDauS[10];
	for (int h = 0; h < 10; h++)
	{
		for (int i = 0; i < DauS.n ; i++)
		{
			if (MaxDauS[h].SoLanMuon< DauS.nDS[i]->SoLanMuon && KTMax(MaxDauS, DauS.nDS[i]->MaDauSach, h) )//va DauS.nDS[i]->MaDauSach chua co trong mang MaxDauS
			{
				MaxDauS[h] = *DauS.nDS[i];//sap xep giam dan theo so luong muon
			}
		} 
	}	
	Xuat10DauSach(MaxDauS, toadoX, toadoY);
	while(true)
	{	char c;
		if(kbhit())
		{	
			c=getch();	
			if(c==27)//ESC
			{ 	
				XoaManHinh(BoxMain[0]-1,BoxMain[1]+1,BoxMain[2]-2,BoxMain[3]);
				XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
				break;
			}
		}
	}
}

bool LayThongTinDauSach(MCONTRO DauS, string madausach, DauSach *&DauSTam,NODE_LIST *tam[])
{
	if (DauS.n==0)
	{
		return false;
	}
	for(int i=0;i<DauS.n;i++)
	{
		if(DauS.nDS[i]->MaDauSach==madausach)
		{
			DauSTam = DauS.nDS[i];//do du lieu DauS vao DauSTam
			int j=0;
			for (NODE_LIST* k = DauSTam->List_DMS.First; k != NULL; k = k->next)
			{
				tam[j]=k;// do du lieu nhung sach co madausach t/m if vao mang tam
				j++;
			}
			return true;
		}
	}
	return false;
}
int TimKiemSach(string str[], string a[], int n, string &tensach)
{
	int vitri;
	int j;
	if(tensach.length()>0)              
		{                          
			for(int i=0;i<n;i++)
			{
				j=str[i].find(tensach);//tim thay tensach trong mang str
				if(j>-1)
				{
					vitri=i;
					return vitri;
				}
			}
			ThongBao("Sach khong ton tai");
		}
	return 0;
}
//XuLyPhim1( c , str , a , madausach , x , vitri , n, toadoY , pointer , i ,key);

void XuLyPhim1( char c, string str[] ,string a[] ,string &masach ,string &x, int &vitri, int &n  ,int toadoY ,int &pointer , int i, bool &key)
{
	if(c == 8)//backspace
	{
		if(x.length() > 0)
			{
				x.erase(x.begin() + x.length() - 1);//xoa ki tu cuoi cung
				gotoXY(BoxMain[0]+20, BoxMain[2]);
				cout <<"                             ";
				gotoXY(BoxMain[0]+20, BoxMain[2]);
				cout << x;
				return;
			}
	} 
	else if(c == 13) //enter
	{
		masach=a[i];
		x=str[i];//tensach
		key=false;	
		return;
		
	}
	else if(c == 27) // Esc
	{	
			key=false;	
			return;
	} 
	else if(c == -32)						
	{
		c = getch(); 
		
			if(c == 72) // len
			{
				if(pointer>toadoY)//khong phai sach dau tien thi pointer-- de di len
				{
					pointer--;
				}
				else if(pointer==toadoY && vitri>0)//sach tim dc hien len dau nhung nhan mui ten len van len dc khi vitri >0 hay ben tren no van con sach
				{
					vitri--;
					XoaManHinhTimKiem();//xoa search
					
				}
				return;
			} 
			else if(c == 80) //xuong
			{
				//n la bien dem sl sach
				if(vitri>n-21 &&vitri<n-1)
				{
					if(i>n-2) return;
					else 
					{
						if(pointer<MaxBox)
						{
							pointer++;
						}
						else if(pointer==MaxBox && vitri<n-21)
						{
							vitri++;
							XoaManHinhTimKiem();
						}
						return;
					}
		
				}
				else if (vitri==n-1) return;//vi tri cuoi cung 
				else if(pointer<MaxBox)//xuong binh thuong
				{
					pointer++;
				}
				else if(pointer==MaxBox && vitri<n-20)//vi tri cuoi cung khi nhan mui ten xuong van xuong tiep khi van con danh sach 
				{
					vitri++;
					XoaManHinhTimKiem();
				}
				return;
			}
	}

}
void XuatMaSach(MCONTRO DauS, string &madausach)
{
	int toadoX= BoxMain[0]+10;
	int toadoXtam;
	int toadoY = BoxMain[2]+3;
	int pointer=toadoY;
	GiaoDienTimkiemSach();
	string *a=new string[DauS.n];
	int n = 0;
	string *str=new string[DauS.n];
	LayMaDauSach(DauS,  str,  a, n);//a[] luu madausach str[] luu tensach, n bien dem sl sach
	char c;
	string x;// chuoi nhap de tim kiem
	string x1=x;
	int i=0;
	int vitri=0;
	bool key=true; 
	
	do
	{
		if(n==0) 
		{
			ThongBao("Khong co cuon sach nao !!");
			XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
			return;
		}
		else
		{
			if(x1==x)// chua nhap du lieu search
			{
				vitri=vitri;//=0
			}
			else
			{
				if(TimKiemSach(str, a,  n,x)==0)//tim kiem khong co sach
				{
					if(x.length() > 0)
					{
						x.erase(x.begin() + x.length() - 1);// xoa ki tu ten sach khong co
						gotoXY(BoxMain[0]+20, BoxMain[2]);
						cout <<"                             ";
						gotoXY(BoxMain[0]+20, BoxMain[2]);
						cout << x;
						madausach=a[vitri];//co ki tu nhap thi cap nhat madausach co ten trung voi ki tu nhap
					}
					vitri=vitri;//=0
				}
				else
				{
					vitri=TimKiemSach(str, a, n, x);//vi tri = vi tri tim thay trong mang str
					pointer=toadoY;
					x1=x;//x1 = chuoi nhap thong tin de search
					XoaManHinhTimKiem();
				}
			}
			BodyTable();// do hoa danh sach sach
			for(int i=vitri;i<n;i++)
			{
				if((i-(vitri))==20) break;// xuat co 20 sach trong 1 giao dien
				gotoXY(BoxMain[0] +10 , toadoY+i-(vitri));//dua sach tim len dau
				cout<<CanDeuChuoi(a[i],20)<<char(179)<<CanDeuChuoi(str[i],45);//xuat ra madausach | tensach
			}
			gotoXY(BoxMain[0]+10,pointer);
			HighLight();
			cout<<CanDeuChuoi(a[pointer-(BoxMain[2]+3)+vitri],20)<<char(179)<<CanDeuChuoi(str[pointer-(BoxMain[2]+3)+vitri],45);//thanh sang o vi tri sach search thay
			i=pointer-(BoxMain[2]+3)+vitri;//
			Normal();
			gotoXY(BoxMain[0]+20+x.length(),BoxMain[2]);//di chuyen con nhay toi phan dang nhap
			ShowCur(1);
			if(kbhit)
			{
				//ShowCur(0);
				c=getch();
				if(((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)||
					c == '+' || c == '-' || c == '*' || c == '/'||c=='.'||c=='_') && x.length()<40)//ki tu nhap
				{
					
						x.insert(x.begin() + x.length(), c);
						gotoXY(toadoX+10,BoxMain[2]);
						DinhDangChuoi(x);
						cout<< x;
					//nhap ki tu de search
				}
				else if (c == 32 && x.length() < 40 && x.length() != 0 && x[x.length()- 1] != ' ')// nhap space
				{
					x.insert(x.begin() + x.length(), ' ');
					if ((whereX() - toadoX) < x.length() - 1)
					{
						toadoXtam = whereX() + 1;
						gotoXY(toadoX, whereY());
						cout << "                                               ";
						gotoXY(toadoX, whereY());
						DinhDangChuoi(x);
						cout<< x;
						gotoXY(toadoXtam, whereY());
					}
					else
						cout << c;
				}
				else 
				{
					XuLyPhim1( c , str , a , madausach , x , vitri , n, toadoY , pointer , i ,key);// xuong len ..
				}
			}
		}
	}while(key);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	delete[]a;
	delete[]str;
	ShowCur(0);
}
void TimSach(MCONTRO DauS)
{
	a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HDTimSach();
	string madausach;
	XuatMaSach(DauS, madausach);
	if ( madausach.length()== 0 )
	{
		return;
	}
	int n;
	for(int i=0;i<DauS.n;i++)
	{
		if(DauS.nDS[i]->MaDauSach==madausach)
		{
			n=DauS.nDS[i]->SoLuongSach;
			break;
		}
	}
	DauSach* DauSTam=NULL;
	NODE_LIST *Sachtam[n];
	LayThongTinDauSach(DauS,madausach,DauSTam,Sachtam);
	XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
	XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	HD10Sach();
	BodyTable();
	int x=BoxMain[0]+5;
	int y= BoxMain[2]-2;
	gotoXY(x,y);
	cout<<" Ma dau sach  :                              ";
	gotoXY(x,y+1);
	cout<<" Ten sach     :                              ";
	gotoXY(x,y+2);
	cout<<" Tac gia      :                              ";
	gotoXY(x,y+3);
	cout<<" Nam xuat ban :                              ";
	gotoXY(x,y+4);
	cout<<" The loai     :                              ";	
	gotoXY(BoxMain[0]+22,BoxMain[2]-2);
	cout<<DauSTam->MaDauSach;
	gotoXY(BoxMain[0]+22,BoxMain[2]-1);
	cout<<DauSTam->TenSach;
	gotoXY(BoxMain[0]+22,BoxMain[2]);
	cout<<DauSTam->TacGia;
	gotoXY(BoxMain[0]+22,BoxMain[2]+1);
	cout<<DauSTam->NamXuatBan;
	gotoXY(BoxMain[0]+22,BoxMain[2]+2);
	cout<<DauSTam->TheLoai;
	int phantu = 11;
	int trang=1;
	int sotrang=1;
	if(n%11==0)
	{
		sotrang=n/11;
	}
	else
	{
		sotrang=n/11+1;
	}
	if(n<=11)
	{
		GiaoDienTimSach(BoxMain[0]+20, BoxMain[2]+4, n);
		XuatSachCua1DauSach(Sachtam , n , 0 , BoxMain[0]+20, BoxMain[2]+4);
	}
	else
	{
		GiaoDienTimSach(BoxMain[0]+20, BoxMain[2]+4, 11);
		XuatSachCua1DauSach(Sachtam , 11 , 0 , BoxMain[0]+20, BoxMain[2]+4);
	}
	char c;
	while(true)
	{
		if(kbhit)
		{
			c=getch();
			if(c == -32)
			{
				c=getch();
				if(c == 77) // qua phai
				{
					if(sotrang>1 && trang<sotrang)
					{
						phantu = n-trang*11;
						if(phantu>=11)
						{
							phantu=11;
						}
						XoaManHinhTimKiemSach();
						GiaoDienTimSach(BoxMain[0]+20, BoxMain[2]+4, phantu);
						XuatSachCua1DauSach(Sachtam , trang*11+phantu , trang*11 , BoxMain[0]+20, BoxMain[2]+4);
						trang++;
					}
				}
				else  if(c==75)// qua trai
				{
					if(trang>1)
					{
						phantu=11;
						trang--;
						XoaManHinhTimKiemSach();
						GiaoDienTimSach(BoxMain[0]+20, BoxMain[2]+4, phantu);
						XuatSachCua1DauSach(Sachtam , trang*11-11+phantu , trang*11-11 , BoxMain[0]+20, BoxMain[2]+4);
					}
				}
			}
			else if(c==27)
			{
				XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2]-2,BoxMain[3]);
				return;
			}	
		}
	}
	for(int i=0;i<n;i++)
	{
		NODE_LIST* t = Sachtam[i];
		Sachtam[i] = Sachtam[i]->next;
		delete t;
	}
	Normal();
}  
void SuaThongTinSach(MCONTRO & DauS)
{
	int toadoX=55;
	int  toadoY =5;
	while(true)
	{
		a:XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
		HDTimSach();
		string madausach;
		XuatMaSach(DauS, madausach);
		if ( madausach.length()== 0 )
		{
			return;
		}
		int n;
		DauSach* DauSTam=NULL;
		NODE_LIST *Sachtam[n];
		LayThongTinDauSach(DauS,madausach,DauSTam,Sachtam);// do du lieu cua DauS vao DauSTam va nhung sach vao SachTam (t/m madausach= DauS.n[i]->MaDauSach)
		XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
		XoaManHinh(BoxHuongDan[0],BoxHuongDan[1],BoxHuongDan[2],BoxHuongDan[3]);
	  	HDNhapDauSach();
		// luu lai cac gia tri
		string TenSachTam;
		string TacGiaTam;
		string TheloaiTam;
		string ViTriTam;
		int SoTrangTam,NamXuatBanTam,SoLuongSachTam;
		//
		TenSachTam=DauSTam->TenSach;
		TacGiaTam= DauSTam->TacGia;
		TheloaiTam=DauSTam->TheLoai;
		ViTriTam=Sachtam[n]->data.ViTri;
		SoTrangTam=DauSTam->SoTrang;
		NamXuatBanTam=DauSTam->NamXuatBan;
		SoLuongSachTam=DauSTam->SoLuongSach;
		int pointer=9;
		char c;
		GiaoDienThemDauSach1(toadoX ,toadoY );
		gotoXY(100,  30);
		cout << "Cap Nhat";
		gotoXY(toadoX + 21, 6);
		cout << DauSTam->MaDauSach;
		gotoXY(toadoX + 21, pointer);
		cout << DauSTam->TenSach;
		gotoXY(toadoX + 21, pointer+3);
		cout<<DauSTam->SoTrang;
		gotoXY(toadoX + 21, pointer+6);
		cout<<DauSTam->TacGia;
		gotoXY(toadoX + 21, pointer+9);
		cout<<DauSTam->NamXuatBan;
		gotoXY(toadoX + 21, pointer+12);
		cout<<DauSTam->TheLoai;
		gotoXY(toadoX + 21, pointer+15);
		string vitridausach=TachLayViTri(Sachtam[n]->data.ViTri);
		cout<<vitridausach;
		int sl=DauSTam->SoLuongSach;
		gotoXY(toadoX + 21, pointer+18);
		cout<<DauSTam->SoLuongSach;
		Normal();
		ShowCur(1);
		pointer = 9;
		while (true)
		{
	
		if (pointer == 9) 
		{
			gotoXY( toadoX + 21 + DauSTam->TenSach.length(), pointer);
			XuLyNhap_TenSach1(DauSTam->TenSach, toadoX + 21 , pointer,40);
			if (DauSTam->TenSach.empty())
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "Ten Sach Rong";
			}
			else if (!KTTenSach(DauSTam->TenSach))
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "Ten Khong Hop Le";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 4);
				cout << "                 ";
			}
			
			if (pointer < 9)
				{
					pointer = 30;
				}
		}
		else if (pointer == 12) // so trang
		{
			gotoXY(toadoX + 21 + DemChuSo(DauSTam->SoTrang), pointer);
			XuLyNhap_So(DauSTam->SoTrang, toadoX + 21 , pointer);
			if (DauSTam->SoTrang <= 0)
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "So Trang Phai >0";
			}
			else if (DauSTam->SoTrang > 10000)
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "So Trang <10000";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 7);
				cout << "                ";
			}
		}
		else if (pointer == 15)// tac gia
		{
			gotoXY(toadoX + 21 + DauSTam->TacGia.length(), pointer);
			XuLyNhap_Chu(DauSTam->TacGia, toadoX + 21, pointer,25);
			if (DauSTam->TacGia.empty())
			{
				gotoXY(toadoX + 80, toadoY + 10);
				cout << "Tac Gia Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 10);
				cout << "            ";
			}
		}
		else if (pointer == 18) // nam
		{
			gotoXY(toadoX + 21 + DemChuSo(DauSTam->NamXuatBan), pointer);
			XuLyNhap_So(DauSTam->NamXuatBan, toadoX + 21, pointer);
			if (DauSTam->NamXuatBan > 2021 || DauSTam->NamXuatBan < 1000)
			{
				gotoXY(toadoX + 80, toadoY + 13);
				cout << "Nam K Hop Le";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 13);
				cout << "             ";
			}
		}
		else if (pointer == 21) // the loai
		{
			gotoXY(toadoX + 21 + DauSTam->TheLoai.length(), pointer);
			XuLyNhap_Chu(DauSTam->TheLoai, toadoX + 21, pointer,20);
			if (DauSTam->TheLoai.empty())
			{
				gotoXY(toadoX + 80, toadoY + 16);
				cout << "The Loai Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 16);
				cout << "              ";
			}
		}
		else if (pointer == 24) // vi tri
		{
			gotoXY(toadoX + 21 + vitridausach.length(), pointer);
			XuLyNhap_ViTri(vitridausach, toadoX + 21, pointer,20);
			if (vitridausach.empty())
			{
				gotoXY(toadoX + 80, toadoY + 19);
				cout << "Vi Tri Rong";
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 19);
				cout << "           ";
			}
		}
		else if (pointer == 27) //so luong
		{
			gotoXY(toadoX + 21 + DemChuSo(DauSTam->SoLuongSach), pointer);
			XuLyNhap_So(DauSTam->SoLuongSach, toadoX + 21, pointer);
			if (DauSTam->SoLuongSach <= 0)
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "So Luong >0";
			}
			else if (DauSTam->SoLuongSach > sl)
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "So Luong <="<<sl;
			}
			else
			{
				gotoXY(toadoX + 80, toadoY + 22);
				cout << "                  ";
			}
		}
		else if (pointer == 30) // Cap nhat hoac huy
			{
				ShowCur(0);
				int pointer2 = 100;
				while (true)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 13)
						{
							if (!DauSTam->TenSach.empty() && DauSTam->SoTrang<=10000 && DauSTam->SoTrang>=0 && !DauSTam->TacGia.empty()&& DauSTam->NamXuatBan <= 2021&&
							 DauSTam->NamXuatBan > 1000 &&
							!DauSTam->TheLoai.empty()&& DauSTam->SoLuongSach <= sl &&DauSTam->SoLuongSach >=0 &&!vitridausach.empty()&& pointer2 == 100)
							{
								
								DinhDangChuoi(DauSTam->TenSach);
								DinhDangChuoi(DauSTam->TacGia);
								DinhDangChuoi(DauSTam->TheLoai);
								DinhDangChuoi(vitridausach);
								DauS.nDS[DauS.n]=DauSTam;
								int j=1,k=1;
								if(DauS.nDS[DauS.n]->MaDauSach==DauSTam->MaDauSach)
								{		
									for (int i = 1; i <= DauSTam->SoLuongSach ; i++)
									{
										for (NODE_LIST* p = DauS.nDS[DauS.n]->List_DMS.First; p != NULL; p = p->next)
										{
										
											if(p->data.MaSach==NoiChuoi(DauS.nDS[DauS.n]->MaDauSach,i))
											{
														
														p->data.ViTri=NoiChuoi(vitridausach,j++);
											}
										}
										
		
									}
								}
								ThongBao("Cap nhat thanh cong");
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
							else
							{
								ThongBao("Vui long dien day du thong tin");
							}
						}
						else if (c == 27)
							{
								DauSTam->TenSach=TenSachTam;
								DauSTam->SoTrang=SoTrangTam;
								DauSTam->TacGia=TacGiaTam;
								DauSTam->NamXuatBan=NamXuatBanTam;
								DauSTam->TheLoai=TheloaiTam;
								DauSTam->SoLuongSach=SoLuongSachTam;
								XoaManHinh(BoxMain[0],BoxMain[1],BoxMain[2],BoxMain[3]);
								goto a;
							}
						else if (c == -32)
						{
							c = getch();
							if (c == 72)//len
							{
								Normal();
								gotoXY(100, 30);
								cout << "Cap nhat";
								ShowCur(1);
								pointer = pointer - 3;
								break;
							}
							else if (c == 80)//xuong
							{
								Normal();
								gotoXY(100, 30);
								cout << "Cap nhat";
								ShowCur(1);
								pointer = 9;
								break;
							}
							gotoXY(pointer2, 30);
						}
					}
					HighLight();
					gotoXY(pointer2, pointer);
					if (pointer2 == 100)
					{
							
						cout << "Cap nhat";
						Normal();
						HDNhapDauSach1();
					}
				}
			}
		}
	}
}


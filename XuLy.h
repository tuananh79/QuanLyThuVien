void DinhDangChuoi(string& str)
{
	//Xoa khoang trang
	while (str[0] == ' ')//ki tu dau tien la ' '
	{
		str.erase(str.begin() + 0);//xoa ki tu dau
	}
	while (str[str.length() - 1] == ' ')//ki tu cuoi la ' '
	{
		str.erase(str.begin() + (str.length() - 1));//xoa vi tri cuoi
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')// 2 ki tu ' ' lien tiep
		{
			str.erase(str.begin() + i);//xoa vi tri i+1
			i--;// quay lai vi tri i de tranh truong hop 3 khoang trang lien tiep
		}
	}
	//Viet thuong tat ca lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa chu cai moi tu
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i+1] && str[i + 1] <= 122))//vi tri tiep theo sau khoang trang se viet hoa
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}

}
int Random()
{
	srand(time(NULL));
	int a;
	while (true)
	{
		a = 1 + rand() % MienGiaTriNgauNhien;
		if (MangRandom[a] == false)
		{
			MangRandom[a] = true;
			SoLuongDocGia++;
			return a;
		}
	}
}
void LayMaDocGiaMuonSachQuaHan(TREE_TDG t, int a[], int& i) 
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGiaMuonSachQuaHan(t->left,a,i);
	if(t->thedocgia.TrangThai== 0)
	{
		a[i] = t->thedocgia.MaThe;
		i++;
	}
	LayMaDocGiaMuonSachQuaHan(t->right, a,i);
}
void LayMaDocGia(TREE_TDG t,string str[], int a[], int& i) 
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGia(t->left,str,a,i);
	str[i] = t->thedocgia.Ho + " " + t->thedocgia.Ten;
	a[i] = t->thedocgia.MaThe;
	i++;
	LayMaDocGia(t->right, str, a,i);
}
void LayMaDocGiaDeXoa(TREE_TDG t, string str[], int a[],  int& i)
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGiaDeXoa(t->left, str, a,i);
	if (t->thedocgia.SoLuongSachDangMuon == 0 && t->thedocgia.TrangThai== 1)
	{
		str[i] = t->thedocgia.Ho + " " + t->thedocgia.Ten;
		a[i] = t->thedocgia.MaThe;
		i++;
	}
	LayMaDocGiaDeXoa(t->right, str, a,i);
}
void LayMaDocGiaDeTra(TREE_TDG t, string str[], int a[],  int& i)
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGiaDeTra(t->left, str, a,i);
	if(t->thedocgia.SoLuongSachDangMuon > 0)
	{
		str[i] = t->thedocgia.Ho + " " + t->thedocgia.Ten;
		a[i] = t->thedocgia.MaThe;
		i++;
	}
	LayMaDocGiaDeTra(t->right, str, a,i);
}
void LayMaDocGiaDeMuon(TREE_TDG t, string str[], int a[], int& i)
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGiaDeMuon(t->left, str, a, i);
	if (t->thedocgia.SoLuongSachDangMuon < 3 &&t->thedocgia.TrangThai == 1)
	{
		str[i] = t->thedocgia.Ho + " " + t->thedocgia.Ten;
		a[i] = t->thedocgia.MaThe;
		i++;
	}
	LayMaDocGiaDeMuon(t->right, str, a, i);
}
char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
string TrangThaiDocGia(int n)
{
	if (n == 1)
		return "Hoat Dong";
	else
		return "Khoa";
}
void LayMaDocGiaDaMuonSach(TREE_TDG t, string str[], int a[], int& i)
{
	if (t == NULL)
	{
		return;
	}
	LayMaDocGiaDaMuonSach(t->left, str, a, i);
	if (t->thedocgia.List_MuonTra.First!=NULL)
	{
		str[i] = t->thedocgia.Ho + " " + t->thedocgia.Ten;
		a[i] = t->thedocgia.MaThe;
		i++;
	}
	LayMaDocGiaDaMuonSach(t->right, str, a, i);
}
void LayMaDauSach(MCONTRO DauS, string str[], string a[], int &n)
{
	if (DauS.n==0)
	{
		return;
	}
	for (int i = 0; i < DauS.n; i++)
	{
		a[i]=DauS.nDS[i]->MaDauSach;
		str[i] = DauS.nDS[i]->TenSach;
		n++;
	}
}
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
string ChuyenSoSangString1(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));//them ki tu do vao vi tri dau tien
		n = n / 10;
	}
	return str;
}
string NoiChuoi(string str, int n)//noi string voi int trong vi tri cua sach
{
	string str2;
	str2 = str;
	string str1 = ChuyenSoSangString(n);
	str2.push_back('_');//day 1 phan tu vao sau cung
	for (int i = 0; i < str1.length(); i++)
	{
		str2.push_back(str1[i]);
	}
	return str2;// str_n
}
string NoiChuoi1(string str, int n)//noi string voi int trong vi tri cua sach
{
	string str2;
	str2 = str;
	string str1 = ChuyenSoSangString(n);
	//str2.erase(str2.end()-1);
	str2.erase(str2.end()-1);
	str2.push_back('_');//day 1 phan tu vao sau cung
	for (int i = 0; i < str1.length(); i++)
	{
		str2.push_back(str1[i]);
	}
	return str2;// str_n
}

string TachLayMaDauSach(string str)
{
	//lay ki tu truoc dau _
	string str1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}
string TachLayViTri(string str)
{
	//lay ki tu truoc dau _
	string str1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			break;
		}
		str1.push_back(str[i]);
	}
	return str1;
}
int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}
void LayNgayHienTai(Date& d)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);
	string str1, str2, str3;
	//ngay
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.Ngay = atoi(str1.c_str());
	// thang
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.Thang = ChuyenThang(str2);
	//nam
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.Nam = atoi(str3.c_str());
}
bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}
int SoSanhNgay(Date d, Date t) 
{
	if (d.Nam == t.Nam)
	{
		if (d.Thang == t.Thang)
		{
			if (d.Ngay > t.Ngay)
			{
				return 1;
			}
			else if (d.Ngay < t.Ngay)
			{
				return 2;
			}
			else
				return 3;
		}
		else if (d.Thang > t.Thang)
		{
			return 1;
		}
		else
			return 2;
	}
	else if (d.Nam > t.Nam)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
int SoNgayQuaHan(Date d)
{
	Date d1;
	LayNgayHienTai(d1);
	if (SoSanhNgay(d1, d) == 1)
	{
		if (d.Nam == d1.Nam)
		{
			if (d.Thang == d1.Thang)
			{
				return d1.Ngay - d.Ngay;
			}
			else
			{
				return SoNgayCuaThang(d.Thang) - d.Ngay + d1.Ngay;
			}
		}
		else
		{
			int SoNgayConLaiCuaNam = 0;
			for (int i = 1; i < d.Thang; i++)
			{
				SoNgayConLaiCuaNam = SoNgayConLaiCuaNam + i * SoNgayCuaThang(i);
			}
			if (KTNamNhuan(d.Nam))
			{
				return 366 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
			else
			{
				return 365 - SoNgayConLaiCuaNam - d.Ngay + d1.Ngay;
			}
		}
	}
	else
		return 0;
}
Date CongNgay(Date t,int SoNgay)
{
	Date d = t;
	d.Ngay = d.Ngay + SoNgay;
	if (d.Ngay > SoNgayCuaThang(d.Thang))
	{
		if (d.Thang == 12)
		{
			d.Thang = 1;
			d.Nam = d.Nam + 1;
		}
		else
		{
			d.Thang = d.Thang + 1;
		}
		d.Ngay = d.Ngay - SoNgayCuaThang(t.Thang);
	}
	return d;
}

void KiemTraQuaHan(TREE_TDG& t, Date NgayHienTai)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		Date Max;
		LayNgayHienTai(Max);
		for (NODE_LIST_MUONTRA* k = t->thedocgia.List_MuonTra.First; k != NULL; k = k->next)
		{
			if (k->data.TrangThai == 0 && SoSanhNgay(NgayHienTai, CongNgay(k->data.NgayMuon,SoNgayMuonMax)) == 1)
			{
				t->thedocgia.TrangThai = 0;
				if (SoSanhNgay(Max, k->data.NgayMuon) == 1)
				{
					Max = k->data.NgayMuon;
				}
			}
			else if (k->data.TrangThai == 3)
			{
				t->thedocgia.TrangThai = 0;
			}
		}

		KiemTraQuaHan(t->left, NgayHienTai);
		KiemTraQuaHan(t->right, NgayHienTai);
	}
}
string LayTenSach(MCONTRO DauS, string MaSach)
{
	for (int i = 0; i < DauS.n; i++)
	{
		if (DauS.nDS[i]->MaDauSach == TachLayMaDauSach(MaSach))
		{
			return DauS.nDS[i]->TenSach;
		}
	}
	return "Ma Sach Ton Tai";
}
string TrangThaiMuonTra(int n)
{
	if (n == 0)
		return "Dang Muon";
	else if (n == 1)
		return "Da Tra";
}
string TrangThaiSach(int n)
{
	if (n == 0)
		return "San Sang";
	else if (n == 1)
		return "Da Muon";
}
void KiemTraQuaHan1DocGia(TREE_TDG &t, Date NgayHienTai)
{
	bool KTKhoaDG=false;
	Date Max;
	LayNgayHienTai(Max);
	for (NODE_LIST_MUONTRA* k = t->thedocgia.List_MuonTra.First; k != NULL; k = k->next)
	{
		if (k->data.TrangThai == 0 && SoSanhNgay(NgayHienTai, CongNgay(k->data.NgayMuon,7)) == 1)
		{
			KTKhoaDG = true;
			t->thedocgia.TrangThai = 0;
			if (SoSanhNgay(Max, k->data.NgayMuon) == 1)
			{
				Max = k->data.NgayMuon;
			}
		}
		else if (k->data.TrangThai == 3)
		{
			KTKhoaDG = true;
			t->thedocgia.TrangThai = 0;
		}
	}
	if (KTKhoaDG == false)
	{
		t->thedocgia.TrangThai = 1;
	}
}
bool laNamNhuan(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int tinhSoNgayTrongThang(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (laNamNhuan(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
bool KTNgayHopLe(int nDay, int nMonth, int nYear)
{
	// Kiem tra nam
	if (nYear < 0)
	{
		return false;
	}

	// Kiem tra tháng
	if (nMonth < 1 || nMonth > 12)
	{
		return false; 
	}

	// Ki?m tra ngày
	if (nDay < 1 || nDay > tinhSoNgayTrongThang(nMonth, nYear))
	{
		return false; 
	}

	return true; 
}
int DemChuSo(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}
void SapXepTheoTen(MCONTRO &DauS)
{
	DauSach* tam=NULL;
	for (int i = 0; i < DauS.n - 1; i++)
	{
		for (int j = i + 1; j < DauS.n; j++)
		{
			if (DauS.nDS[i]->TenSach > DauS.nDS[j]->TenSach)
			{
				tam = DauS.nDS[i];
				DauS.nDS[i] = DauS.nDS[j];
				DauS.nDS[j] = tam;
			}
		}
	}
}
void SapXepTheoTenSach(MCONTRO &DauS)
{
	DauSach* temp = NULL;	
	for (int i = 0; i < DauS.n - 1; i++)
	{
		for (int j = i + 1; j < DauS.n; j++)
		{	
			string ten=DauS.nDS[i]->TenSach;
			string ten1=DauS.nDS[j]->TenSach;
			//if (DauS.nDS[i]->TenSach > DauS.nDS[j]->TenSach)
			if (_stricmp((char*)ten.c_str(), (char*)ten1.c_str())>0)
			{
				temp = DauS.nDS[i];
				DauS.nDS[i] = DauS.nDS[j];
				DauS.nDS[j] = temp;
			}
		}
	}
}
void SapXepTheoTheLoai(MCONTRO &DauS)
{
	DauSach *temp= NULL;
	for (int i=0;i<DauS.n-1;i++)
	{
		for(int j=i+1;j< DauS.n;j++)
		{
			string ten=DauS.nDS[i]->TheLoai;
			string ten1=DauS.nDS[j]->TheLoai;
		//	if ( DauS.nDS[i]->TheLoai > DauS.nDS[j]->TheLoai)
			if (_stricmp((char*)ten.c_str(), (char*)ten1.c_str())>0)
			{
				temp= DauS.nDS[i];
				DauS.nDS[i]=DauS.nDS[j];
				DauS.nDS[j]=temp;
			}
		}
	}
}

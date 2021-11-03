void ThemSachTuFile(MCONTRO &DauS, string MaSach, string ViTri)
{
	NODE_LIST* p = new NODE_LIST;
	if (p == NULL)
	{
		cout << "\nCap phat that bai !";
		return;
	}
	p->data.MaSach = MaSach;
	p->data.TrangThai = 0;
	p->data.ViTri = ViTri;
	p->next = NULL;
	if (DauS.nDS[DauS.n]->List_DMS.First == NULL)
	{
		DauS.nDS[DauS.n]->List_DMS.First = DauS.nDS[DauS.n]->List_DMS.Last = p;
	}
	else
	{
		DauS.nDS[DauS.n]->List_DMS.Last->next=p;
		DauS.nDS[DauS.n]->List_DMS.Last = p;
	}
}
void LoadFileDauSach(MCONTRO& DauS) 
{
	int n;
	string vitri;
	ifstream f;
	f.open("DauSach.txt", ios::in);
	f >> n;
	f.ignore();//xoa bo nho dem
	for (int i = 0; i < n; i++)
	{
		DauS.nDS[DauS.n] = new DauSach;
		getline(f, DauS.nDS[DauS.n]->MaDauSach, ',');
		getline(f, DauS.nDS[DauS.n]->TenSach, ',');
		f >> DauS.nDS[DauS.n]->SoTrang;
		//FileIn.seekg(1, ios::cur);
		f.ignore();
		getline(f, DauS.nDS[DauS.n]->TacGia, ',');
		f >> DauS.nDS[DauS.n]->NamXuatBan;
		//FileIn.seekg(1, ios::cur);
		f.ignore();
		getline(f, DauS.nDS[DauS.n]->TheLoai, ',');
		f >> DauS.nDS[DauS.n]->SoLuongSach;
		//FileIn.seekg(1, ios::cur);
		f.ignore();
		getline(f, vitri);
		DauS.nDS[i]->SoLanMuon = 0;
		DauS.nDS[DauS.n]->List_DMS.First = NULL;
		DauS.nDS[DauS.n]->List_DMS.Last = NULL;
		for (int i = 1; i <= DauS.nDS[DauS.n]->SoLuongSach; i++)
		{
			ThemSachTuFile(DauS, NoiChuoi(DauS.nDS[DauS.n]->MaDauSach, i), NoiChuoi(TachLayMaDauSach(vitri), i));
		}
		DauS.n++;
	}
	f.close();
}
void ThemTheDocGiaTuFile(TREE_TDG& t, int x, ifstream& f)
{
	if (t == NULL)   
	{
		NODE_TREE* p = new NODE_TREE;
		p->thedocgia.MaThe = x;
		//FileIn.seekg(1, ios::cur);
		f.ignore();
		getline(f, p->thedocgia.Ho, ',');
		getline(f, p->thedocgia.Ten, ',');
		getline(f, p->thedocgia.Phai, ',');
		f >> p->thedocgia.TrangThai;
		f.ignore();
		p->thedocgia.SoLuongSachDangMuon = 0;
		p->thedocgia.List_MuonTra.First = NULL;
		p->thedocgia.List_MuonTra.Last = NULL;
		p->left = NULL;
		p->right = NULL;
		t = p;
	}
	else if (t->thedocgia.MaThe > x)
	{
		ThemTheDocGiaTuFile(t->left, x, f);
	}
	else
	{
		ThemTheDocGiaTuFile(t->right, x, f);
	}
}
void LoadFileTheDocGia(TREE_TDG& t)
{
	int MaDocGia;
	ifstream f;
	f.open("DocGia.txt", ios::in);
	string tam;
	while(f.good())
	{
		MaDocGia = 0;
		f >> MaDocGia;
		if (MaDocGia == 0)
		{
			break;
		}
		MangRandom[MaDocGia] = true;
		SoLuongDocGia++;
		ThemTheDocGiaTuFile(t, MaDocGia, f);
	}
	f.close();
}
void ThemDanhSachSachMuonTraTuFile(TREE_TDG& t, int x, ifstream& f, MCONTRO& DauS)
{
	if (t == NULL)
	{
		return;
	}
	else if (t->thedocgia.MaThe == x)
	{
		NODE_LIST_MUONTRA* p = new NODE_LIST_MUONTRA;
		if (p == NULL)
		{
			cout << "\nCap phat that bai !";
			return;
		}
		getline(f, p->data.MaSach, ',');
		f >> p->data.NgayMuon.Ngay;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		f >> p->data.NgayMuon.Thang;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		f >> p->data.NgayMuon.Nam;
		f.ignore();
		//.seekg(1, ios::cur);
		f >> p->data.NgayTra.Ngay;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		f >> p->data.NgayTra.Thang;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		f >> p->data.NgayTra.Nam;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		f >> p->data.TrangThai;
		if (p->data.TrangThai == 0)
		{
			t->thedocgia.SoLuongSachDangMuon++;
		}
		else if (p->data.TrangThai == 3)
		{
			t->thedocgia.TrangThai = 0;
		}
		
		p->next = NULL;

		for (int i = 0; i < DauS.n; i++)
		{
			if (TachLayMaDauSach(p->data.MaSach) == DauS.nDS[i]->MaDauSach)
			{
				for (NODE_LIST* k = DauS.nDS[i]->List_DMS.First; k != NULL; k = k->next)
				{
					if (p->data.MaSach == k->data.MaSach)
					{
						DauS.nDS[i]->SoLanMuon++;
						if (p->data.TrangThai == 0) // dang muon
						{
							k->data.TrangThai = 1; //da co doc gia muon
						}
						else if (p->data.TrangThai == 2)// lam mat
						{
							k->data.TrangThai = 2; //da thanh li
						}
						break;
					}
				}
				break;
			}
		}
		
		if (t->thedocgia.List_MuonTra.First == NULL)
		{
			t->thedocgia.List_MuonTra.First = t->thedocgia.List_MuonTra.Last = p;
		}
		else
		{
			t->thedocgia.List_MuonTra.Last->next = p;
		//	p->left = t->thedocgia.List_MuonTra.Last;
			t->thedocgia.List_MuonTra.Last = p;
		}
		return;
	}
	else if (t->thedocgia.MaThe > x)
	{
		ThemDanhSachSachMuonTraTuFile(t->left, x, f, DauS);
	}
	else
	{
		ThemDanhSachSachMuonTraTuFile(t->right, x, f, DauS);
	}
}
void LoadFileDanhSachSachMuonTra(TREE_TDG& t, MCONTRO& DauS)
{
	int x;
	ifstream f;
	f.open("DanhSachSachMuonTra.txt", ios::in);
	while (1)
	{
		x = 0;
		f >> x;
		f.ignore();
		//FileIn.seekg(1, ios::cur);
		if (x == 0)
		{
			break;
		}
		ThemDanhSachSachMuonTraTuFile(t, x, f, DauS);
		if (f.eof())
		{
			break;
		}
	}
	f.close();
}
void Load(MCONTRO& DauS, TREE_TDG& t)
{
	LoadFileDauSach(DauS);
	LoadFileTheDocGia(t);
	LoadFileDanhSachSachMuonTra(t, DauS);
}

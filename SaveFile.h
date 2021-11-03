
void SaveDanhSachDauSach(MCONTRO DauS) 
{
	ofstream f;
	f.open("DauSach.txt", ios::out);
	f << DauS.n << endl;
	for (int i = 0; i < DauS.n; i++)
	{
		f << DauS.nDS[i]->MaDauSach << ",";
		f << DauS.nDS[i]->TenSach << ",";
		f << DauS.nDS[i]->SoTrang << ",";
		f << DauS.nDS[i]->TacGia << ",";
		f << DauS.nDS[i]->NamXuatBan << ",";
		f << DauS.nDS[i]->TheLoai << ",";
		f << DauS.nDS[i]->SoLuongSach << ",";
		f << DauS.nDS[i]->List_DMS.First->data.ViTri << endl;
	}
	f.close();
}
void SaveDanhSachDocGiavaMuonTra(TREE_TDG t, ofstream& f1, ofstream& f2)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		f1 << t->thedocgia.MaThe << ",";
		f1 << t->thedocgia.Ho << "," ;
		f1 << t->thedocgia.Ten << ",";
		f1 << t->thedocgia.Phai << ",";
		f1 << t->thedocgia.TrangThai << endl;
		for (NODE_LIST_MUONTRA* a = t->thedocgia.List_MuonTra.First; a != NULL; a = a->next)
		{
			f2 << t->thedocgia.MaThe << "," << a->data.MaSach << ",";
			f2 << a->data.NgayMuon.Ngay << "/" << a->data.NgayMuon.Thang << "/" << a->data.NgayMuon.Nam << ",";
			f2 << a->data.NgayTra.Ngay << "/" << a->data.NgayTra.Thang << "/" << a->data.NgayTra.Nam << ",";
			f2 << a->data.TrangThai << endl;
		}
		SaveDanhSachDocGiavaMuonTra(t->left, f1, f2);
		SaveDanhSachDocGiavaMuonTra(t->right, f1, f2);
	}
}
void Save(TREE_TDG t, MCONTRO DauS)
{
	SaveDanhSachDauSach(DauS);

	ofstream f1, f2;
	f1.open("DocGia.txt", ios::out);
	f2.open("DanhSachSachMuonTra.txt", ios::out);
	SaveDanhSachDocGiavaMuonTra(t, f1, f2);
	f1.close();
	f2.close();
}

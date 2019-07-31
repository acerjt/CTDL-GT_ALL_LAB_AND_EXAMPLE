#include <iostream>
#include <string>
#include <fstream>
#define NOW 2001
using namespace std;

struct SinhVien
{
	int MSSV;
	string Ho;
	string Ten;
	int Ngay;
	int Thang;
	int Nam;
	int Gioitinh;
	float Dtb;
};
bool checkmssv(int mssv, string file);
void inputsv(SinhVien sv, string file);
bool chekngay(int ngay);
bool chekngaythang(int ngay, int thang);
bool chekngaythangnam(int ngay, int thang, int nam);
bool checkgioitinh(int gioitinh);
bool checkdiemtrungbinh(float dtb);
void inputngaythangnam(SinhVien &sv);
void writefilesv(SinhVien sv, string file);
void readfilesv(SinhVien sv[], int &n, string file);
void outputsortmssv(SinhVien sv[], int n);
void sortmssv(SinhVien sv[], int n);
void sortdtb(SinhVien sv[], int n);
int main()
{
	system("color 0a");
	int n;
	SinhVien SV[1000];
	cout << "So sinh vien can nhap ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Sinh vien " << i + 1 << endl;
		SinhVien sv;
		inputsv(sv, "SinhVien.dat");
	}
	readfilesv(SV, n, "SinhVien.dat");
	sortmssv(SV, n);
	outputsortmssv(SV, n);
	sortdtb(SV, n);
	outputsortmssv(SV, n);
	system("pause");
}
void outputsv(SinhVien sv)
{
	cout << "Ma so sinh vien: " << sv.MSSV << endl;
	cout << "Ho sinh vien: " << sv.Ho << endl;
	cout << "Ten sinh vien: " << sv.Ten << endl;
	cout << "Ngay thang nam sinh sinh vien: " << sv.Ngay << "/" << sv.Thang << "/" << sv.Nam << endl;
	string gt;
	if (sv.Gioitinh == 0)
		gt = "Nu";
	else
		gt = "Nam";
	cout << "Gioi tinh sinh vien: " << gt << endl;
	cout << "Diem trung binh sinh vien: " << sv.Dtb << endl;
	cout << endl;
}
void outputsortmssv(SinhVien sv[], int n)
{
	for (int i = 0; i < n; i++)
		outputsv(sv[i]);
	
}
void sortmssv(SinhVien sv[], int n)
{
	cout << "===========================================" << endl;
	cout << "Danh sach sinh vien theo ma tang dan" << endl;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (sv[i].MSSV > sv[j].MSSV)
				swap(sv[i], sv[j]);
}
void sortdtb(SinhVien sv[], int n)
{
	cout << "===========================================" << endl;
	cout << "Danh sach sinh vien theo diem giam dan" << endl;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (sv[i].Dtb < sv[j].Dtb)
				swap(sv[i], sv[j]);
}
void swap(SinhVien &a, SinhVien &b)
{
	SinhVien temp = a;
	a = b;
	b = temp;
}
void readfilesv(SinhVien sv[], int &n,string file)
{
	n = 0;
	fstream f;
	f.open(file, ios::in);
	string checkEnd;
	while (f >> checkEnd)
	{
		SinhVien SV;
		SV.MSSV = stoi(checkEnd.c_str());
		f >> SV.Ho >> SV.Ten >> SV.Ngay >> SV.Thang >> SV.Nam >> SV.Gioitinh >> SV.Dtb;
		sv[n] = SV;
		n++;
	}
	f.close();
}
void inputsv(SinhVien sv, string file)
{
	do
	{
		cout << "Nhap ma so sinh vien ";
		cin >> sv.MSSV;
	} while (!checkmssv(sv.MSSV, file));
	cout << "Nhap ho sinh vien ";
	cin >> sv.Ho;
	cout << "Nhap ten sinh vien ";
	cin >> sv.Ten;
	inputngaythangnam(sv);
	do
	{
		cout << "Nhap gioi tinh sinh vien ";
		cin >> sv.Gioitinh;
	} while (!checkgioitinh(sv.Gioitinh));
	do
	{
		cout << "Nhap diem trung binh sinh vien ";
		cin >> sv.Dtb;
	} while (!checkdiemtrungbinh(sv.Dtb));
	writefilesv(sv, file);
}
void writefilesv(SinhVien sv, string file)
{
	fstream f;
	f.open(file, ios::app);
	f << sv.MSSV << " " << sv.Ho << " " << sv.Ten << " " << sv.Ngay << " " << sv.Thang << " " << sv.Nam << " " << sv.Gioitinh << " " << sv.Dtb << endl;
	f.close();
	
}
bool checkdiemtrungbinh(float dtb)
{
	if (dtb < 0 || dtb > 10)
	{
		cout << "Sai gia tri qui dinh" << endl;
		return false;
	}
	return true;
}
bool checkgioitinh(int gioitinh)
{
	if (gioitinh < 0 || gioitinh > 1)
	{
		cout << "Sai gia tri qui dinh" << endl;
		return false;
	}
	return true;
}
void inputngaythangnam(SinhVien &sv)
{
	do
	{
		cout << "Nhap ngay ";
		cin >> sv.Ngay;
	} while (!chekngay(sv.Ngay));
	do
	{
		cout << "Nhap Thang ";
		cin >> sv.Thang;
	} while (!chekngaythang(sv.Ngay, sv.Thang));
	do
	{
		cout << "Nhap Nam ";
		cin >> sv.Nam;
	} while (!chekngaythangnam(sv.Ngay, sv.Thang, sv.Nam));
}
bool chekngaythangnam(int ngay, int thang,int nam)
{
	if (thang == 2 && ngay == 29 && nam % 4 != 0)
	{
		cout << "Ngay thang nam khong hop le" << endl;
		return false;
	}
	if (nam < 0 || nam > NOW)
	{
		cout << "Nam khong hop le" << endl;
		return false;
	}
		
	return true;
}
bool chekngaythang(int ngay, int thang)
{
	if (thang > 12 || thang < 1)
	{
		cout << "Thang khong hop le" << endl;
		return false;
	}
	else if ((thang == 4 ||
		thang == 6 ||
		thang == 9 ||
		thang == 11) && ngay == 31)
	{
		cout << "Ngay thang khong hop le" << endl;
		return false;
	}
	else if (thang == 2 && ngay > 29)
	{
		cout << "Ngay thang khong hop le" << endl;
		return false;
	}
	else
		return true;
}
bool chekngay(int ngay)
{
	if (ngay > 31 || ngay < 1)
	{
		cout << "Ngay khong hop le" << endl;
		return false;
	}
	else
		return true;
}
bool checkmssv(int mssv, string file)
{
	if (mssv < 1)
	{
		cout << "Ma khong hop le" << endl;
		return false;
	}
	fstream f;
	f.open(file, ios::in);
	int ms;
	string checkEnd;
	string Ho;
	string Ten;
	int Ngay;
	int Thang;
	int Nam;
	int Gioitinh;
	float Dtb;
	while (f >> checkEnd)
	{
		ms = stoi(checkEnd.c_str());
		if (ms == mssv)
		{
			cout << "Ma da ton tai" << endl;
			return false;
		}
		else
		{
			f >> Ho >> Ten >> Ngay >> Thang >> Nam >> Gioitinh >> Dtb;
		}
	}
	f.close();
	return true;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct SinhVien
{
	string Ten;
	string MSSV;
	float DTB;
};

int menu();
int menu2();
int menu3();
void Nhap(int &n, int a[]);
void Xuat(int n, int a[]);
void XoaPhanTuk(int &n, int a[]);
void Max(int n, int a[]);
void Swap(int &a, int &b);
void Swap(float &a, float &b);
void Swap(string &a, string &b);
void Min(int n, int a[]);
int DemPhanTuAm(int n, int a[]);
int PhanTuAmLonNhat(int n, int a[]);
int PhanTuDuongNhoNhat(int n, int a[]);
void TimX(int n, int a[]);
void SelectionSort(int n, int a[]);
void InterchangeSort(int n, int a[]);
void InsertionSort(int n, int a[]);
void BinaryFindX(int n, int a[]);
void NhapSV(SinhVien &sv);
void NhapDanhSachSV(int &n, SinhVien* &sv);
void XuatSV(SinhVien sv);
void XuatDanhSachSV(int n, SinhVien* sv);
void DiemTrungBinhCaoNhat(int n, SinhVien *sv);
void DiemTrungBinhLonHon4(int n, SinhVien *sv);
void TimSinhVien(int n, SinhVien *sv);
void XoaSinhVien(int &n, SinhVien *sv);
void SinhVienInterchangeSort(int n, SinhVien *sv);
void SinhVienInsert(int &n, SinhVien *sv);
int main() {
	system("color 0a");
	int n;
	int *a = new int;
	int choice;
	bool flag = true; 
	SinhVien* sv = NULL;
	while (flag != false) {
		choice = menu();
		system("cls");	
		switch (choice)
		{		
		case 1:
			Nhap(n, a);
			int choice2;
			choice2 = menu2();
			if (choice2 == 1)
				Xuat(n, a);
			else if (choice2 == 2)
			{
				XoaPhanTuk(n, a);
				Xuat(n, a);
			}
			else if (choice2 == 3)
			{
				Max(n, a);
				Xuat(n, a);
			}
			else if (choice2 == 4)
			{
				Min(n, a);
				Xuat(n, a);
			}
			else if (choice2 == 5)
			{
				cout << "So Phan Tu Am Trong Mang: "<<  DemPhanTuAm(n, a);
			}
			else if (choice2 == 6)
			{
				if (PhanTuAmLonNhat(n,a) > 0)
					cout << "Khong Co Phan Tu Am Trong Mang";
				else
					cout << "Phan Tu Am Lon Nhat La: "<< PhanTuAmLonNhat(n, a);
			}
			else if (choice2 == 7)
			{
				if (PhanTuDuongNhoNhat(n, a) < 0)
					cout << "Khong Co Phan Tu Duong Trong Mang";
				else
					cout << "Phan Tu Duong Nho Nhat La: " << PhanTuDuongNhoNhat(n, a);
			}
			else if (choice2 == 8)
			{
				TimX(n,a);
			}
			else if (choice2 == 9)
			{
				SelectionSort(n, a);
			}
			else if (choice2 == 10)
			{
				InterchangeSort(n, a);
			}
			else if (choice2 == 11)
			{
				InsertionSort(n, a);
			}
			else if (choice2 == 12)
			{
				BinaryFindX(n, a);
			}
			break;
		case 2:
			int choice3;
			NhapDanhSachSV(n, sv);
			choice3 = menu3();
			if (choice3 == 1)
				XuatDanhSachSV(n, sv);
			else if (choice3 == 2)
				DiemTrungBinhCaoNhat(n, sv);
			else if (choice3 == 3)
				DiemTrungBinhLonHon4(n, sv);
			else if (choice3 == 4)
				TimSinhVien(n, sv);
			else if (choice3 == 5)
			{
				XoaSinhVien(n, sv);
				XuatDanhSachSV(n, sv);
			}
			else if (choice3 == 6)
			{
				SinhVienInterchangeSort(n, sv);
				XuatDanhSachSV(n, sv);
			}
			else if (choice3 == 7)
			{
				SinhVienInsert(n, sv);
			}
			
			break;
		
		case 3:
			cout << "Xin chao.\n";
			flag = false;
			break;
		default:
			cout << "Lua chon khong dung, vui long nhap lai.\n";
			cin >> choice;
			break;
		}

	}

	for (int i = 0; i < n; i++)
		//delete a[i];
	return 0;
}
/**
 funtion: for select the menu
 @para: No
 @result: the id of selected menu
**/

int menu()
{
	
	int choice;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Bai Tap 1";
	cout << "\n 2. Bai Tap 2";
	cout << "\n 3. Thoat chuong trinh";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> choice;
	return choice;
}

int menu2()
{

	int choice2;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Xuat Mang";
	cout << "\n 2. Xoa Phan Tu k";
	cout << "\n 3. Liet Ke Phan Tu Co Gia Tri Lon Nhat";
	cout << "\n 4. Liet Ke Phan Tu Co Gia Tri Nho Nhat";
	cout << "\n 5. Dem So Phan Tu Am";
	cout << "\n 6. Phan Tu Am Lon Nhat";
	cout << "\n 7. Phan Tu Duong Nho Nhat";
	cout << "\n 8. Tim X";
	cout << "\n 9. Selection Sort";
	cout << "\n 10. InterChange Sort";
	cout << "\n 11. Insertion Sort";
	cout << "\n 12. Binary Search";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> choice2;
	return choice2;
}

int menu3()
{

	int choice3;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Danh Sach Sinh Vien";
	cout << "\n 2. Sinh Vien Co Diem Trung Binh Cao Nhat";
	cout << "\n 3. Sinh Vien Co Diem Trung Binh Lon Hon Bang Nam";
	cout << "\n 4. Tim Sinh Vien";
	cout << "\n 5. Xoa Sinh Vien";
	cout << "\n 6. Sap Xep Sinh Vien";
	cout << "\n 7. Them Sinh Vien";
	/*cout << "\n 8. Tim X";
	cout << "\n 9. Selection Sort";
	cout << "\n 10. InterChange Sort";
	cout << "\n 11. Insertion Sort";
	cout << "\n 12. Binary Search";*/
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> choice3;
	return choice3;
}

/**
 funtion: input a value
 @para: input from keyboard
 @result:
**/


void Nhap(int &n, int a[])
{
	do
	{
		cout << "\n Vui long nhap vao so phan tu cua mang (nguyen duong): ";
		cin >> n;
	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

void Xuat(int n, int a[])
{
	for (int i = 0; i < n; i++)
		cout << a[i]<< " ";
}

void XoaPhanTuk(int &n ,int a[])
{
	int k;
	cin >> k;
	for (int i = k; i < n-1; i++)
	{
		a[i] = a[i + 1];
		k++;
	}
	n--;
}

void Max(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i])
				Swap(a[i], a[j]);
}

void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void Swap(float &a, float &b)
{
	float temp;
	temp = a;
	a = b;
	b = temp;
}
void Swap(string &a, string &b)
{
	string temp;
	temp = a;
	a = b;
	b = temp;
	
}

void Min(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				Swap(a[i], a[j]);
}

int DemPhanTuAm(int n, int a[])
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
			count++;
	return count;
}

int PhanTuAmLonNhat(int n, int a[])
{
	int max;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			max = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0 && a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int PhanTuDuongNhoNhat(int n, int a[])
{
	int min;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] < 0)
		{
			min = -1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0 && a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

void TimX(int n, int a[])
{
	int x;
	cin >> x;
	int count = 0;
	vector <int> b;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			count++;
			b.push_back(i);
		}
	}
	if (count == 0)
		cout << "Khong co phan tu x trong mang";
	else
	{
		cout << "Co " << count << " Phan Tu " << x << " Trong Mang" << " Nam O Vi Tri ";
		for (int i = 0; i < b.size(); i++)
			cout << b.at(i) << " ";
	}
}

void SelectionSort(int n, int a[])
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		Swap(a[i], a[min]);
	}
	Xuat(n, a);
}

void InterchangeSort(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				Swap(a[i], a[j]);
		}
	}
	Xuat(n, a);
}

void InsertionSort(int n, int a[])
{
	int i, j, x;
	for (int i = 1; i < n - 1; i++)
	{
		x = a[i];
		j = i - 1;
			while (x < a[j] && j >= 0)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
	}
	Xuat(n, a);
}

void BinaryFindX(int n, int a[])
{
	InterchangeSort(n, a);
	int x;
	cin >> x;
	int middle, left, right;
	left = 0;
	right = n - 1;
	middle = (right + left) / 2;
		while (right != left)
		{
			if (a[middle] > x)
			{
				right = middle;
				middle = right + left / 2;
			}
			else if (a[middle] < x)
			{
				left = middle;
				middle = (right + left) / 2;
			}
			else
				break;
		}
		if (a[middle] == x)
			cout << "Co phan tu x trong mang o vi tri " << middle;
		else cout << "Khong co phan tu x trong mang";
}

void NhapSV(SinhVien &sv)
{
	cout << "Ten Sinh Vien: ";
	cin.ignore();
	getline(cin, sv.Ten);
	//cin.ignore();
	cout << "Ma So Sinh Vien: ";
	getline(cin, sv.MSSV);
	//cin.ignore();
	cout << "Diem Trung Binh: ";
	cin >> sv.DTB;
}
 void NhapDanhSachSV(int &n, SinhVien* &sv)
 {
	 
	 do
	 {
		 cout << "\n So Sinh Vien Can Nhap: ";
		 cin >> n;
	 } while (n <= 0);
	 sv = new SinhVien[n];

	 for (int i = 0; i < n; i++)
	 {
		 NhapSV(sv[i]);
	 }
 }
 void XuatSV(SinhVien sv)
 {
	 cout << "\nTen sinh vien: " << sv.Ten;
	 cout << "\nMa So Sinh Vien: " << sv.MSSV;
	 cout << "\nDiem Trung Binh: " << sv.DTB << endl;
 }

 void XuatDanhSachSV(int n, SinhVien *sv)
 {
	 for (int i = 0; i < n; i++)
	 {
		 cout << "So thu tu: " << i + 1;
		 XuatSV(sv[i]);
	 }
 }

 void DiemTrungBinhCaoNhat(int n, SinhVien *sv)
 {
	 int max = -1;
	 for (int i = 0; i < n; i++)
	 {
		 if (sv[i].DTB >= max)
		 {
			 max = sv[i].DTB;
		 }
	 }
	 for (int i = 0; i < n; i++)
	 {
		 if (sv[i].DTB == max)
		 {
			 XuatSV(sv[i]);
		 }
	 }
 }

 void DiemTrungBinhLonHon4(int n, SinhVien *sv)
 {
	 for (int i = 0; i < n; i++)
	 {
		 if (sv[i].DTB >= 5)
		 {
			 cout << "\nTen sinh vien: " << sv[i].Ten;
			 cout << "\nMa So Sinh Vien: " << sv[i].MSSV;
			 cout << "\nDiem Trung Binh: " << sv[i].DTB << endl;
		 }
	 }
 }

 void TimSinhVien(int n, SinhVien *sv)
 {
	 string tensv;
	 cin.ignore();
	 getline(cin, tensv);
	 vector <SinhVien> sinhvien;
	 for (int i = 0; i < n; i++)
	 {
		 if (tensv == sv[i].Ten)
			 sinhvien.push_back(sv[i]);
	 }

	 if (sinhvien.size() == 0)
		 cout << "Khong Co Sinh Vien Ten " << tensv;
	 else
		 for (int i = 0; i < sinhvien.size(); i++)
		 {
			 XuatSV(sinhvien[i]);
		 }
 }

 void XoaSinhVien(int &n, SinhVien *sv)
 {
	 string mssv;
	 cin.ignore();
	 getline(cin, mssv);
	 for (int i = 0; i < n; i++)
	 {
		 if (sv[i].MSSV == mssv)
		 {
			 while (i < n - 1)
			 {
				 sv[i].MSSV = sv[i + 1].MSSV;
				 sv[i].Ten = sv[i + 1].Ten;
				 sv[i].DTB = sv[i + 1].DTB;
				 i++;
			 }
			 n--;
			 break;
		 }
	 }
 }

 void SinhVienInterchangeSort(int n, SinhVien *sv)
 {
	 for (int i = 0; i < n-1; i++)
	 {
		 int x = i;
		 for (int j = i + 1; j < n; j++)
		 {
			 if (sv[x].DTB > sv[j].DTB)
			 {
				 Swap(sv[x].DTB, sv[j].DTB);
				 Swap(sv[x].Ten, sv[j].Ten);
				 Swap(sv[x].MSSV, sv[j].MSSV);
			 }
		 }
	 }
 }

 void SinhVienInsert(int &n, SinhVien *sv)
 {
	 SinhVien *sv1 = new SinhVien[n + 1];
	 for (int i = 0; i < n; i++)
	 {
		 sv1[i].DTB = sv[i].DTB;
		 sv1[i].MSSV = sv[i].MSSV;
		 sv1[i].Ten = sv[i].Ten;
	 }
	 n++;
	 NhapSV(sv1[n - 1]);
	 SinhVienInterchangeSort(n, sv1);
	 XuatDanhSachSV(n, sv1);
 }


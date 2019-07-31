#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	int masv;
	string hosv;
	string tensv;
	float dtbsv;
};

struct node
{
	node *left;
	node *right;
	SinhVien info;
};

typedef struct node Tnode;

typedef Tnode* Tree;

void inputtree(Tree &t);
void createtree(Tree &t);
int InsertTree(Tree &t, SinhVien sv);
void inputsv(SinhVien &sv, Tree t);
void NLR(Tree t);
int menu();
void searchstandfor(Tree &p, Tree &t);
void removesvunder5score(Tree &t);
void removex(Tree &t);
void LRN(Tree t);


int main()
{
	system("color 0a");

	Tree t;
	createtree(t);
	bool flag = true;
	int choice;
	while (flag)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			inputtree(t);
			break;
		case 2:
			NLR(t);
			break;
		case 3:
			removesvunder5score(t);
			LRN(t);
			break;
		default:
			break;
		}
	}
	


	system("pause");
}
int menu()
{
	cout << "1.Them danh sach n sinh vien vao cay" << endl;
	cout << "2.Hien thi danh sach sinh vien" << endl;
	cout << "3.Xoa sinh vien co diem duoi nam" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void removesvunder5score(Tree &t)
{
	if (t == NULL)
		return;
	else
	if (t != NULL)
	{
		if (t->info.dtbsv < 5.0)
		{
			removex(t);
			removesvunder5score(t);
		}
		removesvunder5score(t->left);
		removesvunder5score(t->right);
	}
	
}
void removex(Tree &t)
{
	if (t != NULL) 
	{
		Tnode *p = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else searchstandfor(p, t->right);
		delete p;
		cout << "Xoa thanh cong" << endl;
		return;
	}
	else
		cout << "Xoa khong thanh cong" << endl;
}
void searchstandfor(Tree &p, Tree &t)
{
	if (t->left != NULL)
		searchstandfor(p, t->left);
	else
	{
		p->info = t->info;
		p = t;
		t = t->right;
	}
}
void inputtree(Tree &t)
{
	cout << "So luong sinh vien can them vao danh sach ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		inputsv(sv, t);
		InsertTree(t, sv);
	}
}
int searchx(Tree t, SinhVien sv)
{
	if (t != NULL) {
		if (t->info.masv == sv.masv)
		{
			cout << "Ma Sinh vien da ton tai" << endl;
			return 0;
		}
		else
		{
			if (sv.masv > t->info.masv)
				searchx(t->right, sv);
			else
				searchx(t->left, sv);
		}
	}
	return 1;
}
void inputsv(SinhVien &sv, Tree t)
{

	do
	{
		cout << "Nhap ma so sinh vien: ";
		cin >> sv.masv;
	} while (searchx(t, sv) != 1);
	cout << "Nhap ho sinh vien: ";
	cin >> sv.hosv;
	cout << "Nhap ten sinh vien: ";
	cin >> sv.tensv;
	do
	{
		cout << "Nhap diem trung binh sinh vien: ";
		cin >> sv.dtbsv;
	} while (sv.dtbsv > 10 || sv.dtbsv < 0);

}
void outputsv(SinhVien sv)
{
	cout << "Ma so sinh vien " << sv.masv << endl;
	cout << "Ho sinh vien: " << sv.hosv << endl;
	cout << "Ten sinh vien: " << sv.tensv << endl;
	cout << "Diem trung binh sinh vien: " << sv.dtbsv << endl;
}
void createtree(Tree &t)
{

	t = NULL;
}

Tnode *CreateTnode(SinhVien sv)
{
	Tnode *p = new Tnode;
	if (p == NULL)
		return NULL;
	p->left = NULL;
	p->right = NULL;
	p->info = sv;
	return p;
}

int InsertTree(Tree &t, SinhVien sv)
{
	if (t != NULL)
	{
		if (sv.masv == t->info.masv)
			return 0;
		else
			if (sv.masv > t->info.masv)
				InsertTree(t->right, sv);
			else
				InsertTree(t->left, sv);
	}
	else
	{
		t = CreateTnode(sv);
		if (t == NULL)
			return -1;
		return 1;
	}
}

void NLR(Tree t)
{
	if (t != NULL)
	{
		outputsv(t->info);
		NLR(t->left);
		NLR(t->right);
	}
}
void NRL(Tree t)
{
	if (t != NULL)
	{
		outputsv(t->info);
		NRL(t->right);
		NRL(t->left);
	}
}
void RLN(Tree t)
{
	if (t != NULL)
	{
		RLN(t->right);
		RLN(t->left);
		outputsv(t->info);
	}
}
void LRN(Tree t)
{
	if (t != NULL)
	{
		LRN(t->left);
		LRN(t->right);
		outputsv(t->info);
	}
}
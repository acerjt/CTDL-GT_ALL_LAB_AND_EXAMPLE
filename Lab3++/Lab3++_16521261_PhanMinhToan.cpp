#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
	string hovaten;
	string mssv;
	int namsinh;
	float DTB;

};


struct node
{
	node* pnext;
	SinhVien sv;
};

struct list
{
	node *phead;
	node * ptail;
};

void init(list &l);
void input(list &l);
void input2(list &l);
SinhVien inputsv();
node * getnode(SinhVien sv);
void addhead(list &l, node *p);
void addtail(list &l, node *p);
void output(list l);
void output(SinhVien sv);
int menu();
void diemtrungbinhnhohonnam(list l);
void xoanode(list &l, node*p);
void xoasinhvientruoc2000(list l);
void sapxepdiemsv(list &l);
void huydanhsachsinhvien(list &l, SinhVien &sv);
int main()
{
	system("color 0a");
	list l;
	init(l);
	bool flag = true;
	while (flag)
	{
		int choice = menu();
		switch (choice)
		{
			case 1:
				input(l);
				output(l);
				break;
			case 2:
				input2(l);
				output(l);
			case 3:
				diemtrungbinhnhohonnam(l);
				break;
			case 4:
				xoasinhvientruoc2000(l);
				output(l);
				break;
			case 5:
				sapxepdiemsv(l);
				output(l);
			case 6:
				for (node *p = l.phead; p != NULL;)
				{
					SinhVien sv;
					huydanhsachsinhvien(l, sv);
					output(sv);
					p = l.phead;
				}
				output(l);
				break;
			default:
				flag = false;
		}
	}
	
	system("pause");
}
int menu()
{
	int n;
	cout << "==========================================================================" << endl;
	cout << "1.Nhap danh sach sien vien vao danh sach lien ket bang cach them vao dau" << endl;
	cout << "2.Nhap danh sach sien vien vao danh sach lien ket bang cach them vao cuoi" << endl;
	cout << "3.Xuat danh sach sinh vien co diem nho hon nam" << endl;
	cout << "4.Xoa sinh vien co nam sinh truoc 2000" << endl;
	cout << "5.Sap xep diem trung binh sinh vien tang dan" << endl;
	cout << "6.Huy danh sach sinh vien va in ra thong tin sinh vien bi xoa" << endl;
	cout << "Lua chon cua ban: " << endl;
	cin >> n;
	return n;
}
void init(list &l)
{
	l.phead = l.ptail = NULL;
}

void input(list &l)
{
	cout << "Nhap vao so phan tu cua danh sach lien ket: ";
	int n;
	cin >> n;
	node * p;
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		sv = inputsv();
		p = getnode(sv);
		addhead(l, p);
	}
}
void input2(list &l)
{
	cout << "Nhap vao so phan tu cua danh sach lien ket";
	int n;
	cin >> n;
	node * p;
	for (int i = 0; i < n; i++)
	{
		SinhVien sv;
		sv = inputsv();
		p = getnode(sv);
		addtail(l, p);
	}
}

SinhVien inputsv()
{
	SinhVien sv;
	cout << "Nhap ho va ten sinh vien: ";
	cin.ignore();
	getline(cin, sv.hovaten);
	cout << "Nhap ma so sinh vien: ";
	getline(cin, sv.mssv);
	cout << "Nhap vao nam sinh sinh vien: ";
	cin >> sv.namsinh;
	cout << "Nhap vao diem trung binh sinh vien: ";
	cin >> sv.DTB;
	return sv;
}

node * getnode(SinhVien sv)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->sv.hovaten = sv.hovaten;
	p->sv.mssv = sv.mssv;
	p->sv.namsinh = sv.namsinh;
	p->sv.DTB = sv.DTB;
	p->pnext = NULL;
	return p;
}

void addhead(list&l, node *p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}
void addtail(list&l, node *p)
{
	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		l.ptail->pnext = p;
		l.ptail = p;
	}
}

void output(list l)
{
	for (node *p = l.phead; p != NULL; p = p->pnext)
	{
		output(p->sv);
	}

}

void output(SinhVien sv)
{
	cout << "Ho va ten sinh vien: " << sv.hovaten << endl;
	cout << "Ma so sinh vien: " << sv.mssv << endl;
	cout << "Nam sinh sinh vien: " << sv.namsinh << endl;
	cout << "Diem trung binh sinh vien: " << sv.DTB << endl;

}

void diemtrungbinhnhohonnam(list l)
{
	for (node *p = l.phead; p != NULL; p = p->pnext)
	{
		if (p->sv.DTB < 5)
			output(p->sv);
	}
}

void xoasinhvientruoc2000(list l)
{
	for (node *p = l.phead; p != NULL; p = p->pnext)
	{
		node* q = p->pnext;
		if (p->sv.namsinh < 2000)
		{
			xoanode(l, p);
			p = q;
		}
	}
}

void xoanode(list &l, node*p)
{
	node * q = l.phead;
	
	if (l.phead == NULL)
	{
		cout << "List empty" << endl;
		return;
	}
	else if (l.phead == l.ptail)
	{
		if (l.phead == p)
		{
			delete q;
			l.phead = l.ptail = NULL;
		}
	}
	while (q != NULL)
	{
		node * k = q->pnext;
		if (k == p)
		{
			q->pnext = k->pnext;
			delete k;
			return;
		}
		q = q->pnext;
	}
}

void sapxepdiemsv(list &l) {
	list l2;
	node *min;   
	node *p, *q, *minprev;
	l2.phead = l2.ptail = NULL;
	while (l.phead != NULL) 
	{
		p = l.phead; 
		q = p->pnext; 
		min = p; 
		minprev = NULL; 
		while (q != NULL)
		{
			if (q->sv.DTB < min->sv.DTB) 
			{
				min = q; 
				minprev = p;
			}	
			p = q; 
			q = q->pnext;
		}
		if (minprev != NULL)
			minprev->pnext = min->pnext;
		else
			l.phead = min->pnext;
		min->pnext = NULL;
		addtail(l2, min);
	}
	l = l2;
}
void huydanhsachsinhvien(list &l, SinhVien &sv)
{
	if (l.phead == NULL)
		return;
	if (l.phead == l.ptail)
	{
		node *p = l.phead;
		sv = l.phead->sv;
		delete p;
		l.phead = l.ptail = NULL;
		return;
	}
	else
	{
		for (node *p = l.phead; p != NULL; p = p->pnext)
		{
			node * q = p->pnext;
			if (q->pnext == NULL)
			{
				sv = q->sv;
				p->pnext = NULL;
				l.ptail = p;
				delete q;
				return;
			}
		}
	}
}
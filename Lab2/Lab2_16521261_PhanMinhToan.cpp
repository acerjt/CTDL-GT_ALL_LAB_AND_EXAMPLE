#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct PhanSo
{
	int tu;
	int mau;
};


struct Node
{
	PhanSo x;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};
int menu();
void Init(List &l);
Node * GetNode(PhanSo x);
void AddHead(List &l, Node *p);
PhanSo Input();
void Input(List &l, int&n);
void Output(List l);
PhanSo Sum(PhanSo a, PhanSo b);
void Sum(List l);
int UCLN(int a, int b);
void Rutgon(PhanSo &x);
PhanSo Max(List l);
int FindMax(List l);
PhanSo Min(List l);
int FindMin(List l);
int TimX(List l, PhanSo x);
int main()
{
	system("color 0a");
	List l;
	int n;	
	/*PhanSo x = Max(l);
	cout << "Phan so lon nhat" << x.tu << "/" << x.mau << endl;
	x = Min(l);
	cout << "Phan so nho nhat" << x.tu << "/" << x.mau << endl;*/
	int choice;
	bool flag = true;
	while (flag != false) {
		choice = menu();
		switch (choice)
		{
		case 1:
			Input(l, n);
			break;
		case 2:
			Output(l);
			break;
		case 3:
			Sum(l);
			break;
		case 4:
			FindMax(l);
			break;
		case 5:
			FindMin(l);
			break;
		case 6:
			PhanSo x = Input();
			TimX(l, x);
			break;
		case 7:
			flag =false;
			break;
		default:
			cout << "Lua chon khong dung, vui long nhap lai.\n";
			cin >> choice;
			break;
		}

	}
	system("pause");
}
int menu()
{
	int choice;
	cout << "\n ================================";
	cout << "\n Vui long chon chuc nang tuong ung";
	cout << "\n 1. Nhap danh sach lien ket";
	cout << "\n 2. Xuat danh sach lien ket";
	cout << "\n 3. Tong cac phan so trong danh sach";
	cout << "\n 4. Vi tri phan so lon nhat";
	cout << "\n 5. Vi tri phan so nho nhat";
	cout << "\n 6. Vi tri phan so x";
	cout << "\n ================================";
	cout << "\n Lua chon cua ban: ";
	cin >> choice;
	return choice;
}


void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}

Node * GetNode(PhanSo x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->x.tu = x.tu;
	p->x.mau = x.mau;
	p->pNext = NULL;
	return p;
}
void AddHead(List &l, Node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}

}
PhanSo Input()
{
	PhanSo x;
	cout << "Nhap tu: ";
	cin >> x.tu;
	cout << "Nhap mau: ";
	cin >> x.mau;
	return x;
}

void Input(List &l, int&n)
{
	cout << ("Nhap so phan tu phan so cua danh sach lien ket: ");
	cin >> n;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		PhanSo x = Input();
		Node * p = GetNode(x);
		if (p == NULL)
			return;
		AddHead(l, p);
	}
}

void Output(List l)
{
	Node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->x.tu << "/" << p->x.mau << endl;
		p = p->pNext;
	}
}
PhanSo Sum(PhanSo a, PhanSo b)
{
	PhanSo c;
	if (a.tu == 0 or a.mau == 0)
	{
		c.tu = b.tu;
		c.mau = b.mau;
	}
	else if (b.tu == 0 or b.mau == 0)
	{
		c.tu = a.tu;
		c.mau = a.mau;
	}
	else
	{

		c.tu = a.tu*b.mau + a.mau *b.tu;
		c.mau = a.mau * b.mau;
	}
	return c;
}
void Sum(List l)
{
	Node *p = l.pHead;
	PhanSo x;
	x.tu = 0;
	x.mau = 0;
	while (p != NULL)
	{
		x = Sum(x, p->x);
		p = p->pNext;
	}
	Rutgon(x);
	cout << "Tong cua day phan so la: " << x.tu << "/" << x.mau << endl;
}

int UCLN(int a, int b)
{
	int tmp;
	while (b != 0) 
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
void Rutgon(PhanSo &x)
{
	int ucln = UCLN(x.tu, x.mau);
	x.tu /= ucln;
	x.mau /= ucln;
}

PhanSo Max(List l)
{
	int c, b;
	PhanSo max = l.pHead->x;
	Node *p = l.pHead;
	while (p != NULL)
	{
		c = max.tu*p->x.mau;
		b = p->x.tu*max.mau;
		if (c < b)
		{
			max = p->x;
		}
		p = p->pNext;
	}
	return max;
}
int FindMax(List l)
{
	PhanSo x = Max(l);
	int count = 0;
	Node *p = l.pHead;
	while (p != NULL)
	{
		count++;
		if (p->x.tu == x.tu && p->x.mau == x.mau)
		{
			cout << "Phan so lon nhat o vi tri: " << count << endl;
			return count;
		}
		p = p->pNext;
	}
	return count;
}
PhanSo Min(List l)
{
	int c, b;
	PhanSo min = l.pHead->x;
	Node *p = l.pHead;
	while (p != NULL)
	{
		c = min.tu*p->x.mau;
		b = p->x.tu*min.mau;
		if (c > b)
		{
			min = p->x;
		}
		p = p->pNext;
	}
	return min;
}
int FindMin(List l)
{
	PhanSo x = Min(l);
	int count = 0;
	Node *p = l.pHead;
	while (p != NULL)
	{
		count++;
		if (p->x.tu == x.tu && p->x.mau == x.mau)
		{
			cout << "Phan so lon nhat o vi tri: " << count << endl;
			return count;
		}
		p = p->pNext;
	}
	return count;
}

int TimX(List l, PhanSo x)
{
	int count = 0;
	Node *p = l.pHead;
	while (p != NULL)
	{
		count++;
		if (p->x.tu == x.tu && p->x.mau == x.mau)
		{
			cout << "x can tim o vi tri " << count << endl;
			return count;
		}
		p = p->pNext;
	}
	cout << "Khong co x trong danh sach";
	return -1;
}
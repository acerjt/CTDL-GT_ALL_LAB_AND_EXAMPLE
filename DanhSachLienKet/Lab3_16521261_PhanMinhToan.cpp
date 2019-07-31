#include <iostream>

using namespace std;

struct node
{
	int info;
	node *pNext;
};

struct list
{
	node *pHead;
	node* pTail;
};

void InitList(list &l);
node* Getnode(int x);
void Addhead(list &l, node *p);
void Addtail(list &l, node *p);
void input(list &l);
void input1(list &l);
void output(list l);
int menu();
void cauc(list &l);
void xoanodecuoi1(list &l);
void xoanodecuoi(list &l);
void xoanodedau(list &l);
int demsonut(list l);
void timxtrongdanhsachlienket(list l);
void xoanodecotruongx(list &l);
void chennodex(list &l);
int main()
{
	system("color 0a");
	list l;
	InitList(l);

	

	bool flag = true;
	while (flag ==true)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			input(l);
			output(l);
			break;
		case 2:
			input1(l);
			output(l);
			break;
		case 3:
			cauc(l);
			break;
		case 4:
			cout << "So nut cua danh sach lien ket: "<< demsonut(l);
			break;
		case 5:
			timxtrongdanhsachlienket(l);
			break;
		case 6:
			xoanodedau(l);
			output(l);
			break;
		case 7:
			xoanodecuoi(l);
			output(l);
			break;
		case 8:
			xoanodecotruongx(l);
			output(l);
			break;
		case 9:
			chennodex(l);
			output(l);
			break;
		default:
			flag = false;
			break;
		}
	}



	system("pause");
}


int menu()
{
	cout << "\n1.Nhap va xuat danh sach lien ket bang cach them vao dau danh sach" << endl;
	cout << "2.Nhap va xuat danh sach lien ket bang cach them vao cuoi danh sach" << endl;
	cout << "3.In ra danh sach theo chieu cuoi ma khong can dung mang phu" << endl;
	cout << "4.Dem so nut trong danh sach lien ket" << endl;
	cout << "5.Tim mot nut co khoa x trong danh sach lien ket" << endl;
	cout << "6.Xoa nut dau danh sach" << endl;
	cout << "7.Xoa nut cuoi danh sach" << endl;
	cout << "8.Xoa nut co truong du lieu bang x" << endl;
	cout << "9.Chen mot nut co du lieu bang x" << endl;
	int n;
	cout << "Lua chon cua ban: ";
	cin >> n;
	return n;
}

void InitList(list &l)
{
	l.pHead = l.pTail = NULL;
}

node* Getnode(int x)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void Addhead(list &l, node *p)
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

void Addtail(list &l, node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void input(list &l)
{
	int n;
	int x;
	node *p;
	cout << "Nhap so phan tu cua danh sach lien ket: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		p=Getnode(x);
		Addhead(l,p);
	}

}

void input1(list &l)
{
	int n;
	int x;
	node *p;
	cout << "Nhap so phan tu cua danh sach lien ket: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		p = Getnode(x);
		Addtail(l, p);
	}

}

void output(list l)
{
	node *p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}

void cauc(list &l)
{
	for (node*p = l.pHead; p!=NULL; p = p->pNext)
	{
		if (p->pNext == NULL)
		{
			xoanodecuoi1(l);
			p = l.pHead;
		}
	}
	if (l.pHead != NULL)
		cout << l.pHead->info;
}

void xoanodecuoi1(list &l)
{
	if (l.pHead == NULL)
	{
		cout << "Empty list" << endl;
	}
	else if (l.pHead == l.pTail)
	{
		cout << l.pHead->info << " ";
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		node *p = l.pHead;
		while (p->pNext!=l.pTail)
			p = p->pNext;
		cout << p->pNext->info << " ";
		delete l.pTail;
		l.pTail = p;
		p->pNext = NULL;
	}
}

void xoanodecuoi(list &l)
{
	if (l.pHead == NULL)
	{
		cout << "Empty list" << endl;
	}
	else if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		node *p = l.pHead;
		while (p->pNext != l.pTail)
			p = p->pNext;
		delete l.pTail;
		l.pTail = p;
		p->pNext = NULL;
	}
}

void xoanodedau(list &l)
{
	if (l.pHead == NULL)
	{
		cout << "Empty list" << endl;
	}
	else if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		node *p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
}


int demsonut(list l)
{
	int count = 0;
	for (node*p = l.pHead; p != NULL; p = p->pNext)
		count++;
	return count;
}

void timxtrongdanhsachlienket(list l)
{
	int x;
	cout << "Nhap x can tim: ";
	cin >> x;
	for (node*p = l.pHead; p != NULL; p = p->pNext)
		if (p->info == x)
		{
			cout << "Co " << x << " trong danh sach lien ket";
			return;
		}
	cout << "Khong co " << x << " trong danh sach lien ket";

}

void xoanodecotruongx(list &l)
{
	int x;
	cout << "Nhap gia tri x cua node can xoa: ";
	cin >> x;
	if (l.pHead->info == x)
	{
		xoanodedau(l);
		return;
	}
	if (l.pTail->info == x)
	{
		xoanodecuoi(l);
		return;
	}
	node*p =new node;
	for (node*q = l.pHead; q != NULL; q = q->pNext)
	{
		p = q->pNext;
		if (p == NULL)
		{
			cout << "Khong co " << x << " trong danh sach lien ket" << endl;
			return;
		}
		if (p->info == x)
		{
			q->pNext = p->pNext;
			delete p;
			return;
		}
	}
}

void chennodex(list &l)
{
	int x;
	cout << "Nhap x: ";
	cin >> x;
	Addhead(l, Getnode(x));
}
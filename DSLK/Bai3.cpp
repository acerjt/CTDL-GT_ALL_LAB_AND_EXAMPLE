#include <iostream>

using namespace std;

struct dathuc
{
	int heso;
	int bacbien;
};
struct node
{
	dathuc info;
	node *pnext;
};
struct list
{
	node *ptail;
	node *phead;
};
void createlist(list &l);
void input(list &l, int &x);
void tongdathuc(list l, int x);
int main()
{
	system("color 0a");
	list l;
	createlist(l);
	int x;
	input(l, x);
	tongdathuc(l, x);
	system("pause");
}

void createlist(list &l)
{
	l.ptail = l.phead = NULL;
}
void input(dathuc &dt)
{
	cout << "Nhap he so: ";
	cin >> dt.heso;
	cout << "Nhap bac cua x: ";
	cin >> dt.bacbien;
}
node * getnode(dathuc dt)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = dt;
	p->pnext = NULL;
	return p;
}

void addhead(list &l, node *p)
{
	if (l.phead == NULL)
		l.phead = l.ptail = p;
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

void input(list &l, int &x)
{
	for (int i = 0; i < 2; i++)
	{
		dathuc dt;
		input(dt);
		node *p = getnode(dt);
		addhead(l, p);
	}
	cout << "Nhap x: ";
	cin >> x;
}

void tongdathuc(list l, int x)
{
	int ketqua = l.phead->info.heso*pow(x, l.phead->info.bacbien)
		        +l.ptail->info.heso*pow(x, l.ptail->info.bacbien);
	cout << "Tong da thuc ";
	cout << l.phead->info.heso << "x^" << l.phead->info.bacbien;
	cout << "+" <<l.ptail->info.heso << "x^" << l.ptail->info.bacbien;
	cout << ": " << ketqua << endl;
}
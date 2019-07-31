#include <iostream>
#include <string>
#define MAX 100

using namespace std;

struct stack
{
	int a[MAX];
	int top;
};

struct node_ghetrong
{
	int soghe;
	node_ghetrong * pnext;
};

struct Khach
{
	int soghe;
	string ten;
	int sothutu;
};

struct node_khach
{
	Khach k;
	node_khach* pnext;
};

struct listghe
{
	node_ghetrong *phead;
	node_ghetrong * ptail;
};

struct listkhach
{
	node_khach * phead;
	node_khach * ptail;
};

struct queue
{
	listkhach l;
};

void createstack(stack &s);
void push(stack &s, int x);
void output(stack s);
void create_listghe(listghe &l);
int isempty_q(queue q);
int isempty(listghe l);
void input(listghe &l);
void outputlistghe(listghe l);
node_ghetrong * getnode(int x);
void Addghe(listghe &l, node_ghetrong *p);
int menu();
void Themhangdoi(queue &q);
void output_hangdoi(listkhach l);
void output_hangdoi(listkhach l);
void outputkhach(Khach k);
void createqueue(queue &q);
void createlistkhach(listkhach &lk);
void muave(listghe &lg, queue &hd, listkhach &lk);
void deletenodehangdoi(queue &q, node_khach *&c);
void InsertKhach(node_khach*k, listkhach &l);
void xoaghetrong(listghe &l, int x);
void xoaghedau(listghe &l);
void xoaghecuoi(listghe &l);
void xoasauq(listghe &l, node_ghetrong *k);
void output_thongtinkhach(listkhach l);
void outputkhach1(Khach k);
void Huyve(listghe &lg, listkhach &lk);
int menu1();
int main()
{
	system("color 0a");
	stack s;
	listghe l;
	queue q;
	listkhach lk;
	createqueue(q);
	create_listghe(l);
	createlistkhach(lk);
	input(l);
	bool flag = true;
	bool flag1 = true;
	while (flag == true)
	{	
		int choice = menu();
		system("cls");
		switch (choice)
		{
		case 1:
			createstack(s);
			int x;
			cout << "Nhap so can chuyen doi: ";
			cin >> x;
			if (x == 0)
				push(s, x);
			else
				while (x != 0)
				{
					int z = x % 2;
					x /= 2;
					push(s, z);
				}
			output(s);
			break;
		case 2:
			while (flag1 == true)
			{
				int choice = menu1();
				system("cls");
				switch (choice)
				{
				case 1:
					Themhangdoi(q);
					output_hangdoi(q.l);
					break;
				case 2:
					muave(l, q, lk);
					break;
				case 3:
					Huyve(l, lk);
					break;
				case 4:
					output_thongtinkhach(lk);
					break;
				default:
					flag1 = false;
					break;
				}
			}
			break;
		default:
			flag = false;
		}
		
	}
	system("pause");
}
int menu()
{
	cout << "1.Bai tap 1" << endl;
	cout << "2.Bai tap 2" << endl;
	cout << "Lua chon ";
	int n;
	cin >> n;
	return n;
}
int menu1()
{
	cout << "1.Lay so xep hang" << endl;
	cout << "2.Mua ve" << endl;
	cout << "3.Huy ve" << endl;
	cout << "4.Ve da ban" << endl;
	cout << "Lua chon ";
	int n; 
	cin >> n;
	return n;
}

void createstack(stack &s)
{
	s.top = -1;
}

int IsEmpty(stack s)
{
	if (s.top < 0)
		return 1;
	else return 0;
}
int IsFull(stack s)
{
	if (s.top >= MAX)
		return 1;
	else 
		return 0;
}
void push(stack &s, int x)
{
	if (IsFull(s) == 0)
	{
		s.top++;
		s.a[s.top] = x;
	}
	else
		cout << "Stack day" << endl;
}

void output(stack s)
{
	for (int i = s.top; i >= 0; i--)
		cout << s.a[i];
	cout << endl;
}

void create_listghe(listghe &l)
{
	l.phead = l.ptail = NULL;
}
void input(listghe &l)
{
	for (int i = 1; i < 10; i++)
	{
		node_ghetrong *p =getnode(i);
		Addghe(l,p);
	}
}
void Addghe(listghe &l, node_ghetrong *p)
{
	if (l.phead == NULL)
		l.phead = l.ptail = p;
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

void createlistkhach(listkhach &lk)
{
	lk.phead = lk.ptail = NULL;
}

void outputlistghe(listghe l)
{
	for (node_ghetrong *p = l.phead; p != NULL; p = p->pnext)
	{
		cout << p->soghe << " ";
	}
	cout << endl;
}
node_ghetrong * getnode(int x)
{
	node_ghetrong *p = new node_ghetrong;
	p->soghe = x;
	p->pnext = NULL;
	return p;
}
void inputkhach(Khach &k)
{
	string s;
	cin.ignore();
	cout << "Nhap ten khach: ";
	getline(cin, s);
	k.ten = s;
}

void createqueue(queue &q)
{
	q.l.phead = q.l.ptail = NULL;
}
void Themhangdoi(queue &q)
{
	node_khach *p = new node_khach;
	if (q.l.phead == NULL)
	{
		p->k.sothutu = 1;
		inputkhach(p->k);
		p->pnext = NULL;
		q.l.phead = q.l.ptail = p;	
	}
	else
	{
		inputkhach(p->k);
		p->pnext = q.l.phead;
		p->k.sothutu = (q.l.phead->k.sothutu + 1);
		q.l.phead = p;
	}
}

void output_hangdoi(listkhach l)
{
	for (node_khach *p = l.phead; p != NULL; p = p->pnext)
	{
		outputkhach(p->k);
	}
}
void output_thongtinkhach(listkhach l)
{
	for (node_khach *p = l.phead; p != NULL; p = p->pnext)
	{
		outputkhach1(p->k);
	}
}
void outputkhach(Khach k)
{
	cout << "Ten Khach: " << k.ten << endl;
	cout << "So thu tu cua khach: " << k.sothutu << endl;
}

void outputkhach1(Khach k)
{
	cout << "Ten Khach: " << k.ten << endl;
	cout << "So ghe cua khach: " << k.soghe << endl;
}

int isempty(listghe l)
{
	if (l.phead == NULL)
		return 1;
	else
		return 0;
}
int isempty(listkhach l)
{
	if (l.phead == NULL)
		return 1;
	else
		return 0;
}

int isempty_q(queue q)
{
	if (q.l.phead == NULL)
		return 1;
	else
		return 0;
}

void muave(listghe &lg, queue &hd, listkhach &lk)
{
	if ((isempty(lg) == 0) && (isempty_q(hd) == 0))
	{
		outputlistghe(lg);
		int x;
		cout << "So ghe khach chon: ";
		cin >> x;
		for (node_ghetrong *p = lg.phead; p != NULL; p = p->pnext)
		{
			if (p->soghe == x)
				break;
			else if (p->pnext == NULL)
			{
				cout << "So ghe khach chon: ";
				cin >> x;
				p = lg.phead;
			}
		}	
		node_khach *k = new node_khach;
		k->k.soghe = x;
		xoaghetrong(lg, x);
		deletenodehangdoi(hd, k);
		InsertKhach(k, lk);

	}
}
void xoaghetrong(listghe &l, int x)
{
	for (node_ghetrong *p = l.phead; p != NULL; p = p->pnext)
	{
		node_ghetrong *q =p->pnext;
		if (p->soghe == x && p == l.phead)
		{
			xoaghedau(l);
			return;
		}
		else if (p->soghe == x && p == l.ptail)
		{
			xoaghecuoi(l);
			return;
		}
		else if (q->soghe == x)
		{
			xoasauq(l, q);
			return;
		}
	}
}

void xoaghedau(listghe &l)
{
	node_ghetrong *p = l.phead;
	if (l.phead == l.ptail)
	{
		delete p;
		l.phead = l.ptail = NULL;
		return;
	}
	else
	{
		l.phead = l.phead->pnext;
		delete p;
		return;
	}
}
void xoaghecuoi(listghe &l)
{
	node_ghetrong *p = l.phead;
	if (l.phead == l.ptail)
	{
		l.phead = l.ptail = NULL;
		delete p;
		return;
	}
	else
	{
		for (node_ghetrong *p = l.phead; p != NULL; p = p->pnext)
		{
			node_ghetrong *q = p->pnext;
			if (q->pnext == NULL)
			{
				p->pnext == NULL;
				l.ptail = p;
				delete q;
				return;
			}
		}
	}
}
void xoasauq(listghe &l, node_ghetrong *k)
{
	for (node_ghetrong *p = l.phead; p != NULL; p = p->pnext)
	{
		node_ghetrong *q = p->pnext;
		if (q == k)
		{
			p->pnext = q->pnext;
			delete q;
			return;
		}
	}
}

void InsertKhach(node_khach*k ,listkhach &l)
{
	node_khach *p = new node_khach;
	if (l.phead == NULL)
	{
		p = k;
		l.phead = l.ptail = p;
		p->pnext = NULL;
	}
	else
	{
		p = k;
		p->pnext = l.phead;
		l.phead = p;
	}
}
void deletenodehangdoi(queue &q, node_khach *&c)
{
	if (q.l.phead == NULL)
		return;
	if (q.l.phead == q.l.ptail)
	{
		node_khach *p = q.l.phead;
		c->k.ten = p->k.ten;
		delete p;
		q.l.phead = q.l.ptail = NULL;
		return;
	}
	else
	{
		for (node_khach *p = q.l.phead; p != NULL; p = p->pnext)
		{
			node_khach *k = p->pnext;
			if (k->pnext == NULL)
			{
				p->pnext = NULL;
				q.l.ptail = p;
				c->k.ten = k->k.ten;
				delete k;
				return;
			}
		}
	}
}

void deletekhach(listkhach &lk, node_khach *&q)
{
	node_khach *p = lk.phead;
	if (lk.phead == lk.ptail)
	{
		q->k.soghe = p->k.soghe;
		delete p;
		lk.phead = lk.ptail = NULL;
	}
	else
	{
		q->k.soghe = p->k.soghe;
		lk.phead = lk.phead->pnext;
		delete p;
	}
}

void Huyve(listghe &lg, listkhach &lk)
{
	if (isempty(lk) == 0)
	{
		node_ghetrong * pg = new node_ghetrong;
		node_khach *p = new node_khach;
		deletekhach(lk, p);
		pg->pnext = NULL;
		pg->soghe = p->k.soghe;
		Addghe(lg, pg);
	}
	else return;
}
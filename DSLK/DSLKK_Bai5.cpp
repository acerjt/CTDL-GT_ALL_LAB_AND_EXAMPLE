#include <iostream>
#include <string>
using namespace std;

struct NS
{
	int maso;
	char *hoten;
	int thamnien;
	float hesoluong;
	float luongcoban;
};

struct node
{
	NS info;
	node *next;
	node *prev;
};

struct list
{
	node *head;
	node *tail;
};
void createlist(list &l);
void input(list &l);
void output(list l);
void addtail(list &l, node *p);
node *getnode(NS ns);
void input(NS &ns);
void output(NS ns);
void addafterq(list &l, node *p, node*q);
void addbeforeq(list &l, node *p, node*q);
void removeafterq(list &l, node*q);
void sapxepthamnien(list &l);
float luongtrungbinh(list l);
int main()
{
	system("color 0a");
	list l;
	createlist(l);
	input(l);
	output(l);
	sapxepthamnien(l);
	cout << "=================================================================" << endl;
	cout << "Nhan su co tham nien giam dan" << endl;
	output(l);
	cout << "Luong trung binh cua cac nhan su: " << luongtrungbinh(l) << endl;
	system("pause");
}

void createlist(list &l)
{
	l.head = l.tail = NULL;
}
void input(list &l)
{
	for (int i = 0; i < 50; i++)
	{
		NS ns;
		input(ns);
		node *p = getnode(ns);
		addtail(l, p);
	}
}
void output(list l)
{
	for (node *p =l.head; p!=NULL; p=p->next)
	{
		output(p->info);
		cout << "======================================" << endl;
	}
}

void input(NS &ns)
{
	cout << "Nhap ma so: ";
	cin >> ns.maso;
	cout << "Nhap ho ten: ";
	string s;
	cin.ignore();
	getline(cin, s);
	ns.hoten = new char[s.size() + 1];
	ns.hoten[s.size()] = 0;
	memcpy(ns.hoten, s.c_str(), s.size());
	cout << "Nhap tham nien: ";
	cin >> ns.thamnien;
	cout << "Nhap he so luong: ";
	cin >> ns.hesoluong;
	cout << "Nhap luong co ban: ";
	cin >> ns.luongcoban;
}

void output(NS ns)
{
	cout << "Ma so: " << ns.maso << endl;
	cout << "Ho ten: " << ns.hoten << endl;
	cout << "Tham nien: " << ns.thamnien << endl;
	cout << "He so luong: " << ns.hesoluong << endl;
	cout << "Luong co ban: " << ns.luongcoban << endl;
}

node *getnode(NS ns)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = ns;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void addhead(list &l, node *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head->prev = p;
		l.head = p;
	}
}
void addtail(list &l, node *p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
}

void sapxepthamnien(list &l)
{
	for (node *p = l.head; p->next != NULL; p = p->next)
	{
		node * max = getnode(p->info);
		node * temp = getnode(p->info);
		node *k = NULL;
		for (node *q = p->next; q != NULL; q = q->next)
			if (max->info.thamnien < q->info.thamnien)
			{
				max = getnode(q->info);
				k = q;
			}
		if (k != NULL)
		{
			addbeforeq(l, temp, k);
			removeafterq(l, temp);
			addbeforeq(l, max, p);
			removeafterq(l, max);
			p = max;
		}
	}

}
void addafterq(list &l, node *p, node*q)
{
	if (q == NULL)
		addhead(l, p);
	else
	{
		if (q->next == NULL)
		{
			addtail(l, p);
		}
		else
		{
			p->next = q->next;
			q->next = p;
			p->prev = q;
			p->next->prev = p;
		}
	}
}
void addbeforeq(list &l, node *p, node*q)
{
	if (q == NULL)
		addhead(l, p);
	else
	{
		if (q->prev == NULL)
		{
			addhead(l, p);
		}
		else
		{
			p->prev = q->prev;
			q->prev = p;
			p->next = q;
			p->prev->next = p;
		}
	}
}

void removeafterq(list &l, node*q)
{
	if (q == NULL)
		return;
	else
	{
		node *p = q->next;
		if (p != NULL)
		{
			q->next = p->next;
			if (q->next == NULL)
				l.tail = q;
			if (p->next != NULL)
			p->next->prev = q;	
			delete p;
		}
		else
		{
			return;
		}
	}
}

float luongtrungbinh(list l)
{
	float ltb = 0;
	int count = 0;
	for (node*p = l.head; p != NULL; p = p->next)
	{
		count++;
		ltb += p->info.hesoluong*p->info.luongcoban;
	}
	ltb /= count;
	return ltb;
}
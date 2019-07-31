#include <iostream>
#include <time.h>
using namespace std;

struct node
{
	node *pnext;
	int info;
};

struct list
{
	node *phead;
	node *ptail;
};
void createlist(list &l);
void input(list &l);
void output(list l);
void sort(list &l);
void phanlist(list l, list &chan, list &le);
void goplist(list &l, list l1, list l2);
int main()
{
	srand((int)time(0));
	system("color 0a");
	list l, l1, l2;
	createlist(l);
	createlist(l1);
	createlist(l2);
	input(l1);
	sort(l1);
	input(l2);
	sort(l2);
	output(l1);
	output(l2);
	goplist(l, l1, l2);
	sort(l);
	output(l);
	system("pause");
}

void createlist(list &l)
{
	l.phead = l.ptail = NULL;
}

node * getnode(int x)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
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

void input(list &l)
{
	
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 100;
		node *p = getnode(x);
		addhead(l, p);
	}
}

void output(list l)
{
	for (node *p = l.phead; p != NULL; p = p->pnext)
		cout << p->info << " ";
	cout << endl;
}

void sort(list &l)
{
	for (node *p = l.phead; p->pnext != NULL; p = p->pnext)
		for (node *q = p->pnext; q != NULL; q = q->pnext)
			if (p->info > q->info)
				swap(p->info, q->info);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void phanlist(list l, list &chan, list &le)
{
	for (node *p = l.phead; p->pnext != NULL; p = p->pnext)
	{
		node *q = new node;
		q = getnode(p->info);
		if (p->info % 2 == 0)
			addhead(chan, q);
		else
			addhead(le, q);
	}
}

void goplist(list &l, list l1, list l2)
{
	l1.ptail->pnext = l2.phead;
	l1.ptail = l2.ptail;
	l = l1;
}

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
int main()
{
	system("color 0a");
	list l, chan, le;
	createlist(l);
	createlist(chan);
	createlist(le);
	input(l);
	output(l);
	phanlist(l, chan, le);
	output(chan);
	output(le);

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
	srand((int)time(0));
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

void phanlist(list l,list &chan, list &le)
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

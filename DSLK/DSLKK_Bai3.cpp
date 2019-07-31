#include <iostream>
#include <time.h>
using namespace std;


struct node
{
	node *next;
	node *prev;
	int info;
};

struct list
{
	node *head;
	node *tail;
};
void createlist(list &l);
void input(list &l);
void output(list l);
void removenode(list &l);
int main()
{
	system("color 0a");
	list l;
	createlist(l);
	srand(time(0));
	input(l);
	output(l);
	removenode(l);
	output(l);
	system("pause");
}

void createlist(list &l)
{
	l.head = l.tail = NULL;
}

node *getnode(int x)
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void addtail(list &l, node *p)
{
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
	}
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

void input(list &l)
{
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 10;	
		node*p = getnode(x);
		addhead(l, p);
	   
	}
}
void output(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		cout << p->info << " ";
	cout << endl;
}

void removenode(list &l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		for (node *q = p->next; q != NULL; q = q->next)
		{
			node*k = q->prev;
			node *h = q->next;
			if (q->info == p->info)
			{
				k->next = q->next;
				if (h != NULL)
					h->prev = k;
				if (q == l.tail)
					l.tail = k;
				delete q;
				q = k;
			}
		}
}
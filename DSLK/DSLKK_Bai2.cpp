#include <iostream>

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
int main()
{
	system("color 0a");
	list l;
	createlist(l);
	input(l);
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
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Gia tri phan tu: ";
		cin >> x;
		node*p = getnode(x);
		if (l.head == NULL)
			addhead(l, p);
		else
		{
			node*q = NULL;
			for (q = l.head; q != NULL; q=q->next)
			{
				if (q->info >= p->info)
					break;
			}
			if (q == NULL)
				addtail(l, p);
			else
				addbeforeq(l, p, q);

		}
	}
}
void output(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		cout << p->info << " ";
	cout << endl;
}
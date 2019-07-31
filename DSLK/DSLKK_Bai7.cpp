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
bool check1(list l);
bool check(list l);
float giatritrungbinh(list l);
int main()
{
	system("color 0a");
	list l;
	srand(time(0));
	createlist(l);
	input(l);
	cout << "Gia tri trung binh: " << giatritrungbinh(l) << endl;
	if (check(l) == false)
		cout << "List khong tang" << endl;
	else cout << "List tang" << endl;
	if (check1(l) == false)
		cout << "List khong giam" << endl;
	else cout << "List giam" << endl;
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

void input(list &l)
{
	for (int i = 0; i < 50000; i++)
	{
		int x = rand() % 50000;
		node *p = getnode(x);
		addhead(l, p);
	}
}
void output(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		cout << p->info << " ";
	cout << endl;
}
float giatritrungbinh(list l)
{
	float sum = 0;
	for (node *p = l.head; p != NULL; p = p->next)
		sum += p->info;
	sum /= 50000;
	return sum;
}

bool check(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		if (p->info > p->next->info)
			return false;
	return true;
}
bool check1(list l)
{
	for (node *p = l.head; p != NULL; p = p->next)
		if (p->info < p->next->info)
			return false;
	return true;
}
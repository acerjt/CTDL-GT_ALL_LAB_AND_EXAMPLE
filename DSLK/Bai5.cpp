#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node *pnext;
};
void Addtail(Node *&list, Node *p);
Node *getnode(int x);
void output(Node *list);
void Shuffle(Node *&list);
void Shuffle1(Node *&list);
int main()
{
	system("color 0a");
	Node *list = NULL;
	int a[6] = { 11,13,7,9,3,10 };

	for (int i = 0; i < 6; i++)
	{
		Node *p = getnode(a[i]);
		Addtail(list, p);
	}
	output(list);
	Node *temp = list;
	Shuffle(list);
	output(list);
	list = temp;
	Shuffle1(list);
	output(list);
	system("pause");
}

Node *getnode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pnext = NULL;
	return p;
}

void Addtail(Node *&list, Node *p)
{
	if (list == NULL)
	{
		list = p;
		return;
	}
	Node*last = list;
	while (last->pnext != NULL)
		last = last->pnext;
	last->pnext = p;

}

void output(Node *list)
{
	for (Node *p = list; p != NULL; p = p->pnext)
	{
		cout << p->info << " ";
	}
	cout << endl;
}
void Shuffle(Node *&list)
{
	Node *listchan = NULL;
	Node *listle = NULL;
	int count = 0;
	for (Node *p = list; p != NULL; p = p->pnext)
	{
		Node *q = getnode(p->info);
		if (count % 2 == 0)
			Addtail(listchan, q);
		else Addtail(listle, q);
		count++;
	}
	Addtail(listchan, listle);
	list = listchan;
}
void Shuffle1(Node *&list)
{
	Node *listchan = NULL;
	Node *listle = NULL;
	int count = 0;
	for (Node *p = list; p != NULL; p = p->pnext)
	{
		Node *q = getnode(p->info);
		if (count % 2 != 0)
			Addtail(listchan, q);
		else Addtail(listle, q);
		count++;
	}
	Addtail(listchan, listle);
	list = listchan;
}
#include <iostream>

using namespace std;


struct node
{
	node *left;
	node *right;
	int info;
};

typedef struct node Tnode;

typedef Tnode* Tree;


void createtree(Tree &t);
int InsertTree(Tree &t, int x);
void RNL(Tree t);
int getnodes(Tree t, int level);
void searchstandfor(Tree &p, Tree &t);
void removex(Tree &t, int x);
void NRL(Tree t);
int numbernode(Tree t);
void treetoarr(Tree t, int a[], int &i);
void outputarr(int a[], int n);
void bubblesort(int a[], int n);
int menu();




int main()
{
	Tree t;
	createtree(t);
	int a[] = { 22, 11, 30, 5, 15, 28, 33, 31 };
	for (int i = 0; i < 8; i++)
	{
		InsertTree(t, a[i]);
	}
	bool flag = true;
	int choice;
	int k;
	int n;
	int *b;
	int h;
	Tree p;
	while (flag)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			RNL(t);
			cout << endl;
			break;
		case 2:
			cout << "Nhap muc cua cay: ";
			cin >> k;
			cout << getnodes(t, k+1) << endl;
			break;
		case 3:
			p = t;
			while (p->left != NULL)
				p = p->left;
			removex(t, p->info);
			NRL(t);
			cout << endl;
			break;
		case 4:
			n = numbernode(t);
			b = new int[n];
			h = 0;
			treetoarr(t, b, h);
			bubblesort(b, n);
			outputarr(b, n);
		default:
			break;
		}
	}
	
	
	

	
	
	system("pause");
}
int menu()
{
	cout << "1.Xuat gia tri cay giam dan" << endl;
	cout << "2.Tra ve so node tai muc k" << endl;
	cout << "3.Xoa node co gia tri nho nhat" << endl;
	cout << "4.Sap xep bubblesort" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void bubblesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] < a[j + 1])
			swap(a[j], a[j+1]);
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void outputarr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int numbernode(Tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		return 1 + numbernode(t->left) + numbernode(t->right);
	}
}
void treetoarr(Tree t, int a[],int &i)
{
	if (t != NULL)
	{
		a[i] = t->info;
		i++;
		treetoarr(t->right, a, i);
		treetoarr(t->left, a, i);
	}
}

void removex(Tree &t, int x)
{
	if (t != NULL) {
		if (t->info == x)
		{
			Tnode *p = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			else searchstandfor(p, t->right);
			delete p;
			cout << "Xoa thanh cong" << endl;
			return;
		}
		else
		{
			if (x > t->info)
				removex(t->right, x);
			else
				removex(t->left, x);
		}
	}
	else
		cout << "Xoa khong thanh cong" << endl;
}
void searchstandfor(Tree &p, Tree &t)
{
	if (t->left != NULL)
		searchstandfor(p, t->left);
	else
	{
		p->info = t->info;
		p = t;
		t = t->right;
	}
}
int getnodes(Tree t, int level)
{
	if (t == NULL)
		return 0;
	if (level == 1)
		return 1;
	else if (level > 1)
	{
		return getnodes(t->left, level - 1) + getnodes(t->right, level - 1);
	}
}
int max(int a, int b)
{
	if (a < b)
		return b;
	else return a;
}
int heighttree(Tree t)
{
	if (t == NULL)
		return 0;
	else return 1 + (max(heighttree(t->left), heighttree(t->right)));
}
void createtree(Tree &t)
{

	t = NULL;
}
Tnode *CreateTnode(int x)
{
	Tnode *p = new Tnode;
	if (p == NULL)
		return NULL;
	p->left = NULL;
	p->right = NULL;
	p->info = x;
	return p;
}

int InsertTree(Tree &t, int x)
{
	if (t != NULL)
	{
		if (t->info == x)
			return 0;
		else
			if (x > t->info)
				InsertTree(t->right, x);
			else
				InsertTree(t->left, x);
	}
	else
	{
		t = CreateTnode(x);
		if (t == NULL)
			return -1;
		return 1;
	}
}

void RNL(Tree t)
{
	if (t != NULL)
	{
		RNL(t->right);
		cout << t->info << " ";
		RNL(t->left);
	}
}
void NRL(Tree t)
{
	if (t != NULL)
	{
		cout << t->info << " ";
		NRL(t->right);
		NRL(t->left);
	}
}

#include <iostream>
#include <vector>

using namespace std;

struct node
{
	int info;
	node *left;
	node *right;
};
typedef node Tnode;

typedef Tnode *Tree;

int tongkphantunhonhat(Tree t, int k, int &count);
void createtree(Tree &t);
int inserttree(Tree &t, int x);
int heighttree(Tree t);
int max(int a, int b);
int getnodes(Tree t, int level);
void nodetungmuc(Tree t, int b[]);
Tnode *createnode(int x);
void NLR(Tree t);
Tnode* createtallesttree(int arr[], int start, int end);
int menu();
int main()
{
	system("color 0a");
	Tree t;
	createtree(t);
	bool flag = true;
	int choice;
	int count = 0;
	int k;
	int h;
	int *b;
	int c[] = { 3,7,9,12,15,28,36,48,51,66,72,78,83,89,96, };
	int a[] = { 7,3,36,1,6,15,40,4,23 };
	int result;
	while (flag)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			for (int i = 0; i < 9; i++)
			{
				inserttree(t, a[i]);
			}
			NLR(t);
			cout << endl;
			cout << "Nhap so phan tu" << endl;
			cin >> k;
			cout << tongkphantunhonhat(t, k, count) << endl;
			break;
		case 2:
			h = heighttree(t);
			b = new int[h];
			nodetungmuc(t, b);
			for (int i = 0; i < h; i++)
				cout << b[i] << " ";
			cout << endl;
			break;
		case 3:
			t = createtallesttree(c, 0, 14);
			NLR(t);
			cout << endl;
			break;
		default:
			break;
		}
	}
	system("pause");
}
int menu()
{
	cout << "1.Bai 1" << endl;
	cout << "2.Bai 2" << endl;
	cout << "3.Bai 3" << endl;
	cout << "Your Choice: ";
	int choice;
	cin >> choice;
	return choice;
}
void NLR(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		cout << t->info << " ";
		NLR(t->left);
		NLR(t->right);
	}
}
Tnode* createtallesttree(int arr[], int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	Tnode *t = createnode(arr[mid]);
	t->left = createtallesttree(arr, start, mid - 1);
	t->right = createtallesttree(arr, mid + 1, end);
	return t;
}
void nodetungmuc(Tree t,int b[])
{
	int h = heighttree(t);
	for (int i = 1; i <= h; i++)
	{
		b[i - 1] = getnodes(t, i);
	}
}
int getnodes(Tree t, int level)
{
	if (t == NULL)
		return 0;
	if (level == 1)
		return t->info;
	else if (level > 1)
	{
		return getnodes(t->left, level - 1) + getnodes(t->right, level - 1);
	}
}
int heighttree(Tree t)
{
	if (t == NULL)
		return 0;
	else return 1 + (max(heighttree(t->left), heighttree(t->right)));
}
int max(int a, int b)
{
	if (b > a)
		return b;
	return a;
}
int tongkphantunhonhat(Tree t, int k, int &count)
{
	if (t == NULL)
		return 0;
	if (count > k)
		return 0;
	int res = tongkphantunhonhat(t->left, k, count);
	if (count >= k)
		return res;
	res += t->info;
	count++;
	if (count >= k)
		return res;
	return res + tongkphantunhonhat(t->right, k, count);
}
void createtree(Tree &t)
{
	t = NULL;
}

Tnode *createnode(int x)
{
	Tnode *p = new Tnode;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

int inserttree(Tree &t, int x)
{
	if (t != NULL)
	{
		if (x == t->info)
			return 0;
		else
			if (x > t->info)
				inserttree(t->right, x);
			else
				inserttree(t->left, x);
	}
	else
	{
		t = createnode(x);
		if (t == NULL)
			return -1;
		return 1;
	}
}
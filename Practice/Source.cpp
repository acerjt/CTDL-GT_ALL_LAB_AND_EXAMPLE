#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct TNODE
{
	int data;
	TNODE *left;
	TNODE *right;
};
typedef TNODE* TREE;


void inputfile(int a[], int n, string file);
void output(int a[], int n);
void quicksort(int a[], int left, int right);
void quicksortleft(int a[], int l, int r);
void quicksortright(int a[], int l, int r);
void interchangesort(int a[], int n);
void selectionsort(int a[], int n);
void bubelsort(int a[], int n);
void shakersort(int a[], int n);
void insertionsort(int a[], int n);
void binaryinsertionsort(int a[], int n);
void mergesort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void heapsort(int a[], int n);
int max(int a, int b);
void heapify(int a[], int n, int i);
void NLR(TREE t);
void InsertTree(TREE &t, int x);
TNODE *GetTNODE(int x);
void createtree(TREE &t);
void RemoveTNODE(TREE &t, int x);
int heighttree(TREE t);
void cau3(TREE t, TREE p);
int mucnode(TREE t, TREE p);
void cau4(TREE t, int level);
int bacnode(TREE t);
int demsonodecuacay(TREE t);
int demsonodela(TREE t);
int main()
{
	system("color 0a");
	//string file = "100.txt";
	//int n = 100;
	//int a[100];
	//inputfile(a, n, file);
	//int b[] ={
	//	14, 50, 1, 15, 15, 6, 16, 4, 22, 8, 0
	//};
	//output(a, 100);
	//cout << endl;
	//heapsort(a, n);
	//output(a, n);
	//cout << endl;
	TREE t;
	createtree(t);
	int a[] = { 7,3,36,1,6,15,40,4,23 };
	for (int i = 0; i < 15; i++)
	{
		InsertTree(t, a[i]);
	}
	NLR(t);
	cout << endl;
	cout << heighttree(t);
	cout << endl;
	cau3(t, t);
	cout << endl;
	cau4(t, 1);
	cout << endl;
	cout << demsonodecuacay(t) << endl;
	cout << demsonodela(t) << endl;
	system("pause");
}
int demsonodela(TREE t)
{

	if (t == NULL)
		return 0;
		else if (t->left == NULL && t->right == NULL)
			return 1;
		else return demsonodela(t->left) + demsonodela(t->right);
}
int demsonodecuacay(TREE t)
{
	if (t != NULL)
	{
		return 1 + demsonodecuacay(t->left) + demsonodecuacay(t->right);
	}
	else return 0;
}
void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		NLR(t->left);
		NLR(t->right);
	}
}
void cau4(TREE t, int level)
{
	if (t != NULL)
	{
		if (level == 1)
			cout << bacnode(t) << " ";
		else if (level > 1)
		{
			cau4(t->right, level - 1);
			cau4(t->left, level - 1);
		}
	}
}
void cau3(TREE t,TREE p)
{
	if (t != NULL)
	{
		cau3(t->left, p);
		cout << mucnode(p, t) << " ";
		cau3(t->right, p);
	}
}
int bacnode(TREE t)
{
	if (t->left == NULL && t->right == NULL)
		return 0;
	else if (t->left != NULL && t->right != NULL)
		return 2;
	else return 1;
}
int mucnode(TREE t, TREE p)
{
		if (t->data == p->data)
			return 0;
		else if (t->data > p->data)
			return 1 + mucnode(t->left, p);
		else if (t->data < p->data)
			return 1 + mucnode(t->right, p);
}
int heighttree(TREE t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + max(heighttree(t->left), heighttree(t->right));
}
int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void createtree(TREE &t)
{
	t = NULL;
}
void searchstandfor(TREE &p, TREE &t)
{
	if (t->right != NULL)
		searchstandfor(p, t->right);
	else
	{
		p->data = t->data;
		p = t;
		t = t->left;
	}
}
void RemoveTNODE(TREE &t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
		{
			TNODE *p = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			else searchstandfor(p, t->left);
			delete p;
			return;
		}
		else if (t->data > x)
			RemoveTNODE(t->left, x);
		else
			RemoveTNODE(t->right, x);
		
	}
}
void InsertTree(TREE &t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
			return;
		else if (t->data > x)
			InsertTree(t->left, x);
		else InsertTree(t->right, x);
	}
	else
	{
		TNODE *p = GetTNODE(x);
		if (p == NULL)
			return;
		t = p;
	}
}
TNODE *GetTNODE(int x)
{
	TNODE *p = new TNODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if (l<n && a[l]>a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (i != largest)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void mergesort(int a[], int l,int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergesort(a, l, m);
	mergesort(a, m + 1, r);
	merge(a, l, m, r);
}

void merge(int a[], int l, int m, int r)
{
	int length = r - l + 1;
	int *temp = new int[length];
	int pos = 0;
	int i = l;
	int j = m + 1;
	while (!(i > m && j > r))
	{
		if ((i <= m && j <= r && a[i] < a[j]) || j > r)
			temp[pos++] = a[i++];
		else
			temp[pos++] = a[j++];
	}
	for (int i = 0; i < length; i++)
		a[i + l] = temp[i];
}

void quicksortright(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l;
	int j = r;
	while (i <j)
	{
		while (a[j] >= pivot)
			j--;
		while (a[i] < pivot)
			i++;
		if (i < j)
			swap(a[i],a[j]);
	}
	swap(a[r], a[i]);
	if (l < j)
		quicksortright(a, l, i-1);
	if (i < r)
		quicksortright(a, i+1, r);
}
void quicksortleft(int a[], int l, int r)
{
	int pivot = a[l];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] <= pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j)
			swap(a[i], a[j]);
	}
	swap(a[l], a[j]);
	if (l < j)
		quicksortleft(a, l, j-1);
	if (i < r)
		quicksortleft(a, j+1, r);
}
void quicksort(int a[], int l, int r)
{
	int pivot = a[(l + r) / 2];
	int i = l;
	int j = r;
	while (i < j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (l < j)
		quicksort(a, l, j);
	if (i < r)
		quicksort(a, i, r);
}
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

void selectionsort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(a[i], a[min]);
	}
}

void bubelsort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void shakersort(int a[], int n)
{
	int j, l, r, k;
	l = 0;
	r = n - 1;
	k = n - 1;

	while (l < r)
	{
		for (j = r; j > l; j--)
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				k = j;
			}
		l = k;
		for (j = l; j < r; j++)
			if (a[j] > a[j + 1])
			{
			
				swap(a[j], a[j + 1]);
				k = j;
			}
		r = k;
	}
}

void insertionsort(int a[], int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
}

void binaryinsertionsort(int a[], int n)
{
	int i, j, l, r, m, x;
	
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		l = 0;
		r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (a[m] > x)
				r = m - 1;
			else
				l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = x;
	}
}

void inputfile(int a[], int n, string file)
{
	fstream f;
	f.open(file, ios::in);
	string checkEnd;
	int count = 0;
	while (f >> checkEnd)
	{
		a[count] = stoi(checkEnd.c_str());
		count++;
	}
	f.close();
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
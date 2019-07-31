#include <iostream>
#include <time.h>

#define SIZE 11

using namespace std;



struct node
{
	int key;
};

node HASHTABLE[SIZE];
int N;

struct node1
{
	int key;
	node1 *next;
};

typedef node1 NODE;
typedef NODE *PHNODE;
PHNODE HASHTTABLE1[SIZE];


void printarr(int a[], int n);
void heapify(int arr[], int n, int i);
void heapsort(int a[], int n);
int linearinsert(int k);
void initHASHTABLE();
int quadraticinsert(int k);
void initHASHTABLE1();
int HF(int key);
void insert(int k);
PHNODE search(int k);
void insertlist(int b, int k);
void traverse();
int menu();
int menuv1();
int main()
{
	system("color 0a");
	bool flag = true;
	int choice;
	int choice2;
	bool flag2;
	int *a;
	int b[] = { 32,15,25,44,36,21 };
	srand(time(0));
	int n;
	while (flag)
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			n = rand() % 20;
			a = new int[n];
			for (int i = 0; i < n; i++)
			{
				cout << "a[" << i << "]: ";
				cin >> a[i];
			}
			printarr(a, n);
			heapsort(a, n);
			break;
		case 2:
			flag2 = true;
			while (flag2)
			{
				choice2 = menuv1();
				switch (choice2)
				{
				case 1:
					initHASHTABLE();
					for (int i = 0; i < 6; i++)
						linearinsert(b[i]);
					for (int i = 0; i < SIZE; i++)
						cout << i << " " << HASHTABLE[i].key << endl;
					break;
				case 2:
					initHASHTABLE();
					for (int i = 0; i < 6; i++)
						quadraticinsert(b[i]);
					for (int i = 0; i < SIZE; i++)
						cout << i << " " << HASHTABLE[i].key << endl;
					break;
				case 3:
					initHASHTABLE1();
					for (int i = 0; i < 6; i++)
						insert(b[i]);
					traverse();
					break;
				default:
					flag2 = false;
					break;
				}
			}
			break;
		default:
			flag = false;
			break;
		}
	}

	
	system("pause");
}
int menuv1()
{
	cout << "1.Cau a" << endl;
	cout << "2.Cau b" << endl;
	cout << "3.Cau c" << endl;
	cout << "Lua chon: ";
	int choice;
	cin >> choice;
	return choice;
}
int menu()
{
	cout << "1.Bai 1" << endl;
	cout << "2.Bai 2" << endl;
	cout << "Lua chon: ";
	int choice;
	cin >> choice;
	return choice;
}
void printarr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	cout << "Xay dung heap" << endl;
	printarr(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
	cout << "HeapSort" << endl;
	printarr(a, n);
}
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void initHASHTABLE1()
{
	for (int i = 0; i < SIZE; i++)
		HASHTTABLE1[i] = NULL;
}
int emptyHASHTABLE(int i)
{
	return (HASHTTABLE1[i] == NULL ? true : false);
}
int empty1()
{
	for (int i = 0; i < SIZE; i++)
		if (HASHTTABLE1[i] != NULL)
			return 0;
	return 1;
}
void insert(int k)
{
	PHNODE p;

	p = search(k);
	if (p == NULL)
	{
		int b = HF(k);
		insertlist(b, k);
	}
	else
	{
		cout << "Ton tai khoa" << endl;
		return;
	}
}
PHNODE search(int k)
{
	PHNODE p;
	int b;
	b = HF(k);
	p = HASHTTABLE1[b];
	if (p == NULL)
		return NULL;
	while (k != p->key && p != NULL)
	{
		p = p->next;
		if (p == NULL)
			return NULL;
	}
	if (p->key != k)
		return NULL;
	return p;
}
void traverseHASHTABLE(int b)
{
	PHNODE p;
	p = HASHTTABLE1[b];
	while (p!=NULL)
	{
		cout << p->key << " ";
		p = p->next;
	}
	cout << endl;
}

void traverse()
{
	int b;
	for (b = 0; b < SIZE; b++)
	{
		cout << "Bucket " << b << ": ";
		traverseHASHTABLE(b);
	}
	cout << endl;
}
void insertlist(int b, int k)
{
	
	if (emptyHASHTABLE(b))
	{
		PHNODE p = new NODE;
		p->key = k;
		p->next = NULL;
		HASHTTABLE1[b] = p;
	}
	else
	{
		PHNODE p = HASHTTABLE1[b];
		while (p->next!=NULL)
		{
			p = p->next;
		}
		PHNODE q = new NODE;
		q->key = k;
		q->next = NULL;
		p->next = q;
		
	}
}
void initHASHTABLE()
{
	for (int i = 0; i < SIZE; i++)
		HASHTABLE[i].key = NULL;
	N = 0;
}
int empty()
{
	return (N == 0 ? true : false);
}
int full()
{
	return(N == SIZE - 1 ? true : false);
}

int HF(int key)
{
	return(key%SIZE);
}
int linearsearch(int k)
{
	int i = HF(k);
	while (HASHTABLE[i].key != k && HASHTABLE[i].key != NULL)
	{
		i = i + 1;
		if (i >= SIZE)
			i -= SIZE;
	}
	if (HASHTABLE[i].key == k)
		return i;
	else
		return SIZE;
}
int linearinsert(int k)
{
	if (linearsearch(k) < SIZE)
		return SIZE;
	if (full())
	{
		cout << "Khong them duoc khoa vao bang" << endl;
		return -1;
	}
	int i = HF(k);
	while (HASHTABLE[i].key != NULL)
	{
		i++;
		if (i >= SIZE)
			i -= SIZE;
	}
	HASHTABLE[i].key = k;
	N += 1;
	return i;
}
int quadraticsearch(int k)
{
	int i = HF(k);
	int d = 1;
	while (HASHTABLE[i].key != k && HASHTABLE[i].key != NULL)
	{
		i = (d + i) % SIZE;
		d += 2;
	}
	if (HASHTABLE[i].key == k)
		return i;
	else
		return SIZE;
}
int quadraticinsert(int k)
{
	if (quadraticsearch(k) < SIZE)
		return SIZE;
	if (full())
	{
		cout << "Khong them duoc khoa vao bang" << endl;
		return -1;
	}
	int i = HF(k);
	int d = 1;
	while (HASHTABLE[i].key != NULL)
	{
		i = (i + d) % SIZE;
		d += 2;
	}
	HASHTABLE[i].key = k;
	N += 1;
	return i;
}
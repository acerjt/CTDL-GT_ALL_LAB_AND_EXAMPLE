#include <iostream>

using namespace std;

void cau1(int a[], int n);
void cau2(int a[], int n);
void output(int a[], int n);
void swap(int &a, int &b);
void cau3(int arr[], int &n, int x);
void cau4(int a[], int b[], int c[], int x, int n, int &j, int &k);
void cau5(int a[], int b[], int c[], int p, int q, int & o);
int main()
{
	system("color 0a");
	int n = 5;
	int j, k;
	int a[100] ={ 12,43,1,34,22 };
	int b[100], c[100];
	cau1(a, n);
	cau2(a, n);
	output(a, n);
	cout << "Input x:";
	int x;
	cin >> x;
	cau3(a, n, x);
	output(a, n);
	int d[100] = { 12,43,1,34,22 };
	int m = 5;
	cout << "A Array: ";
	output(d, m);
	cau4(d, b, c, x, m, j, k);
	cout << "B Array: "; 
	output(b, j);
	cout << "C Array: ";
	output(c, k);
	int e[100];
	int f[100] = { 1,2,4,10 };
	int p = 4;
	int g[100] = { 3,5,7,9,12 };
	int q = 5;
	int o;
	cout << "A Array: ";
	output(f, p);
	cout << "B Array: ";
	output(g, q);
	cau5(f, g, e, p, q, o);
	cout << "C Array: ";
	output(e, o);
	system("pause");
}


void cau4(int a[], int b[], int c[], int x,int n,int &j, int &k)
{
	j = k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < x)
		{
			b[j] = a[i];
			j++;
		}
		else if (a[i] > x)
		{
			c[k] = a[i];
			k++;
		}


}

void cau5(int a[], int b[], int c[], int p, int q, int & o)
{
	o = p + q;
	for (int i = 0; i < p; i++)
		c[i] = a[i];
	for (int i = p, j = 0; i < o; i++, j++)
		c[i] = b[j];
	cau2(c, o);
}


void cau3(int a[], int &n, int x)
{
	int i, j;
	for (i = 0; i < n; i++) 
	{
		if (a[i] > x)
		{
			n++;
			j = n;
			while (j > i)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[i] = x;
			return;
		}
	}
	a[n] = x;
	n++;
}
void cau2(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)  
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void cau1(int a[],int n)
{
	for (int i = 0, j = 1; i < n - 1 && j < n; i++, j++)
	{
		cout << "(" << a[i] << "," << a[j] << ")";
		if (j != n-1)
			cout << ",";
	}
	cout << endl;

}
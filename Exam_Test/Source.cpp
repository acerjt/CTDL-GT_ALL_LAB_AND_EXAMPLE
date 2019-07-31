#include <iostream>
#include <string>
#include <fstream>
using namespace std;



void inputfile(int a[], int n, string file);
void output(int a[], int n);
void quicksort(int a[], int left, int right);
void quicksortleft(int a[], int l, int r);
void quicksortright(int a[], int l, int r);
int main()
{
	system("color 0a");
	string file = "100.txt";
	int n = 100;
	int a[100];
	inputfile(a, n, file);
	int b[] = {
		14, 50, 1, 15, 15, 6, 16, 4, 22, 8, 0
	};
	output(a, 100);
	cout << endl;
	quicksortleft(a, 0, n - 1);
	output(a, n);
	cout << endl;
	//sort(b, 0, 10);
	//output(b, 11);
	system("pause");
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

void quicksortright(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l;
	int j = r;
	while (i < j)
	{
		while ((a[i] < pivot))
		{
			i++;
		}
		j--;
		while (a[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[i]);
	if (j > l)
		quicksortright(a, l, i - 1);
	if (r > i)
		quicksortright(a, i + 1, r);
}
void quicksortleft(int a[], int l, int r)
{
	int pivot = a[l];
	int i = l;
	int j = r;
	while (i < j)
	{
		i++;
		while ((a[i] < pivot))
		{
			i++;
		}
		while (a[j] > pivot)
		{
			j--;
		}
		if (i < j)
		{
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	if (j > l)
		quicksortleft(a, l, j - 1);
	if (r > i)
		quicksortleft(a, j + 1, r);
}

void quicksort(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (x > a[i])
			i++;
		while (x < a[j])
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (j > left)
		quicksort(a, left, j);
	if (i < right)
		quicksort(a, i, right);

}
void heapsort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
void heapify(int a[], int n, int i)
{
	int lagset = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	if (left<n&& a[left]>a[lagset])
		lagset = left;
	if (right<n && a[right]>a[lagset])
		lagset = right;
	if (i != lagset)
	{
		swap(a[i], a[lagset]);
		heapify(a, n, lagset);
	}
}
void mergesort(int a[], int l, int r)
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
	for (i = 0; i < length; i++)
		a[l + i] = temp[i];
}
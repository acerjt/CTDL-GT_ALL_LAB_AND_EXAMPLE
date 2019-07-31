#include <iostream>
//#include <time.h>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;
struct sorttype
{
	string name;
	double time;
};
double selectionsort(int a[], int n);
double insertionsort(int a[], int n);
double bubblesort(int a[], int n);
void output(int a[], int n);
void quicksort(int a[], int left, int right);
void outputfile(int n, string file);
void merge(int a[], int left, int mid, int right);
double interchangesort(int a[], int n);
void inputfile(int a[], int n, string file);
void mergesort(int a[], int left, int right);
void sortsorttime(sorttype *a, int n);
void outputsorttime(sorttype a[], int n);
int menu();

int main()
{
	system("color 0a");
	int a[100];
	int b[1000];
	int c[5000];
	int d[10000];
	int e[50000];
	int n;
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	chrono::duration <double, milli> diff;
	string file;
	sorttype quicks, interchanges, insertions, merges, bubbles, selections;
	quicks.name		   = "QuickSort";
	interchanges.name  = "InterChangeSort";
	insertions.name	   = "InsertionSort";
	merges.name		   = "MergeSort";
	bubbles.name	   = "BubbleSort";
	selections.name	   = "SelectionSort";
	sorttype arr[6];
	bool flag = true;
	while (flag)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			file = "100.txt";
			n = 100;
			inputfile(a, n, file);
			interchanges.time = interchangesort(a, n);
			inputfile(a, n, file);
			insertions.time = insertionsort(a, n);
			inputfile(a, n, file);
			bubbles.time = bubblesort(a, n);
			inputfile(a, n, file);
			selections.time = selectionsort(a, n);
			inputfile(a, n, file);
			start = chrono::steady_clock::now();
			quicksort(a, 0, n-1);
			end = chrono::steady_clock::now();
			diff = end - start;
			quicks.time = diff.count();
			inputfile(a, n, file);
			 start = chrono::steady_clock::now();
			mergesort(a, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			merges.time = diff.count();
			arr[0] = quicks;
			arr[1] = interchanges;
			arr[2] = insertions;
			arr[3] = merges;
			arr[4] = bubbles;
			arr[5] = selections;
			sortsorttime(arr, 6);
			outputsorttime(arr, 6);
			break;
		case 2:
			file = "1000.txt";
			n = 1000;
			inputfile(b, n, file);
			interchanges.time = interchangesort(b, n);
			inputfile(b, n, file);
			insertions.time = insertionsort(b, n);
			inputfile(b, n, file);
			bubbles.time = bubblesort(b, n);
			inputfile(b, n, file);
			selections.time = selectionsort(b, n);
			inputfile(b, n, file);
			start = chrono::steady_clock::now();
			quicksort(b, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			quicks.time = diff.count();
			inputfile(b, n, file);
			start = chrono::steady_clock::now();
			mergesort(b, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			merges.time = diff.count();
			arr[0] = quicks;
			arr[1] = interchanges;
			arr[2] = insertions;
			arr[3] = merges;
			arr[4] = bubbles;
			arr[5] = selections;
			sortsorttime(arr, 6);
			outputsorttime(arr, 6);
			break;
		case 3:
			file = "5000.txt";
			n = 5000;
			inputfile(c, n, file);
			interchanges.time = interchangesort(c, n);
			inputfile(c, n, file);
			insertions.time = insertionsort(c, n);
			inputfile(c, n, file);
			bubbles.time = bubblesort(c, n);
			inputfile(c, n, file);
			selections.time = selectionsort(c, n);
			inputfile(c, n, file);
			start = chrono::steady_clock::now();
			quicksort(c, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			quicks.time = diff.count();
			inputfile(c, n, file);
			start = chrono::steady_clock::now();
			mergesort(c, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			merges.time = diff.count();
			arr[0] = quicks;
			arr[1] = interchanges;
			arr[2] = insertions;
			arr[3] = merges;
			arr[4] = bubbles;
			arr[5] = selections;
			sortsorttime(arr, 6);
			outputsorttime(arr, 6);
			break;
		case 4:
			file = "10000.txt";
			n = 10000;
			inputfile(d, n, file);
			interchanges.time = interchangesort(d, n);
			inputfile(d, n, file);
			insertions.time = insertionsort(d, n);
			inputfile(d, n, file);
			bubbles.time = bubblesort(d, n);
			inputfile(d, n, file);
			selections.time = selectionsort(d, n);
			inputfile(d, n, file);
			start = chrono::steady_clock::now();
			quicksort(d, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			quicks.time = diff.count();
			inputfile(d, n, file);
			start = chrono::steady_clock::now();
			mergesort(d, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			merges.time = diff.count();
			arr[0] = quicks;
			arr[1] = interchanges;
			arr[2] = insertions;
			arr[3] = merges;
			arr[4] = bubbles;
			arr[5] = selections;
			sortsorttime(arr, 6);
			outputsorttime(arr, 6);
			break;
		case 5:
			file = "50000.txt";
			n = 50000;
			inputfile(e, n, file);
			interchanges.time = interchangesort(e, n);
			inputfile(e, n, file);
			insertions.time = insertionsort(e, n);
			inputfile(e, n, file);
			bubbles.time = bubblesort(e, n);
			inputfile(e, n, file);
			selections.time = selectionsort(e, n);
			inputfile(e, n, file);
			start = chrono::steady_clock::now();
			quicksort(e, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			quicks.time = diff.count();
			inputfile(e, n, file);
			start = chrono::steady_clock::now();
			mergesort(e, 0, n - 1);
			end = chrono::steady_clock::now();
			diff = end - start;
			merges.time = diff.count();
			arr[0] = quicks;
			arr[1] = interchanges;
			arr[2] = insertions;
			arr[3] = merges;
			arr[4] = bubbles;
			arr[5] = selections;
			sortsorttime(arr, 6);
			outputsorttime(arr, 6);
			break;
		default:
			break;
		}
	}
	system("pause");
}
int menu()
{
	cout << "1.100 Elements" << endl;
	cout << "2.1000 Elements" << endl;
	cout << "3.5000 Elements" << endl;
	cout << "4.10000 Elements" << endl;
	cout << "5.50000 Elements" << endl;
	cout << "Choice" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void outputsorttime(sorttype a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i].name << "(" << a[i].time << "ms)" << endl;
}
void outputfile(int n,string file)
{
	fstream f;
	f.open(file, ios::out);
	for (int i = 0; i < n; i++)
	{
		int x = rand() % n;
		f << x;
		if (i != n - 1)
			f << " ";
	}

}
void inputfile(int a[],int n, string file)
{
	fstream f;
	f.open(file, ios::in);
	string checkEnd;
	int count = 0;
	while (f>>checkEnd)
	{
		a[count] = stoi(checkEnd.c_str());
		count++;
	}
	f.close();
}

void sortsorttime(sorttype *a,int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].time > a[j].time)
			{
				swap(a[i], a[j]);
			}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void mergesort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge(a, left, mid, right);
}

void merge(int a[], int left, int mid, int right)
{
	int length = right - left + 1;
	int *temp = new int[length];
	int pos = 0;
	int i = left;
	int j = mid + 1;
	while (!(i > mid &&j > right))
	{
		if ((i <= mid && j <= right && a[i] < a[j]) || j > right)
			temp[pos++] = a[i++];
		else
			temp[pos++] = a[j++];
	}
	for (i = 0; i < length; i++)
		a[left + i] = temp[i];
}

void quicksort(int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2];
	i = left;
	j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quicksort(a, left, j);
	if (i < right)
		quicksort(a, i, right);
}
double interchangesort(int a[], int n) 
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	auto result = chrono::duration <double, milli>(diff).count();
	return result;
}
double bubblesort(int a[], int n)
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	auto result = chrono::duration <double, milli>(diff).count();
	return result;
}
double selectionsort(int a[], int n) 
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	auto result = chrono::duration <double, milli>(diff).count();
	return result;
}
double insertionsort(int a[], int n)
{
	auto start = chrono::steady_clock::now();
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	auto result = chrono::duration <double, milli>(diff).count();
	return result;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap(sorttype &a, sorttype &b)
{
	sorttype temp = a;
	a = b;
	b = temp;
}
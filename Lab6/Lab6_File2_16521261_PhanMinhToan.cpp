#include <iostream>
#include <time.h>
using namespace std;
void input(int a[], int &n);
void InterChangeSort(int a[], int n);
void output(int a[], int n);
int menu();
void SelectionSort(int a[], int n);
void Swap(int &a, int &b);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void QuickSort(int a[], int low, int high);
int main()
{
	system("color 0a");
	int a[100];
	int n;
	srand(time(0));
	bool flag = true;
	while (flag)
	{
		cout << "Array: ";
		input(a, n);
		output(a, n);
		int choice = menu();
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			InterChangeSort(a, n);
			cout << "Result: ";
			output(a, n);
			break;
		case 2:
			SelectionSort(a, n);
			cout << "Result: ";
			output(a, n);
			break;
		case 3:
			BubbleSort(a, n);
			cout << "Result: ";
			output(a, n);
			break;
		case 4:
			InsertionSort(a, n);
			cout << "Result: ";
			output(a, n);
			break;
		case 5:
			QuickSort(a, 0, n - 1);
			cout << "Result: ";
			output(a, n);
			break;
		default:
			break;
		}
	}

	system("pause");
}
int Partition(int a[], int low, int high)
{
	int pivot = a[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;    
			Swap(a[i], a[j]);
		}
	}
	Swap(a[i + 1], a[high]);
	return (i + 1);
}

void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(a, low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
	}
}
void InsertionSort(int a[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		int x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				Swap(a[j], a[j + 1]);
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		Swap(a[min], a[i]);
	}
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void InterChangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n; j++)
			if (a[i] > a[j])
				Swap(a[i], a[j]);
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int menu()
{
	cout << "0.Exit" << endl;
	cout << "1.InterChangeSort" << endl;
	cout << "2.SelectionSort" << endl;
	cout << "3.BubbleSort" << endl;
	cout << "4.InsertionSort" << endl;
	cout << "5.QuickSort" << endl;
	cout << "Your Choice" << endl;
	int choice;
	cin >> choice;
	return choice;
}
void input(int a[], int &n)
{
	n = rand() % 20;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}

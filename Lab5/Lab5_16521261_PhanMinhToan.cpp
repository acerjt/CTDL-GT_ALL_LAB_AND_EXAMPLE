#include <iostream>
#include <time.h>
#include <chrono>
#define MAX 20
using namespace std;
int menu();
void createarray(int a[]);
void output(int a[]);
int arraymax(int a[]);
int indexarraymax(int a[]);
void allindexarraymax(int a[]);
void findx(int a[], int index, float t);
void findx2(int a[], int index, float t);
void allindexarrayx(int a[]);
void sortarray(int a[]);
void InterpolationSearch(int a[], int index, float t);
void lietke(int a[]);
void interchangesort(int a[]);
void selectionsort(int a[]);
void findx3(int a[], int index, float t);
int main()
{
	system("color 0a");
	int a[MAX];
	int index = -1;
	float t = 0;
	srand(time(0));
	bool flag = true;
	while (flag)
	{
		int choice = menu();
		switch (choice)
		{
		case 0:
			createarray(a);
			break;
		case 1:
			output(a);
			break;
		case 2:
			cout << "Gia tri lon nhat mang: " << arraymax(a) << endl;
			break;
		case 3:
			cout << "Vi tri gia tri lon nhat trong mang: " << indexarraymax(a) << endl;
			break;
		case 4:
			allindexarraymax(a);
			break;
		case 5:
			findx(a, index, t);
			break;
		case 6:
			findx2(a, index, t);
			break;
		case 7:
			allindexarrayx(a);
		case 8:
			createarray(a);
			sortarray(a);
			break;
		case 9:
			InterpolationSearch(a, index, t);
			break;
		case 10:
			lietke(a);
			break;
		case 11:
			interchangesort(a);
			output(a);
			break;
		case 12:
			selectionsort(a);
			output(a);
			break;
		case 13:
			findx3(a, index, t);
			break;
		default:
			break;
		}

	}
	system("pause");
}

int menu()
{
	cout << "0.Tao mang" << endl;
	cout << "1.In mang" << endl;
	cout << "2.Gia tri lon nhat cua mang" << endl;
	cout << "3.Vi tri gia tri lon nhat cua mang" << endl;
	cout << "4.Tat ca vi tri gia tri lon nhat cua mang" << endl;
	cout << "5.Tim vi tri gia tri x bang thuat toan tim kiem tuyen tinh" << endl;
	cout << "6.Tim vi tri gia tri x bang thuat toan tim kiem tuyen tinh cai tien" << endl;
	cout << "7.Tim tat ca vi tri gia tri cua x bang thuat toan tim kiem tuyen tinh" << endl;
	cout << "8.Tao mang moi va sap xep tang dan" << endl;
	cout << "9.Tim vi tri gia tri x bang thuat toan tim kiem noi suy (Thuc hien sau khi mang da duoc sap xep)" << endl;
	cout << "10.Liet ke cac cap gia tri" << endl;
	cout << "11.Interchangesort" << endl;
	cout << "12.Selectionsort" << endl;
	cout << "13.Tim vi tri gia tri x bang thuat toan tim kiem tuyen tinh cai tien (Thuc hien sau khi mang da duoc sap xep)" << endl;
	cout << "Lua chon: ";
	int choice;
	cin >> choice;
	return choice;
}
void createarray(int a[])
{
	for (int i = 0; i < MAX; i++)
		a[i] = rand() % 100;
}
void output(int a[])
{
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
}
int arraymax(int a[])
{
	int max = a[0];
	for (int i = 0; i < MAX; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int indexarraymax(int a[])
{
	int max = arraymax(a);
	int index = -1;
	for (int i = 0; i < MAX; i++)
		if (a[i] >= max)
		{
			index = i;
			return index;
		}
}

void allindexarraymax(int a[])
{
	int max = arraymax(a);
	cout << "Cac vi tri co gia tri max: ";
	for (int i = 0; i < MAX; i++)
		if (a[i] >= max)
		{	
			cout << i << " ";
		}
	cout << endl;
}

void findx(int a[], int index, float t)
{
	int x;
	cout << "Gia tri can tim trong mang: ";
	cin >> x;
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < MAX; i++)
		if (a[i] == x)
		{
			index = i;
			break;
		}
	auto end = chrono::steady_clock::now();
	auto diff = end - start; 
	cout << "Thoi gian tim la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	if (index != -1)
		cout << "X can tim o vi tri: " << index << endl;
	else
		cout << "Khong tim thay X" << endl;
}
void findx2(int a[], int index, float t)
{
	int x;
	cout << "Gia tri can tim trong mang: ";
	cin >> x;
	a[MAX] = x;
	int i = 0;
	auto start = chrono::steady_clock::now();
	while (a[i] != x)
	{
		i++;
	}
	if (i != MAX)
		index = i;
	else
		index = -1;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Thoi gian tim la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	if (index != -1)
		cout << "X can tim o vi tri: " << index << endl;
	else
		cout << "Khong tim thay X" << endl;
}
void findx3(int a[], int index, float t)
{
	int x;
	cout << "Gia tri can tim trong mang: ";
	cin >> x;
	a[MAX] = x;
	int i = 0;
	auto start = chrono::steady_clock::now();
	while (a[i] < x)
	{
		i++;
	}
	if (i < MAX && a[i] == x)
		index = i;
	else
		index = -1;
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Thoi gian tim la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	if (index != -1)
		cout << "X can tim o vi tri: " << index << endl;
	else
		cout << "Khong tim thay X" << endl;
}
void allindexarrayx(int a[])
{
	int x;
	cout << "Gia tri can tim trong mang: ";
	cin >> x;
	cout << "Cac vi tri co gia tri x: ";
	for (int i = 0; i < MAX; i++)
		if (a[i] == x)
		{
			cout << i << " ";
		}
	cout << endl;
}

void sortarray(int a[])
{
	for (int i = 0; i < MAX - 1; i++)
		for (int j = i + 1; j < MAX; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InterpolationSearch(int a[], int index, float t)
{
	int x;
	cout << "Gia tri can tim trong mang: ";
	cin >> x;
	int left = 0;
	int right = MAX - 1;
	auto start = chrono::steady_clock::now();
	while (left < right)
	{
		int middle = left + (right - left)*(x - a[left]) / (a[right] - a[left]);
		if (a[middle] == x)
		{
			index = middle;
			break;
		}
		else if (a[middle] > x)
			right = middle - 1;
		else
			left = middle + 1;
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Thoi gian tim la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	if (index != -1)
		cout << "X can tim o vi tri: " << index << endl;
	else
		cout << "Khong tim thay X" << endl;
}

void lietke(int a[])
{
	for (int i = 0; i < MAX - 1; i++)
	{
		cout << endl;
		for (int j = i + 1; j < MAX; j++)
			if (a[i] < a[j])
				cout << "(" << a[i] << "," << a[j] << ") ";
	}
	cout << endl;
}

void interchangesort(int a[])
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < MAX - 1; i++)
		for (int j = i + 1; j < MAX; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Thoi gian sap xep la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}

void selectionsort(int a[])
{
	auto start = chrono::steady_clock::now();
	for (int i = 0; i < MAX - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < MAX; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Thoi gian sap xep la: " << chrono::duration <double, milli>(diff).count() << " ms" << endl;
}
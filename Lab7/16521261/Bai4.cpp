#include <iostream>

using namespace std;

void swap(int &a, int &b);
void interchangesort(int a[], int n);
void output(int a[], int n);
int main()
{
	system("color 0a");
	int a[9] = { 12,8,2,14,3,5,10,15,36 };
	interchangesort(a, 9);
	output(a, 9);

	system("pause");
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void interchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j] && a[i] % 2 == 0 && a[j] % 2 == 0)
				swap(a[i], a[j]);
			else if (a[i] < a[j] && a[i] % 2 != 0 && a[j] % 2 != 0)
				swap(a[i], a[j]);
}
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
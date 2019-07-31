#include <iostream>
#include <string>


using namespace std;
void cau2(char b[], char c[], int i, int n, int k);
void cau3(int a[], int i, int k);
int menu();
int main()
{
	system("color 0a");
	string str;
	int count;
	char Set[] = { 'a','b' };
	int n = 2;
	int k = 3;
	int m;
	char kq[100];
	int a[100];
	bool flag = true;
	while (flag)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			count = 0;
			cin.ignore();
			getline(cin, str);
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] != 'a'
					&& str[i] != 'e'
					&& str[i] != 'i'
					&& str[i] != 'o'
					&& str[i] != 'u'
					&& str[i] != 'A'
					&& str[i] != 'E'
					&& str[i] != 'I'
					&& str[i] != 'O'
					&& str[i] != 'U'
					&& !iscntrl(str[i])
					&& !ispunct(str[i])
					&& !isblank(str[i])
					&& !isdigit(str[i]))

					count++;
			}
			cout << count << endl;
			break;
		case 2:
			cau2(kq, Set, 1, n, k);
			break;
		case 3:
			cin >> m;
			cau3(a, 1, m * 2);
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
	cout << "Lua chon ";
	int choice;
	cin >> choice;
	return choice;

}
void xuat(char c[], int k)
{
	for (int i = 1; i <= k; i++)
		cout << c[i];
	cout << endl;
}
void cau2(char b[],char c[], int i, int n,int k)
{
	for (int j = 0; j < n; j++)
	{
		b[i] = c[j];
		if (i == k)
		{
			xuat(b, k);
		}
		else
		cau2(b, c, i + 1, n, k);
	}
}
void xuat(int c[], int k)
{
	for (int i = 1; i <= k; i++)
		cout << c[i];
	cout << endl;
}
bool check(int c[], int k)
{
	int a = 0, b = 0;
	for (int i = 1; i <= k / 2; i++)
		a += c[i];
	for (int i = k / 2 + 1; i <= k; i++)
		b += c[i];
	if (a == b)
		return true;
	return false;
}
void cau3(int a[],int i,int k)
{
	for (int j = 0; j < 2; j++)
	{
		a[i] = j;
		if (i == k)
		{
			if(check(a, k))
				xuat(a, k);
		}
		else
			cau3(a, i + 1, k);
	}
}
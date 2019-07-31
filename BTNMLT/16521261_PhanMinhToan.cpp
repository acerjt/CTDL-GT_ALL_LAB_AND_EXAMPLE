#include <iostream>

using namespace std;


struct Time
{
	int h;
	int m;
	int s;
};


int cau1(int n);
int cau2(int n);
int cau2_2(int n);
int inputn();
int cau2_3(int n);
int menu();
int menu2();
void inputtime(Time &t);
int comparetime(Time time1, Time time2);
void outputtime(Time t);
int converttosecond(Time time);

int main()
{
	system("color 0a");
	int n;
	bool flag = true, flag2 = true;
	int choice;
	Time time1;
	Time time2;
	while (flag)
	{
		choice = menu();
		system("cls");
		switch (choice)
		{
		case 1:
			n = inputn();
			cout << cau1(n) << endl;
			break;
		case 2:
			flag2 = true;
			while (flag2)
			{
				choice = menu2();
				system("cls");
				switch (choice)
				{
				case 1:
					n = inputn();
					cout << cau2(n) << endl;
					break;
				case 2:
					n = inputn();
					cout << cau2_2(n) << endl;
					break;
				case 3:
					n = inputn();
					cout << cau2_3(n) << endl;
					break;
				default:
					flag2 = false;
					break;
				}
			}
			break;
		case 3:
			inputtime(time1);
			inputtime(time2);
			if (comparetime(time1, time2) == 1)
			{
				outputtime(time1);
				cout << " > ";
				outputtime(time2);
				cout << endl;
			}
			else if (comparetime(time1, time2) == -1)
			{
				outputtime(time1);
				cout << " < ";
				outputtime(time2);
				cout << endl;
			}
			else
			{
				outputtime(time1);
				cout << " = ";
				outputtime(time2);
				cout << endl;
			}

			break;
		default:
			flag = false;
			break;
		}
	}
	system("pause");
}
void inputtime(Time &t)
{
	cout << "Nhap gio: ";
	cin >> t.h;
	cout << "Nhap phut: ";
	cin >> t.m;
	cout << "Nhap giay: ";
	cin >> t.s;
}
void outputtime(Time t)
{
	cout << t.h << ":" << t.m << ":" << t.s;
}
int comparetime(Time time1, Time time2)
{
	if (converttosecond(time1) > converttosecond(time2))
		return 1;
	if (converttosecond(time1) > converttosecond(time2))
		return -1;
	else return 0;

}
int converttosecond(Time time)
{
	int second = time.s + time.m * 60 + time.h * 3600;
	return second;
}
int menu()
{
	cout << "Bai 1." << endl;
	cout << "Bai 2." << endl;
	cout << "Bai 3." << endl;
	cout << "Lua chon." << endl;
	int choice;
	cin >> choice;
	return choice;
}
int menu2()
{
	cout << "1.Bien Tam." << endl;
	cout << "2.Mang." << endl;
	cout << "3.De quy" << endl;
	cout << "Lua chon." << endl;
	int choice;
	cin >> choice;
	return choice;
}
int inputn()
{
	int n;
	cout << "Input N:";
	cin >> n;
	return n;
}
int cau1(int n)
{
	long N = n;
	long temp;
	if (N == INT_MAX  || N == INT_MIN)
		return 0;
	temp = N;
	long sodao = 0;
	while (temp != 0)
	{
		long x = temp % 10;
		if (sodao > 214748364)
			return 0;
		sodao = sodao * 10 + x;
		if ((N > 0 && sodao < 0) || (N < 0 && sodao > 0))
			return 0;
		temp = temp / 10;
	}
	return sodao;
}
int cau2(int n)
{
	int result = 0;
	int temp = 0;
	int temp2 = 1;
	if (n == 0)
		return result = temp2;
	if (n < 0)
		return 0;
	for (int i = 0; i < n; i++)
	{
		result = temp2 + temp;
		temp = temp2;
		temp2 = result;
	}
	return result;
}
int cau2_2(int n)
{
	if (n < 0)
		return 0;
	int *a = new int[n+1];
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}
int cau2_3(int n)
{
	if (n > 1)
	{
		return cau2_3(n - 1) + cau2_3(n - 2);
	}
	else if (n <= 1 && n >= 0)
		return 1;
	else return 0;
}
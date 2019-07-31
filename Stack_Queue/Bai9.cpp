#include <iostream>
#include <string>
using namespace std;

#define MAX 20
struct stack
{
	int t;
	string a[MAX];
};
void createstack(stack &s);
void nhiphan(stack &s, int x);
void output(stack s);
void Push(stack &s, char c);
void Pop(stack &s);
void thapluc(stack &s, int x);
void batphan(stack &s, int x);
int menu2();
int main()
{
	system("color 0a");
	stack s;
	bool flag = true;
	while (flag == true)
	{
		cout << "Nhap so can chuyen doi: ";
		int n;
		cin >> n;
		int choice = menu2();
		createstack(s);
		switch (choice)
		{
		case 1:
			nhiphan(s, n);
			break;
		case 2:
			batphan(s, n);
			break;
		case 3:
			thapluc(s, n);
			break;
		default:
			flag = false;
			break;
		}
		output(s);
	}
	system("pause");
}
int menu2()
{
	cout << "1.Nhi phan" << endl;
	cout << "2.Bat phan" << endl;
	cout << "3.Thap luc" << endl;
	cout << "Lua chon";
	int choice;
	cin >> choice;
	return choice;
}
void createstack(stack &s)
{
	s.t = -1;
}
void input(stack &s)
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		Push(s, str.at(i));
}
void output(stack s)
{
	for (int i = s.t; s.t >= 0;)
		Pop(s);
	cout << endl;
}
int IsEmpty(stack s)
{
	if (s.t == -1)
		return 1;
	else return 0;
}
int IsFull(stack s)
{
	if (s.t == MAX)
		return 1;
	else return 0;
}
void Push(stack &s, char c)
{
	if (IsFull(s) == 1)
		cout << "Stack day" << endl;
	else
	{
		s.t++;
		s.a[s.t] = c;
	}
}
void Pop(stack &s)
{
	if (IsEmpty(s) == 1)
		cout << "Stack rong" << endl;
	else
	{
		cout << s.a[s.t];
		s.t--;
	}
}
void nhiphan(stack &s, int x)
{
	while (x != 0)
	{
		int y = x % 2;
		Push(s, '0' + y);
		x = x / 2;
	}
}

void thapluc(stack &s, int x)
{
	while (x != 0)
	{
		int y = (x % 16);
		if (y < 10)
			y = '0' + y;
		if (y == 10)
			y = 'A';
		else if (y == 11)
			y = 'B';
		else if (y == 12)
			y = 'C';
		else if (y == 13)
			y = 'D';
		else if (y == 14)
			y = 'E';
		else if (y == 15)
			y = 'F';
		Push(s,y);
		x = x / 16;
	}
}
void batphan(stack &s, int x)
{
	while (x != 0)
	{
		int y = (x % 8);
		Push(s, '0' + y);
		x = x / 8;
	}
}
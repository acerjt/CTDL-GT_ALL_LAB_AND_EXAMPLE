#include<iostream>
#define MAX 20
using namespace std;

struct dia
{
	int n;
	char a;
	char b;
	char c;
};

struct stack_thn
{
	dia a[MAX];
	int t;
};

void CreateStack(stack_thn &s);
int Push(stack_thn &s, dia x);
int Pop(stack_thn &s, dia &x);
int IsEmpty(stack_thn s);
int main()
{
	system("color 0a");
	stack_thn s;
	dia bo;
	char nguon;
	char trungian;
	char dich;
	int N;
	int m;
	cout << "Nhap so dia cua nguon: "; cin >> m;
	CreateStack(s);
	bo.n = m; bo.a = 'A'; bo.b = 'B'; bo.c = 'C';
	Push(s, bo);
	do
	{
		Pop(s, bo);
		nguon = bo.a; trungian = bo.b; dich = bo.c;
		if (bo.n == 1)
			cout << "\nChuyen " << bo.a << " qua " << bo.c;
		else
		{
			N = bo.n;
			bo.n = N - 1;
			bo.a = trungian;
			bo.b = nguon;
			bo.c = dich;
			Push(s, bo);
			bo.n = 1;
			bo.a = nguon;
			bo.b = ' ';
			bo.c = dich;
			Push(s, bo);
			bo.n = N - 1;
			bo.a = nguon;
			bo.b = dich;
			bo.c = trungian;
			Push(s, bo);
		}
	} while (!IsEmpty(s));

	system("pause");
}
void CreateStack(stack_thn &s)
{
	s.t = -1;
}
int IsEmpty(stack_thn s)
{
	if (s.t == -1)
		return 1;
	else
		return 0;
}
int IsFull(stack_thn s)
{
	if (s.t >= MAX)
		return 1;
	else
		return 0;
}

int Push(stack_thn &s, dia x)
{
	if (IsFull(s) == 0)
	{
		s.t++;
		s.a[s.t] = x;
		return 0;
	}
	else
		return 1;
}

int Pop(stack_thn &s, dia &x)
{
	if (IsEmpty(s) == 0)
	{
		x = s.a[s.t];
		s.t--;
		return 0;
	}
	else
		return 1;
}
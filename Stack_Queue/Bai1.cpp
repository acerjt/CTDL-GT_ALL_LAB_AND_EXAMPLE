#include <iostream>
#include <string>
#define MAX 20
using namespace std;

struct stack
{
	char a[MAX];
	int t;
};

void createstack(stack &s);
void cau1(stack s);
int main()
{
	system("color 0a");
	stack s;
	createstack(s);
	cau1(s);
	
	system("pause");
}

void createstack(stack &s)
{
	s.t = -1;
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
		cout << s.a[s.t] << " ";
		s.t--;
	}
}
void cau1(stack s)
{
	Push(s, 'E');
	Push(s, 'A');
	Push(s, 'S');
	Pop(s);
	Push(s, 'Y');
	Pop(s);
	Pop(s);
	Push(s, 'Q');
	Push(s, 'U');
	Push(s, 'E');
	Pop(s);
	Pop(s);
	Pop(s);
	Push(s, 'S');
	Push(s, 'T');
	Pop(s);
	Pop(s);
	Pop(s);
	Push(s, 'I');
	Pop(s);
	Push(s, 'O');
	Push(s, 'N');
}







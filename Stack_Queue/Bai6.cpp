#include <iostream>
#include <string>
#define MAX 20
using namespace std;

struct stack
{
	char a[MAX];
	int top;
};

void infixtopostfix(char infix[], char postfix[]);
int main()
{
	system("color 0a");
	char A[MAX] = { 'a','-','b','*','c','^','d','+','f' };
	char B[MAX];
	infixtopostfix(A, B);
	printf("Postfix: %s\n", B);
	char C[MAX] = { '1','+','2','+','3','*','4','+','5','-','6','*','7','+','8' };
	infixtopostfix(C, B);
	printf("Postfix: %s\n", B);
	system("pause");
}

void createstack(stack &s)
{
	s.top = -1;
}

int IsEmpty(stack s)
{
	if (s.top == -1)
		return 1;
	return 0;
}

int IsFull(stack s)
{
	if (s.top >= MAX -1)
		return 1;
	return 0;

}

void Push(stack &s, char c)
{
	if (IsFull(s) == 1)
		cout << "Stack day" << endl;
	else
	{
		s.top++;
		s.a[s.top] = c;
	}
}

int Pop(stack &s)
{
	int ret;
	if (IsEmpty(s) == 1)
		return -1;
	else
	{
		ret = s.a[s.top];
		s.top--;
	}
	return ret;
}
int Precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;

	return 3;
}
void infixtopostfix(char infix[], char postfix[])
{
	stack s;
	createstack(s);
	char x, token;
	int i = 0, j = 0;
	for (i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalpha(token))
			postfix[j++] = token;
		else
			if (isalnum(token))
				postfix[j++] = token;
		else
			if(token == '^')
				postfix[j++] = token;
			else if (token == '(')
				Push(s, '(');
			else
				if (token == ')')
					while ((x = Pop(s)) != '(')
						postfix[j++] = x;
				else
				{
					while (Precedence(token) <= Precedence(s.a[s.top]) && !IsEmpty(s))
					{
						x = Pop(s);
						postfix[j++] = x;
					}
					Push(s, token);
				}
	}

	while (!IsEmpty(s))
	{
		x = Pop(s);
		postfix[j++] = x;
	}

	postfix[j] = '\0';
}
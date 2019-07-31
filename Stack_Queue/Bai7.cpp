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
float Evaluate(char *Postfix);
int main()
{
	system("color 0a");
	char A[MAX] = { '1','2','+','3','1','+','*','1','1','+','1','+','/' };
	char B[MAX] = { '3','4','+','3','5','+','*','7','+','8','*' };
	printf("Equals is %f\n", Evaluate(&A[0]));
	printf("Equals is %f\n", Evaluate(&B[0]));
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
	if (s.top >= MAX - 1)
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

float Pop(stack &s)
{
	float ret;
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
				if (token == '^')
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

float Evaluate(char *Postfix)
{
	stack s;
	char *p;
	float op1, op2, result;
	s.top = -1;
	p = &Postfix[0];
	while (*p != '\0')
	{
		while (*p == ' ' || *p == '\t')
		{
			p++;
		}
		while (isdigit(*p))
		{
			int num = 0;
			num = *p - 48;
			*p++;
			Push(s, num);
		}
		if (!isdigit(*p))
		{
			op1 = Pop(s);
			op2 = Pop(s);
			switch (*p)
			{
			case '+':
				result = op2 + op1;
				break;
			case '-':
				result = op2 - op1;
				break;
			case '/':
				result = op2 / op1;
				break;
			case '*':
				result = op2 * op1;
				break;
			default:
				printf("\nInvalid Operator");
				return 0;
			}
			Push(s, result);
		}
		p++;
	}
	return result;
}

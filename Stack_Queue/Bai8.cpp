#include <iostream>
#include <string>
using namespace std;


#define MAX 20
using namespace std;

struct stack
{
	string a[MAX];
	int t;
};

struct queue
{
	int rear;
	int front;
	string a[MAX];
};

void createstack(stack &s);
void input(stack &s);
void Push(stack &s, char c);
void Pop(stack &s);
void input(queue &q);
void output(stack s);
void createqueue(queue &q);
int enq(queue &q, char x);
void output(queue q);
int menu1();
int main()
{
	system("color 0a"); 
	stack s;
	queue q;
	bool flag = true;
	while (flag == true)
	{
		int choice = menu1();
		switch (choice)
		{
		case 1:
			createstack(s);
			input(s);
			output(s);
			break;
		case 2:
			createqueue(q);
			input(q);
			output(q);
			break;
		default:
			flag = false;
			break;
		}
	}
	system("pause");
}
int menu1()
{
	cout << "1.Stack" << endl;
	cout << "2.Queue" << endl;
	cout << "Lua chon: ";
	int choice;
	cin >> choice;
	return choice;
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
		cout << s.a[s.t];
		s.t--;
	}
}
void createqueue(queue &q)
{
	q.front = q.rear = -1;
}
int enq(queue &q, char x)
{
	if (q.rear - q.front + 1 == MAX)
		return 1;
	else
	{
		int f, r;
		if (q.front == -1)
		{
			q.front = 0;
			q.rear = -1;
		}
		if (q.rear == MAX - 1)
		{
			f = q.front;
			r = q.rear;
			for (int i = f; i < r; i++)
				q.a[f - i] = q.a[i];
			q.front = 0;
			q.rear = r - f;
		}
		q.rear++;
		q.a[q.rear] = x;
		return 0;
	}
}
int deq(queue &q)
{
	if (q.front == -1)
		return 1;
	else
	{
		q.front++;
		if (q.front > q.rear)
			q.front = q.rear = -1;
		return 0;
	}
}
void input(queue &q)
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		enq(q, str.at(i));
}
void output(queue q)
{
	for (int i = q.rear; i >= q.front; i--)
		cout << q.a[i];
	cout << endl;
}
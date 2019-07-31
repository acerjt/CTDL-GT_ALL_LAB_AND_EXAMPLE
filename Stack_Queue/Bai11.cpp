#include <iostream>
#include <string>
using namespace std;

#define MAX 20

struct stack
{
	int a[MAX];
	int t;
};
struct queue
{
	int a[MAX];
	int rear;
	int front;
};
void createqueue(queue &q);
void createstack(stack &s);
int enq(queue &q, int x);
void Push(stack &s, int x);
int IsEmpty(stack s);
void Pop(stack &s, int &x);
int deq(queue &q, int &x);
int main()
{
	system("color 0a");
	string str;
	stack s;
	createstack(s);
	queue q;
	createqueue(q);
	cout << "Nhap bieu thuc: ";
	cin >> str;
	cout << "Cac cap dau ngoac tuong ung trong bieu thuc" << endl;
	for (int i = 0; i < str.size(); i++)
		if (str.at(i) == '('&& q.front == -1)
			Push(s, i);
		else if (str.at(i) == '('&& q.front != -1)
		{
			while (q.front != -1)
			{
				int x, y;
				Pop(s, x);
				deq(q, y);
				cout << x << " " << y << endl;
			}
				
				Push(s, i);	
		}
		else if (str.at(i) == ')')
			enq(q, i);
	while (IsEmpty(s) != 1 && q.front != -1)
	{
		int x, y;
		Pop(s, x);
		deq(q, y);
		cout << x << " " << y << endl;
	}
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
	return 0;
}
int IsFull(stack s)
{
	if (s.t >= MAX - 1)
		return 1;
	return 0;
}

void Push(stack &s, int x)
{
	if (IsFull(s) == 0)
	{
		s.t++;
		s.a[s.t] = x;
	}
	else
		cout << "Stack day" << endl;
}
void Pop(stack &s, int &x)
{
	if (IsEmpty(s) == 0)
	{
		x = s.a[s.t];
		s.t--;
	}
	else
		cout << "Stack rong" << endl;
}

void createqueue(queue &q)
{
	q.front = q.rear = -1;
}

int deq(queue &q, int &x)
{
	if (q.front == -1)
		return 1;
	else
	{
		x = q.a[q.front];
		q.front++;
		if (q.front > q.rear)
			q.front = q.rear = -1;
		return 0;
	}
}

int enq(queue &q, int x)
{
	if (q.rear - q.front == MAX - 1)
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
#include <iostream>

#define MAX 10
using namespace std;

class Stack
{
	int t;
	int a[MAX];
public:
	~Stack() {};
	Stack()
	{
		t = -1;
	}
	void Push(int x)
	{
		if (IsFull() == 0)
		{
			t++;
			a[t] = x;
		}
		else cout << "Stack day" << endl;
	}
	void Pop()
	{
		if (IsEmpty() == 0)
		{
			cout << "Lay ra: " << a[t] << endl;
			t--;
		}
		else cout << "Stack rong" << endl;
	}
	int IsEmpty()
	{
		if (this->t == -1)
			return 1;
		else return 0;
	}
	int IsFull()
	{
		if (this->t == MAX)
			return 1;
		else return 0;
	}
	void output()
	{
		for (int i = 0; i <= t; i++)
			cout << a[i] << " ";
		cout << endl;
	}
};


int main()
{
	system("color 0a");
	Stack s;
	s.Push(5);
	s.output();
	s.Push(3);
	s.output();
	s.Pop();
	s.output();
	s.Push(2);
	s.output();
	s.Push(8);
	s.output();
	s.Pop();
	s.output();
	s.Pop();
	s.output();
	s.Pop();
	s.output();
	s.Push(9);
	s.output();
	s.Push(1);
	s.output();
	s.Pop();
	s.output();
	s.Push(7);
	s.output();
	s.Push(6);
	s.output();
	s.Pop();
	s.output();
	s.Pop();
	s.output();
	s.Push(4);
	s.output();
	s.Pop();
	s.output();
	s.Pop();
	s.output();
	system("pause");
}
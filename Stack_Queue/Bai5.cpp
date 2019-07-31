#include <iostream>
#define MAX 10
using namespace std;

class Queue
{
	int rear;
	int front;
	int a[MAX];
public:

	Queue()
	{
		rear = front = -1;
	};
	~Queue() {};
	int deq()
	{
		if (front != -1)
		{
			cout << "Lay phan tu dau hang doi: " << a[front] << " " << endl;;
			front++;
			if (front > rear)
				front = rear = -1;
			return 0;
		}
		else
		{
			cout << "Queue rong" << endl;
			return 1;
		}
	}
	int enq(int x)
	{
		int f, r;
		if (rear - front + 1 == MAX)
			return 1;
		else
		{
			if (front == -1)
			{
				front = 0;
				rear = -1;
			}
			if (rear == MAX - 1)
			{
				f = front;
				r = rear;
				for (int i = f; i < r; i++)
					a[i - f] = a[i];
				front = 0;
				rear = r - f;
			}
			rear++;
			a[rear] = x;
			cout << "Phan tu them vao hang doi " << x << endl;
			return 0;
		}
	}
	void output()
	{
		cout << "Hang doi: ";
		for (int i = front; i <= rear; i++)
			cout << a[i] << " ";
		cout << endl;
	}
};


int main()
{
	system("color 0a");
	Queue q;
	q.enq(5);
	q.output();
	q.enq(3);
	q.output();
	q.deq();
	q.output();
	q.enq(2);
	q.output();
	q.enq(8);
	q.output();
	q.deq();
	q.output();
	q.enq(9);
	q.output();
	q.enq(1);
	q.output();
	q.deq();
	q.output();
	q.enq(7);
	q.output();
	q.enq(6);
	q.output();
	q.deq();
	q.output();
	q.deq();
	q.output();
	q.enq(4);
	q.output();
	q.deq();
	q.output();
	q.deq();
	q.output();
	system("pause");
}
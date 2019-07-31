#include <iostream>

using namespace std;

#define MAX 10
struct stack
{
	int a[MAX];
	int t;
};

struct node
{
	node *pnext;
	int x;
};

struct list
{
	node *phead;
	node *ptail;
};

struct stack1
{
	list l;
};

struct queue
{
	int a[MAX];
	int front;
	int rear;

};

struct queue1
{
	list l;
};

void createstack(stack &s);
int menu();
int menu2();
int menu21();
int Pop(stack &s, int &x);
int Push(stack &s, int x);
int IsEmpty(stack s);
void deletestack(stack &s);
node * Createnode(int x);
void createstack(stack1 &s);
void Push(list &l, node *p);
int Pop(list &l, int &x);
int IsEmpty(list l);
void xoacacphantutrongstack(list &l);
void createqueue(queue &q);
int enqueue(queue &q, int x);
int menu11();
int dequeue(queue &q, int &x);
int IsEmpty(queue q);
void xoatatcaphantutrongqueue(queue &q);
void createqueue(queue1 &q);
void Enqueue(list &l, node *p);
int dequeue(queue1 &q, int &x);
void xoacacphantutrongqueue(list &l);
int main()
{
	system("color 0a");

	int choice = menu();
	bool flag = true;
	bool flag21 = true;
	bool flag2 = true;
	int choice2;
	int choice21;
	int count;
	while (flag == true)
	{
		switch (choice)
		{
		case 1:
			choice2 = menu2();
			while (flag2 == true)
			{
				switch (choice2)
				{
				case 1:
					queue q;
					createqueue(q);
					while (flag21 == true)
					{
						choice21 = menu11();
						switch (choice21)
						{
						case 1:
							for (int i = 2; i <= 5; i++)
								enqueue(q, i);
							break;
						case 2:
							int x,tv;
							tv = dequeue(q, x);
							if (tv == 0)
								cout << "Gia tri lay duoc tu Queque " << x << endl;
							break;
						case 3:
							if (q.front == -1)
								cout << "Queue rong" << endl;
							else
								for (int i = q.front; i <= q.rear; i++)
									cout << q.a[i] << " ";
							cout << endl;
							break;
						case 4:
							count = 0;
							if (IsEmpty(q) == 0)
							{
								for (int i = q.front; i <= q.rear; i++)
									count++;
								cout << "So phan tu cua queue: " << count << endl;
							}
							else
								cout << "Queue rong" << endl;
							break;
						case 5:
							xoatatcaphantutrongqueue(q);
							break;

						default:
							break;
						}
					}
				case 2:
					queue1 q1;
					createqueue(q1);
					while (flag21 == true)
					{
						choice21 = menu11();
						switch (choice21)
						{
						case 1:
							for (int i = 2; i <= 5; i++)
							{
								node *p = new node;
								p = Createnode(i);
								Enqueue(q1.l, p);
							}
							break;
						case 2:
							int x, tv;
							tv = dequeue(q1, x);
							if (tv == 0)
								cout << "Gia tri lay duoc tu Queque " << x << endl;
							break;
						case 3:
							if (q1.l.phead == NULL)
								cout << "Queue rong" << endl;
							else
								for (node *p = q1.l.phead; p != NULL; p = p->pnext)
									cout << p->x << " ";
							cout << endl;
							break;
						case 4:
							count = 0;
							if (IsEmpty(q1.l) == 0)
							{
								for (node *p = q1.l.phead; p != NULL; p = p->pnext)
									count++;
								cout << "So phan tu cua queue: " << count << endl;
							}
							else
								cout << "Queue rong" << endl;
							break;
						case 5:
							xoacacphantutrongqueue(q1.l);
							break;
						default:
							break;
						}
					}
				default:
					break;
				}
			}
			break;
		case 2:
			 choice2 = menu2();
			while (flag2 == true)
			{
				switch (choice2)
				{
				case 1:
					stack s;
					createstack(s);
					
					while (flag21 == true)
					{
						choice21 = menu21();
						switch (choice21)
						{
						case 1:
							for (int i = 2; i <= 5; i++)
								Push(s, i);
							break;
						case 2:
							int x, tv;
							tv = Pop(s, x);
							if (tv == 0) 
								cout << "Gia tri lay duoc tu Stack " << x << endl;
							else
								cout << "Stack rong " << endl;
							break;
						case 3:
							if (IsEmpty(s) == 0)
							{
								cout << "Cac gia tri cua stack: ";
								for (int i = 0; i <= s.t; i++)
									cout << s.a[i] << " ";
								cout << endl;
							}
							else
								cout << "Stack rong!" << endl;
							break;
						case 4:
							count = 0;
							if (IsEmpty(s) == 0)
							{
								for (int i = 0; i <= s.t; i++)
									count++;
								cout << "So phan tu cua Stack " << count << endl;
							}
							else
								cout << "Stack rong!" << endl;
							break;
						case 5:
							deletestack(s);
							break;
						default:
							flag21 = false;
							break;
						}
					}
					break;
				case 2:
					stack1 s1;
					createstack(s1);
					while (flag21 == true)
					{
						choice21 = menu21();
						switch (choice21)
						{
						case 1:
							for (int i = 2; i <= 5; i++)
							{
								node *p = Createnode(i);
								Push(s1.l, p);
							}
							break;
						case 2:
							int x, tv;
							tv = Pop(s1.l, x);
							if (tv == 0) 
								cout << "Gia tri lay duoc tu Stack " << x << endl;
							else
								cout << "Stack rong " << endl;
							break;
						case 3:
							if (IsEmpty(s1.l) == 0)
							{
								cout << "Cac gia tri cua stack: ";
								for (node *p = s1.l.phead; p != NULL; p = p->pnext)
									cout << p->x << " ";
								cout << endl;
							}
							else
								cout << "Stack rong!" << endl;
							break;
						case 4:
							count = 0;
							if (IsEmpty(s1.l) == 0)
							{
								for (node *p = s1.l.phead; p != NULL; p = p->pnext)
									count++;
								cout << "So phan tu cua Stack " << count << endl;
							}
							else
								cout << "Stack rong!" << endl;
							break;
						case 5:
							xoacacphantutrongstack(s1.l);
							break;
						default:
							flag21 = false;
							break;
						}
					}
					break;
				default:
					flag2 = false;
					break;
				}
			}
			break;
		default:
			flag = false;
			break;

		}
	}



	system("pause");
}
int menu()
{
	cout << "1.Bai 1" << endl;
	cout << "2.Bai 2" << endl;
	cout << "Lua chon cua ban: ";
	int choice;
	cin >> choice;
	return choice;
}
int menu2()
{
	cout << "1.Su dung mang" << endl;
	cout << "2.Su dung danh sach lien ket" << endl;
	cout << "Lua chon cua ban: ";
	int choice;
	cin >> choice;
	return choice;
}
int menu21()
{
	cout << "1.Push" << endl;
	cout << "2.Pop" << endl;
	cout << "3.Kiem tra stack co rong hay khong" << endl;
	cout << "4.Dem so luong phan tu trong stack" << endl;
	cout << "5.Xoa tat ca phan tu trong stack" << endl;
	int choice;
	cin >> choice;
	return choice;
}
int menu11()
{
	cout << "1.Enqueue" << endl;
	cout << "2.Dequeue" << endl;
	cout << "3.Kiem tra queue co rong hay khong" << endl;
	cout << "4.Dem so luong phan tu trong queue" << endl;
	cout << "5.Xoa tat ca phan tu trong queue" << endl;
	int choice;
	cin >> choice;
	return choice;
}

void createstack(stack &s)
{
	s.t = -1;
}

int IsEmpty(stack s)
{
	if (s.t == -1)
		return 1;
	else
		return 0;
}

int IsFull(stack s)
{
	if (s.t >= MAX)
		return 1;
	else
		return 0;
}

int Push(stack &s, int x)
{
	if ((IsFull(s)) == 1)
		return 1;
	else
	{
		s.t++;
		s.a[s.t] = x;
		return 0;
	}
}

int Pop(stack &s,int &x)
{
	if (IsEmpty(s) == 1)
		return 1;
	else
	{
		x = s.a[s.t];
		s.t--;
		return 0;
	}
}

int IsEmpty(list l)
{
	if (l.phead == NULL)
		return 1;
	else
		return 0;
}

void Push(list &l, node *p)
{
	if (IsEmpty(l) == 1)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

int Pop(list &l, int &x)
{
	node *p;
	if (IsEmpty(l) == 0)
	{
		p = l.phead;
		x = p->x;
		l.phead = l.phead->pnext;
		if (l.phead == NULL)
			l.ptail = NULL;
		delete p;
		return 0;
	}
	else
		return 1;
}

void createstack(stack1 &s)
{
	s.l.phead = s.l.ptail = NULL;
}
node * Createnode(int x)
{
	node *p = new node;
	p->x = x;
	p->pnext = NULL;
	return p;
}

void deletestack(stack &s)
{
	if (IsEmpty(s) == 1)
		cout << " Stack rong" << endl;
	else
	{
		s.t = -1;
	}
}

void xoacacphantutrongstack(list &l)
{
	if (l.phead == NULL)
	{
		cout << "Stack rong" << endl;
		return;
	}
	for (node *p = l.phead; p != NULL; p = l.phead)
	{
		l.phead = l.phead->pnext;
		delete p;
	}
}

void xoacacphantutrongqueue(list &l)
{
	if (l.phead == NULL)
	{
		cout << "Stack rong" << endl;
		return;
	}
	for (node *p = l.phead; p != NULL; p = l.phead)
	{
		l.phead = l.phead->pnext;
		delete p;
	}
}

void createqueue(queue &q)
{
	q.front = -1;
	q.rear = -1;
}

void createqueue(queue1 &q)
{
	q.l.phead = q.l.ptail = NULL;
}

int dequeue(queue &q,int &x)
{
	if (q.front != -1)
	{
		x = q.a[q.front];
		q.front++;
		if (q.front > q.rear)
		{
			q.front = -1;
			q.rear = -1;
		}
		return 0;
	}
	else
	{
		cout << "Queue rong" << endl;
		return 1;
	}
}
int dequeue(queue1 &q, int &x)
{
	if (IsEmpty(q.l) == 0)
	{
		if (q.l.phead->pnext == NULL)
		{
			node *p = q.l.phead;
			x = q.l.phead->x;
			q.l.phead = q.l.ptail = NULL;
			delete p;
			return 0;
		}
		for (node *p = q.l.phead; p != NULL; p = p->pnext)
		{
			node *k = p->pnext;
			if (k->pnext == NULL)
			{
				x = k->x;
				p->pnext = NULL;
				q.l.ptail = p;
				delete k;
			}
		}
		return 0;
	}
	else
	{
		cout << "Queue rong" << endl;
		return 1;
	}
}

int enqueue(queue &q, int x)
{
	int i;
	int f, r;
	if (q.rear - q.front == MAX - 1)
	{
		return 1;
	}
	else
	{
		if (q.front == -1)
		{
			q.front = 0;
			q.rear = -1;
		}
		if (q.rear + 1 == MAX)
		{
			f = q.front;
			r = q.rear;
			for (i = f; i <= r; i++)
				q.a[i - f] = q.a[i];
			q.front = 0;
			q.rear = r - f;
		}

		q.rear++;
		q.a[q.rear] = x;
		return 0;
	}
}
void Enqueue(list &l, node *p)
{
	if (IsEmpty(l) == 1)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

int IsEmpty(queue q)
{
	if (q.front == -1)
		return 1;
	else
		return 0;
}

void xoatatcaphantutrongqueue(queue &q)
{
	q.front = q.rear = -1;
}
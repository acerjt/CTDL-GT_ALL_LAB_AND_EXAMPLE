#include <iostream>
#include <string>
#define MAX_NUMBER 30
using namespace std;


struct s_bignum
{
	string a[30];
	int t;
};

void Push(s_bignum &s, char c);
void input(s_bignum &s);
void Pop(s_bignum &s, int &x);
s_bignum cong(s_bignum a);
void output(s_bignum s);
void chuyendoi(s_bignum &s);
s_bignum tru(s_bignum a);
s_bignum nhan(s_bignum a);
s_bignum MC();
void createstack(s_bignum &s);
void Madd(s_bignum a, s_bignum &reg);
s_bignum MRC(s_bignum a);
s_bignum tong(s_bignum a, s_bignum b);
void Msub(s_bignum a, s_bignum &reg);
s_bignum hieu(s_bignum a, s_bignum b);
int menu();
int main()
{
	system("color 0a");
	
	s_bignum result;
	input(result);
	s_bignum reg;
	createstack(reg);
	bool flag = true;
	while (flag == true)
	{
		int choice = menu();
		switch (choice)
		{
		case 1:
			result = cong(result);
			output(result);
			break;
		case 2:
			result = tru(result);
			output(result);
			break;
		case 3:
			result = nhan(result);
			output(result);
			break;
		case 5:
			reg = MC();
			input(result);
			break;
		case 6:
			Madd(result, reg);
			input(result);
			//output(result);
			break;
		case 7:
			Msub(result, reg);
			input(result);
			break;
		case 8:
			result = MRC(reg);
			output(result);
			break;
		default:
			break;
		}
	}
	
	
	
	system("pause");
}

int menu()
{
	cout << "1.Cong" << endl;
	cout << "2.Tru" << endl;
	cout << "3.Nhan" << endl;
	cout << "5.MC" << endl;
	cout << "6.M+" << endl;
	cout << "7.M-" << endl;
	cout << "8.MRC" << endl;
	cout << "Lua chon: ";
	int choice;
	cin >> choice;
	return choice;
}

void createstack(s_bignum &s)
{
	s.t = -1;
}
int IsEmpty(s_bignum s)
{
	if (s.t == -1)
		return 1;
	else return 0;
}

int IsFull(s_bignum s)
{
	if (s.t == MAX_NUMBER)
		return 1;
	else return 0;
}

void Push(s_bignum &s, char c)
{
	if (IsFull(s) == 1)
		cout << "Stack day" << endl;
	else
	{
		s.t++;
		s.a[s.t] = c;
	}
}

void Pop(s_bignum &s, int &x)
{
	if (IsEmpty(s) == 1)
		cout << "Stack rong" << endl;
	else
	{
		x = stoi(s.a[s.t]);
		s.t--;
	}
}


void input(s_bignum &s)
{
	createstack(s);
	string str;
	cout << "Toan hang: ";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		Push(s, str.at(i));
	}
}

void output(s_bignum s)
{
	for (int i = 0; i <= s.t; i++)
		cout << s.a[i];
	cout << endl;
}
s_bignum MC()
{
	s_bignum b;
	createstack(b);
	b.t++;
	b.a[b.t] = '0';
	return b;
}
void Madd(s_bignum a, s_bignum &reg)
{
	reg = tong(reg, a);
}
void Msub(s_bignum a, s_bignum &reg)
{
	reg = hieu(reg, a);
}
s_bignum hieu(s_bignum a, s_bignum b)
{
	s_bignum c;
	createstack(c);
	s_bignum d;
	createstack(d);
	while (IsEmpty(b) == 0 || IsEmpty(a) == 0)
	{
		if (IsEmpty(d) == 1)
			Push(d, '0');
		if (IsEmpty(b) == 1)
			Push(b, '0');
		if (IsEmpty(a) == 1)
			Push(a, '0');
		int x, y, z;
		Pop(b, x);
		Pop(a, y);
		Pop(d, z);
		if (y < x)
		{
			int result = y + 10 - (z + x);
			Push(c, '0' + result);
			Push(d, '0' + 1);
		}
		else
		{
			if ((z + x) > y)
			{
				int sum = y + 10 - x - z;
				Push(c, '0' + sum);
				Push(d, '0' + 1);
			}
			else
			{
				int sum = y - x - z;
				Push(c, '0' + sum);
			}
		}
	}
	chuyendoi(c);
	return c;
}
s_bignum MRC(s_bignum a)
{
	return a;
}
s_bignum cong(s_bignum a)
{
	s_bignum b;
	string str;
	input(b);
	s_bignum c;
	createstack(c);
	s_bignum d;
	createstack(d);
	while (IsEmpty(b) == 0 || IsEmpty(a) == 0 )
	{
		if (IsEmpty(d) == 1)
			Push(d, '0');
		if (IsEmpty(b) == 1)
			Push(b, '0');
		if (IsEmpty(a) == 1)
			Push(a, '0');
		int x, y, z;
		Pop(b, x);
		Pop(a, y);
		Pop(d, z);
		int sum = x + y + z;
		if (sum > 9)
		{
			char s1 = '0' +(sum % 10);
			Push(c, s1);
			char s2 = '0'+(sum / 10);
			Push(d, s2);
		}
		else
		{
			char s1 = '0' + sum;
			Push(c, s1);
		}
	} 
	if (IsEmpty(d) == 0)
	{
		int x;
		Pop(d, x);
		Push(c,'0'+x);
	}
	chuyendoi(c);
	return c;
}
s_bignum tong(s_bignum a,s_bignum b)
{
	s_bignum c;
	createstack(c);
	s_bignum d;
	createstack(d);
	while (IsEmpty(b) == 0 || IsEmpty(a) == 0)
	{
		if (IsEmpty(d) == 1)
			Push(d, '0');
		if (IsEmpty(b) == 1)
			Push(b, '0');
		if (IsEmpty(a) == 1)
			Push(a, '0');
		int x, y, z;
		Pop(b, x);
		Pop(a, y);
		Pop(d, z);
		int sum = x + y + z;
		if (sum > 9)
		{
			char s1 = '0' + (sum % 10);
			Push(c, s1);
			char s2 = '0' + (sum / 10);
			Push(d, s2);
		}
		else
		{
			char s1 = '0' + sum;
			Push(c, s1);
		}
	}
	if (IsEmpty(d) == 0)
	{
		int x;
		Pop(d, x);
		Push(c, '0' + x);
	}
	chuyendoi(c);
	return c;
}
s_bignum tru(s_bignum a)
{
	s_bignum b;
	string str;
	input(b);
	s_bignum c;
	createstack(c);
	s_bignum d;
	createstack(d);
	while (IsEmpty(b) == 0 || IsEmpty(a) == 0)
	{
		if (IsEmpty(d) == 1)
			Push(d, '0');
		if (IsEmpty(b) == 1)
			Push(b, '0');
		if (IsEmpty(a) == 1)
			Push(a, '0');
		int x, y, z;
		Pop(b, x);
		Pop(a, y);
		Pop(d, z);
		if (y < x)
		{
			int result = y + 10 - (z + x);
			Push(c, '0' + result);
			Push(d, '0' + 1);
		}
		else
		{
			if ((z + x) > y)
			{
				int sum = y + 10 - x - z;
				Push(c, '0' + sum);
				Push(d, '0' + 1);
			}
			else
			{
				int sum = y - x - z;
				Push(c, '0' + sum);
			}
		}
	}
	chuyendoi(c);
	return c;
}

s_bignum nhan(s_bignum a)
{
	s_bignum b;
	string str;
	input(b);
	s_bignum c;
	createstack(c);
	s_bignum d;
	createstack(d);
	s_bignum e;
	createstack(e);
	for (int i = b.t; i >= 0; i--)
	{
		for (int j = a.t; j >= 0; j--)
		{
			if (IsEmpty(d) == 1)
				Push(d, '0');
			int z;
			Pop(d,z);
			int mul = stoi(a.a[j])*stoi(b.a[i]) + z;
			if (mul > 9)
			{
				char c1 = '0' + (mul % 10);
				Push(c, c1);
				char c2 = '0' + (mul / 10);
				Push(d, c2);
			}
			else
			{
				char c1 = '0' + mul;
				Push(c, c1);
			}
		
		}
		if (IsEmpty(d) == 0)
		{
			int x;
			Pop(d, x);
			Push(c, '0' + x);
		}
		chuyendoi(c);
		e = tong(e, c);
		c.t = -1;
		for (int k = 0; k < (b.t - i + 1); k++)
			Push(c, '0');
	}
	return e;
}

void chuyendoi(s_bignum &s)
{
	s_bignum a;
	createstack(a);
	for (int i = 0; s.t!=-1;)
	{
		int x;
		Pop(s, x);
		Push(a, '0' + x);
	}
	s = a;
}
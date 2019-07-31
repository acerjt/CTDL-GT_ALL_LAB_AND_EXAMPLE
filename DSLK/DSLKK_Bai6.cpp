#include <iostream>

using namespace std;

struct hanghoa
{
	string tenmathang;
	int giamathang;
	int soluongkho;
};

struct node
{
	node *next;
	node *prev;
	hanghoa info;
};

struct list
{
	node *head;
	node *tail;
};

int main()
{
	system("color 0a");



	system("pause");
}
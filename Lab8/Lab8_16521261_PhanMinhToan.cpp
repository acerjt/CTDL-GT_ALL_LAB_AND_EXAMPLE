#include <iostream>
#include <queue>

using namespace std;

struct node
{
	node *left;
	node *right;
	int info;
};

typedef struct node Tnode;

typedef Tnode* Tree;


void createtree(Tree &t);
int InsertTree(Tree &t, unsigned int x);
void LNR(Tree t);
void LRN(Tree t);
void NLR(Tree t);
void NRL(Tree t);
void RNL(Tree t);
void RLN(Tree t);
void searchx(Tree t, unsigned int x);
int menu();
void outputorigintree(int a[], int n);
void removex(Tree &t, unsigned int x);
int numbernode(Tree t);
int havetwochild(Tree t);
int haveonechild(Tree t);
int leafnode(Tree t);
int haveonerightchild(Tree t);
int heighttree(Tree t);
int max(int a, int b);
void nodechan(Tree t);
void nodelonhonx(Tree t, unsigned int x);
void nodelonnhat(Tree t);
void cayconphainhonhat(Tree t);
int dodaiduongdi(Tree t, unsigned int x);
void nodetungmuc(Tree t);
void nodetungmuc1(Tree t);
void getnodes(Tree t, int level);
int main()
{
	system("color 0a");

	Tree t;
	createtree(t);
	int a[] = { 7,3,36,1,6,15,40,4,23 };
	for (int i = 0; i < 9; i++)
	{
		InsertTree(t, a[i]);
	}
	bool flag = true;
	int choose;
	int x;

	while (flag)
	{
		choose = menu();
		system("cls");
		NLR(t);
		cout << "NLR" << endl;
		switch (choose)
		{
		case 1:
			LNR(t);
			cout << "LNR" << endl;
			LRN(t);
			cout << "LRN" << endl;
			NLR(t);
			cout << "NLR" << endl;
			NRL(t);
			cout << "NRL" << endl;
			RNL(t);
			cout << "RNL" << endl;
			RLN(t);
			cout << "RLN" << endl;
			break;
		case 2:
			cout << "Nhap x: ";
			cin >> x;
			searchx(t, x);
			break;
		case 3:
			cout << "Nhap x: ";
			cin >> x;
			removex(t, x);
			break;
		case 4:
			cout << numbernode(t) << endl;
			break;
		case 5:
			cout << havetwochild(t) << endl;
			break;
		case 6:
			cout << haveonechild(t) << endl;
			break;
		case 7:
			cout << haveonerightchild(t) << endl;
			break;
		case 8:
			cout << leafnode(t) << endl;
			break;
		case 9:
			cout << heighttree(t) << endl;
			break;
		case 10:
			 nodechan(t);
			 cout << endl;
			break;
		case 11:
			cout << "Nhap x: ";
			cin >> x;
			nodelonhonx(t, x);
			cout << endl;
		case 12:
			nodelonnhat(t);
			break;
		case 13:
			cayconphainhonhat(t->right);
			break;
		case 14:
			nodetungmuc1(t);
			break;
		case 15:
			cout << "Nhap x: ";
			cin >> x;
			cout << dodaiduongdi(t, x) << endl;
			break;
		default:
			break;
		}
	}

	

	system("pause");
}
int menu()
{
	cout << "1.In cay" << endl;
	cout << "2.Tim node x tren cay" << endl;
	cout << "3.Xoa node co khoa x tren cay" << endl;
	cout << "4.In ra tong so node" << endl;
	cout << "5.In ra so node co 2 cay con" << endl;
	cout << "6.In ra so node co 1 cay con" << endl;
	cout << "7.In ra so node co 1 cay con phai" << endl;
	cout << "8.In ra so node la" << endl;
	cout << "9.In ra chieu cao" << endl;
	cout << "10.In ra  node co gia tri chan" << endl;
	cout << "11.In ra node co gia tri lon hon x" << endl;
	cout << "12.In ra gia tri cua node lon nhat" << endl;
	cout << "13.In ra gia tri cua node co key nho nhat cua cay con phai cua cay." << endl;
	cout << "14.In cac node tren tung muc cua cay" << endl;
	cout << "15. Cho biet do dai duong du tu goc den node co gia tri x" << endl;
	int chose;
	cin >> chose;
	return chose;

}
void nodetungmuc1(Tree t)
{
	int h = heighttree(t);
	for (int i = 1; i <= h; i++)
	{
		getnodes(t, i);
		cout << endl;
	}
}

void getnodes(Tree t, int level)
{
	if (t == NULL)
		return;
	if (level == 1)
		cout << t->info << " ";
	else if (level > 1)
	{
		getnodes(t->left, level - 1);
		getnodes(t->right, level - 1);
	}
}
void nodetungmuc(Tree t)
{
	if (t == NULL) 
		return;
	queue<Tnode *> q;
	q.push(t);

	while (q.empty() == false)
	{ 
		int nodeCount = q.size();
		while (nodeCount > 0)
		{
			node *node = q.front();
			cout << node->info << " ";
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
		cout << endl;
	}
}

int dodaiduongdi(Tree t, unsigned int x)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->info > x)
			return  1 + dodaiduongdi(t->left, x);
		else if (t->info < x)
			return  1 + dodaiduongdi(t->right, x);
		else return 0;
	}
}

void nodelonhonx(Tree t, unsigned int x)
{
	if (t == NULL)
		return;
	else
	{
		if (t->info <= x)
			nodelonhonx(t->right, x);
		else
		{
			cout << t->info << " ";
			nodelonhonx(t->left, x);
			nodelonhonx(t->right, x);
		}
	}
}
void cayconphainhonhat(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		cayconphainhonhat(t->left);
		if (t->left == NULL)
			cout << t->info << " " << endl;
	}
}
void nodelonnhat(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		nodelonnhat(t->right);
		if (t->right == NULL)
			cout << t->info << " " << endl;
	}
}
int numbernode(Tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		return 1 + numbernode(t->left) + numbernode(t->right);
	}
}
int heighttree(Tree t)
{
	if (t == NULL)
		return 0;
	else return 1 + (max(heighttree(t->left), heighttree(t->right)));
}

int max(int a, int b)
{
	 if (a < b)
		return b;
	 else return a;
}
void nodechan(Tree t)
{
	if (t == NULL)
		return;
	else
	{
		if (t->info % 2 == 0)
			cout << t->info << " ";
		nodechan(t->left);
		nodechan(t->right);
	}
}
int leafnode(Tree t)
{
	if (t == NULL)
		return 0;
	else if (t->left == NULL && t->right == NULL)
		return 1;
	else return leafnode(t->left) + leafnode(t->right);


}
int haveonerightchild(Tree t)
{
	if (t == NULL)
		return 0;
	if (t->left == NULL && t->right != NULL)
		return 1 + haveonechild(t->left) + haveonechild(t->right);
	else return haveonechild(t->left) + haveonechild(t->right);

}
int haveonechild(Tree t)
{
	if (t == NULL) 
		return 0;
	if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
		return 1 + haveonechild(t->left) + haveonechild(t->right);
	else return haveonechild(t->left) + haveonechild(t->right);

}
int havetwochild(Tree t)
{
	if (t->left != NULL && t->right != NULL)
	{
		return 1 + havetwochild(t->left) + havetwochild(t->right);
	}
	else
		return 0;
}
void searchstandfor(Tree &p, Tree &t)
{
	if (t->left != NULL)
		searchstandfor(p, t->left);
	else
	{
		p->info = t->info;
		p = t;
		t = t->right;
	}
}
void removex(Tree &t, unsigned int x)
{
	if (t != NULL) {
		if (t->info == x)
		{
			Tnode *p = t;
			if (t->left == NULL)
				t = t->right;
			else if (t->right == NULL)
				t = t->left;
			else searchstandfor(p, t->right);
			delete p;
			cout << "Xoa thanh cong" << endl;
			return;
		}
		else
		{
			if (x > t->info)
				removex(t->right, x);
			else
				removex(t->left, x);
		}
	}
	else
		cout << "Xoa khong thanh cong" << endl;
}
void outputorigintree(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void searchx(Tree t, unsigned int x)
{
	if (t != NULL) {
		if (t->info == x)
		{
			cout << "Co x" << endl;
			return;
		}
		else
		{
			if (x > t->info)
				searchx(t->right, x);
			else
				searchx(t->left, x);
		}
	}
	else
		cout << "Khong co x" << endl;
}

void LRN(Tree t)
{
	if (t != NULL)
	{
		LRN(t->left);
		LRN(t->right);
		cout << t->info << " ";
	}
}
void LNR(Tree t)
{
	if (t != NULL)
	{
		LNR(t->left);
		cout << t->info << " ";
		LNR(t->right);
	}
}
void NLR(Tree t)
{
	if (t != NULL)
	{
		cout << t->info << " ";
		NLR(t->left);
		NLR(t->right);
	}
}
void NRL(Tree t)
{
	if (t != NULL)
	{
		cout << t->info << " ";
		NRL(t->right);
		NRL(t->left);
	}
}
void RNL(Tree t)
{
	if (t != NULL)
	{
		RNL(t->right);
		cout << t->info << " ";
		RNL(t->left);
	}
}
void RLN(Tree t)
{
	if (t != NULL)
	{
		RLN(t->right);
		RLN(t->left);
		cout << t->info << " ";
	}
}

void createtree(Tree &t)
{

	t = NULL;
}

Tnode *CreateTnode(unsigned int x)
{
	Tnode *p = new Tnode;
	if (p == NULL)
		return NULL;
	p->left = NULL;
	p->right = NULL;
	p->info = x;
	return p;
}

int InsertTree(Tree &t, unsigned int x)
{
	if (t != NULL)
	{
		if (x == t->info)
			return 0;
		else
			if (x > t->info)
				InsertTree(t->right, x);
			else
				InsertTree(t->left, x);
	}
	else
	{
		t = CreateTnode(x);
		if (t == NULL)
			return -1;
		return 1;
	}
}
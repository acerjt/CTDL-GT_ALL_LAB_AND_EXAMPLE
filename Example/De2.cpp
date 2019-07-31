#include <iostream>
using namespace std;

// de so 2

typedef struct diemrenluyen {
	int MSSV = 0;
	int GioiTinh = 0;
	float DTB = 0;
}DRL;
void nhapSV(DRL &a, DRL b);
struct node {
	DRL  data;
	struct node *pNext;
};
typedef struct node NODE;

struct list
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;



void CreateLIST(LIST &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
void nhapSV(DRL &a, DRL b) {
	a.MSSV = b.MSSV;
	a.GioiTinh = b.GioiTinh;
	a.DTB = b.DTB;
}

NODE *CreateNODE(DRL x) {

	NODE *p = new NODE;
	nhapSV(p->data, x);
	p->pNext = NULL;
	return p;
}

void AddNode( LIST &l, NODE *p ){
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {

		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void ExportData(LIST l) {
	for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
		cout << "MSSV: " << i->data.MSSV<<endl;
		cout << "Gioi tinh: " << i->data.GioiTinh << endl;
		cout << "DTB: " << i->data.DTB << endl;
	}
}






DRL FindMax(LIST l) {
	DRL max;
	nhapSV(max, l.pHead->data);
	for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
		if (max.DTB < i->data.DTB) {
			nhapSV(max, i->data);
		}
	}
	return max;
}

void SortMSSV(LIST &l) {
	for (NODE *i = l.pHead; i != NULL; i = i->pNext) {
		for (NODE *j = i->pNext; j != NULL; j = j->pNext) {
			if (i->data.MSSV > j->data.MSSV) {
				swap(i->data.MSSV, j->data.MSSV);
				swap(i->data.GioiTinh, j->data.GioiTinh);
				swap(i->data.DTB, j->data.DTB);
			}
		}
	}
}


	




void ImportSV(DRL &a) {
	cout << "Vui long nhap MSSV: ";
	cin >> a.MSSV; cout << endl;
	cout << "Vui long nhap gioi tinh: ";
	cin >> a.GioiTinh; cout << endl;
	cout << "Vui long nhap DTB: ";
	cin >> a.DTB; cout << endl;
}

int main() {

	LIST l;
	DRL a;
	CreateLIST(l);
	cout << "Nhap so luong sinh vien n: ";
	int n;

	
	cin >> n; cout << endl;
	for (int i = 1;i <= n; i++) {
		ImportSV(a);
		NODE *p = CreateNODE(a);
		AddNode(l, p);
	}
	ExportData(l);
	system("pause");
	return 0;
}
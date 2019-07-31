#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
	int result = 0;
	int count = 1;
	while (!ar.empty())
	{
		int x = ar[0];
		for (int j = 1; j < ar.size(); j++)
			if (ar[j] == x)
			{
				count++;
				ar.erase(ar.begin() + j);
				j -= 1;
			}
		ar.erase(ar.begin());
		count /= 2;
		result += count;
	}
	return result;
}

int main()
{
	vector<int> a = {
		10, 20, 20, 10, 10, 30, 50, 10, 20 };
	cout << sockMerchant(9, a);
	

	system("pause");
	return 0;
}



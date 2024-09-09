#include<iostream>
#include<vector>
using namespace std;


int numTrees(int n) {
	vector<int> f(n + 1, 0);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			f[i] += f[j - 1] * f[i - j];
	}

	return f[n];
}


int main() {


	int n{ 0 };
	cin >> n;
	std::cout << numTrees(n) << std::endl;

	return 0;
}
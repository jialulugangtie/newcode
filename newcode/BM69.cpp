#include<iostream>
#include<vector>


using namespace std;

int slove(string str) {
	vector<int> ans(str.size() + 1, 0);
	ans[0] = 1;

	for (int i = 1; i <= str.size(); i++) {
		if (str[i - 1] != '0') ans[i] = ans[i - 1];
		if (i > 1) {
			int temp = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
			if (temp >= 10 && temp <= 26) ans[i] += ans[i - 2];
		}
	}
	return ans[str.size()];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);


	string str{};
	std::cin >> str;

	std::cout << slove(str) << std::endl;
}
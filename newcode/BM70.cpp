#include<iostream>
#include<vector>

using namespace std;

int minMoney(vector<int>& arr, int aim) {
	vector<int> f(aim + 1, 1e8);
	f[0] = 0;
	for (auto& v : arr)
		for (int j = v; j <= aim; j++)
			f[j] = min(f[j], f[j - v] + 1);
	if (f[aim] == 1e8) return -1;
	return f[aim];
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	vector<int> arr;
	int i{ 0 };
	while(std::cin >> i && i != -1){
		arr.emplace_back(i);
	}

	int aim{};
	std::cin >> aim;

	std::cout << minMoney(arr, aim) << std::endl;

	return 0;
}
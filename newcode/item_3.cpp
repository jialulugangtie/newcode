#include<iostream>
#include<vector>
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int T{ 0 };
	std::cin >> T;

	while (T--) {
		int n;
		long long k;
		std::cin >> n >> k;
		int g = 0;
		std::vector<int> temp(n);
		for (int i = 0; i < n; i++) {
			int x{ 0 };
			std::cin >> x;
			temp[i] = x;
			g = i == 0 ? x : gcd(g, x);
		}

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			int x = temp[i];
			cnt += (x / g) - 1;
		}
		std::cout << (cnt <= k ? "YES" : "NO") << '\n';
	}
	return 0;
}
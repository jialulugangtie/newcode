#include<iostream>
#include<string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;

	int ans{ 0 };
	int idx = s.find('0');
	if (idx == std::string::npos) {
		idx = s.size();
	}

	int cnt = count(s.begin(), s.end(), '1');

	for (int i = idx; i < s.size(); i++) {
		if (s[i] == '1') {
			int move_dist = i + cnt - idx * 2 - 1;
			std::cout << move_dist << std::endl;
			ans = std::max(ans, move_dist);
			idx++;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
#include<iostream>
#include<string>
#include<vector>

std::string LCS(std::string str1, std::string str2) {
	const int n = str1.size(), m = str2.size();
	std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, 0));
	int start{ 0 }, end{ 0 };
	int old_ans{ 0 }, new_ans{ 0 };

	for(int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = 0;

			new_ans = std::max(new_ans, f[i][j]);
			if (old_ans != new_ans) {
				start = i - new_ans;
				end = new_ans;
			}
			old_ans = new_ans;
		}
	return str1.substr(start, end);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string str1{}, str2{};

	std::cin >> str1 >> str2;
	
	std::cout << LCS(str1, str2) << '\n';


	return 0;
}
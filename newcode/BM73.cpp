#include <iostream>
#include<vector>
using namespace std;

string longestPalindrome_1(string s) {
	string res;
	for (int i = 0; i < s.size(); i++) {
		int l = i - 1, r = i + 1;
		while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
		if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);

		l = i, r = i + 1;
		while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
		if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
	}
	return res;
}

string longestPalindrome_2(string s) {
	if (s.empty()) return "";
	int n = s.length();
	
	vector<vector<bool>> isPolindrome(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) isPolindrome[i][i] = true;

	int start = 0, maxLength = 1;
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (s[i] == s[j] && (len == 2 || isPolindrome[i + 1][j - 1])) {
				isPolindrome[i][j] = true;
				start = i;
				maxLength = len;
			}
		}
	}
	return s.substr(start, maxLength);
}


int main() {



}
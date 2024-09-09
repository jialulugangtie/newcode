#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

void slove() {
	int n;
	cin >> n;
	vector<int> deg{ n, 0 };
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		deg[u]++;
		deg[v]++;
	}

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (i == 0) mp[deg[i]]++;
		else mp[deg[i] - 1]++;
	}

	int ans{ 0 };
	for (auto& [k, v] : mp) {
		ans += v * (v - 1) / 2;
	}

	cout << ans << "\n";
}



int main() {

	int t{ 0 };
	cin >> t;
	while (t--) {
		slove();
	}

}
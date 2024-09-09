#include<iostream>
#include<vector>


using namespace std;

vector<int> e[200000];
long long a[200000];
long long ans{ 0 };
long long dfs(int u, int fa) {
	long long sum = 0;
	for (int v : e[u]) {
		if (v == fa) continue;
		sum += dfs(v, u);
	}

	if (sum > a[u]) ans += sum - a[u];

	return max(sum, a[u]);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n{ 0 };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1, 0);
	cout << ans << endl;
}
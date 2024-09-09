#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n{ 0 };
	cin >> n;
	int len = n * 2 - 1;
	vector<int> arr(len, 0);
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end(), [](int a, int b) {
		return abs(a) > abs(b);
		});

	long long sum{ 0 };
	int negative_count{ 0 };
	for (int i = 0; i < len; i++) {
		if (arr[i] < 0) {
			negative_count++;
		}

		sum += abs(arr[i]);
	}
	
	if (negative_count % 2 == 1) {
		sum -= 2 * abs(arr[len] - 1);
	}

	std::cout << sum << std::endl;
	return 0;
}
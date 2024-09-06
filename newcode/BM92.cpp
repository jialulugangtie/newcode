#include<iostream>
#include<vector>


using namespace std;


int maxLength(vector<int>& arr) {
	vector<int> record(arr.size(), 0);
	record[0] = 1;

	for (int i = 1; i < arr.size(); i++) {
		int distance{ 0 };
		int temp = record[i - 1];
		int j = i;
		while (temp--) {
			if (j > 0 && arr[i] == arr[--j]) {
				distance = i - j;
				break;
			}
		}

		if (distance) {
			record[i] = distance;
		}
		else {
			record[i] = record[i - 1] + 1;
		}
	}
	return *std::max_element(record.begin(), record.end());
}

int maxLength_2(vector<int>& arr) {
	vector<int> record(arr.size(), 0);
	record[0] = 1;
	for (int i = 1; i < arr.size(); i++) {
		vector<int> compare(arr.begin() + i - record[i - 1], arr.begin() + i);
		auto it = std::find(compare.rbegin(), compare.rend(), arr[i]);
		if (it != compare.rend()) {
			record[i] = std::distance(compare.rbegin(), it) + 1;
		}
		else {
			record[i] = record[i - 1] + 1;
		}
	}
	return *max_element(record.begin(), record.end());
}

int main() {
	vector<int> res{ 1, 2, 3, 4, 5, 6, 6 };
	std::cout << maxLength_2(res) << std::endl;
	return 0;
}
#include <iostream>
#include<vector>
#include<unordered_map>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int op_count{ 0 };
    std::cin >> op_count;
    std::unordered_map<int, int> warehouse;
    int index{ -1 };
    for (int i = 0; i < op_count; i++) {
        std::cin >> index;
        warehouse[index]++;
    }

    std::cin >> op_count;
    for (int i = 0; i < op_count; i++) {
        std::cin >> index;
        warehouse[index]--;
    }

    std::vector<int> ans(16, 0);
    for (const auto& [v1, v2] : warehouse) {
        if (v2 >= 1 && v2 <= 15) {
            ans[v2]++;
        }
    }

    for (int i = 1; i <= 15; i++) {
        std::cout << ans[i] << (i == 15 ? "\n" : " ");
    }
    return 0;
}



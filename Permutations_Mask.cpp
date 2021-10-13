#include <iostream>
#include <vector>
#include <queue>
#include <stack>


void print2d(std::vector<std::vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            std::cout << arr[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void printArr(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
    }
    std::cout << "\n";
}

//better approach (and also preserves order)
void permutation(std::vector<std::vector<int>>& results, std::vector<int>& input, std::vector<int>& currentOrder, std::vector<bool>& mask) {
    if (currentOrder.size() == input.size()) {
        results.push_back(currentOrder);
    }

    for (int i = 0; i < input.size(); i++) {
        if (!mask[i]) {
            mask[i] = true;
            currentOrder.push_back(input[i]);
            permutation(results, input, currentOrder, mask);
            mask[i] = false;
            currentOrder.pop_back();
        }
    }
}

std::vector<std::vector<int>> permutationWithMask(std::vector<int>& input) {
    std::vector<std::vector<int>> results;
    std::vector<bool> mask(input.size(), false);
    std::vector<int> currentOrder;
    permutation(results, input, currentOrder, mask);
    return results;
}

int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    std::vector<std::vector<int>> res = permutationWithMask(arr);
    print2d(res);
    return 0;
}

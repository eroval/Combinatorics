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

//Heap's algo (doesn't preserve order)
void HeapMethod(std::vector<std::vector<int>>& results, std::vector<int>& input, int size) {
    if (size == 1) {
        results.push_back(input);
    }
    else {
        for (int i = 0; i < size; i++) {
            HeapMethod(results, input, size - 1);

            if (size % 2 == 0) {
                std::swap(input[i], input[size - 1]);
            }
            else {
                std::swap(input[0], input[size - 1]);
            }
        }
    }
}

std::vector<std::vector<int>> HeapPermutations(std::vector<int>& input) {
    std::vector<std::vector<int>> results;
    HeapMethod(results, input, input.size());
    return results;
}

int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    std::vector<std::vector<int>> res = HeapPermutations(arr);
    print2d(res);
    return 0;
}

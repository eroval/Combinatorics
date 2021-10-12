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

//naive approach
std::vector<std::vector<int>> permutations(std::vector<int>& input) {
    if (input.size() <= 1) {
        return {input};
    }
    
    //unnecessary creations of arrays 
    std::vector<std::vector<int>> results;

    for (unsigned i = 0; i < input.size(); ++i) {
        std::vector<int> inputcopy(input);
        inputcopy.erase(inputcopy.begin() + i);
        std::vector<std::vector<int>> res = permutations(inputcopy);

        for (int j = 0; j < res.size(); j++) {
            res[j].insert(res[j].begin(), input[i]);
            results.push_back(res[j]);
        }
    }

    return results;
}


int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    std::vector<std::vector<int>> res = permutations(arr);
    print2d(res);
    return 0;
}
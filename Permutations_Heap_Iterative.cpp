

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

//Iterative Heap
std::vector<std::vector<int>> HeapPermutationsIteratively(std::vector<int>& input) {
    std::vector<std::vector<int>> results;

    //MIND = BLOWN
    //this is used as a replication of the stack trace
    //much better than saving values into a queue
    //and is an absolute hack in reality
    //maybe will implement something similar into the sorts
    std::vector<int> forloop_arr(input.size(), 0);

    results.push_back(input);

    int i = 1;
    while(i<input.size()) {
        if (forloop_arr[i] < i) {
            if (i % 2 == 0) {
                std::swap(input[0], input[i]);
            }
            else {
                std::swap(input[forloop_arr[i]], input[i]);
            }
            results.push_back(input);
            ++forloop_arr[i];
            i = 1;
        }
        else {
            forloop_arr[i] = 0;
            ++i;
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

    std::vector<std::vector<int>> res = HeapPermutationsIteratively(arr);
    print2d(res);
    return 0;
}
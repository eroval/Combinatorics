#include <iostream>

//Combinations Iteratively
int main()
{
    int n=3;
    std::string arr2[3] = { "Harry", "Setwert", "Garry"};
   
    bool** arr = new bool*[pow(2, n)];

    for (int i = 0; i < pow(2, n); i++) {
        arr[i] = new bool[n]{};
    }
    
    for (int i = 0; i < pow(2, n); i++) {
        int y = i;
        for (int j = 0; j < n; j++) {
            arr[i][2 - j] = y % 2;
            y /= 2;
        }
    }

    for (int i = 0; i < pow(2, n); i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                std::cout << arr2[j]<<" ";
            }
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < pow(2, n); i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
// Write a function which accept an array of integers and its size then return the minimum
// value of its elements. Test by calling them in main().

#include <iostream>

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {5, 2, 8, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int minVal = findMin(arr, size);
    
    std::cout << "The minimum value in the array is: " << minVal << std::endl;
    
    return 0;
}
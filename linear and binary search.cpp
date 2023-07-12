#include <iostream>
#include <ctime>
using namespace std;

// Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);
        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    const int MAX_SIZE = 100000;
    int arr[MAX_SIZE];
    int size, target;

    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter the target element to search: ";
    cin >> target;

    // Binary Search
    clock_t start = clock();
    int binaryIndex = binarySearch(arr, 0, size - 1, target);
    clock_t end = clock();
    double binaryTime = double(end - start) / CLOCKS_PER_SEC;

    // Linear Search
    start = clock();
    int linearIndex = linearSearch(arr, size, target);
    end = clock();
    double linearTime = double(end - start) / CLOCKS_PER_SEC;

    // Display results
    if (binaryIndex != -1) {
        cout << "Binary Search: Element found at index " << binaryIndex << endl;
        cout << "Time taken by Binary Search: " << binaryTime << " seconds" << endl;
    } else {
        cout << "Binary Search: Element not found" << endl;
    }

    if (linearIndex != -1) {
        cout << "Linear Search: Element found at index " << linearIndex << endl;
        cout << "Time taken by Linear Search: " << linearTime << " seconds" << endl;
    } else {
        cout << "Linear Search: Element not found" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>

// Create a function that performs a binary search.
// We will divide the array into two halves and compare the target value with the middle element.
// If the target value is less than the middle element, we will search in the left half
// If the target value is greater than the middle element, we will search in the right half.
// We will continue this process until we find the target value or the search range is empty.
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

// Create a function that performs a selection sort.
// Selection sort works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning.
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// Create a function that performs an insertion sort.
// Insertion sort works by building a sorted portion of the array one element at a time.
// This is done by comparing each element with the elements before it and inserting it into its correct position.
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Create a function that performs a bubble sort.
// Bubble sort works by repeatedly stepping through the list to be sorted, comparing each pair of adjacent
// elements and swapping them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

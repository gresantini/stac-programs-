// Author: Greta Santini
// Date: 3/1/2025


#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void measureSortTime(void (*sortFunction)(vector<int>&), vector<int> arr, const string& sortName) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();

    cout << "Elapsed time in nanoseconds for " << arr.size() << " elements using " << sortName << ": "
         << duration_cast<nanoseconds>(end - start).count() << " ns\n";
}


void measureMergeSortTime(vector<int> arr) {
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();

    cout << "Elapsed time in nanoseconds for " << arr.size() << " elements using Merge Sort: "
         << duration_cast<nanoseconds>(end - start).count() << " ns\n";
}


void measureSystemSortTime(vector<int> arr) {
    auto start = high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    auto end = high_resolution_clock::now();

    cout << "Elapsed time in nanoseconds for " << arr.size() << " elements using System Sort: "
         << duration_cast<nanoseconds>(end - start).count() << " ns\n";
}


int generateRandomNumber() {
    return rand() % 1000000 + 100000;  // Generate numbers between 100,000 and 1,000,000
}

int main() {
    srand(time(0)); // Seed for random number generation

    vector<int> smallArray = {5, 2, 9, 1, 5, 6, 3, 8, 4, 7};
    vector<int> largeArray(100000);
    generate(largeArray.begin(), largeArray.end(), generateRandomNumber);

    cout << "Using System Sort\n";
    measureSystemSortTime(smallArray);
    measureSystemSortTime(largeArray);

    cout << "\nUsing Bubble Sort\n";
    measureSortTime(bubbleSort, smallArray, "Bubble Sort");
    measureSortTime(bubbleSort, largeArray, "Bubble Sort");

    cout << "\nUsing Merge Sort\n";
    measureMergeSortTime(smallArray);
    measureMergeSortTime(largeArray);

    return 0;
}

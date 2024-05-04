#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) 
        for (int j = 0; j < arr.size() - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    for (int i = 0, j = 0, k = l; i < n1 || j < n2; k++)
        if (j == n2 || (i < n1 && L[i] <= R[j])) arr[k] = L[i++];
        else arr[k] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    bubbleSort(arr);
    cout << "Bubble Sorted array is: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout << "Selection Sorted array is: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    insertionSort(arr);
    cout << "Insertion Sorted array is: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    mergeSort(arr);
    cout << "Merge Sorted array is: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    arr = {64, 25, 12, 22, 11};
    quickSort(arr);
    cout << "Quick Sorted array is: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

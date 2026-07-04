#include <iostream>
#include <vector>

using namespace std;

vector<int> findAllIndices(int arr[], int size, int key) {
    vector<int> indices;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {                              // If we hit a match save the current index
            indices.push_back(i); 
        }
    }
    
    return indices;                       // Returns empty vector if nothing matched
}

// Simple helper to print out the vector nicely
void printResult(const vector<int>& indices) {
    if (indices.empty()) {
        cout << "Key not found (or array is empty)." << endl;
    } else {
        cout << "Element found at indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }
}

int main() {
                                                             //testcases
    int arr1[] = {10, 20, 30, 20, 40, 20, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 20;
    
    cout << "Multiple occurrences of 20" << endl;
    vector<int> result1 = findAllIndices(arr1, size1, key1);
    printResult(result1);

    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int key2 = 99;
    
    cout << "Key 99 not present" << endl;
    vector<int> result2 = findAllIndices(arr2, size2, key2);
    printResult(result2);

    int* arr3 = nullptr;
    int size3 = 0;
    int key3 = 10;
    
    cout << "Empty array" << endl;
    vector<int> result3 = findAllIndices(arr3, size3, key3);
    printResult(result3);

    return 0;
}
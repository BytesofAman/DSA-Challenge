#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2); // ceil(gap/2)
}

void merge(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = nextGap(m + n);

    while (gap > 0) {
        int i, j;

        // Case 1: Compare elements in arr1
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // Case 2: Compare elements between arr1 and arr2
        for (j = (gap > m ? gap - m : 0); i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // Case 3: Compare elements in arr2
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }

        gap = nextGap(gap);
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7 , 9};
    vector<int> arr2 = {0 ,2, 4, 6, 8};

    int m = arr1.size(), n = arr2.size();

    merge(arr1, arr2, m, n);

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "arr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}

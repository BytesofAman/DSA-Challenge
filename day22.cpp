#include <bits/stdc++.h>
using namespace std;

int firstElementKTimes(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    
    for (int num : arr) {
        freq[num]++;
    }

    
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1; 
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int ans = firstElementKTimes(arr, k);
    cout << "Output: " << ans << endl;

    return 0;
}

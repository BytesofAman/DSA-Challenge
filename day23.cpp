#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq; 
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        
        dq.push_back(i);

    
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
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

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> ans = maxSlidingWindow(arr, k);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

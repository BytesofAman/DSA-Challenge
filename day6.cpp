#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int, int>> result;
    unordered_map<long long, vector<int>> mp;  // prefixSum -> list of indices
    long long prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Case 1: Subarray from 0 to i
        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        // Case 2: prefixSum seen before -> subarray found
        if (mp.find(prefixSum) != mp.end()) {
            for (int startIndex : mp[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store current index for this prefixSum
        mp[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {0, 0, 0};
    vector<pair<int, int>> res = findZeroSumSubarrays(arr);

    cout << "Subarrays with Zero Sum: \n";
    for (auto &p : res) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());  // sort kar ke key bana lo
        mp[key].push_back(s);          // original string ko group me daalo
    }

    vector<vector<string>> result;
    for (auto it : mp) {
        result.push_back(it.second);   
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (auto group : ans) {
        cout << "[ ";
        for (auto word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}

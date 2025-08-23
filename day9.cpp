#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return ""; 
    
    string prefix = strs[0]; 
    
    for (int i = 1; i < strs.size(); i++) {
        string current = strs[i];
        int j = 0;
        
        
        while (j < prefix.size() && j < current.size() && prefix[j] == current[j]) {
            j++;
        }
        
        
        prefix = prefix.substr(0, j);
        
        if (prefix == "") return ""; 
    }
    
    return prefix;
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
    
    string ans = longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << ans << endl;
    
    return 0;
}

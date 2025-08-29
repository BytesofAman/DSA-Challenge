#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1);
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char ch = s[right];

       
        if (lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }

        lastIndex[ch] = right; 
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}

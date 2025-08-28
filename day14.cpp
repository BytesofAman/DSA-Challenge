#include <bits/stdc++.h>
using namespace std;

int countAtMostK(string s, int k) {
    int n = s.size();
    int left = 0, right = 0;
    int count = 0;
    unordered_map<char, int> freq;

    for (right = 0; right < n; right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        count += (right - left + 1);
    }
    return count;
}

int countExactlyK(string s, int k) {
    if (k == 0) return 0;
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << "Number of substrings with exactly " << k 
         << " distinct characters: " << countExactlyK(s, k) << endl;
    return 0;
}

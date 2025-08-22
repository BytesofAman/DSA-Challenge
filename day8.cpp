#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    vector<string> words;
    string word;
    stringstream ss(s);   // string ko split karega (space ignore karke)

    while (ss >> word) {   // ek-ek word nikalega
        words.push_back(word);
    }

    reverse(words.begin(), words.end()); // order reverse kar diya

    // Join words with single space
    string result;
    for (int i = 0; i < words.size(); i++) {
        if (i > 0) result += " ";
        result += words[i];
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);   // user se full line input

    string ans = reverseWords(s);
    cout << "Reversed string: " << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element at the bottom of stack
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    // Recursively reverse remaining stack
    reverseStack(st);

    // Insert popped element at the bottom
    insertAtBottom(st, topElement);
}

int main() {
    stack<int> st;
    int n;

    cout << "Enter number of elements in stack: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}

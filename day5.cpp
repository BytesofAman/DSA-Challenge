#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLeaders(vector<int>& arr, int n) {
    vector<int> leaders;
    int maxRight = arr[n-1];   
    leaders.push_back(maxRight);

    
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            leaders.push_back(arr[i]);
        }
    }

   
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr =  {100, 50, 20, 10};
    int n = arr.size();

    vector<int> leaders = findLeaders(arr, n);

    cout << "Leaders are: ";
    for (int x : leaders) cout << x << " ";
    cout << endl;

    return 0;
}

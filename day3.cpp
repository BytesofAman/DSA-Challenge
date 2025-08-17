#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    
    int slow = arr[0];
    int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() {
    vector<int> arr = {3, 1,  8, 9, 4, 2 ,7 ,5 ,6  , 8};
    cout << "Duplicate number: " << findDuplicate(arr) << endl;
    return 0;
}

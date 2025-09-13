#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    const int INF = 1e9; // large value
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}

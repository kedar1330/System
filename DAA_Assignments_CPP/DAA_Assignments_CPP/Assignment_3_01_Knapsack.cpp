#include <iostream>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Number of items must be between 0 and 100." << endl;
        return 1;
    }

    int val[100], wt[100];
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter knapsack capacity: ";
    cin >> W;

    if (W < 0 || W > 100) {
        cout << "Capacity must be between 0 and 100." << endl;
        return 1;
    }

    int dp[101][101] = {};

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int includeItem = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int excludeItem = dp[i - 1][w];
                dp[i][w] = max(includeItem, excludeItem);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][W] << endl;
    return 0;
}

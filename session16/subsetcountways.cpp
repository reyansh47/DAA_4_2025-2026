#include <bits/stdc++.h>
using namespace std;

int Solve(int i, int target, int arr[], int n, int dp[][1001])
{
    if(target == 0)
        return 1;

    if(i == n)
        return 0;

    if(dp[i][target] != -1)
        return dp[i][target];

    int take = 0;
    if(arr[i] <= target)
        take = Solve(i + 1, target - arr[i], arr, n, dp);

    int nonTake = Solve(i + 1, target, arr, n, dp);

    return dp[i][target] = take + nonTake;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array of integers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int dp[101][1001];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= target; j++)
            dp[i][j] = -1;

    cout << "Number of subsets: "
         << Solve(0, target, arr, n, dp);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int solve(int arr[], int arrSize, int sum1, int totalSum, int i, vector<vector<int>>& dp)
    {
        if(i == arrSize)
        {
            int sum2 = totalSum - sum1;
            return abs(sum1 - sum2);
        }
        if(dp[i][sum1] != -1)
            return dp[i][sum1];
        
        int pick = solve(arr, arrSize, sum1 + arr[i], totalSum, i + 1, dp);
        int notpick = solve(arr, arrSize, sum1, totalSum, i + 1, dp);
        return dp[i][sum1] = min(pick, notpick);
    }
    
public:
    int minDifference(int arr[], int arrSize) {
        int sum = 0;
        for(int i = 0; i < arrSize; i++)
            sum += arr[i];
        
        vector<vector<int>> dp(arrSize + 1, vector<int>(sum + 1, -1));
        
        return solve(arr, arrSize, 0, sum, 0, dp);
    }
};

int main()
{
    Solution sol;
    int arr[] = {1, 5, 11, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    
    cout << sol.minDifference(arr, arrSize) << endl;
    
    return 0;
}

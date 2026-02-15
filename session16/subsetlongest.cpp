#include <bits/stdc++.h>
using namespace std;

int solve(int i,int target,int arr[],int dp[][1001],int n)
{
    if(i==n)
    {
        if(target==0)
            return 0;
        else
            return -1;
    }

    if(dp[i][target]!=-1)
        return dp[i][target];

    int take=-1;

    if(arr[i]<=target)
    {
        int next=solve(i+1,target-arr[i],arr,dp,n);
        if(next!=-1)
            take=1+next;
    }

    int skip=solve(i+1,target,arr,dp,n);

    int ans;
    if(take>skip)
        ans=take;
    else
        ans=skip;

    dp[i][target]=ans;
    return ans;
}

vector<int> longest(int dp[][1001],int arr[],int target,int n)
{
    vector<int> ans;
    int i=0;

    while(i<n && target>0)
    {
        int take=-1;

        if(arr[i]<=target)
        {
            int next=dp[i+1][target-arr[i]];
            if(next!=-1)
                take=1+next;
        }

        int skip=dp[i+1][target];

        if(take>=skip && take!=-1)
        {
            ans.push_back(arr[i]);
            target=target-arr[i];
            i++;
        }
        else
            i++;
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array of integers: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int target;
    cout<<"Enter target value: ";
    cin>>target;

    int dp[101][1001];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=target;j++)
            dp[i][j]=-1;

    int length=solve(0,target,arr,dp,n);
    cout<<"Length of longest subset: "<<length<<endl;

    vector<int> result=longest(dp,arr,target,n);
    cout<<"Longest subset: ";
    for(int x:result)
        cout<<x<<" ";

    return 0;
}

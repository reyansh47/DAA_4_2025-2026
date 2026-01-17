#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:

    int getFreeSlot(int pos, vector<int> &mainslot){
        if(mainslot[pos] == pos) return pos;
        return mainslot[pos] = getFreeSlot(mainslot[pos], mainslot);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        vector<int> order(profit.size());
        for(int i = 0; i < profit.size(); i++) order[i] = i;

        sort(order.begin(), order.end(), [&](int i, int j){
            return profit[i] > profit[j];
        });

        vector<int> p = profit, d = deadline;
        for(int i = 0; i < order.size(); i++){
            profit[i] = p[order[i]];
            deadline[i] = d[order[i]];
        }

        int maxm = 0;
        for(int i = 0; i < deadline.size(); i++){
            maxm = max(maxm, deadline[i]);
        }

        vector<int> first(maxm + 1);
        for(int i = 0; i <= maxm; i++) first[i] = i;

        int result = 0;
        int count = 0;

        for(int i = 0; i < profit.size(); i++){
            int available = getFreeSlot(deadline[i], first);
            if(available > 0){
                first[available] = getFreeSlot(available - 1, first);
                result += profit[i];
                count++;
            }
        }

        vector<int> ans;
        ans.push_back(count);
        ans.push_back(result);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> deadline(n), profit(n);

    for(int i = 0; i < n; i++) cin >> deadline[i];
    for(int i = 0; i < n; i++) cin >> profit[i];

    Solution obj;
    vector<int> res = obj.jobSequencing(deadline, profit);

    cout << "Jobs Done: " << res[0] << "\n";
    cout << "Total Profit: " << res[1] << "\n";

    return 0;
}

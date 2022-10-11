#include<bits/stdc++.h>
using namespace std;

bool solve(string &goal, unordered_map<string, int> &mp, int dp[], int i) {
    int n = goal.size();
    if(i >= n) return 1;
    if(dp[i] != -1) return dp[i];
    for(int j = i; j<n; j++) {
        string temp = goal.substr(i, j-i+1);
        if(mp[temp] > 0) {
            mp[temp]--;
            if(solve(goal, mp, dp, j+1)) {
                dp[i] = 1;
                mp[temp]++;
                return 1;
            }
            mp[temp]++;
        }
    }
    dp[i] = 0;
    return 0;
}


int main() {
    int n;
    string goal;
    cin>>n>>goal;
    unordered_map<string, int> mp;
    for(int i = 0; i<n; i++) {
        string temp;
        cin>>temp;
        mp[temp]++;
    }

    int dp[goal.size()];
    memset(dp, -1, sizeof(dp));

    cout<<solve(goal, mp, dp, 0);

}
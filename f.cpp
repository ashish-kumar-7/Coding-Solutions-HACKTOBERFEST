#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll M = 1e9+7;


void solve(ll num) {

    ll d, n, x;
    cin>>d>>n>>x;
    vector<vector<ll>> arr(n, vector<ll> (3));
    for(ll i = 0; i<n; i++) {
        cin>>arr[i][2]>>arr[i][0]>>arr[i][1];
    }
    sort(arr.begin(), arr.end());
    
    priority_queue<pair<int, int>> pq;

    int ans = 0, prev = arr[0][0] - 1, day = arr[0][0], curr = 0;
    while(day < d and curr < n) {
        int i = curr;
        while(i < n and arr[i][0] == day) {
            pq.push({arr[i][1], arr[i][2]});
            i++;
        }
        curr = i;
        int seed = (day - prev)*x;
        prev = day;
        if(i < n) day = arr[i][0];

        while(seed > 0 and !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            ans += min(seed, temp.second) * temp.first;
            if(temp.second > seed) pq.push({temp.first, temp.second - seed});
            seed -= temp.second;
        }
    }

    if(prev < d-1) {
        int seed = (d - prev - 1)*x;
        while(seed > 0 and !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            ans += min(seed, temp.second) * temp.first;
            if(temp.second > seed) pq.push({temp.first, temp.second - seed});
            seed -= temp.second;
        }
    }

    cout<<"Case #"<<num<<": "<<ans<<'\n';


}

int s(int &x) {
    return 0;
}

int main() {
    int x = 97;
    int y = s(&(x++));
    cout<<x;
}

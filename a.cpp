#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100000;

void dfs(vector<int> nodes[], stack<int> &st, vector<bool> &vis, int node) {
    vis[node] = 1;
    for(auto i:nodes[node]) {
        if(!vis[i]) dfs(nodes, st, vis, i);
    }
    st.push(node);
}

void topoSort(vector<int> nodes[], int n) {
    vector<bool> vis(N, 0);
    stack<int> st;

    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(nodes, st, vis, i);
    }
    while(!st.empty()) {
        cout<<st.top()<<'\n';
        st.pop();
    }
}


int main() {

    int n, m;
    cin>>n;

    // vector<int> nodes[N];
    // for(int i=0; i<m; i++) {
    //     int a, b;
    //     cin>>a>>b;
    //     nodes[b].push_back(a);
    // }

    // topoSort(nodes, n);

    int ans = 0;
    for(int i=1; i*i<n; i++) {
        ans = n/i;
    }

    cout<<ans;

}



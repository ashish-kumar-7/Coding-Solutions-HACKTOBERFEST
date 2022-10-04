#include<bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int k){
    vector<int> result;
    int b= n/(k*(k+1)/2);
    if(b==0){
        result.push_back(-1);
        return result;
    }
    int r=1;
    for(int i=1; i*i<=n; i++){
        if(n%i != 0){
            continue;
        }
        if(i<= b && i>r){
            r=i;
        }
        if((n/i) <= b && (n/i) >r){
            r=(n/i);
        }
    }
    for(int i=1; i<k;i++){
        result.push_back(r*i);
    }
    int res= n-(r*(k*(k-1)/2));
    result.push_back(res);
    return result;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>r;
        r=solve(n,k);
        for(int i=0; i<r.size(); i++){
            cout<<r[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

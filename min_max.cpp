#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define mp make_pair
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(j,a,b) for(int j=a;j>b;j--)


void solve(){
    int n;cin>>n;
    int ans = 0;
    f(i,0,n){
        int temp;cin>>temp;
        ans |= temp;
    }
    cout<<ans<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
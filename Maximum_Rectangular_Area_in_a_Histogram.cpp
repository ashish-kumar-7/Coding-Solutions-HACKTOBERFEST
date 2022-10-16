
// Maximum Rectangular Area in a Histogram

#include<bits/stdc++.h>
using namespace std;

// T(n) = O(n)
// single traversal
// S(n) = O(n)

class solution
{
    public:
    // approach linear increasing fill the stack 
     long long getMaxArea(long long arr[], int n)
    {
        stack<long long>st;
        long long maxi=0;
        for(long long i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                long long height=arr[st.top()];
                st.pop();
                long long width;
                if(st.empty())width=i;
                else width= i-st.top()-1;
                maxi=max(maxi, width*height);
            }
            st.push(i);
        }
        return maxi;
    }
   
 
};


int main(){
  	long long t;
  	cin>>t;

  	while(t--){
  		int n;
  		cin>>n;
  		long long arr[n];
  		for(int i=0;i<n;i++){
  			cin>>arr[i];
  		}

  		solution obj;
  		cout<<obj.getMaxArea(arr,n)<<endl;
  	}


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


class Tree {
      public:
          int val;
          Tree *left;
          Tree *right;

        Tree(int num) {
            val = num;
            right = NULL;
            left = NULL;
        }
 };
 
bool dfs(Tree* node, int num, int& ans) {
    if (node == NULL) return true;
    bool check = dfs(node->left, node->val, ans) and dfs(node->right, node->val, ans);

    if (check == true) {
        ans++;
        if (node->val == num) return true;
    }

    return false;
}

int solve(Tree* root) {
    int ans = 0;
    bool buff = dfs(root, root->val, ans);
    return ans;
}

void bubbleSort(vector<int> &nums) {
    int n = nums.size();
    for(int i=1; i<n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
        }
    }
}

void selectionSort(vector<int> &nums) {
    int n = nums.size();
    for(int i=0; i<n-1; i++) {
        int mn = i;
        for(int j = i+1; j<n; j++) {
            if(nums[mn] > nums[j]) mn = j;
        }
        swap(nums[mn], nums[i]);
    }
}

void insertionSort(vector<int> &nums) {
    int n = nums.size();
    for(int i=1; i<n; i++) {
        int j = i-1, temp = nums[i];
        while(j>=0 && nums[j] > temp){
            nums[j+1] = nums[j];
            j--;    
        }
        nums[j+1] = temp;
    }
}

int findPivot(vector<int> &nums, int pivot, int lo, int hi) {
    int i = lo, j = lo;
    while(i<hi) {
        if(nums[i] < pivot) {
            swap(nums[i], nums[j]);
            j++;
        }
        i++;
    }
    return j;
}

void quickSort(vector<int> &nums, int lo, int hi) {
    if(lo >= hi) return;
    int pivot = findPivot(nums, nums[hi], lo, hi);
    swap(nums[pivot], nums[hi]);
    quickSort(nums, lo, pivot-1);
    quickSort(nums, pivot+1, hi);
}

void merge(vector<int> &nums, int l1, int r1, int l2, int r2) {
    int i = l1, j = l2;
    vector<int> temp;
    while(i<=r1 and j<=r2) {
        if(nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=r1) {
        temp.push_back(nums[i]);
        i++;
    }

    while(j<=r2) {
        temp.push_back(nums[j]);
        j++;
    }
    for(int k=l1; k<=r2; k++) {
        nums[k] = temp[k-l1];
    }
}

void mergeSort(vector<int> &nums, int lo, int hi) {
    if(lo==hi) return;
    int mid = (hi+lo)/2;
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid+1, hi);
    merge(nums, lo, mid, mid+1, hi);
}

int lowerBound(int arr[], int n, int num) {
    int l = 0, r = n-1, mid;
    while(l < r) {
        mid = (l+r)/2;
        if(arr[mid] < num) l = mid + 1;
        else r = mid;
    }
    return arr[l];
}

int upperBound(int arr[], int n, int num) {
    int l = 0, r = n-1, mid;
    while(l < r) {
        mid = (l+r)/2;
        if(arr[mid] <= num) l = mid + 1;
        else r = mid;
    }
    return arr[l];
}



int main() {
    // map<int, bool> mp;
    // mp[8] = 1;
    // mp[7] = 1;
    // mp[1] = 1;
    // mp[3] = 1;
    // vector<int> vec;
    // auto lb = lower_bound(mp.begin(), mp.end(), 3);
    // cout<<lb;
    // string s = "-098";
    // int nm = stoi(s);
    // cout<<nm;
    // int t;
    // cin>>t;
    // while(t--) {
    //     int n;
    //     cin>>n;
    //     vector<int> nums(n);
    //     for(int i=0; i<n; i++) cin>>nums[i];
    //     mergeSort(nums, 0, n-1);
    //     for(auto i:nums) cout<<i<<' ';
    //     cout<<endl;

    // }

    // int arr[] = {1, 2, 4, 5, 8, 10};
    // cout<<"lower bound: "<<lowerBound(arr, 6, 1)<<endl;
    // cout<<"upper bound: "<<upperBound(arr, 6, 1)<<endl;
    // int n;
    // cin>>n;
    // cout<<(n>>1)<<' '<<n/2;

    // int arr[9] = {0};
    // for(auto i:arr){
    //     i += 1;
    // }
    // for(auto i:arr) {
    //     cout<<i<<endl;
    // }

    // Tree *node = new Tree(10);
    // Tree *temp = node -> right;
    // temp -> val = 69;
    // cout<<temp->val;

    // string s = "";
    // s += 'a';
    // s += 'b';
    // cout<<s;

    int a = 'a';
    cout<<a;
}

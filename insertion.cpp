#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> v;
    public:
    Heap(int s=10){
        v.reserve(s+1);
        v.push_back(-1);
    };

    void push(int data){
        v.push_back(data);

        int index = v.size()-1;
        int parent = index/2;

        while(index>1 and v[index]< v[parent]){
            swap(v[index], v[parent]);
            index=parent;
            parent=parent/2;
        }
    }

    void printHeap(){
        for(int x: v){
            cout<<x<<" ";
        }
    }
};

int main(){
    Heap h;
    h.push(8);
    h.push(3);
    h.push(10);
    h.push(1);
    h.push(6);
    h.push(14);
    h.push(4);
    h.push(7);
    h.push(13);

    h.printHeap();
}
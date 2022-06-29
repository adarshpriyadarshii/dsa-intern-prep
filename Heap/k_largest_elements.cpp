#include <bits/stdc++.h>
using namespace std;

vector<int> klargest(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> minH;
    for(int i=0;i<n;i++){
        minH.push(arr[i]);
        if(minH.size()>k){
            minH.pop();
        }
    }
    vector<int> ans;
    while(minH.size()>0){
        ans.push_back(minH.top());
        minH.pop();
    }
    return ans;
}

int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=4;
    vector<int> ans=klargest(arr,n,key);
    for(auto it:ans){
        cout<<it<<" ";
    }

}
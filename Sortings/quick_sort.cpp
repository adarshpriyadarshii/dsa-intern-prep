#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    int r=n-1;
    quickSort(a,l,r);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
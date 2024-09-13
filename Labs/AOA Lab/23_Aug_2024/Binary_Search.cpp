#include <iostream>
using namespace std;

int BinarySearch(int arr[] , int n , int target) {    // iski complexity O(logn)

    int start = 0 ;
    int end =  n-1;

    while(start<=end) {
        int mid = start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if (arr[mid]<target){
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return -1;
}

int main() {
    
    int arr[]={1,2,3,4,5,6,7,8,9,12,14,64};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Element present at index : "<<BinarySearch(arr,n,6);
    return 0;
}
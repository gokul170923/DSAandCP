#include<bits/stdc++.h>
using namespace std;
/*
Sliding Window Technique is a method used to efficiently solve
problems that involve defining a window or range in the input
data (arrays or strings) and then moving that window across
the data to perform some operation within the window.
This technique is commonly used in algorithms like finding subarrays
with a specific sum, finding the longest substring with unique characters,
or solving problems that require a fixed-size window to process elements efficiently.

These problems generally require Finding Maximum/Minimum Subarray,
Substrings which satisfy some specific condition.
    types --->
                1.fixed sized window
                2.variable sized window
                3.no of subarrays with some condition
                4.shortest/minimum window
*/

// 1. print all subarray of size k.
void fixedWindow(vector<int>&arr,int k){
    int n =arr.size();
    if(k>n){
        cout<<"invalid\n";
        return;
    }
    int i =0,j = i+k-1;
    while(j<n){

        if(j-i+1>k){
            i++;
        }
        cout<<"[ ";
        for(int l =i;l<=j;l++) cout<<arr[l]<<',';
        cout<<"]"<<endl;
        j++;
    }
}

// 2. largest sum from k size subarrays
void largestKsum(vector<int>&arr,int k){
    int n = arr.size();
    if(k>n){
        cout<<"invalid\n";
        return;
    }
    int max_sum =0;
    int i=0,j=0;
    while(j<k){
        max_sum+=arr[j];
        j++;
    }
    int window_sum=max_sum;
    while(j<n){
        window_sum+=arr[j];
        if(j-i+1>k){
            window_sum-=arr[i];
            i++;
        }
        max_sum = max(max_sum,window_sum);
        j++;    
    }
    cout<<"maximum sum of k size subarrays : "<<max_sum<<endl;

}





int main(){

    vector<int>arr = {4,5,2,-1,-5,0,7,1,4,-4};
    int k;cin>>k;
    fixedWindow(arr,k);
    largestKsum(arr,k);

}
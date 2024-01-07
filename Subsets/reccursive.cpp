// using Reccursion make choice

#include <bits/stdc++.h>
using namespace std;
void print(vector<int>&arr){
    cout<<"[";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<",";
    }
    cout<<"]"<<endl;
}

// TC : O(2^N)
// SC : O(N)stack + O(2^N)subsets

void recc(vector<int>arr,vector<int>temp,int i,int n){
    if(i>=n){
        print(temp);
        return;
    }
    recc(arr,temp,i+1,n);
    temp.push_back(arr[i]);
    recc(arr,temp,i+1,n);
   
    


}



int main(){
    vector<int>arr={3,1,2},temp;
    recc(arr,temp,0,3);
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// TC : O(N!*N)
// SC : O(N)stack  + O(N!)permutations

void recc(vector<int>arr,vector<vector<int>>&permutes,int i){
   if(i==arr.size()){
       permutes.push_back(arr);
       return;
   }
    for(int k =i;k<arr.size();k++){
        swap(arr[i],arr[k]);
        recc(arr,permutes,i+1);
        swap(arr[i],arr[k]);
 
    }
 
}

int main(){
    vector<int>arr={1,2,3};
    vector<vector<int>>permutes;
    recc(arr,permutes,0);
    for(auto i:permutes){
        for(auto j:i) cout<<j<<' ';
        cout<<endl;
    }
    cout<<permutes.size();

   
}
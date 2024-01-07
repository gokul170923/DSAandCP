#include <bits/stdc++.h>
using namespace std;

void recc(vector<int>&arr,vector<int>visited,vector<vector<int>>&permutes,vector<int>temp){
    if(temp.size()==arr.size()){
        permutes.push_back(temp);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(visited[i]==1) continue;
        visited[i] = 1;
        temp.push_back(arr[i]);
        recc(arr,visited,permutes,temp);
        temp.pop_back();
        visited[i]=0;

    }


}


int main(){
    vector<int>arr={1,2,3,4},visited(arr.size(),0);
    vector<vector<int>>permutes;
    recc(arr,visited,permutes,{});
    for(auto i:permutes){
        for(auto j:i) cout<<j<<' ';
        cout<<endl;
    }
    cout<<permutes.size();

   
}
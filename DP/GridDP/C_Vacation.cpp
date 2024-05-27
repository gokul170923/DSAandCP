#include <bits/stdc++.h>
using namespace std; 

int recc(vector<vector<int>>&arr,int n,int index,int prev){
    if(index>=n) return 0;

    int currmax = 0;
    for(int i =0;i<3;i++){
        if(i!=prev){
            int now  = arr[index][i] + recc(arr,n,index+1,i);
            currmax = max(now,currmax);
        }
    }
    return currmax;
}

int memo(vector<vector<int>>&arr,vector<vector<int>>&dp,int n,int index,int prev){

    int currmax = 0;
    for(int i =0;i<3;i++){
        if(i!=prev){
            if(dp[index][i]==0){
                dp[index][i]= arr[index][i] + memo(arr,dp,n,index+1,i);
            }
            currmax = max(currmax,dp[index][i]);
        }
    }
    return currmax;
}

int tabulate(vector<vector<int>>&arr,vector<vector<int>>&dp,int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k!=j){
                    dp[i-1][k] = max(dp[i-1][k],arr[i-1][k]+dp[i][j]);
                }
            }
        }
    }
    return max({dp[0][0],dp[0][1],dp[0][2]});
}

// space optimise it with two 1D (size 3) arrays form prev level and curr level

void solve(){
    int n;cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i =0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    dp[n-1][0] =arr[n-1][0];
    dp[n-1][1] =arr[n-1][1];
    dp[n-1][2] =arr[n-1][2];
    //cout<<recc(arr,n,0,-1);
    //cout<<memo(arr,dp,n,0,-1);
    cout<<tabulate(arr,dp,n);
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
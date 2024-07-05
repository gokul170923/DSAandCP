#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll recc(vector<pair<ll,ll>>&arr,ll n,ll value){
    if(value==0) return 0;
    if(value<0) return INT_MAX;
    if(n==0 && value>0) return INT_MAX;

    ll nottake = recc(arr,n-1,value);
    
    //take
    if(value - arr[n-1].second >=0){
        nottake =  min(nottake ,arr[n-1].first +  recc(arr,n-1,value-arr[n-1].second));
    }
    return nottake;
}    


ll memo(vector<pair<ll,ll>>&arr,vector<vector<ll>>&dp,ll n,ll value){
    if(value==0) return 0;
    if(value<0) return INT_MAX;
    if(n==0 && value>0) return INT_MAX;
    if(dp[n][value]!=-1) return dp[n][value];

    ll nottake = memo(arr,dp,n-1,value);
    
    //take
    if(value - arr[n-1].second >=0){
        nottake =  min(nottake ,arr[n-1].first +  memo(arr,dp,n-1,value-arr[n-1].second));
    }
    return dp[n][value] = nottake;
} 


void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    ll max_value = 100007,ans;
    vector<pair<ll,ll>>arr(n);
    for(auto &i:arr){
        cin>>i.first>>i.second;
    }

    vector<vector<ll>>dp(n+1,vector<ll>(max_value+1,-1));

    for(int i= max_value;i>=0;i--){
        //ans  = recc(arr,n,i);
        ans = memo(arr,dp,n,i);
        //  ans = tabulate(arr,dp,n,k);
        if(ans<=k){
            ans = i;
            break;
        }
    }
    cout<<ans;
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
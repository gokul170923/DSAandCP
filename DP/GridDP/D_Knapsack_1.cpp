#include <bits/stdc++.h>
using namespace std;
                    
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl '\n' 
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()


ll recc(vector<pair<ll,ll>>&arr,ll n,ll k){
    if(n==0) return 0;
    ll take = 0;
    if(arr[n-1].first<= k){
        take = max(take ,arr[n-1].second +  recc(arr,n-1,k-arr[n-1].first));
    }
    ll nottake = recc(arr,n-1,k);
    return max(nottake,take);
}    


ll memo(vector<pair<ll,ll>>&arr,vector<vector<ll>>&dp,ll n,ll k){
    if(n==0) return 0;
    if(dp[n-1][k]!=-1) return dp[n-1][k];

    ll take = 0;
    if(arr[n-1].first<= k){
        take = max(take ,arr[n-1].second +  memo(arr,dp,n-1,k-arr[n-1].first));
    }
    ll nottake = memo(arr,dp,n-1,k);

    return dp[n-1][k] = max(nottake,take);
}  

ll tabulate(vector<pair<ll,ll>>&arr,vector<vector<ll>>&dp,ll n,ll k){
    
    for(int i =1;i<=n;i++){
        for(int w =1;w<=k;w++){
            if(arr[i-1].first<=w){
                dp[i][w] = max(dp[i-1][w],arr[i-1].second + dp[i-1][w-arr[i-1].first]);
            }
            else dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][k];
}

void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    vector<pair<ll,ll>>arr(n);
    for(auto &i:arr){
        cin>>i.first>>i.second;
    }
    vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
    //cout<<recc(arr,n,k);
    //cout<<memo(arr,dp,n,k);
    cout<<tabulate(arr,dp,n,k);
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
                    
#define ll long long

ll recc(vector<ll>&arr,ll n,ll target){
    if(target==0) return 0;
    ll minstep = INT_MAX;
    for(ll i=0;i<n;i++){
        if(target-arr[i]>=0) minstep  = min(minstep,recc(arr,n,target-arr[i]));
    }
    return minstep+1;
}

ll memo(vector<ll>&arr,ll n,ll target,vector<ll>&dp){

    if(dp[target]!=INT_MAX) return dp[target];

    for(ll i=0;i<n;i++){
        if(target-arr[i]>=0){
            dp[target]  = min(dp[target],memo(arr,n,target-arr[i],dp));
        }
    }
    dp[target]++;
    return dp[target];
}

ll tabulate(vector<ll>&arr,ll n,ll target,vector<ll>&dp){
    sort(arr.begin(),arr.end());

    for(ll i=0;i<target;i++){

        for(ll j:arr){
            if(j> target-i) break;
            if(dp[i]>=INT_MAX) continue;
            ll give = dp[i]+1;
            dp[i+j] = min(dp[i+j],give);
        }

    }
    return dp[target]>=INT_MAX?-1:dp[target];
}


void solve(){
    ll n;cin>>n;
    ll target;cin>>target;
    vector<ll>arr(n);
    for(ll &i:arr) cin>>i;

    vector<ll>dp(target+1,INT_MAX);
    dp[0] = 0;
    //ll ans = recc(arr,n,target);
    //ll ans = memo(arr,n,target,dp);
    cout<<tabulate(arr,n,target,dp);
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
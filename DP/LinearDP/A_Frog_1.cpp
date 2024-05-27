#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll recc(vector<ll>&arr,ll n,ll i){
        if(i==n-1) return 0;
        ll l =100000,r =100000;
        if(i+1<n) l = abs(arr[i]-arr[i+1])+recc(arr,n,i+1);
        if(i+2<n) r = abs(arr[i]-arr[i+2])+recc(arr,n,i+2);
        return min(l,r);
}

ll memo(vector<ll>&arr,vector<ll>&dp,ll n,ll i){
    if(dp[i]==-1){
        ll l=10000,r=10000;
        if(i+1<n) l = abs(arr[i]-arr[i+1]) + memo(arr,dp,n,i+1);
        if(i+2<n) r = abs(arr[i]-arr[i+2]) + memo(arr,dp,n,i+2);
        dp[i] = min(l,r);
    }
    return dp[i];
}

ll tabu(vector<ll>&arr,vector<ll>&dp,ll n){
    for(ll i=n-1;i>=0;i--){
        if(i-1 >=0){
            ll c = abs(arr[i]-arr[i-1]) + dp[i];
            if(dp[i-1] ==-1) dp[i-1] = c;
            else dp[i-1] = min(dp[i-1],c);
        }
        if(i-2 >=0){
            ll c = abs(arr[i]-arr[i-2]) + dp[i];
            if(dp[i-2] ==-1) dp[i-2] = c;
            else dp[i-2] = min(dp[i-2],c);
        }
    }
    return dp[0];
}

ll optimised(vector<ll>&arr,ll n){
    ll a ,b =-1,c =0;
    for(ll i=n-1;i>0;i--){
        if(i-1 >=0){
            ll can = abs(arr[i]-arr[i-1]) + c;
            if(b==-1) b = can;
            else b = min(b,can);
        }
        if(i-2 >=0){
            ll can = abs(arr[i]-arr[i-2]) + c;
            a = can;
        }
        c = b;
        b = a;
    }
    return c;
}

void solve(){
    ll n;cin>>n;
    vector<ll>arr(n),dp(n,-1);
    dp[n-1] =0;
    for(ll &i:arr) cin>>i;
    //cout<<recc(arr,n,0);
    //cout<<memo(arr,dp,n,0);
    //cout<<tabu(arr,dp,n);
    cout<<optimised(arr,n);
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
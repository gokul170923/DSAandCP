#include <bits/stdc++.h>
using namespace std;
                    
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl '\n' 
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

ll recc(vector<ll>&arr,ll n,ll k){
    if(n==0) return 0;
    ll minmove = INT_MAX;
    for(ll i =1;i<=k;i++){
        if(n - i >=0){
            minmove = min( minmove,abs(arr[n]-arr[n-i])+recc(arr,n-i,k));
        }
    }
    return minmove;
}

ll memo(vector<ll>&arr,vector<ll>&dp ,ll n,ll k){
    if(n==0) return 0;
    ll minmove = INT_MAX;
    for(ll i =1;i<=k;i++){
        if(n-i>=0){
            if(dp[n-i]==-1) dp[n-1] = memo(arr,dp,n-i,k);
            minmove = min(minmove,dp[n-i]+abs(arr[n]-arr[n-i]));
        }
    }
    return dp[n] = minmove;
}

ll tabulate(vector<ll>&arr,ll n,ll k){
    vector<ll>dp(n,-1);
    dp[n-1] =0;
    for(ll i = n -1;i>0;i--){
        for(ll j =1;j<=k;j++){
            if(i-j>=0){
                ll move = abs(arr[i]-arr[i-j])+dp[i];
                if(dp[i-j]==-1) dp[i-j] =move;
                else dp[i-j] = min(dp[i-j],move);
            }
        }
    }
    return dp[0];
}



void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    vector<ll>arr(n),dp(n,-1);
    dp[0] =0;
    for(ll &i:arr) cin>>i;
    //cout<<recc(arr,n-1,k);
    //cout<<memo(arr,dp,n-1,k);
    //cout<<tabulate(arr,n,k);
}
                        
                        
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
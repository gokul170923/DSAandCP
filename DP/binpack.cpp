#include <bits/stdc++.h>
using namespace std;
                    
                    
void solve(){
        int n;cin>>n;
        int limit;cin>>limit;
        vector<int>arr(n);
        for(int &i:arr) cin>>i;
        vector<pair<int,int>>dp(1<<n,{INT_MAX,INT_MAX});
        dp[0] =  {1,0};
        for(int i=1;i<(1<<n);i++){
                
                for(int j=0;j<n;j++){
                        if((i>>j)&1){
                                auto prev = dp[(i^(1<<j))];
                                if(prev.second + arr[j]>limit){
                                        prev.first ++;
                                        prev.second =arr[j];
                                }
                                else prev.second += arr[j];
                                dp[i] = min(dp[i],prev);
                        }
                }
        }
        cout<<dp[(1<<n)-1].first;
}
                        
                        
int main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       solve();
       return 0;
}
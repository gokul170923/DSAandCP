#include <bits/stdc++.h>
using namespace std;
                    
void tabulate(string &s){
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) dp[i][i] = true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>=j) continue;
                if(s[i]==s[j] && 
                (i+1==j || dp[i+1][j-1])) 
                    dp[i][j] = true;
            }
        }
}
                        
                        
int32_t main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       return 0;
}
#include <bits/stdc++.h>
using namespace std;

                                This is subset sum problem with dp + bitmasking

// simple reccursion 
vector<int> subsetSums(vector<int>& arr) {
       vector<int>ans;
       int n = arr.size();
       auto recc = [&](auto &self,int i,int sum)->void{
            if(i==n){
                ans.push_back(sum);
                return;
            }
            self(self,i+1,sum);
            self(self,i+1,sum+arr[i]);
       };
       recc(recc,0,0);
       return ans;
} O(2^N)


// normal bitmask
vector<int> subsetSums(vector<int>& arr) {
       vector<int>ans;
       int n = arr.size();
       for(int i=0;i<(1<<n);i++){
           int sum = 0;
           for(int j=0;j<n;j++){
               if((i>>j)&1) sum+=arr[j];
           }
           ans.push_back(sum);
       }
       return ans;
} O(2^N * N)


// bitmask with dp 
vector<int> subsetSums(vector<int>& arr) {
       int n = arr.size();
       vector<int>dp(1<<n);
       dp[0] = 0;
       for(int i=1;i<(1<<n);i++){
           int sum = dp[i&(i-1)] + arr[__builtin_ctz(i)];
           dp[i] = sum;
       }
       return dp;
} O(2^N)


// bonus use binary representation 
vector<int> subsetSums(vector<int>& arr) {
       vector<int> dp = {0};

        for (int num : arr) {
            int n = dp.size(); 
            for (int i = 0; i < n; ++i) {
                dp.push_back(dp[i] + num);
            }
            for(int i:dp) cout<<i<<" ";
            cout<<endl;
        }
        return dp;
} O(2^N)



                        
                        
int main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       int t;cin >> t;
       while(t--) solve();
       return 0;
}
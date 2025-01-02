#include <bits/stdc++.h>
using namespace std;

string ConstructLCSfromDp(vector<vector<int>>&dp,string& s,string& t,int n,int m){
    string ans ="";
    int i=0,j=0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            ans+=s[i];
            i++;
            j++;
        }
        else if(i+1>=n && j+1>=m) break;
        else if(i+1>=n) j++;
        else if(j+1>=m) i++;
        else{
            if(dp[i+1][j]>dp[i][j+1]) i++;
            else j++;
        }
    }
    return ans;
}

int recc(string &s,string &t,int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n ||j==m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j]= 1+recc(s,t,i+1,j+1,n,m,dp);
    }
    else{
        int l=recc(s,t,i,j+1,n,m,dp); 
        int r= recc(s,t,i+1,j,n,m,dp);;
        return dp[i][j] =max(l,r);
    }
}
                        
int main(){
    string s,t;cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    recc(s,t,0,0,n,m,dp);
    for(auto i:dp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<ConstructLCSfromDp(dp,s,t,n,m);
    return 0;
}
/*

        Dynamic Programming is a methord that uses the existence of overlaping 
        subproblems by getting rid of them

        Overlaping subproblems : when a problem breaks down into smaller
        subproblems an they are the same

        Methords :-
                    1. Memoization ( top - down) - reccursion
                    2. Tabulation ( botton - up) - iterative

        general approach :-
                    -> reccursion
                    -> memoization
                    -> tabulation
                    -> space optimization

    eg :- Fibbonaci
            . 1 2 3 4 5 6 7  8
            0 1 1 2 3 5 8 13 21 . . .

*/

#include<bits/stdc++.h>
using namespace std;

int recc(int n){
    if(n<2) return n;
    return recc(n-1) + recc(n-2);
}

int memoization(int n,vector<int>&dp){
    if(n < 2 ) return dp[n];
    if(dp[n-1]==-1) dp[n-1] = memoization(n-1,dp);
    if(dp[n-2]==-1) dp[n-2] = memoization(n-2,dp);
    return dp[n-1]+dp[n-2];
}

int tabulation(int n){
    vector<int>dp(n+1);
    dp[0] =0;
    dp[1] =1;
    for(int i=2;i<=n;i++){
        dp[i] =  dp[i-1] +dp[i-2];
    }
    return dp[n];
}

int spaceoptimized(int n){
    if(n<2) return n;
    int a = 0 , b= 1;
    for(int i=2;i<=n;i++){
        int t = a+b;
        a = b;
        b = t;
    }
    return b;
}


int main(){
    int n;cin>>n;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    cout<<recc(n)<<endl;
    cout<<memoization(n,dp)<<endl;
    cout<<tabulation(n)<<endl;
    cout<<spaceoptimized(n)<<endl;
}
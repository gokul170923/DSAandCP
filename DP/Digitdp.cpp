class Solution {
public:
    #define ll long long
    ll mod = 1000000007;
    ll dp[500][2][10];

    vector<ll> find(string &s,ll b){
        vector<ll>ans,q;
        for(char i:s) q.push_back(i-'0');
        while(!q.empty()){
            ll rem = 0 , n = q.size() ;
            bool ok = false;
            vector<ll>temp;
            for(ll i=0;i<n;i++){
                ll curr = (rem*10 + q[i]);
                if(curr>=b || ok){
                    temp.push_back(curr/b);
                    ok = true;
                }
                rem = curr % b;
            }
            ans.push_back(rem);
            q = temp;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void Minus(string &s){
        ll n  = s.size();
        for(ll i=n-1;i>=0;i--){
            if(s[i]-'0'>0){
                s[i] = char((s[i]-'0'-1)+'0');
                break;
            }
            else s[i] = '9';
        }
        if(s[0]=='0'){
            reverse(s.begin(),s.end());
            s.pop_back();
            reverse(s.begin(),s.end());
        }
    }

    ll recc(vector<ll>&arr,ll i,ll smaller,ll last,ll n,ll b){
        if(i==n) return 1;
        if(dp[i][smaller][last]!=-1) return dp[i][smaller][last];
        ll ub = (smaller?b:arr[i]+1) , ans  = 0;
        for(ll d=last;d<ub;d++){
            ans = (ans%mod + recc(arr,i+1,smaller?1:(d!=arr[i]),d,n,b)%mod) % mod;
        }
        return dp[i][smaller][last] = ans;
    }

    int countNumbers(string l, string r, int b) {
        ll right = 0  , left = 0;
        {
            memset(dp,-1,sizeof(dp));
            vector<ll> R = find(r,b);
            right = recc(R,0,0,0,R.size(),b);
        }
        if(l!="0"){
            memset(dp,-1,sizeof(dp));
            Minus(l);
            vector<ll> L = find(l,b);
            left = recc(L,0,0,0,L.size(),b);
        }
        return (right%mod - left%mod + mod)%mod;
    }
};

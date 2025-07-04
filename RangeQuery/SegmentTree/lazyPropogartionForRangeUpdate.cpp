#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
                    
class SegmentTree{
public:
        ll ln , n;
        vector<ll>arr,lazy;
 
        SegmentTree(vector<ll>&a,ll m){
                ln = ceil(log2(m));
                ln = (1<<ln) , n = (ln<<1);
                arr.resize(n,0);
                lazy.resize(n,0);
                build(a,0,0,ln-1,m);
        }
 
        void build(vector<ll>&a,ll index,ll l,ll r,ll n){
                if(l==r){
                        if(l<n) arr[index] = a[l];
                        return;
                }
                ll mid = (l+r)/2;
                build(a,2*index+1,l,mid,n);
                build(a,2*index+2,mid+1,r,n);
                arr[index] = arr[2*index+1]+arr[2*index+2];
        }
 
        ll rq(ll index,ll l,ll r,ll start,ll end){
                push(index);
                if(l>=start && r<=end) return arr[index];
                else if(r<start || l > end) return 0;
                ll mid = (l+r)/2;
                return rq(2*index+1,l,mid,start,end)+
                        rq(2*index+2,mid+1,r,start,end);
        }
 
        ll range_query(ll start,ll end){
                return rq(0,0,ln-1,start,end);
        }
 
        void push(ll index){
                arr[index] += lazy[index];
                if(2*index+1<n) lazy[2*index+1] += lazy[index];
                if(2*index+2<n) lazy[2*index+2] += lazy[index];
                lazy[index] = 0;
        }
 
        void rup(ll index,ll l,ll r,ll start,ll end,ll rval){
                if(l>=start && r<=end){
                        lazy[index] += rval;
                        return;
                }
                else if(r<start || l > end) return;
                ll mid = (l+r)/2;
                rup(2*index+1,l,mid,start,end,rval);
                rup(2*index+2,mid+1,r,start,end,rval);
        }
 
        void range_update(ll start,ll end,ll rval){
                rup(0,0,ln-1,start,end,rval);
        }
 
};
                    
void solve(){
        ll n,q;cin>>n>>q;
        vector<ll>arr(n);
        for(ll &i:arr) cin>>i;
        SegmentTree * sgt = new SegmentTree(arr,n);
        cout<<endl;
        while(q--){
               ll type;cin>>type;
               if(type==1){
                        ll a,b,u;cin>>a>>b>>u;
                        sgt->range_update(a-1,b-1,u);
               }
               else{
                        ll in;cin>>in;
                        cout<<sgt->range_query(in-1,in-1)<<'\n';
               }
        }
}
                        
                        
int32_t main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       solve();
       return 0;

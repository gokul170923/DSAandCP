#include <bits/stdc++.h>
using namespace std;
                    
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define nl cout<<'\n'
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(x) for(auto i:x) cout<<i<<' '
                    
const int mod = 1000000007;

int in = 0;
vector<int>a;

//      Subtree Queries CSES

void eulerTour2(vector<vector<int>>&adj,int node,int p,vector<pair<int,int>>&index){
        index[node].first = in;
        a.push_back(node);
        in++;
        for(int i:adj[node]){
                if(i==p) continue;
                eulerTour2(adj,i,node,index);
        }
        index[node].second = in;
        a.push_back(node);
        in++;
}

class SegmentTree{
public:
        int orgn,n,ln;
        vector<int>arr;
        SegmentTree(vector<int>&val){
                orgn = in;
                ln = ceil(log2(in));
                ln = (1<<ln) , n = (ln<<1);
                arr.resize(n);
                build(0,ln-1,0,val);
        }

        void build(int l,int r,int index,vector<int>&val){
                if(l==r){
                        if(l<orgn) arr[index] = val[a[l]];
                        return;
                }
                int mid = l + (r-l)/2;
                build(l,mid,2*index+1,val);
                build(mid+1,r,2*index+2,val);
                arr[index] = arr[2*index+1] + arr[2*index+2];
        }
        
        void pup(int l,int r,int index,int in ,int val){
                if(l==r){
                        arr[index] = val;
                        return;
                }
                int mid = l + (r-l)/2;
                if(in<=mid) pup(l,mid,2*index+1,in,val);
                else pup(mid+1,r,2*index+2,in,val);
                arr[index] = arr[2*index+1] + arr[2*index+2];
        }
        
        void point_update(int in,int val){
                pup(0,ln-1,0,in,val);
        }
        
        int rq(int l,int r,int index,int start,int end){
                if(l>=start && r<=end) return arr[index];
                else if(l>end || r< start) return 0;
                int mid = l + (r-l)/2;
                return rq(l,mid,2*index+1,start,end)
                        + rq(mid+1,r,2*index+2,start,end);
        }

        int range_query(int start,int end){
                return rq(0,ln-1,0,start,end);
        }
};
                    
void solve(){
        int n;cin>>n;
        int q;cin>>q;
        vector<int>val(n);
        for(int &i:val) cin>>i;

        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
                int u,v;cin>>u>>v;
                u--,v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        vector<pair<int,int>>index(n);
        eulerTour2(adj,0,-1,index);
        SegmentTree sgt(val);
        while(q--){
                int t;cin>>t;
                if(t==1){
                        int node,val;cin>>node>>val;
                        sgt.point_update(index[node-1].first,val);
                        sgt.point_update(index[node-1].second,val);
                }
                else{
                        int node;cin>>node;
                        cout<<sgt.range_query(index[node-1].first,index[node-1].second)/2;
                        nl;
                }
        }
}
                        
                        
int32_t main(){
       std::ios::sync_with_stdio(false);
       std::cin.tie(nullptr);
       solve();
       return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define nl cout<<'\n'
#define int long long
#define all(x) x.begin(),x.end()
                    
class SegmentTree{
public:
        int orgn,n,ln;
        vector<int>arr;

        SegmentTree(int m){
                orgn = m;
                ln = ceil(log2(m));
                ln = (1LL<<ln) , n = (ln<<1LL);
                arr.resize(n);
        }

        void point_update(int l,int r,int index,int in ,int val){
                if(l==r){
                        arr[index] += val;
                        return;
                }
                int mid = l + (r-l)/2;
                if(in<=mid) point_update(l,mid,2*index+1,in,val);
                else point_update(mid+1,r,2*index+2,in,val);
                arr[index] = arr[2*index+1] + arr[2*index+2];
        }

        void point_update(int in,int val){
                point_update(0,ln-1,0,in,val);
        }

        int range_query(int l,int r,int index,int start,int end){
                if(l>=start && r<=end) return arr[index];
                else if(r<start || l>end) return 0;
                int mid = l + (r-l)/2;
                return range_query(l,mid,2*index+1,start,end) +
                        range_query(mid+1,r,2*index+2,start,end); 
        }

        int range_query(int start,int end){
                return range_query(0,ln-1,0,start,end);
        }
};
                    
void solve(){
        int n;cin>>n;
        int m;cin>>m;

        vector<int>arr(n);
        for(int &i:arr) cin>>i;

        vector<array<int,3>>q(m);
        for(int i=0;i<m;i++){
                char x;cin>>x;
                q[i][0] = (x=='?'?0:1);
                cin>>q[i][1]>>q[i][2];
        }


        /*********************        coordinate compression        ***************/
        vector<int>usedSalaries(all(arr));
        for(int i=0;i<m;i++){
                usedSalaries.push_back(q[i][1]);
                usedSalaries.push_back(q[i][2]);
        } 
        //      sort , remove duplicate
        sort(all(usedSalaries));
        auto it = unique(all(usedSalaries));
        usedSalaries.erase(it,usedSalaries.end());

        int N = usedSalaries.size();
        unordered_map<int,int>val_to_index;
        for(int i=0;i<N;i++) val_to_index[usedSalaries[i]] = i;

        /************************************************************************ */


        SegmentTree sgt(N);
        for(int i=0;i<n;i++){
                sgt.point_update(val_to_index[arr[i]],1);
        }
        
        for(int i=0;i<m;i++){
                if(q[i][0]){    // change
                        int elem_to_change = arr[q[i][1]-1];
                        sgt.point_update(val_to_index[elem_to_change],-1);
                        sgt.point_update(val_to_index[q[i][2]],1);
                        arr[q[i][1]-1] = q[i][2];
                }
                else{   // query
                        cout<<sgt.range_query(val_to_index[q[i][1]],val_to_index[q[i][2]]);
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

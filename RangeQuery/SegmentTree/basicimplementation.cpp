#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    int n,ln;
    vector<long long>arr;
    
    SegmentTree(int m,vector<int>&a){ // init 
        ln = ceil(log2(m));
        ln = 1<<ln , n = ln<<1;
        arr.resize(n,0);
        build(0,ln-1,0,a,m);
    }
    
    void build(int l,int r,int index,vector<int>&a,int m){ 
        if(l==r){                                       // build
                if(l<m) arr[index] = a[l];
                return;
        }
        int mid = (l+r)/2;
        build(l,mid,2*index+1,a,m);
        build(mid+1,r,2*index+2,a,m);
        arr[index] = arr[2*index+1] + arr[2*index+2];
    }
    
    long long rq(int l ,int r,int index , int start , int end){
        if(l>=start && r<=end) return arr[index];       // Range query
        if(r<start || l>end) return 0;
        int mid = (l+r)/2;
        return rq(l,mid,2*index+1,start,end) + 
                rq(mid+1,r,2*index+2,start,end);
    }
    long long range_query(int start,int end){
        return rq(0,ln-1,0,start,end);
    }

    void pup(int l,int r,int index,int point,int pval){
        if(l==r){
                arr[index] = pval;                        // point updates
                return;
        }
        int mid = (l+r)/2;
        if(point <= mid ) pup(l,mid,2*index+1,point,pval);
        else pup(mid+1,r,2*index+2,point,pval);
        arr[index] = arr[2*index+1] + arr[2*index+2];
    }
    void point_update(int point,int pval){
        pup(0,ln-1,0,point,pval);
    }
};

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    SegmentTree sgt(6,arr);
    cout<<sgt.range_query(1,5)<<endl;
    sgt.point_update(5,10);
    cout<<sgt.range_query(1,5);
    return 0;
}
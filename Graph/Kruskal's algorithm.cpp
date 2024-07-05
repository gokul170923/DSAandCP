int find(vector<int>&ds,int u){
	if(u==ds[u]) return u;
	return ds[u] = find(ds,ds[u]);
}
void unionof(vector<int>&ds,int u,int v){
    int p1 = find(ds,u);
    int p2 = find(ds,v);
    
    if(p1!=p2) ds[p2] = p1;
    
}
	
	
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int>disjoint_set(V);
    
    for(int i=0;i<V;i++) disjoint_set[i] = i;
    
    priority_queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<V;i++){
        for(vector<int> j:adj[i]){
            q.push({-j[1],{i,j[0]}});
            
        }
    }
    
    int ans =0;
    while(q.empty()==false){
        int w = -q.top().first;
        int u = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        
        if(find(disjoint_set,u)!=find(disjoint_set,v)){
            unionof(disjoint_set,u,v);
            ans+=w;
        }
        
    }
    return ans;  
}
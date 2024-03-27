class Solution
{
	//  https://www.geeksforgeeks.org/topological-sorting/
	
    // IN TOPOLOGICAL SORT WITH BFS ,USE KHAN'S ALGORITHM : THE BASIC IDEA IS TO 
    // START WITH NODE HAVING INDEGREE 0 AT THE MOMENT
	public:

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V);
	    for(int i=0;i<V;i++){
	        for(int it:adj[i]) indegree[it]++;
	    }
	    queue<int>q;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	     while(q.empty()==false){
	        int node= q.front();
	        ans.push_back(node);
	        q.pop();
	        for(int i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	        
	    }
	    return ans;
	}
};
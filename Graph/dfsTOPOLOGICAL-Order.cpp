// MAIN LOGIC BEHINGD TOPOLOGICAL ORDER IS THAT 
// IT IS IN THE ORDER OF DIRECTCION OF DIRECTED ACYCLIC GRAPH




class Solution
{

    //  https://www.geeksforgeeks.org/topological-sorting/
	public:
	void dfs(vector<int>adj[] , vector<int>&visited,stack<int>&st,int node){
	    visited[node]=1;
	    for(int i:adj[node]){
	        if(visited[i]==0)
	           dfs(adj,visited,st,i);
	    }
	    st.push(node);
	}

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>visited(V);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(visited[i]==0){
	            dfs(adj,visited,st,i);
	        }
	    }
	    vector<int>ans;
	    while(st.empty()==false){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	}
};

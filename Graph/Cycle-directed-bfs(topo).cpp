/* INTUTION : THE NORMAL VISITED LOGIC OR UNDIRECTED WONT WORK HERE SINCE IT WILL FAIL AT 
   CASES WHERE 1---->2
               |     ^
               |     |
               ------>3
    SO THE DFS APPROACH WAS TO KEEP TRACK OF THE PATH UISNG A DATASTRUCTURE
    (can use only visited too) BUT THERE WE HAD BACKTRACKING BECUASE W EWERE DOING DEPTH 
    HERE WE WILL VISIT MULTIPLE NODE AT ONCE HENCE A PATHVIISTED ARRAY FAILS .
    
    USE TOPOSORT IF THE OUTPUT IS NOT OF SIZE V IT HAS A CYCLE SINCE
    WE WONT BE ABLE TO TRAVERSE EACH ELEMENT.
    
    
*/

//           https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1



class Solution {
  public:

    bool isCyclic(int V, vector<int> adj[]) {
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
	    return ans.size()!=V;
       
       
    }
};


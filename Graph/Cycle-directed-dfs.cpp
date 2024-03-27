
/* INTUTION : THE NORMAL VISITED LOGIC OR UNDIRECTED WONT WORK HERE SINCE IT WILL FAIL AT 
   CASES WHERE 1---->2
               |     ^
               |     |
               ------>3
    SO THE APPROACH IS TO KEEP TRACK OF THE PATH UISNG A DATASTRUCTURE (can use only visited too)
*/
//           https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// WITH PATH VISITED
class Solution {
  public:
    bool dfs(vector<int>adj[],vector<int>&visited,vector<int>&pathvisited,int node){
        visited[node]=1;
        pathvisited[node]=1;
        for(int i:adj[node]){
            if(visited[i]==0){
                if(dfs(adj,visited,pathvisited,i)) return true;
            }
            else if(pathvisited[i]==1) return true;
        }
        pathvisited[node]=0;
        return false;
        
    }
   
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,0),pathvisited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0 && dfs(adj,visited,pathvisited,i)) return true;
        }
        return false;
    }
};


// WITHOUT PATH VISITED

  public:
    bool dfs(vector<int>adj[],vector<int>&visited,int node){
        visited[node]=2;
    
        for(int i:adj[node]){
            if(visited[i]==0){
                if(dfs(adj,visited,i)) return true;
            }
            else if(visited[i]==2) return true;
        }
        visited[node]=1;
        return false;
        
    }
   
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0 && dfs(adj,visited,i)) return true;
        }
        return false;
    }
};

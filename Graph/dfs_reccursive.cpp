#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void adjacencylist();
void adjacencymatrix();


/***************************************   dfs   *********************************

1. dfs on adjacencylist  (traverse in elements)
2. dfs on adjacencymatrix  (traverse in indexes)
*/

void dfs(vector<vector<int>>adjl,vector<int>&visited,int node){
    visited[node]=1;
    cout<<node<<' ';

    for(int i:adjl[node]){
        if(visited[i]==0){
            
            dfs(adjl,visited,i);
        }
    }

}
void dfs(vector<vector<int>>adjm,vector<int>&visited,int node,int e){
    visited[node]=1;
    cout<<node<<' ';

    for(int i=0;i<adjm[node].size();i++){
        if(adjm[node][i]==1 && visited[i]==0){
            
            dfs(adjm,visited,i,e);
        }
    }

}






int main(){
    adjacencymatrix();
    adjacencylist();
    return 0;
}



//***************************************   Adjacency matrix   *********************************

void adjacencymatrix(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<vector<int>>adjm(n,vector<int>(n,0));
    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"Adjacency matrix : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjm[i][j]<<' ';
        }
        cout<<'\n';
    }
    vector<int>visited(n,0);
    dfs(adjm,visited,1,e);

}


//***************************************   Adjacency list  *********************************

void adjacencylist(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<vector<int>>adjl(n);
    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    cout<<"Adjacency list : \n";
    for(int i=0;i<n;i++){
        cout<<i<<" : ";
        for(int j:adjl[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    vector<int>visited(n,0);
    dfs(adjl,visited,1);


}

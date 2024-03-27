#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void adjacencylist();
void adjacencymatrix();


/***************************************   bfs   *********************************

1. bfs on adjacencylist  (traverse in elements)
2. bfs on adjacencymatrix  (traverse in indexes)
*/


// Function to perform Breadth-First Search on an adjacency list
void bfs(vector<vector<int>> adjl, int v) {
    queue<int> q;
    vector<int> visited(v + 1, 0);
    int start;
    cout << "Start BFS from node: ";
    cin >> start;
    q.push(start);
    visited[start] = 1;

    while (q.empty() == false) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        // Traverse adjacent nodes and enqueue if not visited
        for (int &i : adjl[node]) {
            if (visited[i] != 1) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}


// Function to perform Breadth-First Search on an adjacency matrix
void bfs(vector<vector<int>> adjm, int v, int e) {
    queue<int> q;
    vector<int> visited(v, 0);
    int start;
    cout << "Start BFS from node: ";
    cin >> start;
    q.push(start);
    visited[start] = 1;

    while (q.empty() == false) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        // Traverse adjacent nodes and enqueue if not visited
        for (int i = 0; i < adjm[node].size(); i++) {
            if(adjm[node][i]==1 && visited[i]!=1){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}




int main(){
    adjacencymatrix();
    //adjacencylist();
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
    bfs(adjm,n,e);

}


//***************************************   Adjacency list   *********************************

void adjacencylist(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<vector<int>>adjl(n+1);
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
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j:adjl[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    bfs(adjl,n);


}

#include<iostream>
#include<vector>
using namespace std;


//***************************************   Adjacency matrix   *********************************

// Function to create an adjacency matrix
void adjacencymatrix(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    // Initialize adjacency matrix with all zeros
    vector<vector<int>>adjm(n,vector<int>(n,0));

    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;

    // Input edges and update adjacency matrix
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjm[x-1][y-1]=1;
        adjm[y-1][x-1]=1;
    }

    // Display the adjacency matrix
    cout<<"Adjacency matrix : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjm[i][j]<<' ';
        }
        cout<<'\n';
    }
}





//***************************************   Adjacency matrix   *********************************

// Function to create an adjacency list
void adjacencylist(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    // Initialize adjacency list as a vector of vectors
    vector<vector<int>>adjl(n+1);

    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;

    // Input edges and update adjacency list
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    // Display the adjacency list
    cout<<"Adjacency list : \n";
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j:adjl[i]){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
}



int main(){
    // Call functions to create adjacency matrix and adjacency list
    adjacencymatrix();
    adjacencylist();
    return 0;
}

//BFS traversal on an undirected graph
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traverse(vector<int> adj[],int x,int n){
    //we make a visited array,and mark nodes that have been pushed into the queue
    vector<int> visited(n+1,0);
    queue<int>q;
    q.push(x);//push the starting node into the queue and mark the starting node as visited in the vector
    visited[x]=1;
    cout<<endl<<"The BFS traversal of the Graph : ";
    while(!q.empty()){
        int z = q.front();
        q.pop();
        cout<<z<<" ";
        //now push the adjacent nodes of z, into the queue which have not been marked visited
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
};
int main(){
    //create and store graph in adjacency list
    cout<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    //creating the adjacency list to store neighbours of nodes
    vector<int> adj[n+1];
    cout<<endl<<"Enter the (m) edges : ";
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<endl<<"The adjacency list has been created : "<<endl;
    for(int i =1;i<n+1;i++){
        cout<<i<<" : "; 
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int x;
    cout<<endl<<"Enter the starting node : ";
    cin>>x;
    //call the bfs function
    bfs_traverse(adj,x,n);//send the adjacency list,its size or the no of nodes,the starting node as the arguments
    return 0;
}
*/


//Traversal
/* 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traverse(vector<int> adj[],int n, int x){
    vector<int> visited(n+1,0);
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int z = q.front();
        cout<<z<<" ";
        q.pop();
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs_traverse(vector<int>adj[],int n,int x,vector<int>& visited){
    visited[x]=1;
    cout<<x<<" ";
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traverse(adj,n,i,visited);
        }
    }
}
int main(){
    
    //storing  graph
    cout<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    cout<<endl<<"Enter the (m) edges : ";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //now the graph has been stored

    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Enter the starting node for the bfs and dfs traversal : ";
    int x;
    cin>>x;
    vector<int> visited(n+1,0);
    cout<<endl<<"The BFS traversal of the garph is : ";
    bfs_traverse(adj,n,x);
    cout<<endl<<"The DFS traversal of the graph is : ";
    dfs_traverse(adj,n,x,visited);

    return 0;
}*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bfs_traverse(vector<int> adj[],int n, int x){
    vector<int> visited(n+1,0);
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int z = q.front();
        q.pop();
        cout<<z<<" ";
        for(int i : adj[z]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
void dfs_traverse(vector<int> adj[], int n,int x, vector<int>& visited){
    visited[x]=1;
    cout<<x<<" ";
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traverse(adj,n,i,visited);
        }
    }
}

int main(){

    //storing graph
    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];
    cout<<"Enter (m) edges : "<<endl;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the graph has been stored in an adjacency list

    cout<<endl<<"The adjacency list : ";
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }//the adjacency list has been printed
    cout<<endl<<"Enter the starting node for the traversal of this graph : ";
    int x;
    cin>>x;
    //calling BFS traversal algorithm on the graph
    cout<<endl<<"The BFS traversal of this graph : ";
    bfs_traverse(adj,n,x);//sending adjacency list over there

    //for dfs traversal we have to send in a visited lits by reference
    vector<int> dfs_visit(n+1,0);
    cout<<endl<<"The DFS traversal of this graph : ";
    dfs_traverse(adj,n,x,dfs_visit);

    return 0;
}
*/
//APPLY BFS AND DFS in : 
//1.adjacency list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traverse(vector<vector<int>> adj, int x){
    queue<int>q;
    int size = adj.size();
    vector<int> visited(size,0);
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int N = q.front();
        cout<<N<<" ";
        q.pop();
        for(int i : adj[N]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs_traverse(vector<vector<int>> adj, int x, vector<int> & visited){
    visited[x]=1;
    cout<<x<<" ";
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traverse(adj,i,visited);
        }
    }
}

int main(){
    cout<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(0)); //0 to n index , for if 0 to n-1 or from 1 to n.

    cout<<endl<<"Enter the (m) edges : ";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<<endl<<"The adjacency list : ";
    for(int i =0;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting node for traversal : ";
    int x;
    cin>>x;

    //now first for the bfs
    cout<<endl<<"The BFS traversal of the graph : ";
    bfs_traverse(adj,x);
    
    //since the DFS algo consists of recursion, we'll have to pass a visited list from the main() itself
    vector<int> visited(n+1,0);
    cout<<endl<<"The DFS traversal of the graph : ";
    dfs_traverse(adj,x,visited);

    return 0;
}
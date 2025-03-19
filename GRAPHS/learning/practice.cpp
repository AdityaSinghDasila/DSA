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
/*
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
*/

/*

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
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

void dfs_traversal(vector<vector<int>> adj, int x, vector<int>& visited){
    visited[x]=1;
    cout<<x<<" ";
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }
}

int main(){
    cout<<endl<<"Enter the number of nodes and edges  : ";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<"Enter (m) edges : "<<endl;
    
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//now the adjacency list has been made

    cout<<endl<<"The adjacency list : "<<endl;
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting node of the graph : ";
    int x;
    cin>>x;

    cout<<endl<<"The BFS traversal of the graph : ";
    bfs_traversal(adj,x);


    vector<int> visited(n+1,0);
    cout<<endl<<"The DFS traversal of the graph : ";
    dfs_traversal(adj,x,visited);

    return 0;
}
*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traverse(vector<vector<int>> adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int z = q.front();
        q.pop();
        cout<<z<<" ";
        for(int y : adj[z]){
            if(visited[y]==0){
                visited[y]=1;
                q.push(y);
            }
        }
    }
}

void dfs_traverse(vector<vector<int>> adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int y : adj[x]){
        if(visited[y]==0){
            dfs_traverse(adj,y,visited);
        }
    }
}

int main(){

    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<endl<<"Enter the edges : ";
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//The adjaceny list has been made

    cout<<endl<<"The adjacency list made : "<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<" : ";
        for(int x : adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }//success

    //now to traverse this graph: 
    int x;
    cout<<endl<<"Enter the starting point of the graph : ";
    cin>>x;
    cout<<"The BFS traversal of the graph  : ";
    bfs_traverse(adj,x);

    vector<int> visited(n+1,0); //initialised with 0, which means not visited yet
    cout<<endl<<"The DFS traversal of the graph : ";
    dfs_traverse(adj,x,visited);


    return 0;
    
}
*/

//matrix???
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traverse(vector<vector<int>>& adj, int x){
    queue<int>q;
    vector<int> visited(adj.size(),0);
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int n  = q.front();
        q.pop();
        cout<<n<<" ";
        for(int j =1;j<adj[n].size();j++){
            if(adj[n][j]==1 && visited[j]==0){
                q.push(j);
                visited[j]=1;
            }
        }
    }
}

void dfs_traverse(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i=1;i<adj[x].size();i++){
        if(adj[x][i]==1 && visited[i]==0){
            dfs_traverse(adj,i,visited);
        }
    }
}

int main(){
    
    cout<<endl<<"Enter the number of nodes : ";
    int n,m;
    cin>>n;
    cout<<endl<<"Enter the number of edges : ";
    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    cin>>m;

    cout<<endl<<"Enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }//the adjacency matrix has been made

    cout<<endl<<"The adjacency matrix is as follows : "<<endl;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }//works!

    int x;
    cout<<"Enter the starting node for traversal  : ";
    cin>>x;
    cout<<"The BFS traversal of the graph is : ";
    bfs_traverse(adj,x);


    vector<int> visited(n+1,0);
    cout<<endl<<"The DFS traversal of the graph is : ";
    dfs_traverse(adj,x,visited);

    return 0;

}
*/

/*
#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>>& adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int m = q.front();
        q.pop();
        cout<<m<<" ";
        for(int i : adj[m]){
            if(visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void dfsTraversal(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfsTraversal(adj,i,visited);
        }
    }
}

int main(){

    //graph 
    cout<<endl<<"Enter the number of nodes and vertices : ";
    int n,m;
    cin>>n>>m;

    cout<<endl<<"Enter the edges : ";
    vector<vector<int>> adj(n+1,vector<int>(0,0));
    for(int i =0 ;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been formed

    cout<<endl<<"The adjacency list : "<<endl;
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(auto j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting node for the graph traversal : ";
    int x;
    cin>>x;

    cout<<endl<<"The BFS traversal of the graph : ";
    bfsTraversal(adj,x);

    vector<int> dfsVisited(n+1,0);
    cout<<endl<<"The dfs traversal of the graph : ";
    dfsTraversal(adj,x,dfsVisited);

    return 0;
}

*/

/*
//matrix representation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> returnAdjList(vector<vector<int>>& adj){
    int r = adj.size();
    vector<vector<int>> Adj(r,vector<int>(0,0));
    for(int i =1;i<r;i++){
        for(int j =1;j<r;j++){
            if(adj[i][j]==1){
                Adj[i].push_back(j);
            }
        }
    }
    return Adj;
}

int main(){

    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    cout<<endl<<"Enter the edges : "<<endl;

    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }//adjacency matrix made

    cout<<endl<<"Adjacency matrix : "<<endl;
    for(int i =1;i<=n;i++){
        cout<<i<<" -->    ";
        for(int j =1;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    //making adjacency list from matrix 
    vector<vector<int>> Adj = returnAdjList(adj);
    for(int i = 1;i<=n;i++){
        cout<<i<<" : ";
        for(int j : Adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
*/


/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>>& adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int m = q.front();
        cout<<m<<" ";
        q.pop();
        for(int i : adj[m]){
            if(visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void dfs_traversal(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }
}

int main(){

    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<endl<<"Enter the edges : ";
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//adjacency list made

    cout<<endl<<"The adjacency list of the graph : ";
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

    cout<<endl<<"The bfs traversal of the graph : ";
    bfs_traversal(adj,x);


    vector<int> dfs_visited(n+1,0);
    cout<<endl<<"The dfs traversal of the graph : ";
    dfs_traversal(adj,x,dfs_visited);

    return 0;
}

*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>> &adj, int x){
    int n = adj.size();
    vector<int> visited(n,0);
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int m = q.front();
        q.pop();
        cout<<m<<" ";
        for(int i : adj[m]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}//code for bfs traversal of the graph 

void dfs_traversal(vector<vector<int>> adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }
}//code for dfs traversal of the graph 

int main(){

    cout<<endl<<"Enter the no of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<endl<<"Enter the edges : "<<endl;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been made

    //printing the list
    cout<<endl<<"The adjacency list : ";
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(auto j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }    

    int x;
    cout<<endl<<"Enter the starting node of the graph : ";
    cin>>x;

    cout<<endl<<"The BFS traversal of the graph starting from "<<x<<" : ";
    bfs_traversal(adj,x);

    vector<int> dfs_visited(n+1,0);

    cout<<endl<<"The DFS traversal of the graph starting from "<<x<<" : ";
    dfs_traversal(adj,x,dfs_visited);

    return 0;
}
*/

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>>& adj, int x){
    vector<int> visited(adj.size(),0);
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int n = q.front();
        cout<<n<<" ";
        q.pop();
        for(int i : adj[n]){
            if(visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfs_traversal(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }
}

int main(){

    cout<<endl<<"Enter the number of nodes and edges : ";
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<endl<<"Enter the edges : "<<endl;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacency list has been made

    cout<<"The adjacency list : ";
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j: adj[i]){
            cout<<j<<" ";
        } 
        cout<<endl;
    }

    vector<vector<int>> matrix(n+1,vector<int>(n+1,0));
    //lets fill the matrix with the adjacency list
    for(int i =1;i<n+1;i++){
        for(int j : adj[i]){
            matrix[i][j] =1;
        }
    }//now the matrix has been made

    cout<<endl<<"The adjacency matrix : "<<endl;
    for(int i =1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting node : ";
    int x;
    cin>>x;

    cout<<endl<<"The BFS traversal of the graph : ";
    bfs_traversal(adj,x);

    cout<<endl<<"The DFS traversal of the graph : ";
    vector<int> visited(n+1,0);
    dfs_traversal(adj,x,visited);

    return 0;
}
*/



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(vector<vector<int>>& adj, int x){
    
    vector<int> visited(adj.size(),0);
    queue<int>q;
    q.push(x);
    visited[x]=1;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        cout<<i<<" ";
        for(int j : adj[i]){
            if(visited[j]==0){
                q.push(j);
                visited[j]=1;
            }
        }
    }
}


void dfs_traversal(vector<vector<int>>& adj, int x, vector<int>& visited){
    cout<<x<<" ";
    visited[x]=1;
    for(int i : adj[x]){
        if(visited[i]==0){
            dfs_traversal(adj,i,visited);
        }
    }
}

int main(){

    cout<<endl<<"Enter the number of nodes and edges in the graph : ";
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(0,0));
    cout<<endl<<"Enter the edges of the graph : ";
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }//the adjacent list has been made

    cout<<endl<<"The adjacency list : ";
    for(int i =1;i<n+1;i++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting node : ";
    int x;
    cin>>x;

    cout<<endl<<"The BFS traversal of the graph : ";
    bfs_traversal(adj,x);

    cout<<endl<<"The DFS traversal of the graph : ";
    vector<int> visited(n+1,0);
    dfs_traversal(adj,x,visited);

    return 0;
}
















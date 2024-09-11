#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool find_cycle(vector<vector<int>> adj,int i,vector<int>& visited){

    queue<pair<int,int>> q;
    int n = adj.size();
    int node = i;
    int parent = -1;
    q.push({node,parent});
    visited[node]=1;

    while(!q.empty()){
        pair<int,int> N = q.front();
        q.pop();
        node = N.first;
        parent = N.second;
        for(int i : adj[node]){
            if(visited[i]==0){
                q.push({i,node});
                parent = node;
            }
            else{
                if(i!=parent){
                    return true;
                }
            }
        }       
    }
    return false; 
}   

int main(){

    //lets make graph that is looped, with adjacency matrix
    vector<vector<int>> adj(9,vector<int>(0));
    cout<<endl<<"Enter the edges : ";
    for(int i =0;i<8;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<endl<<"The adjacency list will be : ";
    for(int i=0;i<adj.size();i++){
        cout<<i<<" : ";
        for( int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int n = adj.size();
    vector<int> visited(n,0);
    int flag =0;
    bool ans = false;   
    for(int i =0;i<adj.size();i++){
        if(visited[i]==0){
            ans = find_cycle(adj,i,visited);
        if(ans){
            cout<<"Loop found!"; 
            flag =1;
            break;
            }
        }
    }
    if(!flag)
        cout<<endl<<"No loop found";
    return 0;

}
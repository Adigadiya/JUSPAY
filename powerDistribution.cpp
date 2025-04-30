#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int dfs(vector<vector<int>>& adj, vector<vector<int>>&cost, int curr,int par, int target, int currcost){
    if(curr == target) return currcost;

    for(auto adjnode:adj[curr]){
        if(adjnode == par) continue;

        int path= dfs(adj,cost, adjnode,curr, target, currcost+ cost[curr][adjnode]);
        if(path!=-1) return path;
    }
    return -1;
}

int main() {
ios::sync_with_stdio(false);    
cin.tie(nullptr);

    int n, r,m;
    cin>>n>>r>>m;

    vector<vector<int>>adj(n+1);
    vector<vector<int>>cost(n+1, vector<int>(n+1));

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        cost[u][v]=w;
        cost[v][u]=w;
    }

    int q;
    cin>>q;

    ll resSum=0;

    while(q--){
        int type,a,b,w;
        cin>>type>>a>>b>>w;

        if(type==1){
           int pathCost=dfs(adj,cost,a,-1,b,0);
           resSum+=(pathCost!=-1)?pathCost:0;
        }
        else{
            cost[a][b]=w;
            cost[b][a]=w;
        }
    }

    cout<<resSum<<" ";


    return 0;
}


/* 7 2 6
2 3 30 
3 1 10
2 5 15
4 7 12
5 7 20
6 5 14
4
1 7 3 0
2 2 5 10 
1 1 4 0
1 2 7 0  */
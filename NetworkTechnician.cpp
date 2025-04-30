#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007



int dfs(vector<vector<int>>&adj, int node,vector<int>&unsafe, int cntunsafe, int &m){
    if(unsafe[node]) cntunsafe+=1;
    else cntunsafe=0;

    if(cntunsafe>m) return 0; //path not suitable
    if(adj[node].empty()) return 1; //leaf node;

    int paths=0;
    for(auto adjnode:adj[node]){
         paths+= dfs(adj,adjnode, unsafe, cntunsafe,m);
    }
    return paths;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;

    vector<int>unsafe(n+1);
    for(int i=1; i<=n; i++){
        cin>>unsafe[i];
    }
    
    vector<vector<int>>adj(n+1);
    for(int i=1; i<=k; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    cout<<dfs(adj, 1,unsafe, 0,m)<<endl;

    return 0;
}
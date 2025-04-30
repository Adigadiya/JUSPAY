#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int n;
cin>>n;

vector<vector<int>>adj(n+1);

vector<int>rebellious(n+1);

for(int i=1; i<=n; i++){
    int par, rebel;
    cin >> par>>rebel;

    if(par!=-1)adj[par].push_back(i);
    rebellious[i]=rebel;
}

bool flag=false;
for(int i=1; i<=n; i++){
    
    if(rebellious[i]){
        int nobleChildren=0;
        for(auto child:adj[i])  if(rebellious[child] == 0) nobleChildren++;
        
        if(!nobleChildren){ cout<<i<<" "; flag= true;}
    }
}
if(!flag) cout<<-1<<endl;
return 0;
}
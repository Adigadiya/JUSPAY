#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007



int LCA(int a, int b){
    if(a==b) return a;
    if(a==1 || b==1) return 1;

    while(a!=b){
        if(a>b) a>>=1;
        else b>>=1;
    }
    return a;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);

int q;
cin>>q;

unordered_map<int,int>toll;

auto updateToll=[&](int a, int b, int t){
    int lca= LCA(a,b);

    while(a!=lca){
        toll[a]+=t; a>>=1;
    }
    while(b!=lca){
        toll[b]+=t; b>>=1;
    }
};

auto findSum=[&](int a, int b){
    int lca= LCA(a,b);
    
    int pathSum=0;
    while(a!=lca){
        pathSum+=toll[a]; a>>=1;
    }
    while(b!=lca){
        pathSum+=toll[b]; b>>=1;
    }
    return pathSum;
};

int sum =0;
for(int i=0; i<q; i++){
    int op, x,y,t;
    cin>>op>>x>>y>>t;

    if(op == 1) updateToll(x,y,t);
    else{
        sum+= findSum(x,y); 
    }
}
    cout<<sum<<endl;


    return 0;
}
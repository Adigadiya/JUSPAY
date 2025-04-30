#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>par,rank;

    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);

        for(int i=1;i<=n; i++) par[i]=i;
    }

    int findUpar(int x){
        if(par[x] == x) return x;
        return par[x]= findUpar(par[x]);
    }

    void Ubr(int x,int y){
        int uparx= findUpar(x), upary= findUpar(y);

        if(rank[uparx] == rank[upary]){
            par[upary]= uparx;
            rank[uparx]++;
        }
        else if(rank[uparx] > rank[upary]){
            par[upary]=uparx;
        }
        else par[uparx]=upary;
    }
};

int main(){
    int n;
    cin>>n;

    unordered_map<char,int>charToId;
    unordered_map<int,char>idToChar;

    int id=1;
    vector<pair<char,char>>mergers;
    
    for(int i=0; i<n ;i++){
        char a,b;
        cin>>a>>b;

        mergers.push_back({a,b});
        if(charToId.count(a)==0){
            charToId[a]=id; idToChar[id]=a;
            id++;
        }
        if(charToId.count(b) == 0){
            charToId[b]=id; idToChar[id]=b;
            id++;
        }
    }
    
    DisjointSet ds(id);

    for(auto merger: mergers){
        int x= charToId[merger.first], y= charToId[merger.second];

        ds.Ubr(x,y);
    }

    set<char>topLevel;
    for(int i=1; i<id;i++){
        topLevel.insert(idToChar[ds.findUpar(i)]);
    }

    for(auto top:topLevel) cout<<top<<" ";

}

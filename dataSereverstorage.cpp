#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);


    int n;
    cin>>n;

    vector<ll>servers(n,0);
    for(int i=0; i<n; i++){
        cin>>servers[i];
    }

    sort(servers.begin(), servers.end());
    int l=0,r=0, maxwindowSize=-1;

    while(r<n){
        
        while((servers[r]-servers[l]+1)>n) l++;
        
        maxwindowSize= max(r-l+1, maxwindowSize);
        r++;
    }

    cout<< (n-maxwindowSize)<<endl; 

    return 0;
}
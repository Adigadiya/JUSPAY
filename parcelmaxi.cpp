#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);


    int n;
    cin>>n;

    vector<int>parcels(n);
    for(int i=0; i<n; i++) cin>>parcels[i];

    unordered_set<int>x(parcels.begin(), parcels.end());
    vector<int>a(x.begin(), x.end());

    sort(a.begin(), a.end());
    int l=0, r=0,maxSize=-1;

    while(r<n){ 
        
        while(l<=r && (a[r] > a[l]+n)) l++;
    
        maxSize= max(r-l+1, maxSize);
        r++;
    }
    
    cout<<maxSize;
    return 0;
}
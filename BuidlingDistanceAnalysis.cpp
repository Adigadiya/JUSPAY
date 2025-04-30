#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int compute(vector<int>&positions){
    sort(positions.begin(), positions.end());

    int sum=0, n=positions.size(), prefixsum=0;

    for(int i=0; i<n; i++){
        sum+= (positions[i]*i - prefixsum);
        prefixsum+= positions[i];
    }
    return sum;

} 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    unordered_map<int,vector<int>>rowlist, collist;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int type;
            cin>>type;

            rowlist[type].push_back(i);
            collist[type].push_back(j);
        }
    }
     int ans=0;
    for(auto rows:rowlist){
        ans+= compute(rows.second);  //d = |r1-r2| + |c1-c2|
    }
    for(auto cols:collist){   
        ans+= compute(cols.second);
    }

    cout<<ans<<endl;
}
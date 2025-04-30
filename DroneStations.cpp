#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin>>n;

    vector<pair<ll, ll>>intervals;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;

        intervals.push_back({a,b});
    }

    sort(intervals.begin(), intervals.end());

    auto isPossible=[&](const vector<pair<ll,ll>>&intervals, ll d)->bool{
        ll lastplaced = intervals[0].first;
        
        for(int i=1; i<n; i++){
            ll nextstop = max(lastplaced +d, intervals[i].first);
            
            if(nextstop<=intervals[i].second) lastplaced= nextstop;
            else return false;
        }
        return true;
    };

    ll low= 1, high=1e14;

    while(low<=high){
        ll mid= (low + (high-low)/2);

        if(isPossible(intervals, mid)) low=mid+1;
        else high =mid-1;
    }

    cout<<high;




    return 0;
}
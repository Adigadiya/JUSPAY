#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, T, K;
    cin>>N>>T>>K;

    unordered_map<string, vector<int>> ipLogs;

    for (int i = 0; i < N; ++i) {
        int timestamp;
        string ip;
        cin>>timestamp>>ip;
        ipLogs[ip].push_back(timestamp);
    }

    set<string> flaggedIPs;

    for (auto& entry : ipLogs) {
        const string& ip = entry.first;
        vector<int>& timestamps = entry.second;

        sort(timestamps.begin(), timestamps.end());

        int l=0, r=0, n=timestamps.size();
        
        while(r<n){
            if(timestamps[r] - timestamps[l]<=T){
                if(r-l+1>=K){                  //if valid window size >=k 
                    flaggedIPs.insert(ip);
                    break;
                }
                else r++;
            }   
            else l++;
        }
    }

    if (flaggedIPs.empty()) {
        cout <<"No Threats Detected"<< endl;
    } else {
        for (const auto& ip :flaggedIPs) {
            cout <<ip<< " ";
        }
        cout <<endl;
    }

    return 0;
}
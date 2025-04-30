/*In a cloud storage system, files are assigned encrypted names consisting of lowercase English letters.
When a file is updated, its encrypted name must also be updated following these rules:

The new file name must be exactly k characters long.

The new file name can only include characters that are present in the original file name.

The new file name must be lexicographically larger than the original file name (i.e., must come after the original name in dictionary order).

Among all valid new file names, you must find the smallest possible one.

If no valid new name exists, return "NO". */



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;


    auto repeatable=[&](string s, int n, int k)->string{

        set<char>st(s.begin(), s.end());
        vector<char>chars(st.begin(), st.end());

        if(k>n){
            for(int i=0; i<k-n; i++) s.push_back(chars[0]);
            return s;
        }
        string res= s.substr(0,k);

        for(int i=k-1; i>=0; i--){
            auto it= upper_bound(chars.begin(), chars.end(),res[i]);

            if(it== chars.end()) continue;
            
            res[i]=*it;

            for(int j=i+1; j<k;j++) res[j] =chars[0];
            return res;
        }
        return "NO";
    };

    //if unlimited repetition of characters of s allowed;
    cout<< repeatable(s,n,k)<<endl;

    return 0;
}
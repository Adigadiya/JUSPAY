#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

    int n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    int cnt=0;

    for(int i=1; i<n-1; i++){
        if(s1[i] == '.' && s2[i] == '.'){

            if(s1[i+1] == 'X' && s1[i-1] =='X' && s2[i-1] =='.' && s2[i+1]=='.') cnt+=1;
            
            else if(s2[i+1] =='X' && s2[i-1]=='X' && s1[i-1] =='.' && s1[i+1] =='.') cnt+=1;
        } 
    }
    cout<< cnt<<endl;
    return 0;
}
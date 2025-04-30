#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int yG=0, xG=0, xC=0, smallestseg=1e8;
    bool bigY=false;

    int n=s.length();

    for(int i=0; i<n; i++){
        if(s[i] =='X'){

            xG+=1;
            int group=0;
            while(i<n && s[i] =='X'){
                group+=1;
                xC+=1;
                i++;
            }
            smallestseg= min(smallestseg,group);
            i--;
        }
        else{
            yG+=1;
            int group=0;
            while(i<n && s[i] =='Y'){
                group+=1;
                if(group>1) bigY=true; 
                i++;
            }
            i--;
        }
    }
    if(yG < xG && bigY) cout<<xC-smallestseg;
    else cout<<xC<<" ";

}
#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;

int solve(string s,int i,int j,bool isTrue){
    //Base Condt.
    if(i>j) return 0;
    if(i==j){
        if(isTrue==true) return s[i]=='T';
        else return s[i]=='F';
    }
    //Creating Key for Map
    string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    if(m.find(temp)!=m.end())return m[temp];
    //Storing recursive data to map
    int ans=0;
    for(int k=i+1;k<j;k+=2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        if(s[k]=='&'){
            if(isTrue==true) ans=ans+lt*rt;
            else ans=ans+lf*rf+lf*rt+lt*rf;
        }else if(s[k]=='|'){
                if(isTrue==true) ans+=(lt*rt)+(lt*rf)+(lf*rt);
                else ans+=(lf*rf);
        }else if(s[k]=='^'){
                if(isTrue==true) ans+=lt*rf+rt*lf;
                else ans+=lt*rt+lf*rf;
        }
        
    }
    return m[temp]=ans;
}

int main(){
    string s="T^F&T";
    int i=0,j=s.length()-1;
    cout<<solve(s,i,j,true);
    return 0;
}
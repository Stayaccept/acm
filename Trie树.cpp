#include<bits/stdc++.h>
using namespace std;

const int siz=100005;
string s[10005];
int rt,f[siz],tr[siz][10];                      //初始化rt
void in(string s){
    int i,u,v;
    u=0;
    for(i=0;i<s.size();i++){
        v=s[i]-'0';
        if(tr[u][v]==0)
        tr[u][v]=++rt;
        u=tr[u][v];
    }
    f[u]=1;
}
int sol(string s){
    int i,u,v;
    u=0;
    for(i=0;i<s.size();i++){
        v=s[i]-'0';
        if(tr[u][v]==0)
        return 0;
        u=tr[u][v];
        if(f[u]==1)
        return 1;
    }
    return 0;
}

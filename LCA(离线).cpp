#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int siz=100005;
int fa[siz],vis[siz];
int ll[siz],rr[siz];
map<P,int> ans;
vector<int> G[siz],q[siz];
int get(int x){
    if(x==fa[x])
    return x;
    return fa[x]=get(fa[x]);
}
void tarjan(int u){
    int i,v;
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        tarjan(v);
        fa[v]=u;
    }
    vis[u]=1;
    for(i=0;i<q[u].size();i++){
        v=q[u][i];
        if(vis[v]==0)
        continue;
        ans[make_pair(u,v)]=get(v);
    }
}                                               //询问要存成双向  

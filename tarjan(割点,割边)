#include<bits/stdc++.h>
using namespace std;

const int siz_N=20005;
const int siz_M=100005;
struct node{
    int v,id;
};                                              //id为边的编号
vector<node> G[siz_N];
int low[siz_N],dfn[siz_N];
int rt,vis_N[siz_N],vis_M[siz_M];
void tarjan(int u,int fa){                      //注意图是否联通
    int i,v,id,tmp;
    tmp=0;
    dfn[u]=low[u]=++rt;
    for(i=0;i<G[u].size();i++){
        v=G[u][i].v;
        id=G[u][i].id;
        if(dfn[v]==0){
            tmp++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(fa!=-1&&low[v]>=dfn[u])
            vis_N[u]=1;
            if(low[v]>dfn[u])
            vis_M[id]=1;
        }
        else if(v!=fa)
        low[u]=min(low[u],dfn[v]);
    }
    if(fa==-1&&tmp>=2)
    vis_N[u]=1;
}

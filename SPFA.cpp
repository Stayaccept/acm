#include<bits/stdc++.h>
using namespace std;

const int siz=20005;
const int INF=0x3f3f3f3f;
struct node{
    int v,w;
};
vector<node> G[siz];
int d[siz],vis[siz];
void spfa(int s){
    int i,u,v,w;
    queue<int> qu;
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0,vis[s]=1;
    qu.push(s);
    while(qu.size()){
        u=qu.front();
        qu.pop();
        vis[u]=0;
        for(i=0;i<G[u].size();i++){
            v=G[u][i].v;
            w=G[u][i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(vis[v]==0){
                    vis[v]=1;
                    qu.push(v);
                }
            }
        }
    }
    return;
}

#include<bits/stdc++.h>
using namespace std;

const int siz=50005;
int tr[siz<<2];
void pushup(int rt){
    tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
void build(int l,int r,int rt){
    int mid;
    if(l==r){
        scanf("%d",&tr[rt]);
        return;
    }
    mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void change(int p,int q,int l,int r,int rt){
    int mid;
    if(l==r){
        tr[rt]+=q;
        return;
    }
    mid=(l+r)>>1;
    if(p<=mid)
    change(p,q,l,mid,rt<<1);
    else
    change(p,q,mid+1,r,rt<<1|1);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    int ans,mid;
    if(L<=l&&r<=R)
    return tr[rt];
    ans=0,mid=(l+r)>>1;
    if(L<=mid)
    ans+=query(L,R,l,mid,rt<<1);
    if(R>mid)
    ans+=query(L,R,mid+1,r,rt<<1|1);
    return ans;
}

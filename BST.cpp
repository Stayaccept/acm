#include<bits/stdc++.h>
using namespace std;

const int siz=1005;
const int INF=0x3f3f3f3f;
int rt=0;
struct node{
    int ls,rs;
    int val,cnt,siz;
}t[siz];
void add(int s,int v){
    if(rt==0){
        rt++;
        t[rt].val=v;
        t[rt].cnt=1;
        t[rt].siz=1;
        return;
    }
    t[s].siz++;
    if(t[s].val==v){
        t[s].cnt++;
        return;
    }
    if(t[s].val<v){
        if(t[s].rs!=0)
        add(t[s].rs,v);
        else{
            rt++;
            t[s].rs=rt;
            t[rt].val=v;
            t[rt].cnt=1;
            t[rt].siz=1;
        }
    }
    else{
        if(t[s].ls!=0)
        add(t[s].ls,v);
        else{
            rt++;
            t[s].ls=rt;
            t[rt].val=v;
            t[rt].cnt=1;
            t[rt].siz=1;
        }
    }
}
int GetPre(int s,int v,int ans){
    if(t[s].val>=v){
        if(t[s].ls!=0)
        return GetPre(t[s].ls,v,ans);
        else
        return ans;
    }
    else{
        if(t[s].rs==0)
        return t[s].val;
        else{
            if(t[s].cnt!=0)
            return GetPre(t[s].rs,v,t[s].val);
            else
            return GetPre(t[s].rs,v,ans);
        }
    }
}
int GetNext(int s,int v,int ans){
    if(t[s].val<=v){
        if(t[s].rs!=0)
        return GetNext(t[s].rs,v,ans);
        else
        return ans;
    }
    else{
        if(t[s].ls==0)
        return t[s].val;
        else{
            if(t[s].cnt!=0)
            return GetNext(t[s].ls,v,t[s].val);
            else
            return GetNext(t[s].ls,v,ans);
        }
    }
}
int GetValbyRank(int s,int rk){
    if(s==0)
    return INF;
    if(t[t[s].ls].siz>=rk)
    return GetValbyRank(t[s].ls,rk);
    else if(t[t[s].ls].siz+t[s].cnt>=rk)
    return t[s].val;
    else
    return GetValbyRank(t[s].rs,rk-t[t[s].ls].siz-t[s].cnt);
}
int GetRankbyVal(int s,int v){
    if(s==0)
    return INF;
    if(t[s].val==v)
    return t[t[s].ls].siz+1;
    else if(t[s].val>v)
    return GetRankbyVal(t[s].ls,v);
    else
    return GetRankbyVal(t[s].rs,v)+t[t[s].ls].siz+t[s].cnt;
}

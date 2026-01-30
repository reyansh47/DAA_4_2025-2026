#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long il;
typedef vector<int> vi;
typedef pair<int,int> pii;

int v;
vector<vector<int>> adjList;
vector<int> path;
vector<bool> vis;

bool hasEdge(int u,int v){
    for(int x:adjList[u]){
        if(x==v) return true;
    }
    return false;
}

bool solve(int u,int cnt){
    if(cnt==v){
        return hasEdge(u,path[0]);
    }

    for(int nxt:adjList[u]){
        if(!vis[nxt]){
            vis[nxt]=true;
            path[cnt]=nxt;

            if(solve(nxt,cnt+1)) return true;

            vis[nxt]=false;
        }
    }

    return false;
}

int main(){

    v=5;

    adjList={
        {1,3},
        {0,2,3,4},
        {1,4},
        {0,1,4},
        {1,2,3}
    };

    path.resize(v);
    vis.assign(v,false);

    path[0]=0;
    vis[0]=true;

    if(solve(0,1)){
        for(int i=0;i<v;i++) cout<<path[i]<<" ";
        cout<<path[0];
    }
    else cout<<"No cycle";

    return 0;
}

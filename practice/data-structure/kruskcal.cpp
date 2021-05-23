#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#include <queue>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000

typedef struct EDGE{
    int cost, from, to;
}edge;

int V, E;
vector<edge> G(0);
vector<edge> picked(0);
int par[MAX_V];
int vrank[MAX_V];

void init(int n);
int find(int x);
void unit(int x, int y);
bool same(int x, int y);

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int kruskal(){
    sort(G.begin(), G.end(), comp);
    init(V);
    int res = 0;
    rep(i, 0, G.size()-1){
        edge e = G[i];
        if(!same(e.from, e.to)){
            unit(e.from, e.to);
            res += e.cost;
            picked.push_back(e);
        }
    }    
    return res;
}


int main(){
    cin >> V >> E;

    rep(i, 0, E-1){
        int from, to, cos;
        cin >> from >> to >> cos;
        G.push_back(edge{cos, from, to});
    }
    

    
    int res = kruskal();
    cout << res << endl;

    rep(i, 0, picked.size()-1){
        edge e = picked[i];
        printf("vertex_pair:(%d, %d) cost: %d\n", e.from, e.to, e.cost);
    }
    
}

void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        vrank[i] = 0;
    }
}

int find(int x){
    if(par[x] == x) return x;
    else{
        return par[x] = find(par[x]);
    }
}

void unit(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(vrank[x] < vrank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(vrank[x] == vrank[y]) vrank[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}
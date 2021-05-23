#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stack>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define MAX_E 100

typedef pair<int, int> P; // node-id, color

int V, E;
vector<vector<int>> G(MAX_V, vector<int>(0));
vector<int> colors(MAX_V);

bool search(){
    stack<P> stk;
    stk.push(P(0, 1));
    rep(i, 0, V-1) colors[i] = 0;

    while(stk.size()){
        P p = stk.top(); stk.pop();
        int v = p.first;
        int c = p.second;

        if(colors[v]!=0){
            if(colors[v] != c) return false;
            continue;
        }

        colors[v] = c;

        rep(nv, 0, G[v].size()-1){
            stk.push(P(G[v][nv], -c));
        }
    }
    return colors[0]==1;
}

int main(){
    cin >> V >> E;
    rep(v, 0, E-1){
        int from, to;
        cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    if(search()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
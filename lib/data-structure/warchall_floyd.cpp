#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;
#define MAX_V 100
#define INF 100000

int d[MAX_V][MAX_V];
int V, E;

void warshall_floyd(){
    rep(k, 0, V-1){
        rep(i, 0, V-1){
            rep(j, 0, V-1){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void display(){
    rep(i, 0, V-1){
        rep(j, 0, V-1){
            cout << i << "->" << j << " =" << d[i][j] << endl;
        }
    }
}

int main(){
    cin >> V >> E;

    rep(i, 0, V-1){
        rep(j, 0, V-1){
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }

    rep(i, 0, E-1){
        int from, to, cos;
        cin >> from >> to >> cos;
        d[from][to] = cos;
        d[to][from] = cos;
    }

    //display();

    warshall_floyd();

    display();
}
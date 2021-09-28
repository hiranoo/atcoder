#define _GLIBCXX_DEBUG
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
#include <bits/stdc++.h>
//#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> road(n, vector<int>(0));

  rep(i, 0, m-1){
    int a, b; cin >> a >> b;
    road[a-1].push_back(b-1);
    road[b-1].push_back(a-1);
  }

  rep(i, 0, n-1){
    cout << road[i].size() << endl;
  }
  return 0;
}

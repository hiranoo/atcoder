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

vector<int> ans(51);

int search(vector<vector<int>> &children, int p){
  if(children[p].size() == 0){
    ans[p] = 1;
    return 1;
  }

  int ret = 1;
  for( int c : children[p] ){
    ret += search(children, c);
  }
  ans[p] = ret;
  return ret;
}

int main(){
  int n; cin >> n;
  vector<vector<int>> tree(n, vector<int>(0));
  rep(i, 1, n-1){
    int ret; cin >> ret;
    tree[ret].push_back(i);
  }

  int res = search(tree, 0);
  rep(i, 0, n-1) cout << ans[i] << endl;
  return 0;
}
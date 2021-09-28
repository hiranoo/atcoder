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
#include <atcoder/segtree>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using namespace atcoder;
typedef pair<int, int> pii;

const int INF = 1000000001;

int op(int a, int b){
  return max(a, b);
}

int e(){
  return -1;
}

int segf;
bool f(int v){
  return v < segf;
}

int main1();
int main2();

int main(){
  return main2();
}

int main1(){
  int n, q; cin >> n >> q;
  segtree<int, op, e> tree(n+1);
  rep(i, 0, n-1) {
    int a; cin >> a;
    tree.set(i+1, a);
  }

  rep(i, 0, q-1) {
    int t, x, v; cin >> t >> x >> v;
    if(t==1){
      tree.set(x, v);
    }
    if(t==2){
      cout << tree.prod(x, v+1) << endl;
    }
    if(t==3){
      segf = v;
      cout << tree.max_right<f>(x) << endl;
    }
  }

  return 0;
}


int main2(){
  int n, q; cin >> n >> q;
  segtree<int, op, e> tree(n+1);
  rep(i, 1, n){
    int a; cin >> a;
    tree.set(i, a);
  } 

  rep(i, 0, q-1) {
    int t, x, y; cin >> t >> x >> y;
    if(t==1){
      tree.set(x, y);
    }
    if(t==2){
      cout << tree.prod(x, y+1) << endl;
    }
    if(t==3){
      int m = tree.prod(x, n+1);
      if(m < y) cout << n+1 << endl;
      else{
        int l = x, r = n+1;
        while(r-l>1){
          int k = (l+r)/2;
          int m1 = tree.prod(l, k);
          int m2 = tree.prod(k, r);
          if(m1 >= y) r = k;
          else l = k;
        }
        cout << l << endl;
      }
    }
  }

  return 0;
}
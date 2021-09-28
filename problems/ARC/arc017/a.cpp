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
typedef pair<int, int> pii;


int main(){
  int n; cin >> n;

  bool is_prime = true;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0) {is_prime = false; break;}
  }

  if(is_prime) cout << "YES" << endl;
  else cout << "NO" << endl;
}
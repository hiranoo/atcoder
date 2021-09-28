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
#include <time.h>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> pii;

bool is_prime(int n){
  if(n == 1) return false;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0) return false;
  }
  return true;
}

int main(){
  int n; cin >> n;
  if(is_prime((n*(n+1))/2)) cout << "WANWAN" << endl;
  else cout << "BOWWOW" << endl;
}
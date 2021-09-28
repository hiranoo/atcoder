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

bool is_prime(int n){
  if(n == 1) return false;

  bool prime = true;
  for(int i = 2; i*i <= n; i++){
    if(n % i == 0){
      prime = false;
      break;
    }
  }
  return prime;
}

int main(){
  int q; cin >> q;

  map<int, int> similar;
  for(int x = 1; x <= 100000; x++){
    if(is_prime(x) && is_prime((x+1)/2)) similar[x]++;
  }

  int num = 0;
  vector<int> prime_counter(100005, 0);
  for(int i = 0; i <= 100000; i++){
    if(similar.count(i) > 0) num++;
    prime_counter[i] = num;
  }

  
  for(int query = 0; query < q; query++){
    int l, r; cin >> l >> r;
    printf("%d\n", prime_counter[r] - prime_counter[l-1]);
  }
  
}
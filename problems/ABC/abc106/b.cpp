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

/*****   素数を列挙して, vectorで返す関数 O(√n) **********************/

vector<int> make_primes(int n){
  vector<int> primes;
  vector<int> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for(int i = 2; i <= n; i++){
    if(is_prime[i]){
      primes.emplace_back(i);
      for(int j = 2*i; j <= n; j+=i){
        is_prime[j] = false;
      }
    }
  }

  return primes;  
}


int main(){
  int n; cin >> n;

  vector<int> primes = make_primes(200);
  int m = primes.size();
  int ans = 0;

  // 2 * 2 * 2
  rep(i, 1, m-1) rep(j, i+1, m-1) rep(k, j+1, m-1) {
    int ret = primes[i] * primes[j] * primes[k];
    if(ret <= n) {
      ans++;
      //cout << primes[i] << " " << primes[j] << " " << primes[k] << endl;
    }
  }
  
  // 2 * 4
  rep(i, 1, m-1) rep(j, 1, m-1) {
    if(i != j && primes[i] * pow(primes[j], 3) <= n) {
      ans++;
      //cout << primes[i] << " " << primes[j] << "^3" << endl;
    }
  }

  cout << ans << endl;
}
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
  int x; cin >> x;

  if(x == 1){
    cout << 2 << endl;
    return 0;
  }

  /*
  vector<int> is_prime(1000000, true);
  for(int i = 2; i * i <= 2*x; i++){
    for(int j = 2*i; j <= 2*x; j+=i){
      is_prime[j] = false;
    }
  }

  int n = x;
  while(true){
    if(is_prime[n]){
      cout << n << endl;
      return 0;
    }
    n++;
  }
  */

  vector<int> is_prime(1000000, true);
  vector<int> prime(0);
  for(int i = 2; i*i <= x; i++){
    if(is_prime[i]) prime.push_back(i);
    for(int j = i*2; j <= x; j+=i){
      is_prime[j] = false;
    }
  }

  while(true){
    bool flag = true;
    for(auto p : prime){
      if(x % p == 0){
        x++; 
        flag = false;
        break;
      }
    }
    if(flag){
      cout << x << endl;
      return 0;
    }
  }
}
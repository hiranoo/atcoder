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
using namespace std;
typedef pair<int, int> pii;


int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  
  if(a == b){
    cout << '=' << endl;
    return 0;
  }

  bool swap = false;
  if(a < b){
    swap = true;
    int tmp = a;
    a = b;
    b = tmp;
  }

  if(a > b){
    if(a > 0){
      if(b >= 0){
        if(!swap) cout << ">" << endl;
        else cout << "<" << endl;
        return 0;
      }else{
        if(c%2 == 1){
          if(!swap) cout << ">" << endl;
          else cout << "<" << endl;
          return 0;
        }else{
          if(a > -b){
            if(!swap) cout << ">" << endl;
            else cout << "<" << endl;
            return 0;
          }else if(a == -b){
            cout << "=" << endl;
            return 0;
          }else{
            if(!swap) cout << "<" << endl;
            else cout << ">" << endl;
            return 0;
          }
        }
      }
    }else if(a == 0){
      if(c%2 == 1){
        if(!swap) cout << ">" << endl;
        else cout << "<" << endl;
        return 0;
      }else{
        if(!swap) cout << "<" << endl;
        else cout << ">" << endl;
        return 0;
      }
    }else{
      if(c%2 == 1){
        if(!swap) cout << ">" << endl;
        else cout << "<" << endl;
        return 0;
      }else{
        if(!swap) cout << "<" << endl;
        else cout << ">" << endl;
        return 0;
      }
    }
  }

  return 0;
}

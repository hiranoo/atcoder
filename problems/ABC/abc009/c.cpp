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
using namespace std;
#define MAX_V 100
#define MAX_E 100
#define INF 100000
#define MAX_N 100005
#define INF 100000

void display(int count_S[], int count_T[]){
  rep(i, 0, 26-1){
    if(count_S[i]==0 && count_T[i]==0)continue;
    cout << (char)('a'+i) << ": " << count_S[i] << "個 in S" << endl;
    cout << (char)('a'+i) << ": " << count_T[i] << "個 in T" << endl;
  }
}

int same_num(string t, string S){
  int ret = 0;
  rep(i, 0, min(t.size(), S.size())){
    ret += t[i]==S[i]? 1: 0;
  }
  return ret;
}

int f(char c){
  return c - 'a';
}

int fl(vector<int> a, vector<int> b){
  int ret = 0;
  rep(i, 0, 26-1){
    ret += max(0, b[i] - a[i]);
  }
  return ret;
}

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;

  vector<int> a(26), b(26);
  rep(i, 0, n-1){
    a[f(s[i])]++;
  }
  b = a;

  string t(n, '?');

  rep(i, 0, n-1){
    b[f(s[i])]--; // sの文字数カウンター
    rep(j, 26){
      if(a[j]==0) continue; // まだ使える文字を小さい順に探索
      a[j]--;
      int x = fl(a, b); // diff
      x += s[i]!='a'+j? 1: 0; // 今見てる文字が最小パターンの文字と異なるかどうか
      if(x <= k){
        t[i] = 'a' + j; // まだ使える最小の文字が、制約を満たすので文字列tに加える
        if(s[i]!=t[i])k--; //　差分xの計算がすでに使った文字を考慮しないから、ここでkを減らしておく
        break;
      }
      a[j]++; // 制約を満たせなかったら、使うのをやめる
    }
  }

  cout << t << endl;
  return 0;

}
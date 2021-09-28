#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double pi = 3.141592653589793;
int inf = 1001001001;
ll INF = 1001001001001001001;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define rep(i, n) FOR(i, 0, n)
#define all(x) x.begin(), x.end()
#define pb push_back
#define pf push_front
ll MOD = 1000000007;
using P = pair<ll, ll>;
using Q = pair<ll, P>;







int main() {
    ll N;cin >> N;
    vector<ll> A(2*N);
    ll total = 0;
    rep(i, N) {
        cin >> A[i];
        A[i+N] = A[i];
        total += A[i];
    }
    ll ok = 0, ng = INF;
    while(ok+1<ng) {
        ll mid = (ok+ng)/2;
        vector<ll> Next(N, -1);
        vector<ll> Size(N, -1);
        ll right = 0;
        ll sum = 0;
        rep(left, N) {
            while (right<(2*N)&&sum<mid) {
                sum += A[right];
                right++;
            }
       
            if (sum>=mid) {
                Next[left] = right;
                Size[left] = sum;
            }
            if (right == left) right++;
            else sum -= A[left];
        
        }
        bool can = false;
        rep(i, N) {
            ll ni = Next[i];
            if (ni == -1) continue;
            if (Size[i]>=total) continue;
            ni%= N;
            ll nni = Next[ni];
            if (nni == -1) continue;
            

            if (total-Size[i]-Size[ni]>=mid) {
                can = true;
            }
        }
        if (can) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
      


    
    return 0;
}
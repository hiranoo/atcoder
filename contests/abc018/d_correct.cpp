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
using p = pair<ll, ll>;

double eps = 1e-12;



int main() {
    ll N, M, P, Q, R;cin >> N >> M >> P >> Q >> R;
    vector<ll> x(R), y(R), z(R);
    vector<p> taio[20];
    
    rep(i, R) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;y[i]--;
        taio[x[i]].pb(p(y[i], z[i]));

    }
    ll ninki[20];
    ll ans = 0;
    for (ll i = 0; i < (1LL<<N); i++) {
        ll one = __builtin_popcount(i);
        if (one!=P) continue;
        rep(j, 20) ninki[j] = 0;
        rep(j, N) {
            if (i&(1<<j)){
                for (ll k = 0; k < taio[j].size(); k++) {
                    p man = taio[j][k];
                    ll hito = man.first;
                    ll atai = man.second;
                    ninki[hito]+=atai; 

                }
                
            }
            
        }
        sort(ninki, ninki+20, greater<ll> ());
        ll koho = 0;
        

        rep(j, Q) koho += ninki[j];
        ans = max(ans, koho);
    }
    cout << ans << endl;
    return 0;
}

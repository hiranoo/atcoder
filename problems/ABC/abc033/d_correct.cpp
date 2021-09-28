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
double eps = 1e-12;




int main() {
	ll N;cin >> N;
	vector<ll> x(N), y(N);
	rep(i, N) cin >> x[i] >> y[i];
	vector<double> kakudo;
	ll eikaku = 0, chokaku = 0, donkaku = 0;
	rep(i, N) {
		kakudo.erase(all(kakudo));
		rep(j, N) {
			if (i == j) continue;
			kakudo.pb(atan2(x[j]-x[i], y[j]-y[i]));
			
		
		}
		sort(all(kakudo));
		rep(j, N-1) kakudo.pb(kakudo[j]+M_PI*2.0);
		rep(j, N-1) {
		    chokaku += upper_bound(all(kakudo), kakudo[j]+M_PI/2.0+eps)-lower_bound(all(kakudo), kakudo[j]+M_PI/2.0-eps);
		    donkaku += lower_bound(all(kakudo), kakudo[j]+M_PI+eps)-upper_bound(all(kakudo), kakudo[j]+M_PI/2.0+eps);
		}
		

	}
	cout << N*(N-1)*(N-2)/6-chokaku-donkaku << " " << chokaku << " " << donkaku << endl;
	
	return 0;
}



#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
using namespace std;

#ifdef NO_UNLOCK_IO
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
struct FastIO {
	static void scan(double &x) {
		scanf("%lf", &x);
	}
	template <class Integral>
	static void scan(Integral &x) {
		int k, m = 1;
		x = 0;
		for (;;) {
			k = getchar_unlocked();
			//if (k == '-') {
			//	m = -1;
			//	break;
			//}
			//else
			if ('0' <= k && k <= '9') {
				x = k - '0';
				break;
			}
		}
		for (;;) {
			k = getchar_unlocked();
			if (k < '0' || k > '9')
				break;

			x = x * 10 + k - '0';
		}
		//x *= m;//mul is faster than branch-misprediction penalty (maybe)
	}
	template <class Arithmetic, class... Rest>
	static void scan(Arithmetic &x, Rest&... y) {
		scan(x);
		scan(y...);
	}
	static void print(double x, char c) {
		printf("%.12f%c", x, c);
	}
	static void print(const char *x, char c) {
		printf("%s%c", x, c);
	}
	template <class Integral>
	static void print(Integral x, char c) {
		int s = 0, m = 0;
		char f[20];//Is this faster than "static char" ?
		if (x < 0) {
			m = 1;
			x = -x;
		}
		while (x) {
			f[s++] = x % 10;
			x /= 10;
		}

		if (!s)
			f[s++] = 0;

		if (m) putchar_unlocked('-');
		while (s--)
			putchar_unlocked(f[s] + '0');

		putchar_unlocked(c);
	}
	template <class Arithmetic>
	static void println(Arithmetic x) {
		print(x, '\n');
	}
};

template <typename M>
class SegTree {
	using T = typename M::element_type;
	std::vector<T> tree;
	const int n;

public:

	SegTree(const std::vector<T> &a) : n(a.size() - 1 ? 1 << (32 - __builtin_clz(a.size() - 1)) : 1) {
		int n0 = a.size();
		tree.reserve(2 * n);
		for (int i = 0; i < n0; ++i)  tree[i + n] = a[i];
		for (int i = n0; i < n; ++i)  tree[i + n] = M::id;
		for (int i = n - 1; i > 0; --i) tree[i] = M::op(tree[2 * i], tree[2 * i | 1]);
	}

	T query(int l, int r) {
		T v = M::id;
		for (int t = r - l; t >= 1; t = r - l) {
			int x = l | ((1U << 31) >> __builtin_clz(t));
			int u = x & (-x);
			int k = __builtin_ctz(x);
			v = M::op(v, tree[(n | l) >> k]);
			l += u;
		}
		return v;
	}

	void update(int i, T x) {
		int k = i + n;
		tree[k] = x;
		for (k = k >> 1; k > 0; k >>= 1) {
			tree[k] = M::op(tree[2 * k], tree[2 * k | 1]);
		}
	}
};

struct doubleAffineMonoid {
	using element_type = std::pair<double, double>;
	static element_type op(element_type const& x, element_type const& y) {
		return element_type(x.first * y.first, y.first * x.second + y.second);
	}
	static const element_type id;
};
const doubleAffineMonoid::element_type doubleAffineMonoid::id = doubleAffineMonoid::element_type(1.0, 0.0);

using Monoid = doubleAffineMonoid;

struct Q {
	unsigned long long int p;
	double a;
	double b;
	Q(unsigned long long int p, double a, double b) :p(p), a(a), b(b) {}
};

bool compp(const Q &l, const Q &r) {
	return l.p < r.p;
}


std::vector<Q> queries;

int main() {
	uint64_t n;
	uint32_t m;
	FastIO::scan(n, m);
	queries.reserve(m);
	std::vector<uint64_t>mmm(m);
	for (uint32_t i = 0; i < m; i++) {
		uint64_t p;
		double a, b;
		FastIO::scan(p, a, b);
		mmm[i] = (p << 17) + i;
		queries.emplace_back(Q(p, a, b));
	}

	std::sort(mmm.begin(), mmm.end());
	uint64_t tmp = -1;
	int idx = -1;
	for (uint32_t i = 0; i<m; i++) {
		if ((mmm[i] >> 17) != tmp) {
			tmp = mmm[i] >> 17;
			++idx;
		}
		queries[mmm[i] & ((uint64_t(1) << 17) - 1)].p = idx;
	}

	std::vector<Monoid::element_type> vec(m, Monoid::id);
	SegTree<Monoid> segtree(vec);

	double vmax, vmin;
	vmax = vmin = 1.0;
	for (int i = 0; i<m; i++) {
		segtree.update(queries[i].p, Monoid::element_type(queries[i].a, queries[i].b));
		Monoid::element_type x = segtree.query(0, m);
		double v = x.first + x.second;
		vmax = std::max(vmax, v);
		vmin = std::min(vmin, v);
	}

	std::printf("%lf\n%lf\n", vmin, vmax);
	return 0;
}
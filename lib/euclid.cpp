// ap + bq = gcd(a, b)
pll extGCD(ll a, ll b) {
    ll p11 = 1, p12 = 0, p21 = 0, p22 = 1;
    while (b) {
        ll s = a / b;
        // matrix{{0, 1}, {1, -s}}
        a -= s * b;
        swap(a, b);
 
        p11 -= s * p21;
        p12 -= s * p22;
        swap(p11, p21);
        swap(p12, p22);
    }
    return {p11, p12};
}
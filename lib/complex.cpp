struct P {
  double a, b;
  P(){}
  P(double a, double b) : a(a), b(b) {}
  P operator* (const P &p) {
    return P(a*p.a-b*p.b, a*p.b+b*p.a);
  }
  P operator+ (const P &p) {
    return P(a+p.a, b+p.b);
  }
  P operator- (const P &p) {
    return P(a-p.a, b-p.b);
  }
  P operator/ (int d) {
    return P(a/d, b/d);
  }
};
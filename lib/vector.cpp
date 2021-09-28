struct P {
  int x, y;
  P() {
    x = 0; y = 0;
  }
  P(int xx, int yy) : x(xx), y(yy) {}
  bool operator< (const P &p) {
    if(x == p.x) return y < p.y;
    return x < p.x;
  }
  bool operator== (const P &p) {
    return x==p.x && y==p.y;
  }
  P operator+ (const P &p) {
    return P(x+p.x, y+p.y);
  }
  P operator- (const P &p) {
    return P(x-p.x, y-p.y);
  }
};
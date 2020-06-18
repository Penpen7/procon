#include <bits/stdc++.h>
#define repz(i, z, n) for (decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for (decltype(n) i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(ALL(v)))
#define MIN(v) (*min_element(ALL(v)))
#define INF 1000000000000 //1E+12

// 略
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define READ cin >>
#define PRINT cout <<
#define PYES cout << "Yes" << endl;
#define POK cout << "OK" << endl;
#define PNO cout << "No" << endl;
#define PNG cout << "NG" << endl;

using namespace std;

// デバッグ用
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cout << H << " ";
  debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// typedef
typedef long long ll;
typedef unsigned long long ul;

// const
// 円周率
const double pi = M_PI;
// mod用
// 1E+9 +7
const ll mod = (int)1e+9 + 7;
// 1s間で可能なループ回数2E+8回
// int        最大値2147483647         〜2E+9
// long long  最大値9223372036854775807〜9E+18
// 総和accumulate
// 単純リストvector<type> push_back
// 連想配列map<key,value> insert,
// 集合set<type>
// pair キーとバリューを格納 firstとsecondでアクセス
// 小数点指定 cout << fixed << setprecision(15) << endl;
// to_string<->stoi
// stoll(longlong)
// stod(double)
// deep copy v1->v2 copy(v1.begin(), v1.end(), back_inserter(v2) );
// 大文字65-90(-32)
// 小文字97-122(+32)
struct mint
{
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
mint choose(ll n,ll a){
  mint x=1;
  mint y=1;
  ll i=0;
  while(i<a){
    x*=n-i;
    y*=i+1;
    i++;
  }
  return x/y;
}

int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll x,y; cin >> x >> y;
  ll a=2*x-y, b=-x+2*y;
  if(a%3!=0 or b%3!=0 or a<0 or b<0){
    cout << 0 << endl;
    return 0;
  }
  a/=3; b/=3;
  cout << choose(a+b,a) << endl;
  return 0;
}

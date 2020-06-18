#include <bits/stdc++.h>
#define repz(i, z, n) for (decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for (decltype(n) i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(all(v)))
#define MIN(v) (*min_element(all(v)))
#define INF 1000000000000 //1E+12

// 略
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define READ cin >>
#define PRINT cout <<

using namespace std;
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cout << H << " ";
  debug_out(T...);
}
// 効率的に累乗を求める
// O(log n)

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef unsigned long long ul;
typedef pair<ll, ll> P;
// 1s間で可能なループ回数2E+8回
// intの最大値2147483647~2E+9
// long longの最大値9223372036854775807〜9E+18
// 総和accumulate
// 単純リストvector<> push_back
// 連想配列map<key,value> insert,
// pair キーとバリューを格納 firstとsecondでアクセス
// 小数点指定 cout << fixed << setprecision(15) << endl;
// to_string<->stoi
// stoll(longlong)
// stod(double)
// 大文字65-90(-32)
// 小文字97-122(+32)
// 1E+9 +7
const ll mod = 1000000000 + 7;
ll e_gcd(ll a, ll b)
{
  return b != 0 ? e_gcd(b, a % b) : a;
}
ll modpow(ll a, ll n)
{
  ll res = 1;
  while (n > 0) {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  map<P, P> d;
  rep(i, n)
  {
    bool f_or_s = false;
    ll a, b;
    cin >> a >> b;
    // debug_out(a,b);
    if ((a > 0 and b > 0) or (a < 0 and b < 0)) {
      f_or_s = false;
      a = abs(a);
      b = abs(b);
      ll gcd = e_gcd(a, b);
      a /= gcd;
      b /= gcd;
    } else if ((a > 0 and b < 0) or (a < 0 and b > 0)) {
      f_or_s = true;
      swap(a, b);
      a = abs(a);
      b = abs(b);
      ll gcd = e_gcd(a, b);
      a /= gcd;
      b /= gcd;
    } else if (a == 0 and b == 0) {
      f_or_s = false;
    } else {
      f_or_s = a > 0;
      a = 1;
      b = 0;
    }
    P p = P(a, b);
    if (d.count(p) == 0)
      d[p] = P(0, 0);
    if (f_or_s)
      d[p].F++;
    else
      d[p].S++;
  }
  ll res = 1;
  ll z = 0;
  for (pair<P, P> i : d) {
    if (i.F.F == 0 and i.F.S == 0) {
      z = i.S.F + i.S.S;
      continue;
    }
    res *= modpow(2, i.S.F) + modpow(2, i.S.S) - 1;
    res %= mod;
    // debug_out(res,mod);
    // debug_out(i.F.F, i.F.S, i.S.F, i.S.S);
  }
  cout << (res + z + mod - 1) % mod << endl;

  return 0;
}

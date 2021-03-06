#include <bits/stdc++.h>
#define repz(i, z, n) for (decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for (decltype(n) i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(ALL(v)))
#define MIN(v) (*min_element(ALL(v)))
#define INF 1e+18 //1E+12

// 略
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define READ cin >>
#define PRINT cout <<

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

typedef long long ll;
typedef unsigned long long ul;

// const
// 円周率
const double pi = M_PI;
// mod用
// 1E+9 +7
const ll mod = (ll)1e+9 + 7;
// 1s間で可能なループ回数2E+8回
// ll        最大値2147483647         〜2E+9
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
vector<ll> am, ap;
ll msize, psize;
ll zero = 0;
ll k;
bool judge_m(ll mid)
{
  ll sum = 0;
  for (ll j : ap) {
    ll d = (mid - j + 1) / j;
    sum += upper_bound(ALL(am), d) - am.begin();
  }
  debug("mid,sum", mid, sum);
  return sum >= k;
}
ll judge_p(ll mid)
{
  ll sum = 0;
  rep(i, psize)
  {
    ll d = mid / ap[i];
    ll temp = upper_bound(ALL(ap), d) - ap.begin();
    if (i < temp)
      temp--;
    sum += temp;
  }
  rep(i, msize)
  {
    ll d = mid / am[i];
    ll temp = upper_bound(ALL(am), d) - am.begin();
    temp += msize;
    if (i < temp)
      temp--;
    sum += temp;
  }
  sum /= 2;
  debug(sum,mid,k);
  return sum >= k;
}

int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n;
  cin >> n >> k;

  rep(i, n)
  {
    ll temp;
    cin >> temp;
    if (temp < 0) {
      am.push_back(temp);
      msize++;
    }
    if (temp > 0) {
      ap.push_back(temp);
      psize++;
    }
    if (temp == 0)
      zero++;
  }
  // - or 0 or +を判断する
  ll product_m = msize * psize;
  ll product_p = msize * (msize - 1) / 2 + psize * (psize - 1) / 2;
  ll product_z = n * (n - 1) / 2 - product_m - product_p;

  if (k <= product_m) {
    sort(ALL(am));
    sort(ALL(ap));
    ll l = -INF - 1;
    ll r = -1;
    while (r - l > 1) {
      ll mid = (l + r) / 2;
      if (judge_m(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << r << endl;
    return 0;
  } else if (k <= product_m + product_z) {
    cout << 0 << endl;
    return 0;
  } else {
    k -= (product_m + product_z);
//    rep(i,msize) am[i] = abs(am[i]);
    sort(ALL(am));
    sort(ALL(ap));
    ll l = -1;
    ll r = 1e18;
    while (r - l > 1) {
      ll mid = (l + r) / 2;
      if (judge_p(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << r << endl;
    return 0;
  }
  return 0;
}

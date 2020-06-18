#include <bits/stdc++.h>
#define repz(i, z, n) for (decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for (decltype(n) i = 0; i < (n); i++)

#define REPZ(i, z, n) for (decltype(n) i = (z); i <= (n); i++)
#define REP(i, n) for (decltype(n) i = 0; i <= (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(ALL(v)))
#define MIN(v) (*min_element(ALL(v)))
#define INF 1000000000000  // 1E+12

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
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

// typedef
typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

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
void dfs(ll v, ll bef, vector<ll> &res, vector<set<ll>> &a, vector<ll> &r,
         vector<bool> &ischecked) {
  ischecked[v] = true;
  bef = bef + r[v];
  res[v] += bef;

  if (SIZE(a[v]) == 0) return;

  for (ll i : a[v]) {
    if (!ischecked[i]) dfs(i, bef, res, a, r, ischecked);
  }
}

int main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n, q;
  cin >> n >> q;
  vector<set<ll>> a(n, set<ll>());
  rep(i, n - 1) {
    ll tempa, tempb;
    cin >> tempa >> tempb;
    tempa--;
    tempb--;
    a[tempa].insert(tempb);
    a[tempb].insert(tempa);
  }
  vector<ll> r(n, 0);
  rep(i, q) {
    ll temp, tempx;
    cin >> temp >> tempx;
    temp--;
    if (r[temp] == 0)
      r[temp] = tempx;
    else
      r[temp] += tempx;
  }
  vector<ll> res(n, 0);
  vector<bool> ischecked(n, false);
  dfs(0, 0, res, a, r, ischecked);
  rep(i, n) {
    cout << res[i];
    if (i != n - 1) cout << " ";
  }
  cout << endl;

  return 0;
}

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
typedef pair<ll, ll> pl;

// const
// 円周率
const ld pi = acos(-1);
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
//  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
//  ba;
int main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ll xsize, ysize;
  cin >> xsize >> ysize;
  swap(xsize, ysize);
  vector<vector<char>> a(xsize, vector<char>(ysize));
  vector<vector<ll>> d(xsize, vector<ll>(ysize));
  vector<vector<ll>> e(xsize, vector<ll>(ysize));
  rep(y, ysize) {
    rep(x, xsize) { cin >> a[x][y]; }
  }
  rep(y, ysize) {
    ll sum = 0;
    rep(x, xsize) {
      if (a[x][y] == '.')
        sum++;
      else {
        repz(i, x - sum, x) d[i][y] = sum;
        sum = 0;
      }
    }
    repz(i, xsize - sum, xsize) d[i][y] = sum;
  }
  rep(x, xsize) {
    ll sum = 0;
    rep(y, ysize) {
      if (a[x][y] == '.')
        sum++;
      else {
        repz(i, y - sum, y) e[x][i] = sum;
        sum = 0;
      }
    }
    repz(i, ysize - sum, ysize) e[x][i] = sum;
  }
  ll res = 0;
  rep(y, ysize) {
    rep(x, xsize) {
      if (a[x][y] == '#') continue;
      chmax(res, d[x][y] + e[x][y]);
    }
  }
  cout << res - 1 << endl;

  return 0;
}

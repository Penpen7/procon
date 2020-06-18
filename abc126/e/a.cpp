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

struct UnionFind {
  vector<ll> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<ll> siz;

  UnionFind(ll N) : par(N), siz(N) {  //最初は全てが根であるとして初期化
    for (ll i = 0; i < N; i++) {
      par[i] = i;
      siz[i] = 1;
    }
  }

  ll root(ll x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(ll x, ll y) {  // xとyの木を併合
    ll rx = root(x);         // xの根をrx
    ll ry = root(y);         // yの根をry
    if (rx == ry) {
      return;  // xとyの根が同じ(=同じ木にある)時はそのまま
    } else {
      if (size(rx) < size(ry)) swap(rx, ry);
      par[ry] =
          rx;  // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
      siz[rx] += siz[ry];  // 大きさを付け換える
    }
  }

  bool same(ll x, ll y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }
  ll size(ll x) { return siz[root(x)]; }
};
int main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n,m; cin >> n >> m;
  UnionFind u(n);
  rep(i,m){
    ll x, y, z; cin >> x>> y >>z;
    x--; y--;
    u.unite(x,y);
  }
  set<ll> parent;
  rep(i,n){
    parent.insert(u.root(i));
  }
  cout << SIZE(parent) << endl;
  return 0;
}

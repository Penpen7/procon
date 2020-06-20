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
#define PYES cout << "YES" << endl
#define pyes cout << "Yes" << endl
#define POK cout << "OK" << endl
#define PNO cout << "NO" << endl
#define pno cout << "No" << endl
#define PNG cout << "NG" << endl
#define ret return 0

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
//  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
//  ba;
struct tsort {
  int V;
  vector<vector<int>> G;
  vector<int> deg, res;
  tsort(int node_size) : V(node_size), G(V), deg(V, 0) {}
  void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
  }
  bool sort() {
    queue<int> que;
    for (int i = 0; i < V; i++) {
      if (deg[i] == 0) {
        que.push(i);
      }
    }
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      res.push_back(p);
      for (int v : G[p]) {
        if (--deg[v] == 0) {
          que.push(v);
        }
      }
    }
    return (*max_element(deg.begin(), deg.end()) == 0);
  }
};
signed main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  tsort t(n);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
  }
  t.sort();

  vector<int> dp(n, 0);
  for (int i : t.res) {
    for (int to : t.G[i]) {
      chmax(dp[to], dp[i] + 1);
    }
  }
  cout << MAX(dp) << endl;
  ret;
}

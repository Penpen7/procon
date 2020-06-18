#include <bits/stdc++.h>
#define repz(i, z, n) for (decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for (decltype(n) i = 0; i < (n); i++)
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
typedef pair<int, int> P;
vector<vector<char>> a;
vector<vector<bool>> isvisited;
ll xsize, ysize;
ll gx, gy;
ll bfs(int sx, int sy) {
  int dx[] = {1, 0, -1, 1, -1, 0};
  int dy[] = {1, 1, 1, 0, 0, -1};
  ll res = INF;
  P s = {sx, sy};
  queue<P> q;
  vector<vector<ll>> d(xsize, vector<ll>(ysize, -1));
  d[sx][sy] = 0;
  q.push(s);
  while (!q.empty()) {
    // rep(y, ysize) {
    //   rep(x, xsize) { cout << d[x][y]; }
    //   cout << endl;
    // }
    P p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    rep(i, 6) {
      debug(dx[i], dy[i]);
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 or ny < 0 or nx >= xsize or ny >= ysize) continue;
      if (a[nx][ny] == '#') continue;
      if (d[nx][ny] != -1) continue;
      d[nx][ny] = d[x][y] + 1;
      if (nx == gx and ny == gy) {
        return d[nx][ny];
      }
      q.push({nx, ny});
    }
  }
  return INF;
}
int main() {
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  vector<P> s;
  xsize = 501;
  ysize = 501;
  a = vector<vector<char>>(xsize, vector<char>(ysize, '.'));
  isvisited = vector<vector<bool>>(xsize, vector<bool>(ysize, false));
  int n;
  cin >> n >> gx >> gy;
  gx += xsize / 2;
  gy += ysize / 2;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    x += xsize / 2;
    y += ysize / 2;
    a[x][y] = '#';
  }
  // rep(y, ysize) {
  //   rep(x, xsize) { cout << a[x][y]; }
  //   cout << endl;
  // }
  ll res = bfs(xsize / 2, ysize / 2);
  if (res == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;

  return 0;
}

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
typedef pair<int, int> P;
struct L {
  int a, b, c;
  L(int a = 0, int b = 0, int c = 0)
      : a(a)
      , b(b)
      , c(c)
  {
  }
};
int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<L> xline, yline;
  map<int, int> mx, my;
  mx[0] = 0;
  my[0] = 0;
  rep(i, n)
  {
    int a, b, c;
    cin >> a >> b >> c;
    mx[a] = 0;
    mx[b] = 0;
    my[c] = 0;
    xline.emplace_back(a, b, c);
  }
  rep(i, m)
  {
    int a, b, c;
    cin >> c >> a >> b;
    my[a] = 0;
    my[b] = 0;
    mx[c] = 0;
    yline.emplace_back(a, b, c);
  }
  vector<int> xs, ys;
  for (auto& i : mx) {
    i.second = SIZE(xs);
    xs.push_back(i.first);
  }
  for (auto& i : my) {
    i.second = SIZE(ys);
    ys.push_back(i.first);
  }
  int xsize = 2 * SIZE(xs);
  int ysize = 2 * SIZE(ys);

  vector<vector<int>> d(xsize, vector<int>(ysize, 0));

  for (L i : xline) {
    int a = mx[i.a] * 2;
    int b = mx[i.b] * 2;
    int c = my[i.c] * 2;
    for (int x = a; x <= b; x++)
      d[x][c] = -1;
  }
  for (L i : yline) {
    int a = my[i.a] * 2;
    int b = my[i.b] * 2;
    int c = mx[i.c] * 2;
    for (int y = a; y <= b; y++)
      d[c][y] = -1;
  }
  queue<P> q;
  int sx = mx[0] * 2, sy = my[0] * 2;
  int dx[] = { -1, 0, 1, 0 };
  int dy[] = { 0, 1, 0, -1 };
  d[sx][sy] = 1;
  // rep(x, xsize){
  //   rep(y,ysize){
  //     cout << d[x][y];
  //   }
  //   cout << endl;
  // }
  q.emplace(sx, sy);
  while (SIZE(q) > 0) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    rep(v, 4)
    {
      int nx = x + dx[v];
      int ny = y + dy[v];
      if (nx < 0 or nx >= xsize or ny < 0 or ny >= ysize)
        continue;
      if (d[nx][ny] != 0)
        continue;
      d[nx][ny] = d[x][y];
      q.emplace(nx, ny);
    }
  }
  ll ans = 0;
  rep(x, xsize)
  {
    rep(y, ysize)
    {
      if (d[x][y] != 1)
        continue;
      if (x == 0 or x == xsize - 1 or y == 0 or y == ysize - 1) {
        cout << "INF" << endl;
        return 0;
      }
      if (x % 2 == 0 or y % 2 == 0)
        continue;
      ll sx = xs[x / 2 + 1] - xs[x / 2];
      ll sy = ys[y / 2 + 1] - ys[y / 2];
      ans += sx * sy;
    }
  }
  cout << ans << endl;

  return 0;
}

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
typedef pair<int, int> P;
vector<vector<char>> a;
int xsize, ysize;
int bfs(int sx, int sy)
{
  int dx[] = { -1, 0, 1, 0 };
  int dy[] = { 0, 1, 0, -1 };
  int res = -1;
  P s = { sx, sy };
  queue<P> q;
  vector<vector<int>> d(xsize, vector<int>(ysize, -1));
  d[sx][sy] = 0;
  q.push(s);
  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    rep(i, 4)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 or ny < 0 or nx >= xsize or ny >= ysize)
        continue;
      if (a[nx][ny] == '#')
        continue;
      if (d[nx][ny] != -1)
        continue;
      d[nx][ny] = d[x][y] + 1;
      res = max(d[nx][ny], res);
      q.push({ nx, ny });
    }
  }
  return res;
}
int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> ysize >> xsize;
  vector<P> s;
  a = vector<vector<char>>(xsize, vector<char>(ysize));
  rep(y, ysize)
  {
    rep(x, xsize)
    {
      char temp; cin >> a[x][y];
      if (a[x][y] == '.')
        s.push_back({ x, y });
    }
  }
  int res = -1;
  for (P p : s) {
    res = max(res, bfs(p.first, p.second));
  }
  cout << res << endl;

  return 0;
}

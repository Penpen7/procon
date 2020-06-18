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
int solve(vector<char> c) {
  int res = 0;
  bool p = false;
  rep(i, SIZE(c)) {
    if (c[i] == 'D') {
      res += 1;
      if (p) res += 1;
      p = false;
    }
    p = c[i] == 'P';
  }
  return res;
}
vector<char> cres;
ll res2 = -1;
void dfs(int d, vector<char> c) {
  if (d == SIZE(c)) {
    int res = solve(c);
    if (res >= res2) {
      cres = c;
      res2 = res;
      debug(res);
    }
    return;
  }
  if (c[d] == '?') {
    c[d] = 'P';
    dfs(d + 1, c);
    c[d] = 'D';
    dfs(d + 1, c);
  } else {
    dfs(d + 1, c);
  }
}

int main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  vector<char> t;
  string s;
  cin >> s;
  rep(i, SIZE(s)) { t.push_back(s[i]); }
  // dfs(0, t);
  for (char i : t) {
    if (i == '?')
      cout << 'D';
    else
      cout << i;
  }
  cout << endl;

  return 0;
}

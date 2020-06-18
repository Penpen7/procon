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
int tate_sum(int l, int r, vector<string> s) {
  vector<int> tate(3, 0);
  rep(x, 3) {
    rep(y, 5) { tate[x] += s[y][l + x] == '#'; }
  }
  int a = tate[0];
  int b = tate[1];
  int c = tate[2];
  debug(a,b,c);
  if (a == 5 and b == 2 and c == 5) return 0;
  if (a == 2 and b == 5 and c == 1) return 1;
  if (a == 3 and b == 3 and c == 5) return 3;
  if (a == 3 and b == 1 and c == 5) return 4;
  if (a == 5 and b == 3 and c == 4) return 6;
  if (a == 1 and b == 1 and c == 5) return 7;
  if (a == 5 and b == 3 and c == 5) return 8;
  if (a == 4 and b == 3 and c == 5) return 9;
  if (s[1][l]=='.') return 2;
  return 5;
}
int main() {
  // faster
  // C言語流の入出力は使用できない
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(5);
  rep(i, 5) cin >> s[i];
  rep(i, n) {
    int l = 4 * i + 1;
    int r = 4 * i + 4;
    cout << tate_sum(l, r, s);
  }
  return 0;
}

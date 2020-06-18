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
//-- 小文字97-122(+32)
struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> _size;

  UnionFind(int N)
      : par(N), _size(N)
  { //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++){
      par[i] = i;
      _size[i] = 1;
    }
  }

  int root(int x)
  { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y)
  {                   // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry)
      return;     //xとyの根が同じ(=同じ木にある)時はそのまま
    if (size(rx) < size(ry)) swap(rx,ry);
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    siz[rx]+= siz[ry];
  }

  bool same(int x, int y)
  { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
  int size(int x) {
    return _size[root(x)];
  }
};
int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  UnionFind fav(n), block(n);
  vector<int> fav_par(n, 0), block_par(n, 0);
  vector<int> direct_connect(n, 0);
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    fav.unite(a, b);
    direct_connect[a]++;
    direct_connect[b]++;
  }
  rep(i, k)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    block.unite(a, b);
    direct_connect[a]++;
    direct_connect[b]++;
  }
  rep(i, n)
  {
    fav_par[fav.root(i)]++;
    block_par[block.root(i)]++;
  }
  for(auto i:fav.par){
    debug(i);
  }
  for(auto i:block.par){
    debug(i);
  }
  rep(i, n)
  {
    debug("par",fav.par[i], block.par[i], fav_par[fav.par[i]], block_par[block.par[i]], direct_connect[i]);
    cout << fav_par[fav.root(i)]-1 + block_par[block.root(i)]-1 - direct_connect[n] - 1 << endl;
  }
  return 0;
}

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

int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n; cin >> n;

  int d=1;
  vector<vector<int>> lr(10, vector<int>(10,0));
  bool isend = false;
  // i 桁数
  // l 最高位の桁
  // k 実際の値
  // nになるか桁数を満足するまで、計算を行う
  rep(i,6){
    repz(l,1,10){
      repz(k,l*d,(l+1)*d){
        if(k>n){
          isend = true;
          break;
        }
        int r = k%10;
        lr[l][r]++;
      }
      if(isend) break;
    }
    if(isend) break;
    d*=10;
  }

  ll res=0;
  rep(r,10){
    rep(l,10){
      res+=lr[r][l]*lr[l][r];
    }
  }
  cout << res << endl;

  return 0;
}

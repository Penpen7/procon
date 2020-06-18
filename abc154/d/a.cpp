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

int main()
{
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll n,k;cin >> n >> k;
  vector<ll> p(n,0);
  rep(i,n){
    cin >> p[i];
  }
  ll res = -1;
  if(k==1){
    res = MAX(p);
  }else{
    repz(i,1,n){
      p[i]=p[i-1]+p[i];
      debug(p[i]);
    }
    if(k==n){
      res=p[n-1];
    }else{
      for(ll i=0;i+k<n;i++){
        res = max(p[i+k]-p[i], res);
      }
    }
  }

  cout << fixed << setprecision(15) << (double)(res+k)*0.5 << endl;
  return 0;
}

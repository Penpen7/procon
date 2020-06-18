#include <bits/stdc++.h>
#define reoz(i, z, n) for(decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for(decltype(n) i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(v) ((ll)(v).size())
#define MAX(v) (*max_element(all(v)))
#define MIN(v) (*min_element(all(v)))
#define INF 1000000000000 //1E+12
#define MOD 1000000007    //合同式の法

// 略
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define READ cin >>
#define PRINT cout <<

using namespace std;
typedef long long ll;
typedef unsigned long long ul;
// 1s間で可能なループ回数2E+8回
// intの最大値2147483647~2E+9
// long longの最大値9223372036854775807〜9E+18
// 総和accumulate
// 単純リストvector<> push_back
// 連想配列map<key,value> insert,
// pair キーとバリューを格納 firstとsecondでアクセス
// 小数点指定 setprecision()
// to_string<->stoi
// stoll(longlong)
// stod(double)
// 大文字65-90(-32)
// 小文字97-122(+32)
// 1E+9 +7
const ll mod = 1000000000+7;
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a,b,h,m; cin >> a >> b >> h >> m;
  double angle=30*h+0.5*m-6*m;
  //cout << angle << endl;
  //cout << cos(double(angle)/180.0/3.141592653589793238) << endl;
  
  double res = sqrt(double(a)*double(a)+double(b)*double(b)-2.0*double(a)*double(b)*cos(double(angle)/180.0*3.141592653589793238));
  
  cout << fixed << setprecision(20) << res << endl;
  return 0;
}

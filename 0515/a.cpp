#include <bits/stdc++.h>
#define REPZ(i, z, n) for(decltype(n) i = (z); i < (n); i++)
#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
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
int n,m,q;
int resmax=0;
  vector<int> a,b,c,d;
template<typename T> bool chmax(T &m, const T q) {
  if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) {
  if (m > q) {m = q; return true;} else return false; }
void dfs(vector<int> A) {
    // 数列の長さが N に達したら打ち切り
    if (A.size() == n+1) {
      int res=0;
        REP(i,q){
          if(A[b[i]]-A[a[i]]==c[i]) res+=d[i];
        }
        resmax = max(res, resmax);
        // 処理
        return;
    }

    A.push_back(A.back());
    while(A.back()<=m){
      dfs(A);
      A.back()++;
    }
}
using namespace std;
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m >> q;
  a=b=c=d = vector<int>(q);
  REP(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  dfs(vector<int>(1,1)); 
  cout << resmax << endl;
  return 0;
}

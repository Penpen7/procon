#include <bits/stdc++.h>
#define repz(i, z, n) for(decltype(n) i = (z); i < (n); i++)
#define rep(i, n) for(decltype(n) i = 0; i < (n); i++)
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
void debug_out(){ cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T){
  cout << H << " ";
  debug_out(T...);
}

#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
typedef pair<int,int> P;

typedef long long ll;
typedef unsigned long long ul;
// 1s間で可能なループ回数2E+8回
// intの最大値2147483647~2E+9
// long longの最大値9223372036854775807〜9E+18
// 総和accumulate
// 単純リストvector<> push_back
// 連想配列map<key,value> insert,
// pair キーとバリューを格納 firstとsecondでアクセス
// 小数点指定 cout << fixed << setprecision(15) << endl;
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
  map<int,P> A;
  vector<vector<bool>> isused(3,vector<bool>(3));
  
  rep(i,3){
    rep(j,3){
      int temp; cin >> temp;
      A[temp]=MP(j,i);
    }
  }
  int n; cin >> n;
  rep(i, n){
    int temp; cin >> temp;
    if(A.count(temp)>0) isused[A[temp].F][A[temp].S] = true;
  }
  // rep(i,3){
  //   rep(j,3){
  //     cout << isused[j][i];
  //   }
  //   cout << endl;
  // }
  bool isbreak = false;
  rep(i,3){
    isbreak = isbreak or (isused[0][i] and isused[1][i] and isused[2][i]);
    isbreak = isbreak or (isused[i][0] and isused[i][1] and isused[i][2]);
    isbreak = isbreak or (isused[0][0] and isused[1][1] and isused[2][2]);
    isbreak = isbreak or (isused[0][2] and isused[1][1] and isused[2][0]);
  }
  
  if(isbreak) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

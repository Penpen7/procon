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
bool ispalindrome(string s){
  rep(i, SIZE(s)/2){
    if(s[i]!=s[SIZE(s)-1-i]) return false;
  }
  return true;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  string s; cin >> s;
  int n = SIZE(s);
  string first_part=s.substr(0, (n-1)/2);
  string second_part=s.substr((n+3)/2-1, n+1-(n+3)/2);
  // debug_out(first_part);
  // debug_out(second_part);
  if(ispalindrome(s) and ispalindrome(first_part) and ispalindrome(second_part)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

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
// for(string i:s) cout << i << endl;
using namespace std;
void dfs(){ 
  return;
}
bool check(vector<pair<int,int>> c){
  int h=0;
  for(pair<int,int> i:c){
    int b=h+i.first;
    if(b<0) return false;
    h+=i.second;
  }
  return true;
}

int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; cin >> n;
  vector<string> s(n); REP(i,n) cin >> s[i];
  vector<pair<int,int>> mxminp,mxminm;

  int h=0;
  for(string i:s){
    int sum=0;
    int mins_temp=0;
    for(char k:i){
      if(k=='(') sum++;  
      else sum--;
      mins_temp=min(sum,mins_temp);
    }
    if(sum>0){
      mxminp.PB(MP(mins_temp, sum));
    }else{
 //     maxs_temp=max(maxs_temp-mins_temp,-maxs_temp);
 //     mins_temp=min(maxs_temp-mins_temp,-maxs_temp);

      mxminm.PB(MP(mins_temp-sum, -sum));
    }
    h+=sum;
  }
  sort(mxminm.rbegin(), mxminm.rend());
  sort(mxminp.rbegin(), mxminp.rend());
    //for(pair<int,int> i:mxminm) cout << i.first << " " <<  i.second << endl;
   //for(pair<int,int> i:mxminp) cout << i.first << " " <<  i.second << endl;
  if(h==0 and check(mxminp) and check(mxminm)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

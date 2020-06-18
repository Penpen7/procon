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
using namespace std;
typedef queue<pair<int,int>> qii;
qii q;
pair<int,int> s,g;
vector<vector<char>> a;
int r,c;

//void displayd(){
//  REP(k, r){
//    REP(i, c){
//      cout << a[i][k];
//    }
//    cout << "\n";
//  }
//   
//}
ll dfs(){ 
  vector<vector<ll>> d(c, vector<ll>(r));
  REP(i,c){
    REP(k,r){
      d[i][k]=INF;
    }
  }
  d[s.F][s.S]=0;
  q.push(s);
  
  while(SIZE(q)>0){
//    displayd();
    pair<int,int> p=q.front(); q.pop(); 
    if(p.F==g.F and p.S==g.S) return d[p.F][p.S];

    REPZ(i, -1, 2){
      REPZ(k, -1,2){
        int x=p.F+i;
        int y=p.S+k;
        if((i==k)or(i==-k)) continue;
        if(0<=x and x<c and 0<=y and y<c and a[x][y]!='#' and d[x][y]==INF){
          q.push(MP(x,y));
          d[x][y]=d[p.F][p.S]+1;
        }
      }
    }
  }
  return INF;
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> r >> c;
  int sx,sy; cin >> sy >> sx;
  int gx,gy; cin >> gy >> gx;
  s = MP(sx-1,sy-1);
  g = MP(gx-1,gy-1);
  a=vector<vector<char>>(c,vector<char>(r));
  REP(k, r){
    REP(i, c){
      char temp;
      cin >> temp;
      a[i][k]=temp;
    }
  }
  //displayd();
  ll res = dfs();
  if(res!=INF) cout << dfs() << endl; 
  return 0;
}

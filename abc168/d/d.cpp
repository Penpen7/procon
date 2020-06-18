#include <bits/stdc++.h>
#define repz(i, z, n) for(decltype(n) i = (z); i < (n); i++)
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
typedef pair<int,int> P;
const ll mod = 1000000000+7;
struct edge{ll to, cost;};

// s:start, d:distance, g: hen, prev asi
void shortest_path(int s,vector<ll> &d, vector<vector<edge>> &G,vector<ll> &prev){
  priority_queue<P, vector<P>,greater<P>> que;

  d=vector<ll>(SIZE(d),INF);
  prev = vector<ll>(SIZE(d), INF);
  d[s]=0;
  que.push(P(0,s));

  while(!que.empty()) {
    P p = que.top(); que.pop();
    // cout << p.F << p.S << endl;
    int v = p.second;
    if(d[v]<p.first) continue;
    for(edge e:G[v]){
      // cout << e.to << "<-"<< v << endl;
      // cout << d[e.to] << d[v] << e.cost << endl;
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to],e.to));
        prev[e.to] = v;
      }
    }
    // cout << d[0] << d[1] << d[2] << d[3] << endl;
  }
}
int main(){
  // faster
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<ll> d(n);
  vector<vector<edge>> G(n, vector<edge>(0));
  vector<ll> prev;

  rep(i,m){
    int a,b;  cin >> a >> b;
    edge e, j;
    e.cost = 1;
    e.to = b-1;
    j.cost = 1;
    j.to = a-1;
    G[a-1].push_back(e);
    G[b-1].push_back(j);
  }
  // rep(i,n){
  //   for(edge e:G[i]){
  //     cout << i << " " << e.to << endl;
  //   }
  // }
  shortest_path(0, d, G, prev);
  repz(i,1,n){
    if(d[i]==INF){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  repz(i,1,n) cout << prev[i]+1 << endl;
  return 0;
}

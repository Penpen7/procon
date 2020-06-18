#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i <= n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;
vector<int> a, b, c, d;
int N,M,Q;
int max_res;

void show(vector<int> A){
  for(int i:A){
    cout << i << " ";
  }
  cout << endl;
}
void dfs(vector<int> A,int counter){
 counter++;
 cout << "counter" << counter << endl;
 show(A);
 if(A.size() == N+1){
   int res = 0;
   rep(i,0,Q-1){
   if(A[b[i]]-A[a[i]]==c[i]){
     res += d[i];
   }
   }
   max_res = max(res,max_res);
   return;
 }
 A.push_back(A.back());
 while(A.back()<=M){
   cout << "call" << counter << "->" << counter+1<< endl;
   dfs(A,counter);
   A.back()++;
 }

}
int main(){
  int i=0;
  cin >> N >> M >> Q;
  a = b = c = d = vector<int>(Q);
  while(cin >> a[i] >> b[i] >> c[i] >> d[i]){
    i++;
    if(i>=Q) break;
  }
  dfs(vector<int>(1,1),0);
  cout << max_res << endl;
  return 0;
}

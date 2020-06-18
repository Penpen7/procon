#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define repl(i, z, n) for(ll i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

using namespace std;

int main(){
  vector<int> a=vector<int>(3);
  vector<int> res;
  int n;
  cin >> n;
  vector<string> s=vector<string>(n);
  repl(i,0,3) cin >> a[i];
  repl(i,0,n) cin >> s[i];
  
  if(accumulate(all(a),0)==0){
    cout << "No\n";
    exit(0);
  }
  repl(i,0,n){
    int x = s[i][0]-'A';
    int y = s[i][1]-'A';
    if(i<n-1 && a[x]==1 && a[y]==1){
      bool found_x=(x==(s[i+1][0]-'A') || x==(s[i+1][1]-'A'));
      if(found_x){
        a[x]++;
        a[y]--;
        res.push_back(x); 
      }else{
        a[x]--;
        a[y]++;
        res.push_back(y); 
      }
    }else{
      if(a[x]<=0 && a[y] <=0){
        cout << "No\n";
        exit(0);
      }
      if(a[x]<a[y]){
        a[x]++;
        a[y]--;
        res.push_back(x);
      }else{
        a[y]++;
        a[x]--;
        res.push_back(y);

      }
    } 
  }
  cout << "Yes\n";
  for(int i:res){
    cout << char(i+'A') << endl;
  }
  return 0; 
}


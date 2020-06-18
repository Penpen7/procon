#include <bits/stdc++.h>
#define rep(i, z, n) for(ll i = z; i <= n; i++)
#define repl(i, z, n) for(ll i = z; i < n; i++)
#define all(v) v.begin(), v.end()
#define STR(var) #var
typedef long long ll;

using namespace std;

ll N, A, B, C;

int main(){
  ll A[3]; 
  cin >> N >> A[0] >> A[1] >> A[2];
  vector<pair<ll,ll>> operate_turn;
  vector<string> operate;
  vector<ll> res;
  repl(i,0,N){

    string s;
    cin >> s;
    operate.push_back(s);
    if(s=="AB") operate_turn.push_back(make_pair(0,1));
    if(s=="BC") operate_turn.push_back(make_pair(1,2));
    if(s=="AC") operate_turn.push_back(make_pair(0,2));
  }
  if(A[0]+A[1]+A[2]==0){
    cout << "No" << endl;
  }else if(A[0]+A[1]+A[2]==1){
    repl(i,0,N){
      ll first=operate_turn[i].first;
      ll second=operate_turn[i].second;
      
      if(A[first]==0 && A[second]>0){
        A[first]++;
        A[second]--;
        res.push_back(first);
      }else if(A[first]>0 && A[second]==0){
        A[second]++;
        A[first]--;
        res.push_back(second);
      }else{
        cout << "No" << endl;
        return 0;
      }
    }
  }else{
    ll first=operate_turn[0].first;
    ll second=operate_turn[0].second;
    if(A[first]==0 && A[second]==0){
      cout << "No" << endl;
      return 0;
    }
    cout << "Yes" << endl;
    repl(i,0,N){
        //cout << first << " " << second << endl;
        //cout << i << " "<< A[0] <<" " << A[1] <<" " <<A[2] << endl;
      ll first=operate_turn[i].first;
      ll second=operate_turn[i].second;
      ll first_next, second_next;
      if(i<N-1){
        first_next=operate_turn[0].first;
        second_next=operate_turn[0].second;
      }
      if(A[first]==1 && A[second]==1 && i<N-1 && (first != first_next || second != second_next)){
        if(first==first_next){
          A[first]++;
          A[second]--;
          res.push_back(first);
          continue;
        }else if(second==second_next){
          A[second]++;
          A[first]--;
        res.push_back(second);
          continue;
        }else{
          A[1]++;
          res.push_back(1);
          if(first==1){
            A[second]--;
          }else{
            A[first]--;
          }
          continue;
        }
      }
      if(A[first]==0 && A[second]>0){
        A[first]++;
        A[second]--;
        res.push_back(first);
        continue;
      }else if(A[first]>0 && A[second]==0){
        A[second]++;
        A[first]--;
        res.push_back(second);
        continue;
      }
      A[first]++;
      A[second]--;
      res.push_back(first);
    }
  }

  for(ll i:res){
    char str[] = {'A', 'B', 'C'};
    cout << str[i] << endl;
  }
  
  return 0;
}


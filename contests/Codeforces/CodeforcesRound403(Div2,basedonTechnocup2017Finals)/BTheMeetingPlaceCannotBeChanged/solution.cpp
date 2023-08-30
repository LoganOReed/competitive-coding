#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> l,s;

// return position of rightmost guy after t time
double rightmost_left(double t){
  double r = INT_MIN;
  for(int i=0;i<n;i++){
    r = max(r, l[i] - s[i]*t);
  }
  return r;
}

double leftmost_right(double t){
  double r = INT_MAX;
  for(int i=0;i<n;i++){
    r = min(r, l[i] + s[i]*t);
  }
  return r; 
}

int main(){
  cin>>n;
  l.resize(n);
  s.resize(n);
  for(int i=0;i<n;i++){
    cin>>l[i];
  }
  for(int i=0;i<n;i++){
    cin>>s[i];
  }

  double low = 0.0, high=1e9, mid;
  while((high - low) > 1e-7){
    mid = (low + high) / 2;
    if(leftmost_right(mid) >= rightmost_left(mid)){
      high = mid;
    }else{
      low = mid;
    }
  }

  cout.precision(8);
  cout << high;
  return 0;
}

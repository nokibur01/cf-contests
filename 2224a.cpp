#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
using st = std::string;

int findgcd(int n1, int n2) {
    if (n1 == 0) return n2;
    int mn = n1 > n2 ? n2 : n1;
    int mx = n1 > n2 ? n1 : n2;
    return findgcd(mx % mn, mn);
}

// for decimal cout << fixed << setprecision(n) << value;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int>v(n);
        for(auto &val:v) cin>>val;
        for(int i=n-2;i>=0;i--){
            if(v[i+1]>0){
                long long int a = v[i]+v[i+1];
                if(a>v[i]) v[i]=a; 
            }
        }
        int cnt=0;
        for(auto val:v){
            if(val>0) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
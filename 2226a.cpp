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

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        long long int sum = 0;
        vector<int>v2;
        int sz = v.size();
        while(sz>1){
            int mn = min_element(v.begin(),v.end())-v.begin();
            int a = v[mn];
            v.erase(v.begin()+mn);
            int mx = max_element(v.begin(),v.end())-v.begin();
            a*=v[mx];
            v2.pb(a);
            v.erase(v.begin()+mx);sz = v.size();
        }
        long long int minimum = INT_MAX;
        int p = 0;
        if(v.size()==1){
            for(int i=0;i<v2.size();i++){
                if((v[0]*v2[i])<minimum){
                    p = i;
                    minimum=v[0]*v2[i];
                }
            }
            for(int i=0;i<v2.size();i++){
                if(v2[i]==1) continue;
                if(i==p){
                    sum+=v[0]*v2[i];
                }
                else {
                    sum+=v2[i];
                }
                sum%=676767677;
            }
        }
        else{
            for(int i=0;i<v2.size();i++){
                    if(v2[i]==1) continue;
                    sum+=v2[i];
                    sum%=676767677;
            }
        }
        if(sum==0) cout<<"1"<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}

// solve korte pari nai contest time e!
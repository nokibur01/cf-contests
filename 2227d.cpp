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

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(2*n);
        for(auto &val:v) cin>>val;
        stack<int>s;
        vector<int>v2;
        v2.pb(-1);
        for(int i=0;i<2*n;i++){
            //int sz=s.size();
            if(!s.empty() && s.top()==v[i]){
                s.pop();
                v2.pb(v[i]);
            }
            else if(s.size()>=2){
                int a = s.top();
                s.pop();
                if(s.top()==v[i]){
                    v2.pb(v[i]);
                    v2.pb(a);
                    s.pop();
                }
                else{
                    s.push(a);
                    s.push(v[i]);
                    v2.pb(-1);
                }
            }
            else{
                s.push(v[i]);
                v2.pb(-1);
            }
            
        }
        v2.pb(-1);
        //for(auto val:v2) cout<<val<<" ";
        //cout<<endl;
        int p = find(v2.begin(),v2.end(),0) - v2.begin();
        vector<int>v3;
        v3.pb(v2[p]);
        int i=p-1,j=p+1;
        while(v2[i]!=-1){
            v3.pb(v2[i--]);
        }
        while(v2[j]!=-1){
            v3.pb(v2[j++]);
        }
        sort(v3.begin(),v3.end());
        int mex = v3.size();
        for(int i=0;i<v3.size();i++){
            if(v3[i]!=i) {mex=i;break;}
        }
        cout<<mex<<endl;
    }

    return 0;
}

// solve korte pari nai contest time e
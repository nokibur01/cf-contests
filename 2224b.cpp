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
        long long int n;
        cin>>n;
        vector<long long int>v(n),v2(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v2[i]=v[i];
        }
        int haveZero = find(v.begin(),v.end(),0)-v.begin();
        if(haveZero==n){
            long long int mx = *max_element(v.begin(),v.end()) * n;
            cout<<mx<<endl;
        }
        else{
            sort(v.begin(),v.end());
            long long int sum=v.back()*n;
            long long int mex = 1,mexSum=1,a=0;
            for(int i=0;i<n-1;i++){
                if(v[i]==a){
                    mexSum+=mex;
                }
                else if(v[i]==a+1){
                    a+=1;
                    mex+=1;
                    mexSum+=mex;
                }
                else{mexSum+=mex;}
            }
            cout<<sum+mexSum<<endl;
        }
    }

    return 0;
}

// solve korte pari nai
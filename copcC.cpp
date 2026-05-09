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
        long long int x,k;
        cin>>x>>k;
        if(x%k==0){
            cout<<"0"<<" "<<k<<endl;
        }
        else{
            int a=-1*x;
            cout<<a<<" "<<x<<endl;
        }
    }

    return 0;
}

//ac
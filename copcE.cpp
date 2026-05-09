#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;
using st = string;

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
    int n,q;
    cin>>n>>q;
    vector<long long int>v(n + 1);
    map<long long int, vector<long long int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        mp[v[i]].pb(i);
    }
    while (q--) {
        long long int l, r, x;
        cin>>l>>r>>x;
        int lb = 0;
        int ub = mp[x].size() - 1;
        int leftVal = mp[x].size();
        while (lb <= ub) {
            int mid=(lb+ub)/2;
            if (mp[x][mid]>=l) {
                leftVal =mid;
                ub =mid-1;
            }
            else {
                lb =mid+1;
            }
        }

        lb = 0;
        ub = mp[x].size()-1;
        int rightVal =mp[x].size();
        while (lb <= ub) {
            int mid = (lb + ub) / 2;
            if (mp[x][mid]>r) {
                rightVal = mid;
                ub =mid-1;
            }
            else {
                lb =mid+1;
            }
        }

        cout <<rightVal-leftVal<< endl;
    }

    return 0;
}

// solved
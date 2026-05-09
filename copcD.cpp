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

const double PI=acos(-1.0);
// for decimal cout << fixed << setprecision(n) << value;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        double x1,x2,y1,y2,r1,r2;
        cin>>x1>>y1>>r1;
        cin>>x2>>y2>>r2;
        double dis = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double ans;
        //kono overlap na hole
        if (dis>=r1+r2) {
            ans=0.0;
        }
        //ekta arektar moddhe
        else if(dis<=abs(r1-r2)) {
            double smallRad=min(r1, r2);
            ans=PI*smallRad*smallRad;
        }
        else {
            double t1=2.0*acos((r1*r1+dis*dis-r2*r2)/(2.0*r1*dis));
            double t2=2.0*acos((r2*r2+dis*dis-r1*r1)/(2.0*r2*dis));
            double area1=0.5*r1*r1*(t1-sin(t1));
            double area2=0.5*r2*r2*(t2-sin(t2));
            ans = area1 + area2;
        }
        cout<<"Case "<<i++<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }

    return 0;
}
/*https://www.quora.com/Given-the-radius-of-two-circles-and-the-distance-between-their-centers-how-can-I-find-the-common-area-between-the-circles-assuming-the-circles-intersect*/
// solved
#include <bits/stdc++.h>
#define int long long

using namespace std;

int b , s , c;
int nb, ns, nc;
int pb, ps, pc;
int ru;

int solve(int n){
    int r1 = ((n * b) - nb) * pb;
    int r2 = ((n * s) - ns) * ps;
    int r3 = ((n * c) - nc) * pc;
    r1 = max((int)0 , r1);
    r2 = max((int)0 , r2);
    r3 = max((int)0 , r3);
    return r1 + r2 + r3;
}

int32_t main()
{
    string s1;
    cin >> s1;
    b = count(s1.begin(), s1.end(), 'B');
    s = count(s1.begin(), s1.end(), 'S');
    c = count(s1.begin(), s1.end(), 'C');
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> ru;
    int l = 0; int r = 1e14;
    while(l < r){
        int mid = (l + r) / 2;
        if(solve(mid) <= ru){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1;

}
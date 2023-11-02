#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> factors;

void solve(int x){
    for(int i = 2; i <= x; i++){
        if(x % i == 0){
            factors.push_back(i);
			if(x / i != 1)
            	solve(x / i);
            break;
        }
    }
}


int32_t main()
{
    int n;
    cin >> n;
    solve(n);
    sort(factors.begin(), factors.end());
    for(int i = 0; i < factors.size(); i++){
        cout << factors[i];
        if(i != factors.size() - 1){
            cout << ' ';
        }    
    }
}
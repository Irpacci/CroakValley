#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    string s1, s2;
    cin >> n >> k >> s1 >> s2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(s1[i] == s2[j]){
                s1[i] -= 32;
            }
        }
    }
    cout << s1;
}
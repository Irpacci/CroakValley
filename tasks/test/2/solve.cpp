#include <bits/stdc++.h>

using namespace std;

int main(){

	int N, K;
    cin >> N >> K;
    vector <int> v(N);
	vector <int> v1, v2, v3;
	for(int i = 0; i < N; i++){
		cin >> v[i];
		if (v[i] % K == 0)
			v2.push_back(v[i]);
		else if(v[i] < K)
			v1.push_back(v[i]);
		else
			v3.push_back(v[i]);
	}

	for(int i = 0; i < v1.size(); i++){
		cout << v1[i];
		if (i != v1.size() - 1)
            cout << ' ';
    }
	cout << '\n';
		
	for(int i = 0; i < v2.size(); i++){
		cout << v2[i];
        if (i != v2.size() - 1)
			cout << ' ';
	}
	cout << '\n';

	for(int i = 0; i < v3.size(); i++){
		cout << v3[i];
		if (i != v3.size() - 1)
			cout << ' ';
	}
}

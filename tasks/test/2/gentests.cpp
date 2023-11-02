#include <bits/stdc++.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	for(int test_number = 1; test_number <= 30; test_number++){
		ofstream outputFile("gen_input/input" + to_string(test_number) + ".txt");
		int N = rand() % 100 + 1;
		int K = rand() % 10 + 1;
		vector<int> v;	
		outputFile << N << '\n' << K << '\n';
		for(int i = 0; i < N; i++){
			outputFile << rand() % 101 << ' ';
		}
		

	}
}
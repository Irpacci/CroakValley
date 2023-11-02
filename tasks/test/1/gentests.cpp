#include <bits/stdc++.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	string usedsymbols = "qwertyuiopasdfghjklzxcvbnm";
	for(int test_number = 1; test_number <= 30; test_number++){
		ofstream outputFile("gen_input/input" + to_string(test_number) + ".txt");
		int N = rand() % 50 + 1;
		int K = rand() % 26 + 1;
		map<char, bool> used_symbols;
		string S1 = "";
		string S2 = "";
		for(int i = 0; i < N; i++){
			S1 += usedsymbols[rand() % usedsymbols.size()];
		} 
		bool flag = true;
		while(flag){
			char c = usedsymbols[rand() % usedsymbols.size()];
			if(!used_symbols[c]){
				S2 += c;
			}
			used_symbols[c] = true;
			if(S2.size() == K)
				flag = false;
		}
		outputFile << N << '\n' << K << '\n' << S1 << '\n' << S2;
	}
}
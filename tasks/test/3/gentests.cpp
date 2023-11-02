#include <bits/stdc++.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	string input_string_char = "BSC";
	for(int test_number = 1; test_number <= 30; test_number++){
		ofstream outputFile("gen_input/input" + to_string(test_number) + ".txt");
		int n = rand() % 100 + 1;
		string input_string = "";
	    while(n--){
		    int k = rand() % 3;
		    input_string += input_string_char[k];
		}
		int N1, N2, N3, K1, K2, K3;
		N1 = rand() % 100 + 1;
		N2 = rand() % 100 + 1;
		N3 = rand() % 100 + 1;
		K1 = rand() % 100 + 1;
		K2 = rand() % 100 + 1;
		K3 = rand() % 100 + 1;
		int R = rand() % 1000000000000 + 1;
		outputFile << input_string << '\n' << N1 << ' ' << N2 << ' ' << N3 << '\n' << K1 << ' ' << K2 << ' ' << K3 << '\n' << R;
	}
}
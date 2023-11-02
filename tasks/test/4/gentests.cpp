#include <bits/stdc++.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	string input_string_char = "BSC";
	for(int test_number = 1; test_number <= 30; test_number++){
		ofstream outputFile("gen_input/input" + to_string(test_number) + ".txt");
		int n = rand() % 100000000 + 1;
		outputFile << n;
	}
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	for(int test_number = 1; test_number <= 30; test_number++){
        string name_of_inputFile = "gen_input/input" + to_string(test_number) + ".txt";
		string name_of_outputFile = "gen_output/output" + to_string(test_number) + ".txt";
		
		ifstream inputfile;
		ofstream outputfile;
		inputfile.open(name_of_inputFile);
		outputfile.open(name_of_outputFile);

		int N, K;
        inputfile >> N >> K;
        string S1, S2;
        inputfile >> S1 >> S2;
		for(int i = 0; i < S1.size(); i++){
			for(int j = 0; j < S2.size(); j++){
				if(S1[i] == S2[j])
					S1[i] = S1[i] - 32;
			}
		}
		outputfile << S1;
		inputfile.close();
		outputfile.close();
	}
}
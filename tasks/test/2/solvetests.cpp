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
        vector <int> v(N);
		vector <int> v1, v2, v3;
		for(int i = 0; i < N; i++){
			inputfile >> v[i];
			if (v[i] < K)
				v1.push_back(i);
			else if(v[i] % K == 0)
				v2.push_back(i);
			else
				v3.push_back(i);
		}

		for(int i = 0; i < v1.size(); i++){
			outputfile << v1[i];
			if (i != v1.size() - 1)
				outputfile << ' ';
		}
		outputfile << '\n';
		
		for(int i = 0; i < v2.size(); i++){
			outputfile << v2[i];
			if (i != v2.size() - 1)
				outputfile << ' ';
		}
		outputfile << '\n';

		for(int i = 0; i < v3.size(); i++){
			outputfile << v3[i];
			if (i != v3.size() - 1)
				outputfile << ' ';
		}


		inputfile.close();
		outputfile.close();
	}
}

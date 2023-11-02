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

int32_t main(){
	
	for(int test_number = 1; test_number <= 30; test_number++){
        string name_of_inputFile = "gen_input/input" + to_string(test_number) + ".txt";
		string name_of_outputFile = "gen_output/output" + to_string(test_number) + ".txt";
		
		ifstream inputfile;
		ofstream outputfile;
		inputfile.open(name_of_inputFile);
		outputfile.open(name_of_outputFile);

		int n;
		inputfile >> n;
		factors.clear();
		solve(n);
		sort(factors.begin(), factors.end());
		for(int i = 0; i < factors.size(); i++){
			outputfile << factors[i];
			if(i != factors.size() - 1){
				outputfile << ' ';
			}    
		}

		inputfile.close();
		outputfile.close();
	}
}
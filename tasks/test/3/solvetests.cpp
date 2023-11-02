#include <bits/stdc++.h>
#define int long long

using namespace std;

int b , s , c;
int nb, ns, nc;
int pb, ps, pc;
int ru;

int solve(int n){
    int r1 = ((n * b) - nb) * pb;
    int r2 = ((n * s) - ns) * ps;
    int r3 = ((n * c) - nc) * pc;
    r1 = max((int)0 , r1);
    r2 = max((int)0 , r2);
    r3 = max((int)0 , r3);
    return r1 + r2 + r3;
}

int32_t main(){
	
	for(int test_number = 1; test_number <= 30; test_number++){
        string name_of_inputFile = "gen_input/input" + to_string(test_number) + ".txt";
		string name_of_outputFile = "gen_output/output" + to_string(test_number) + ".txt";
		
		ifstream inputfile;
		ofstream outputfile;
		inputfile.open(name_of_inputFile);
		outputfile.open(name_of_outputFile);

		string s1;
		inputfile >> s1;
		b = count(s1.begin(), s1.end(), 'B');
		s = count(s1.begin(), s1.end(), 'S');
		c = count(s1.begin(), s1.end(), 'C');
		inputfile >> nb >> ns >> nc;
		inputfile >> pb >> ps >> pc;
		inputfile >> ru;
		int l = 0; int r = 1e14;
		while(l < r){
			int mid = (l + r) / 2;
			if(solve(mid) <= ru){
				l = mid + 1;
			} else {
				r = mid;
			}
		}
    	outputfile << l - 1;

		inputfile.close();
		outputfile.close();
	}
}
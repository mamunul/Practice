//
//  BasicAlgorithm.hpp
//  Practice
//
//  Created by Mamunul on 11/20/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#ifndef BasicAlgorithm_hpp
#define BasicAlgorithm_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class BasicAlgorithm{
public:
	bool isPrime(unsigned long long n);
	
	unsigned long long factorial_loop(unsigned int n);
	unsigned long long factorial_recursion(unsigned n);
	std::vector<std::string> permutation(std::string s,int r);
	int fibonacci_recursion(int n);
	vector<int> fibonacci_loop_memo(int n);
	int fibonacci_logn(int n);
    string longest_common_subsequence(string s1, string s2);
	vector<string> combination(string s,int r);
	string longest_common_substring(string s1, string s2);
    int no_occurance_as_sequence(string seq, string str);
    set<int> prime_factors(int n);
    vector<int> seive_eratosthenes(int n);
    bool knuth_morris_pratt(string pattern,string str);
	
};

#endif /* BasicAlgorithm_hpp */

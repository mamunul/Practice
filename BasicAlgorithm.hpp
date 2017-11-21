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

using namespace std;

class BasicAlgorithm{
public:
	bool isPrime(unsigned long long n);
	
	unsigned long long factorial_loop(unsigned int n);
	unsigned long long factorial_recursion(unsigned n);
	std::vector<std::string> permutation(std::string s);
	int fibonacci_recursion(int n);
	vector<int> fibonacci_loop_memo(int n);
	int fibonacci_logn(int n);
	string longest_common_substring(string s);
	string longest_commom_subsequence(string s);
	
	
};

#endif /* BasicAlgorithm_hpp */

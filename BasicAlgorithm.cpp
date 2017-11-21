//
//  BasicAlgorithm.cpp
//  Practice
//
//  Created by Mamunul on 11/20/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "BasicAlgorithm.hpp"
#include <iostream>

using namespace std;


bool BasicAlgorithm::isPrime(unsigned long long n){

	for(unsigned long long i = 2;i*i<=n;i++){
	
		if (n%i == 0) {
			return false;
		}
	}

	return true;
}

unsigned long long BasicAlgorithm::factorial_loop(unsigned int n){
	
	unsigned long long result  = 1;
	for(int i = 1;i<=n;i++){
		result *= i;
	}
	return result;


}

unsigned long long BasicAlgorithm::factorial_recursion(unsigned n){
	if(n == 0)
		return 1;
	else
		return n * factorial_recursion(n-1);


}

 void permutation(std::string p,std::string s,std::vector<std::string> *v){
	
	if (s.empty()) {
		v->push_back(p);
		return;
	}
	
	for (int i = 0; i < s.length(); i++) {
		string pr = p + s[i];
		string sr = s.substr(0,i) + s.substr(i + 1,s.length() - (i + 1));
		permutation(pr,sr,v);
	}

}

std::vector<std::string> BasicAlgorithm::permutation(std::string s){

	std::vector<std::string> result;
	::permutation("",s,&result);
	
	return result;
}

int BasicAlgorithm::fibonacci_recursion(int n){
	
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;

	return fibonacci_recursion(n-1)+fibonacci_recursion(n-2);
	
}

vector<int> BasicAlgorithm::fibonacci_loop_memo(int n){
	
	vector<int> result;
	result.push_back(0);
	result.push_back(1);
	
	for(int i = 2;i <= n;i++){
		
		result.push_back(result[i-1]+result[i-2]);
		
	}

	return result;
}

int fib(int n,int *f){
	

	if (n == 0) {
		return 0;
	}
	if(n == 1 || n == 2)
		f[n] = 1;
	
	if(f[n]>0)
		return f[n];

	
	int k;
	k = n & 1 ? (n+1)/2 : n/2 ;
	

	
	if(n & 1){
		
		f[n] = fib(k,f) * fib(k,f) + fib(k-1,f) * fib(k-1,f);
	}else{
		f[n] = (2 * fib(k-1,f) + fib(k,f)) * fib(k,f);
	
	}
	
	return f[n];
}

int BasicAlgorithm::fibonacci_logn(int n){

	int *f = new int[n+1];
	
	memset(f, 0, (n+1) * sizeof(int));

	int r = fib(n,f);
	delete[] f;
	
	return r;
}





//
//  BasicAlgorithm.cpp
//  Practice
//
//  Created by Mamunul on 11/20/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "BasicAlgorithm.hpp"
#include <iostream>
#include <cmath>

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

 void permutation(std::string p,std::string s,std::vector<std::string> *v, int r){
	
	if (p.length() == r) {
		v->push_back(p);
		return;
	}
	
	for (int i = 0; i < s.length(); i++) {
		string pr = p + s[i];
		string sr = s.substr(0,i) + s.substr(i + 1,s.length() - (i + 1));
		permutation(pr,sr,v,r);
	}

}

std::vector<std::string> BasicAlgorithm::permutation(std::string s,int r){

	std::vector<std::string> result;
	::permutation("",s,&result,r);
	
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

void combinate(string p, string s, int r,int k,vector<string> *v){
	
	
	if(p.length() == r){
	
		v->push_back(p);
		return;
	}

	for(int i = k;i<s.length();i++){
		
		string pr = p + s[i];
		combinate(pr,s,r,i+1,v);
		
		
	}
}

vector<string> BasicAlgorithm::combination(string s, int r){

	vector<string> v;
	
	string prefix = "";

	combinate(prefix,s, r, 0 , &v);

	return v;
}

string BasicAlgorithm::longest_common_substring(string s1, string s2){
	
	string r; int max_length = 0;
	pair<int,int> p;
	
	int lcs[100][100] = {0};
	
	for(int i = 1;i<=s1.length();i++){
	
		for(int j = 1;j<=s2.length();j++){
		
			if(s1[i-1] == s2[j-1]){
			
				lcs[i][j] = 1 +lcs[i-1][j-1];
				if(max_length < lcs[i][j]){
					max_length = lcs[i][j];
					p.first = i;
					p.second = j;
				}
				
			}
		}
	}
	
	int i = p.first - max_length;
	
	r = s1.substr(i,max_length);
	
	return r;

}
string lc_sequence_backtrack(int lcs[100][100],int i,int j,string p,string s1){
    if (i == 0 || j == 0) {
        return p;
    }

    if(lcs[i][j] == lcs[i-1][j]){
        return lc_sequence_backtrack(lcs,i-1,j,p,s1);
    }
    if(lcs[i][j] == lcs[i][j-1]){
        return lc_sequence_backtrack(lcs,i,j-1,p,s1);
    }
    p=s1[i-1]+p;
    return lc_sequence_backtrack(lcs,i-1, j-1,p,s1);
}
string BasicAlgorithm::longest_common_subsequence(string s1, string s2){

    int lcs[100][100] = {0};
	
    for(int i = 1;i <= s1.length();i++){
        for(int j = 1;j<=s2.length();j++){
            if(s1[i-1] != s2[j-1])
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            else
                lcs[i][j] = lcs[i-1][j-1]+1;
        }
    }
    
    string q = lc_sequence_backtrack(lcs, (int)s1.length(), (int)s2.length(), "", s1);
	return q;

}

int BasicAlgorithm::no_occurance_as_sequence(string seq, string str){
    
    int lcs[100][100] = {0};
    
    for(int i = 0;i<=seq.length();i++){
        for(int j = 0;j<=str.length();j++){
            
            if(i == 0)
                lcs[i][j] = 1;
            if(i==0 || j ==0)
                continue;

            if (seq[i-1] == str[j-1])
                lcs[i][j] = lcs[i-1][j-1] + lcs[i][j-1];
            else
                lcs[i][j] = lcs[i][j-1];

        }
    }
    return lcs[seq.length()][str.length()];
}

set<int> BasicAlgorithm::prime_factors(int n){
    
    set<int> v;
        
    while(n%2== 0){
        v.insert(2);
        n /=2;
    }
    
    for(int i = 3;i*i<n;i++){
        while (n%i == 0) {
            n /=i;
            v.insert(i);
        }
    }
    v.insert(n);
    return v;
}

vector<int> BasicAlgorithm::seive_eratosthenes(int n){
    vector<int> v;
    int prime[500];
    
    for(int i = 0;i<=n;i++)
        prime[i] = i;
    
    for(int i = 2;i<=n;i++){
        if (prime[i] != -1){
            v.push_back(i);
            for(int j = i+i ;j<=n;j+=i){
                prime[j] = -1;
            }
        }
            
    }
    return v;
}

bool BasicAlgorithm::knuth_morris_pratt(string pattern,string str){
    
    int table[100] = {0};
    int len = 0,i = 1;
    while(i<pattern.length()){
        
        if (pattern[len] == pattern[i]) {
            table[i] = len+1;
            len++;
            i++;
        }else{
            if(len == 0){
                i++;
            }else{
                len = table[len-1]; 
            }
        }
    }
    
    len = 0;i = 0;
    while(i<str.length()){
        
        if (str[i] == pattern[len]) {
            i++;
            len++;
            if(len == pattern.length())
                return true;
        }else{
            if(len == 0){
                i++;
            }else
                len = table[len-1];
        }
    }

        return false;

}

int BasicAlgorithm::rabin_karp(string pattern, string str){
    
    int hash = 0;
    for(int i = 0;i<pattern.length();i++){
        hash += (i+1)*pattern[i];
    }
    
    for(int i = 0;i<=(str.length()-pattern.length());i++){
        int subhash = 0;
        for (int j = i; j<(i+pattern.length()); j++) {
            subhash += (j-i+1)*str[j];
        }
        if(hash == subhash)
            return i;
    }
    
    return -1;
}

vector<vector<int>> BasicAlgorithm::floyd_warshall(vector<vector<int>> graph){
    //positive and negative
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j<graph[i].size();j++){
            for(int k = 0;k<graph[i].size();k++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
    return graph;
}

vector<int> BasicAlgorithm::dijkstra(vector<vector<int>> graph){
    //positive only
    vector<int> dp((int)graph.size(),1000);
    vector<int> visited((int)graph.size(),0);
    int c = (int)graph.size();
    dp[0] = 0;
    int v = 0;
    while(c-- > 0){
        visited[v] = 1;
        int mindp = 1000;int minv = 0;
        for(int j = 0;j<graph.size();j++){
            if(graph[v][j] > 0 && !visited[j]){
                if(v == 0){
                    dp[j] = graph[v][j];
                }else{
                    dp[j] = min(dp[j],graph[v][j]+dp[v]);
                }
                
                if(mindp>dp[j] ){
                    mindp = dp[j];
                    minv = j;
                }
            }
        }
        v = minv;
    }
    
    return dp;
}

vector<int> BasicAlgorithm::bellman_ford(vector<Edge> graph,int vertexCount){
    //positive and negative
    vector<int> dp(vertexCount,1000);
    dp[0] = 0;
    vertexCount--;
    while(vertexCount-- >0){
        for(vector<Edge>::iterator itr = graph.begin();itr != graph.end();itr++){
           dp[itr->d] = min(dp[itr->d],dp[itr->s]+itr->w);
        }
    }
    return dp;
}

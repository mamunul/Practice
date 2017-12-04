//
//  main.cpp
//  Patterns
//
//  Created by Mamunul on 11/11/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include <iostream>
#include "ExampleA.hpp"
#include "ExampleB.hpp"
#include "BasicAlgorithm.hpp"
#define INF 1000
//#include "VectorElementPractice.hpp"
//#include "ArgumentPractice.hpp"

void test(ExampleB *e){//pass by reference

	e->vir_pub_method2();//dynamically bind method at runtime

};
int matrixsum(int **a, int **b, int m, int n)
{
    return a[m][n] + b[m][n];
    
}
void test3(ExampleA *e){
	e->vir_pub_method2();
}

void test2(ExampleB e){//pass by value(copy fields only in 'e' Class Type of ExampleB)
	
	//	e.vir_pub_method();
	e.vir_pub_method2();//bind method at compile time
	
};

void test4(ExampleB& e){
	e.vir_pub_method2();
}

int main(int argc, const char * argv[]) {
	// insert code here...
//	std::cout << "Hello, World!\n";

	
//	VectorElementPractice vep;
	
//	ArgumentPractice ap;
	
//	ap.run();
	
//	vep.run();
//	ExampleA example;
//	example.pub_method();
//	example.vir_pub_method();
//	example.pri_method2();
//	
//	ExampleB exampleb;
//	exampleb.pub_method();
//	exampleb.vir_pub_method();
	
//	ExampleB e = ExampleA();
//	e.vir_pub_method();
//	e.vir_pub_method2();
//    ExampleB *e = new ExampleA();
//
//    ExampleB *e2 = new ExampleB();
//
//    ExampleA *ea = new ExampleA();
	
//    e->vir_pub_method2();
//    e2->vir_pub_method2();
//
//    ExampleB e123 = ExampleB();
	
//    ExampleB e234 = ExampleA();//values are copied from ExampleA class methods are pointng to ExampleB class -- so ExampleA methods are not visible which is implicit assignment operator behavior, to change it override it.
	
//    e123.vir_pub_method2();
//    e234.vir_pub_method2();

	
//	test3(ea);
	
//	test(e);
//	test(e2);
	
	
//	test2(*e);
//	test2(*e2);
//	ex.pub_method();
	
	BasicAlgorithm b; int n = 25;
    vector<vector<int>> v {
        {0,-1,4,0,0},
        {0,0,3,2,2},
        {0,0,0,0,0},
        {0,1,5,0,0},
        {0,0,0,-3,0}
    };
    vector<Edge> g;
    g.push_back(Edge{0,1,-1});
    g.push_back(Edge{0,2,4});
    g.push_back(Edge{1,2,3});
    g.push_back(Edge{1,3,2});
    g.push_back(Edge{1,4,2});
    g.push_back(Edge{3,1,1});
    g.push_back(Edge{3,2,5});
    g.push_back(Edge{4,3,-3});

//    vector<vector<int>> v2 = b.floyd_warshall(v);
    vector<int> v3 = b.bellman_ford(g,5);
    for(int i = 0;i<v3.size();i++){
 
        cout << v3[i] << " ";
  
        cout << endl;
    }

    
	

//    int r = matrixsum(a, b, 4, 4);
	

	
    return 0;
}




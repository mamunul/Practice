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
//#include "VectorElementPractice.hpp"
//#include "ArgumentPractice.hpp"

void test(ExampleB *e){//pass by reference

	e->vir_pub_method2();//dynamically bind method at runtime

};

void test3(ExampleA *e){
	e->vir_pub_method2();
}

void test2(ExampleB e){//pass by value(copy fields only in 'e' Class Type of ExampleB)
	
	//	e.vir_pub_method();
	e.vir_pub_method2();//bind method at compile time
	
};

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
	ExampleB *e = new ExampleA();
	
	ExampleB *e2 = new ExampleB();
	
	ExampleA *ea = new ExampleA();
	
//	test3(ea);
	
	test(e);
	test(e2);
	
	
	test2(*e);
	test2(*e2);
//	ex.pub_method();

	
    return 0;
}

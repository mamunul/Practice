//
//  ExampleA.cpp
//  Practice
//
//  Created by Mamunul on 11/13/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "ExampleA.hpp"
#include <stdio.h>
#include <iostream>

ExampleA::ExampleA(){
	//ExampleA::aa = 70; //not accessible compile time error
//	ExampleA::a = 88; //not accessible compile time error
	//uninit_const_var = 20;// compile time error- const variable connot be assigned after declaration
	//uninit_private_const_var = 40; // compile time error

//	a = 678;
}

int ExampleA::pub_method_args(int a,char *s){

	int b = 30;
	int c = a + b;

	return c;
}

int ExampleA::pub_method(){

	//ExampleA::aa = 50; //not accessible compile time error
	int a = 20; int b = 30;
	int c = a + b;
	return c;


}

int ExampleA::vir_pub_method(){

	int d = ExampleB::vir_pub_method();
	
	int f = 242341;
	
	return d * f;

}

int ExampleA::pri_method2(){
	
//	ExampleB::pri_method2();

	int d = 456; int f = 242341;
	
	return d * f;

}

int ExampleA::vir_pri_method(){
	
//	ExampleB::vir_pri_method();

	int d = 456; int f = 242341;
	
	return d * f;
}

int ExampleA::vir_pub_method2(){
	
	std::cout << "inside child(ExampleA) class vir_pub_method2\n";
	int d = 456; int f = 242341;
	
	return d * f;

}

int pri_method(){

	int a = 20; int b = 30;
	int c = a + b;
	return c;
}

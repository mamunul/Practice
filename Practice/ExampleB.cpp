//
//  ExampleB.cpp
//  Practice
//
//  Created by Mamunul on 11/14/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "ExampleB.hpp"
#include <iostream>

ExampleB::ExampleB(){
	
	a = 40;
	b = 345;

}

int ExampleB::vir_pri_method(){
	int sum = a+b;
	return sum;
}

int ExampleB::pri_method2(){
	int sum = a+b;
	return sum;
}


int ExampleB::vir_pub_method(){
	int sum = a+b;
	return sum;
}

int ExampleB::pub_method(){
	int sum = a+b;
	return sum;
}

int ExampleB::vir_pub_method2(){
	
	std::cout << "inside of parent(ExampleB) class vir_pub_method2\n";
	int sum = a+b;
	return sum;
}

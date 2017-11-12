//
//  VectorElementPractice.cpp
//  Patterns
//
//  Created by Mamunul on 11/11/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "VectorElementPractice.hpp"
#include <vector>
#include "Sample.hpp"

std::vector<Sample> createVectorWithSampleElement(){
	
	
	std::vector<Sample> v1;
	
	Sample s1;
	
	v1.push_back(s1);//s1 is copied as new instance
	v1.push_back(s1);//s1 is copied as new instance
	
	v1[0].var = 6;
	v1[1].var = 70;
	
	std::cout << "1st element copied:" << s1.var << "\n";
	
	return v1;
	
}

std::vector<Sample*> createVectorWithSampleElement2(){
	
	std::vector<Sample*> v1;
	
	Sample s;
	
	v1.push_back(&s); // pointer is copied whose address is in stack
	
	v1[0]->var = 89;
	
	std::cout << "1st element copied:" << s.var << std::endl;
	
	return v1;
	
}

std::vector<Sample*> createVectorWithSampleElement3(){
	
	
	std::vector<Sample*> v1;
	
	Sample *s = new Sample;//instance created in heap
	
	s->var = 55;
	
	v1.push_back(s);//heap address copied
	
	std::cout << "1st element copied:" << v1[0]->var << std::endl;
	
	return v1;
}

void VectorElementPractice::run(){
	
	std::cout << "Default value of element object varible is 45\n";
	
	std::cout << "\nExample 1 -- vector element is created in stack and cpied by value\n";
	
	std::vector<Sample> v = createVectorWithSampleElement();
	
	std::cout << "element1:" << v[0].var << ",2:" << v[1].var << "\n";
	
	std::cout << "\nExample 2 -- vector element is created in stack and copied the reference\n";
	
	std::vector<Sample*> v2 = createVectorWithSampleElement2();
	
	std::cout << "vector:" << v2[0]->var << std::endl;
	
	std::cout << "\nExample 3 -- vector element is created in heap and copied the reference\n";
	
	std::vector<Sample*> v3 = createVectorWithSampleElement3();
	
	std::cout << "vector:" << v3[0]->var << std::endl;


}

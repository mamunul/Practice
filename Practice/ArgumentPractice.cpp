//
//  ArgumentPractice.cpp
//  Patterns
//
//  Created by Mamunul on 11/11/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#include "ArgumentPractice.hpp"
#include "Sample.hpp"
#include <iostream>

void changeArgumentValue(Sample s1,Sample *s2,Sample s3,Sample &s4,Sample *s5){


	s1.var = 80;//s1 instance is copied
	s2->var = 81;//s2 instance is reference
	s3.var = 82;//s3 is copied
	s4.var = 83;//s4 is reference
	s5->var = 84;//s5 is reference
	
	std::cout << "Inside Method value changed\n";
	std::cout << "1:" << s1.var << " 2:" << s2->var << " 3:" << s3.var << " 4:" << s4.var << " 5:" << s5->var << std::endl;

}

void ArgumentPractice::run(){

	std::cout << "Sample variable default value: 45\n";
	
	Sample s1,s2;//in stack after returning from run method these will not be available
	Sample *s3 = new Sample; // heap
	Sample *s4 = new Sample; // heap
	Sample *s5  = new Sample; // heap
	
	changeArgumentValue(s1,&s2,*s3,*s4,s5);//s3 has been dereferenced so vaue is passed
	
	std::cout << "After Method execution\n";
	std::cout << "1:" << s1.var << " 2:" << s2.var << " 3:" << s3->var << " 4:" << s4->var << " 5:" << s5->var << std::endl;


}



//
//  ExampleB.hpp
//  Practice
//
//  Created by Mamunul on 11/14/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#ifndef ExampleB_hpp
#define ExampleB_hpp

#include <stdio.h>

class ExampleB{

private:
	int a;
	virtual int vir_pri_method();
	int pri_method2();
	
public:
	int b;
	ExampleB();
	virtual int vir_pub_method();
	virtual int vir_pub_method2();
	int pub_method();


};

#endif /* ExampleB_hpp */

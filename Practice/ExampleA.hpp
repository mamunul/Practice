//
//  ExampleA.hpp
//  Practice
//
//  Created by Mamunul on 11/13/17.
//  Copyright © 2017 Mamunul. All rights reserved.
//

#ifndef ExampleA_hpp
#define ExampleA_hpp

#include <stdio.h>
#include "ExampleB.hpp"

static int a;
static int aa = 89;

class ExampleA:public ExampleB{

public:
	ExampleA();
	// unable to initialize on any method
	static const int b = 30; // const var cannot initialied after declaration
	int vara;
	int var;
	int pub_method();
	int pub_method_args(int a, char *s);
	virtual int vir_pri_method();
	int pri_method2();
	virtual int vir_pub_method();
	virtual int vir_pub_method2();
	
private:

	int p_vara;
	int p_var;
	static const int bb = 45;
	int pri_method();
	int static static_method();

};

#endif /* ExampleA_hpp */

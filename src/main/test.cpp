/*
Simple Template Tests in C++

Written in 2024 by Eunbin Bak

To the extent possible under law, the author(s) have dedicated 
all copyright and related and neighboring rights to this software 
to the public domain worldwide. This software is distributed
without any warranty.

You should have received a copy of the CC0 Public Domain Dedication 
along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "test.h"

int main (int argc, char * argv [])
{
	std::cout << std::setprecision (10);

	std::cout << "sin(2): " << sin (2) << "\t| " << cpp::math::sin <2>::value () << std::endl;	
	std::cout << "cos(2): " << cos (2) << "\t| " << cpp::math::cos <2>::value () << std::endl;
	std::cout << "tan(2): " << tan (2) << "\t| " << cpp::math::tan <2>::value () << std::endl;
	std::cout << "exp(2): " << exp (2) << "\t| " << cpp::math::exp <2>::value () << std::endl;
	
	return 0;
}


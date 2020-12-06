#include <iostream>
#include "main.h"

B C::print() {
	std::cout << "Hello, world !" << std::endl;
	B *b = new B();
    return *b;
}

int main() {
	C* c = new C();
	c->print();
	return 0;  
}

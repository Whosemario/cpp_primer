#include <iostream>
#include <functional>


class A {
public:
	virtual void func() {
		std::cout << "virtual in A" << std::endl;
	}
	
	void func2() {
		std::cout << "in A" << std::endl;
		func();
	}
};

class B : public A {
	virtual void func() {
		std::cout << "virtaul in B" << std::endl;
	}
	void func2() {
		std::cout << "in B" << std::endl;
		func();
	}
};

int main(int args, char* argv[])
{
	B b;
	auto vf = std::bind(&A::func, &b);
	vf();
	auto f = std::bind(&A::func2, &b);
	f();	
	return 0;
}

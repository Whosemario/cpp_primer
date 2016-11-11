/*
	std::forward的使用可以让函数将其实参类型不变的转发给其他函数

	std::forward<T>(value) -> T&&
	eg:
		std::forward<int> -> int&&
		std::forward<int&> -> int & && -> int&
		std::forward<int&&> -> int&& && -> int&&
*/

#include <utility>
#include <iostream>

void pfunc(int& x) { std::cout << "[lvalue]"; }
void pfunc(int&& x) { std::cout << "[rvalue]"; }

template<typename T>
void testFunc(T&& x) {
	pfunc(x);	// always left-value
	pfunc(std::forward<T>(x));
}

int main(int args, char* argv[])
{
	int a = 1;
	testFunc(a); // print [lvalue][lvalue]
	std::cout << std::endl;

	testFunc(47);  // print [lvalue][rvalue]
	std::cout << std::endl;

	return 0;
}
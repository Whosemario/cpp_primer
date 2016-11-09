/*
	16.2.5 模板实参推断引用
*/

#include <iostream>

// p必须是左值，如果p是常量，T将推断为const
template<typename T>
void f1(T& p) {}

// p可以是左值，也可以是右值；可以是常量，也可以是非常量
template<typename T>
void f2(const T& p) {}

// 引用折叠
// p为右值：T为非引用
// p为左值：T为引用
template<typename T>
void f3(T&& p) {
	T t = p;
	t = t + 1;
}

int main(int args, char* argv[])
{
	int i = 47;
	const int ci = 100;
	f1(i);
	f1(ci);
	//  f1(47); error: 47为右值

	f2(ci);
	f2(47);
	f2(i);

	f3(i);   // i -> 48
	// f3(ci); error: T is const int&
	std::cout << i << std::endl;

	return 0;
}

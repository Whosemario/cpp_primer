/*
	参考：https://isocpp.org/wiki/faq/exceptions#ctors-can-throw
	1. placement new / delete 要对应
		下面在构造函数中抛出异常后，内部会调用对应的delete方法，防止内存泄漏
	2. 参数网址说明：构造函数可以抛异常，但习惯函数尽量退出程序吧
*/
#include <iostream>
#include <exception>

class A {
public:
	A() {
		int a = 0;
		throw 20;
	}

	static void* operator new(std::size_t size) {
		return ::operator new(size);
	}

	static void operator delete(void* p) {
		std::cout << "in delete" << std::endl;
		::operator delete(p);
	}
};

int main(int args, char* argv[])
{
	try {
		A* ptr = new A();
	}
	catch (int e) {

	}
	return 0;
}
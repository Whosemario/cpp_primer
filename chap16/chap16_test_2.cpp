/*
	16.2.5 模板实参推断引用
*/

// p必须是左值，如果p是常量，T将推断为const
template<typename T>
void f1(T& p) {}

// p可以是左值，也可以是右值；可以是常量，也可以是非常量
template<typename T>
void f2(const T& p) {}

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

	return 0;
}
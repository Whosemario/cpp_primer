/*
  几个关键点：
	1. 顶层const和底层const
	2. constexpr 常量表达式
	3. decltype 使用
	4. auto
 */

int main(int argc, char* argv[])
{

	// 顶层const就是我们说的const
	// 底层const与引用和指针相关

	const int ci = 10;   // 顶层
	const int *pci = &ci;  // 顶层
	int i = 10;
	int const* pi = &i; 	// 底层
	int const &ri = i;		// 底层

	// decltype(*pi) k;   error int& k;
	// decltype(ri) k;    error int& k;
	decltype(i) k;
	decltype(ci) k2 = 2;   // const int 
	// k2 = 11; 		error const int

	// auto 会忽略顶层const
	auto z = ci;
	z = 111;

	return 0;
}

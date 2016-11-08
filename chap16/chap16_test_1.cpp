#include <iostream>
#include <vector>

template<typename T>
class Blob {
public:
	typedef T value_type;
	// [1] vector<T>::size_type is "Dependent Name" 
	typedef typename std::vector<T>::size_type size_type;
};

int main(int args, char* argv[]) 
{
	Blob<int>::size_type i = 0;
	std::cout << i << std::endl;
	return 0;
}

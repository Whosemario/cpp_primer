/*
	Effective C++ 3e 条款43


*/

template<typename T>
class Msg {
public:
	void sendMsg() {
		T val = 0;
	}
};

template<>
class Msg<double>
{
public:
	void sendDoubleMsg() {
		double val = 0;
	}
};

template<typename T>
class LogMsg : Msg<T> {
public:
	void sendLogMsg() {
		sendMsg();
	}
};

int main(int args, char* argv[])
{
	LogMsg<int> inst;
	LogMsg<double> inst;
	return 0;
}
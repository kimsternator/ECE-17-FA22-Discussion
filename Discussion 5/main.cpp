#include <iostream>
#include <string>
#include <map>
#include <functional>

using std::cout, std::endl,
	std::string, std::map, std::function;

void funcExample();
void templateFuncExample();

static map<string, function<void()>> argumentFunctions = {
		{"func", funcExample},
		{"templateFunc", templateFuncExample},
};

// ****************************************************

void func() {
	cout << "Default Function" << endl;
}

void func(int anInt) {
	cout << "Int Function" << endl;
}

void func(double aDouble) {
	cout << "Double Function" << endl;
}

void func(float aFloat) {
	cout << "Float Function" << endl;
}

// ****************************************************

template<typename T>
void templateFunc(T aVal) {
	cout << "Default Template Function" << endl;
}

template<typename T>
void templateFunc(T aVal, int anInt) {
	cout << "Int Template Function" << endl;
}

template<typename T>
void templateFunc(T aVal, float aFloat) {
	cout << "Float Template Function" << endl;
}

template<typename T1, typename T2>
void templateFunc(T1 aVal, T2 anotherVal) {
	cout << "Default Template x2 Function" << endl;
}

// ****************************************************

int main(int argc, const char* argv[]) {
	if (argc <= 1) {
		return 0;
	}

	if (argumentFunctions.find(argv[1]) != argumentFunctions.end()) {
		argumentFunctions[argv[1]]();
	}

	return 0;
}

void funcExample() {
	func();
	func(1);
	func(1.0);
	func(1.0f);
}

void templateFuncExample() {
//	templateFunc("");
//	templateFunc(1);
//	templateFunc(1.0);
//	templateFunc(1.0f);

	templateFunc("", 1);
	templateFunc("", 1.0f);
	templateFunc("", 1.0);
	templateFunc("", "");
}

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <list>
#include <chrono>
#include <vector>

using std::cout, std::endl,
	std::ostream, std::map, std::string, std::function, std::list, std::vector;

void runPointerExample();
void runLinkedListExample();

static map<string, function<void()>> argumentFunctions = {
		{"pointer", runPointerExample},
		{"list", runLinkedListExample},
};

int main(int argc, const char* argv[]) {
	if (argc <= 1) {
		return 0;
	}

	if (argumentFunctions.find(argv[1]) != argumentFunctions.end()) {
		argumentFunctions[argv[1]]();
	}

	return 0;
}

struct Obj {
	Obj(int aNum) : num(aNum) {}

	friend ostream& operator<<(ostream &anOutput, const Obj &aCopy){
		anOutput << aCopy.num;
		return anOutput;
	}

	int num;
};

void printPointer(Obj* anObj) {
	cout << "Object: " << *anObj << ": Pointer: " << anObj << endl;
}

void runPointerExample() {
	Obj* theObj = new Obj(5);
	Obj theOtherObj(5);
	printPointer(theObj);
	printPointer(&theOtherObj);
}

void printList(const list<int>& aList) {
	cout << "List" << endl;
	for (int it : aList) {
		cout << it << " ";
	}
	cout << endl;
}

void printVector(const vector<int>& aVector) {
	cout << "Vector" << endl;
	for (int it : aVector) {
		cout << it << " ";
	}
	cout << endl;
}

void populateList(list<int>& aList) {
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++) {
		aList.push_back(i);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
	cout << "List took: " << duration.count() << " ms" << endl;
}

void populateVector(vector<int>& aVector) {
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 10; i++) {
		aVector.push_back(i);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
	cout << "Vector took: " << duration.count() << " ms" << endl;
}

void runLinkedListExample() {
	list<int> theList;
	vector<int> theVector;
	populateList(theList);
	populateVector(theVector);

	printList(theList);
	printVector(theVector);
}

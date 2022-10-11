#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include "Base.hpp"
#include "Derived.hpp"

using std::cout, std::endl,
	std::vector, std::string, std::map, std::unordered_map, std::fstream;

void printMap(map<int, size_t> aMap);
void printMap(unordered_map<int, size_t> aMap);

bool isPunct(char aChar) {
	static std::string punct(".;?!:,'-\nA");
	return std::string::npos != punct.find(aChar);
}

void runFrequencyExample() {
	vector<int> numbers = {3, 1, 4, 5, 3, 4, 5};
//	map<int, size_t> theFrequencies;
	unordered_map<int, size_t> theFrequencies;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (theFrequencies.find(numbers[i]) == theFrequencies.end()) { // key not found
            theFrequencies[numbers[i]] = 1;
        } else {
            theFrequencies[numbers[i]] += 1;
        }
        printMap(theFrequencies);
        std::cout << endl;
    }
}

void runFileExample() {
	/*
	 * g, p pointers (get, put)
	 *  tell, seek
	 * get, getline, >> operator
	 */
	string filename = R"(C:\Users\steph\Documents\Class\TA\ECE 17\FA22\ECE-17-FA22-Discussion\Discussion 3\text.txt)";
	fstream stream(filename);

	if (!stream.is_open()) {
	    return;
	}
//    cout << (char) stream.get() << endl;
//    cout << (char) stream.get() << endl;
//    cout << (char) stream.get() << endl;
//    cout << (std::string) stream.getline()
//    stream.seekg(0);
//	cout << stream.tellg() << " " << stream.tellp();
	string temp;
	while (stream >> temp) {
	    cout << temp << ((stream.eof() || isPunct((char) stream.peek())) ? "" : "_");
	    while (stream.peek() == '\n') {
	        cout << "\n";
	        stream.get();
	    }
	}
}

void runUserInputExample() {
    cout << "Enter an input: ";
    string userInput;
    std::cin >> userInput;
    cout << userInput;
}

void runStringCleaningExample() {
	/*
	 * removing punctuation
	 * making all characters lowercase
	 */
	string a = "1AS.,Ss";
	cout << a << endl;
	a.erase(std::remove_if(a.begin(), a.end(), isPunct), a.end());
	cout << a << endl;
}

void runInheritanceExample() {
	Base baseClass;
	Derived derivedClass;
	baseClass.printHi();
	derivedClass.printHi();
	derivedClass.printHere();
}

int main(int argc, const char* argv[]) {
	if (argc <= 1) {
		return 0;
	}
	string argument(argv[1]);
	if (argument == "frequency") {
		runFrequencyExample();
	} else if (argument == "file") {
		runFileExample();
	} else if (argument == "user") {
		runUserInputExample();
	} else if (argument == "string") {
		runStringCleaningExample();
	} else if (argument == "inheritance") {
		runInheritanceExample();
	}
	return 0;
}

void printMap(map<int, size_t> aMap) {
	for (auto& pair : aMap) {
		cout << "{ " << pair.first << ", " << pair.second << " }" << endl;
	}
}

void printMap(unordered_map<int, size_t> aMap) {
	for (auto& pair : aMap) {
		cout << "{ " << pair.first << ", " << pair.second << " }" << endl;
	}
}


#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::endl,
		std::ifstream, std::map, std::string, std::vector, std::function,
		std::pair;

using IntPair = pair<int, int>;
using WordFreq = map<string, size_t>;
using FreqPair = pair<string, size_t>;

template <typename T>
void printVector(vector<T>& aVec, string aSep="", string anEnd="\n") {
	for (T element : aVec) {
		cout << std::to_string(element) << aSep;
	}
	cout << anEnd;
}

template <typename T>
void printVector(vector<pair<T, T>>& aVec, string aSep="", string anEnd="\n") {
	for (pair<T, T> element : aVec) {
		cout << element.first << ":" << element.second << aSep;
	}
	cout << anEnd;
}

void vectorExample(ifstream& theInput);
void streamExample(ifstream& theInput);

static map<string, function<void(ifstream& theInput)>> argumentFunctions = {
		{"vector", vectorExample},
		{"stream", streamExample},
};

void outputFile(vector<string> aWords) {
	for (auto &word: aWords) {
	    if (word == "paragraph") {
	        cout << "_";
	    } else {
            cout << word;
        }
		if (word.back() != '\n') {
			cout << " ";
		}
	}
}

void vectorExample(ifstream& theInput) {
	vector<string> words;
	string currentWord;
	while (theInput >> currentWord) {
		while (!theInput.eof() && theInput.peek() == '\n') {
			currentWord += "\n";
			theInput.get();
		}
		words.push_back(currentWord);
	}

	outputFile(words);
	// Get Stream flags
//    cout << std::hex << theInput.flags() << endl;
}

bool customComparator(const std::pair<int, int>& aLeft, const std::pair<int, int>& aRight) {
    if (aLeft.second != aRight.second) {
        return aLeft.second < aRight.second;
    }
    return aLeft.first < aRight.first;
}

void streamExample(ifstream& theInput) {
	vector<std::pair<int, int>> vec = {
			{1, 2},
			{3, 0},
			{1, 3},
			{1, 2},
			{2, 1},
			{2, 3},
	};
    int aNum = 3;
    printVector(vec, ", ");
    std::sort(vec.begin(), vec.end(), [&vec, aNum](const std::pair<int, int>& aLeft, const std::pair<int, int>& aRight){
        if (aLeft.second != aRight.second) {
            return aLeft.second < aRight.second;
        }
        return aLeft.first < aRight.first;
    });
    printVector(vec, ", ");

    // Sorting a vector of ints
//	vector<int> anotherVec = {2, 3, 6, 2, 1, 2};
//    printVector(anotherVec, ", ");
//    std::sort(anotherVec.begin(), anotherVec.end(), customComparator);
//    printVector(anotherVec, ", ");

    // Resetting the flags example
//    WordFreq words;
//    string currentWord;
//    while (theInput >> currentWord) {
//        while (!theInput.eof() && theInput.peek() == '\n') {
//            currentWord += "\n";
//            theInput.get();
//        }
//        words[currentWord]++;
//    }
//    theInput.clear();
//    theInput.seekg(0, std::ios::beg);
//    theInput >> currentWord;
//    int a = 1;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		return 0;
	}
	ifstream theFile("../text.txt");
	if (!theFile.is_open()) {
		cout << "Could not open file" << endl;
		return -1;
	}
	argumentFunctions[argv[1]](theFile);

	return 0;
}

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
		cout << word;
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
}

void streamExample(ifstream& theInput) {
	vector<std::pair<int, int>> vec = {
			{1, 2},
			{3, 4},
			{1, 3},
			{1, 4},
			{2, 3},
			{2, 4},
	};
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

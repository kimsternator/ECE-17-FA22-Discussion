#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#include "Card.hpp"

// Using keywords
using std::vector, std::cout, std::endl, std::string,
ECE17::Card, ECE17::Faces, ECE17::Suits;

// Forward Declarations
void runTests();
template <typename T>
void printVector(vector<T> aVec, const string& aSep = "\n", const string& aEnd = "\n");
string printBool(bool aBool);
void runShuffle();

string printBool(bool aBool) {
    return aBool ? "True" : "False";
}

double findMean(vector<int> aVec) {
    return 0.0;
}

int findMode(vector<int> aVec) {
    return -1;
}

bool containsNumber(vector<int> aVec, int aNum) {
    return false;
}

void shuffleVector(vector<int> &aVec) {

}

void cardExamples() {
    Card theCard;
    cout << theCard << endl;
    Card anotherCard(Faces::king, Suits::diamonds);
    cout << printBool(theCard == anotherCard) << endl;
}

int main(int argc, const char * argv[]) {
    if (argc <= 1) {
        return 0;
    }
    string testArg(argv[1]);
    if (testArg == "vector") {
        runTests();
    } else if (testArg == "shuffle") {
        runShuffle();
    } else if (testArg == "card") {
        cardExamples();
    }
    return 0;
}

template <typename T>
void printVector(vector<T> aVec, const string& aSep, const string& aEnd) {
    for (T& val: aVec) {
        cout << val << aSep;
    }
    cout << aEnd;
}

void runMeanTest() {
    vector<int> theVec = {1, 2, 3, 4, 5};
    double foundMean = findMean(theVec);
    double expectedMean = std::accumulate(theVec.begin(), theVec.end(), 0.0) / theVec.size();
    cout << "Mean Test\n" << "Expected: " << expectedMean << " | Found: " << foundMean << endl;
}

void runModeTest() {
    vector<int> theVec = {1, 2, 3, 1, 2, 2};
    int foundMode = findMode(theVec);
    int expectedMode = 2;
    cout << "Mode Test\n" << "Expected: " << expectedMode << " | Found: " << foundMode << endl;
}

void runContainsNumberTest() {
    vector<int> theVec = {1, 2, 0, 3, 4, 5};
    bool foundContainsNumber = containsNumber(theVec, 0);
    bool expectedContainsNumber = true;
    cout << "Contains Test\n" << "Expected: " << printBool(expectedContainsNumber) << " | Found: " << printBool(foundContainsNumber) << endl;
}

void runTests() {
    runMeanTest();
    runModeTest();
    runContainsNumberTest();
}

void runShuffle() {
    vector<int> theVec = {1, 2, 3, 4, 5};
    cout << "Initial Vector" << endl;
    printVector(theVec, ", ");
    shuffleVector(theVec);
    cout << "Shuffled Vector" << endl;
    printVector(theVec, ", ");
}
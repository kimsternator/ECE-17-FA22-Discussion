#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

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
    // list of numbers - mean
//    // Iteration approach
//    for (auto it = aVec.begin(); it != aVec.end(); it++) {}
//    // Range
//    for (auto val : aVec) {}
    // Index
    double sum = 0.0;
    for (size_t i = 0; i < aVec.size(); i++) {
        sum += aVec[i];
    }
    // Runtime polymorphism

    return sum / aVec.size();
}

int findMode(vector<int> aVec) {
    // 1 2 3 3 - 3
    int maxElement = 0, maxFreq = 0;
    for (int i = 0; i < aVec.size(); i++) {
        int count = 0;
        for (int j = 0; j < aVec.size(); j++) {
            if (i == j) {
                continue;
            }
            if (aVec[i] == aVec[j]) {
                count++;
            }
        }
        if (maxFreq < count) {
            maxElement = aVec[i];
            maxFreq = count;
        }
    }
    return maxElement;
}

// Pass-by-value
bool containsNumber(vector<int> aVec, int aNum) {
    for (auto val : aVec) {
        if (val == aNum) {
            return true;
        }
    }
    return false;
}

void swap(vector<int> &aVec, size_t i1, size_t i2) {
    int temp = aVec[i1];
    aVec[i1] = aVec[i2];
    aVec[i2] = temp;
}

// Pass-by-reference
void shuffleVector(vector<int> &aVec) {
    /* Iterate over the vector
     * swap current index with a random index
     * {0, .., size - 1}
    */
//    for (size_t i = 0; i < aVec.size(); i++) {
//        size_t randomIndex = rand() % aVec.size();
//        swap(aVec, i, randomIndex);
//    }

    srand(NULL);
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(aVec), std::end(aVec), rng);
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

void example() {
    vector<Suits> suits = {Suits::diamonds, Suits::spades, Suits::hearts, Suits::clubs};
    for (int face = (int) Faces::two; face <= (int) Faces::ace; face++) {
        for (Suits suit : suits) {
            cout << face << " " << (char) suit << endl;
        }
    }
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
#include <iostream>
#include <vector>
#include <string>
#include <variant>

struct Base;

using namespace std;
using VARIANT = variant<int, string, Base*>;

//Visitor Pattern
template <typename T>
void printVector(vector<T>& aVec, string aSep="", string anEnd="\n") {
    for (T element : aVec) {
        cout << std::to_string(element) << aSep;
    }
    cout << anEnd;
}

// Exist in the source code (PA4 exist in LinkedList class)
// interface (purely virtual)
class IVisitor {
public:
    virtual void visit(int aNum)=0;
};

void visitWith(vector<int>& aVec, IVisitor* aVisitor) {
    for (auto element : aVec) {
        aVisitor->visit(element);
    }
}

// Exist in the user code (PA4 exists in testing file)
class PrintVisitor : public IVisitor {
public:
    void visit(int aNum) override {
        cout << aNum;
    }
};

class PrintSpaceVisitor : public IVisitor {
public:
    void visit(int aNum) override {
        cout << aNum << " ";
    }
};

// Runtime polymorphism

struct Base {
    virtual void fun() {
        cout << "Base" << endl;
    }
};
struct Child1 : public Base {
    virtual void fun() override {
        cout << "Child1" << endl;
    }
};
struct Child2 : public Base {
    virtual void fun() override {
        cout << "Child2" << endl;
    }
};
struct Child11 : public Child1 {
    virtual void fun() override {
        cout << "Child11" << endl;
    }
};

// Variant

int main() {
//    vector<int> intVec = {1, 2, 3, 4, 5, 6};
//    IVisitor* aVisitor = new PrintVisitor();
//    IVisitor* anotherVisitor = new PrintSpaceVisitor();
//    visitWith(intVec, aVisitor);
//    cout << endl;
//    visitWith(intVec, anotherVisitor);

//    vector<int> theVec = {1, 2, 3, 4, 5, 6};
//    vector<Base*> anotherVec = {new Base(), new Child1(), new Child2(), new Child11()};
//
//    for (Base* element : anotherVec) {
//        element->fun();
//    }

    /*
     * C
     * any variable can be it's type (for value) or NULL
     * Java
     * same story
     * Python (Dynamically typed)
     * a = 1
     * a = "s"
     * similar except it's value or None
     *
     * C++
     * nullptr = 0
     * Optional => value or std::nullopt
     * variant<
     */

    VARIANT theVar;
    vector<VARIANT> theVec = {1, "s", new Base(), new Child1()};

    return 0;
}

/* within a Node class
 * Node* this;
 *
 * Node& call operator ()
 * *this => Node
 * class Node {
 *  Node& operator()() {
 *      return *this;
 *  }
 * }
 * // workaround
 * (*this)();
 */

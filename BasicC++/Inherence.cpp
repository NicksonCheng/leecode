#include <iostream>
using namespace std;

class A {
  public:
	A() { cout << "Construct A" << endl; }
	~A() { cout << "Destruct A" << endl; }

  private:
};
class B : public A {
  public:
	B() { cout << "Construct B" << endl; }
	~B() { cout << "Destruct B" << endl; }

  private:
};

int main() { B b; }
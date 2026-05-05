#include<iostream>
using namespace std;

class Prototype {
public:
    virtual Prototype* getPrototype() const = 0;
    virtual ~Prototype() = default;
};

class Shape : public Prototype {
private:
    int length;
    int breadth;
    int* temp;

public:
    Shape(int l, int b, int* c) {
        length = l;
        breadth = b;
        temp = new int(*c);  // deep copy
    }

    Shape(const Shape& instance) {
        length = instance.length;
        breadth = instance.breadth;
        temp = new int(*(instance.temp));
    }

    ~Shape() {
        delete temp;
    }

    Prototype* getPrototype() const override {
        return new Shape(*this);
    }

    void getDetails() {
        cout << length << endl;
        cout << breadth << endl;
        cout << *temp << endl;
    }
};

int main()
{
    int c = 20;
    Shape s1(10,12,&c);
    s1.getDetails();
    auto s2 = s1.getPrototype();
}
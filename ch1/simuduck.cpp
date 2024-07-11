#include <iostream>
using namespace std;

/*
  Duck class
  Three methods
  1. quack
  2. swim
  3. display (abstract)
*/
class Duck
{
    void quack()
    {
        cout<<"Quack Quack";
    }

    void swim()
    {
        cout<<"Swim Swim";
    }

    //Abstract function
    virtual void display() const = 0;
};

class MallardDuck: public Duck
{
    void display() const override
    {
        cout<<"MallardDuck";
    }
};

class RedHeadDuck: public Duck
{
    void display() const override
    {
        cout<<"RedHeadDuck";
    }
};


int main()
{
  return 0;
}
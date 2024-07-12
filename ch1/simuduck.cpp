/*
1. New requirement
1.1 Ducks need to fly
        We can add another fly function in Duck class
        Issue is now every duck can fly 
        but duck like wooden or rubber duck can't fly
        we can overrride the fly function in particualr scenario
        but if more duck types are added then we need to override it at may places
        This will create duplicacy of code

 */
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
    public: 
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

    void fly()
    {
        cout<<"Fly Fly";
    }
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

class RubberDuck: public Duck
{

    public: 
    void display() const override
    {
        cout<<"RubberDuck";
    }

    void quack()
    {
        cout<<"Squeak Squeak";
    }
};


int main()
{
  RubberDuck rduck;
  rduck.swim();
  rduck.display();
  return 0;
}
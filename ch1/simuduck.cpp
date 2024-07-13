/*
1. New requirement
1.1 Ducks need to fly
        We can add another fly function in Duck class
        Issue is now every duck can fly 
        but duck like wooden or rubber duck can't fly
        we can overrride the fly function in particualr scenario
        but if more duck types are added then we need to override it at may places
        This will create duplicacy of code
1.2 Interface
    In C++ we don't have interface as such 
    but we can use a class which would only have pure virtual function
    Interface is a way to describe the behaviour of class without commiting
    to the particular implementation
    we can use interface in this scenario as the class which needs to implement the 
    fly behaviour will only need to implement it.

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

    void swim()
    {
        cout<<"Swim Swim";
    }

    virtual void display() const = 0;

};

//Interface
class Flyable
{
    virtual void fly() = 0;
};

class Quackable
{   
    virtual void quack() = 0;
};

class MallardDuck: public Duck, Flyable,Quackable
{
    void display() const override
    {
        cout<<"MallardDuck";
    }

    void fly() override
    {
        cout<<"mallardDuck";
    }
    void quack() override
    {
        cout <<"quack quack";
    }
};

class RedHeadDuck: public Duck,Flyable,Quackable
{
    void display() const override
    {
        cout<<"RedHeadDuck";
    }
    void fly() override
    {
        cout<<"RedHeadDuck";
    }
    void quack() override
    {
        cout <<"quack quack";
    }
};

class RubberDuck: public Duck,Flyable,Quackable
{

    public: 
    void display() const override
    {
        cout<<"RubberDuck";
    }

    void quack () override
    {
        cout<<"Squeak Squeak";
    }
    void fly() override
    {
        cout<<"Squeak Squeak";
    }
};


int main()
{
  RubberDuck rduck;
  RedHeadDuck redDuck;
  MallardDuck mduck;
  rduck.swim();
  rduck.display();
  rduck.quack();
  return 0;
}
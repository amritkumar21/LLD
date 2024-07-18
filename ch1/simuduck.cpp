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
1.3 Issue with adding interface
    If we need to change fly method a little we need to do it on all places where it is implemented
    Since fly functiolanlity is will remain same for all duck it will create duplicacy of code

1.4 Design Principle **** Strategy design patter (behavioural)****
    Separate the whats stays the same with what varies
1.5 OO principles 
    Favour composition over inheritance
    Encapsulates what veries
    Program to interaces not implementation
1.6 Stratgey pattern
    It defines a family of algorithms
    encapsualtes each one and make them interchangable.
    It lets the algorithm varies independently from the client that use it

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

class FlyBehaviour
{
    public:
    virtual void fly() = 0;
};

class QuackBehaviour
{
    public:
    virtual void quack() = 0;
};

class Quack:public QuackBehaviour
{
    void quack() override
    {
      cout<<"Quack";
    }
};

class Squeak:public QuackBehaviour
{
    void quack() override
    {
      cout<<"Squeak";
    }
};

class MuteQuack:public QuackBehaviour
{
    void quack() override
    {
      cout<<"MuteQuack";
    }
};

class Duck
{
    public: 

    FlyBehaviour* flyBehaviour;
    QuackBehaviour* quackBehaviour;

    void swim()
    {
        cout<<"Swim Swim";
    }
    void performQuack()
    {
        quackBehaviour->quack();
    }
    void performFly()
    {
        flyBehaviour->fly();
    }
    void setFlyBehaviour(FlyBehaviour* fb)
    {
       flyBehaviour = fb;
    }
    void setQuackBehaviour(QuackBehaviour* qb)
    {
        quackBehaviour = qb;
    }
    virtual void display() const = 0;

};

class FlyWithWings:public FlyBehaviour
{
    void fly() override
    {
      cout<<"fly with wings";
    }
};

class FlyNoWay:public FlyBehaviour
{
    void fly() override
    {
      cout<<"fly no way";
    }
};



class MallardDuck: public Duck
{
   public:
   MallardDuck()
   {
     quackBehaviour = new Quack();
     flyBehaviour = new FlyWithWings();
   }

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
};

class Modelduck: public Duck
{
   public:
   Modelduck()
   {
     quackBehaviour = new Quack();
     flyBehaviour = new FlyNoWay();
   }

   void display() const override
   {
    cout<<"Modelduck";
   }   
};

int main()
{

  MallardDuck mduck;
  mduck.performFly();
  mduck.performQuack();
  mduck.display();
  cout<<"\n";

  Modelduck moduck;
  moduck.performFly();
  moduck.performQuack();
  cout<<"\n";

  moduck.setQuackBehaviour(new Squeak());
  moduck.setFlyBehaviour(new FlyWithWings());
  moduck.performFly();
  moduck.performQuack();


  return 0;
}
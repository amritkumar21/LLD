#include<iostream>
using namespace std;

/*
Boil water
Brew beverage (varies)
Pour into cup
Add condiments (varies)
*/

class PrepareBeverage
{
    protected: 
        void boilWater()
        { 
            cout<<"Boiling water"<<endl;
        }
        void pour()
        { 
            cout<<"Pouring into cup"<<endl;
        }
        virtual void addCond()=0;
        virtual void brew() = 0;
    public:
        virtual void prepareReceipe() final
        {
            boilWater();
            brew();
            pour();
            addCond();
        }

        virtual ~PrepareBeverage() =default;
};


class PrepareCoffee: public PrepareBeverage
{
    public:
        void addCond() override
        {
            cout<<"Adding Sugar and milk"<<endl;
        }

        void brew() override
        {
            cout<<"Brewing coffee"<<endl;
        }
};


class PrepareTea: public PrepareBeverage
{
    public:
        void addCond() override
        {
            cout<<"Adding Lemon"<<endl;
        }

        void brew() override
        {
            cout<<"Steeping tea leaves"<<endl;
        }
};

int main()
{
    PrepareBeverage* tea = new PrepareTea();
    PrepareCoffee* coffee = new PrepareCoffee();
    coffee->prepareReceipe();
    tea->prepareReceipe();

    delete coffee;
    delete tea;
}
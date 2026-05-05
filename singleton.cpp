#include<iostream>
using namespace std;


class Singleton
{
    private:
        Singleton(){ cout<<"First instance called"<<endl;}
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
    public:
        static Singleton& getInstance()
        {
           static Singleton instance;
           return instance;
        }   
};

int main()
{
    auto& instance1 = Singleton::getInstance();
    auto& instance2 = Singleton::getInstance();
}
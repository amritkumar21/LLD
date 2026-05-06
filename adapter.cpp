#include<iostream>
#include<memory>
using namespace std;

class ModernPaymentSystem
{
    public:
        virtual void pay(int amount) = 0;
        virtual ~ModernPaymentSystem() = default;

};

class LegacyPaymentSystem
{
    public:
        void payAmount(double amount)
        {
            cout<<"Amount Paid :"<<amount<<endl;
        }
};

class ModernLegacyAdapter: public ModernPaymentSystem
{
    private:
        unique_ptr<LegacyPaymentSystem> legacySystem;
    public:
        ModernLegacyAdapter(unique_ptr<LegacyPaymentSystem> legacySystem)
        {
            this->legacySystem = std::move(legacySystem);
        }
        void pay(int amount) override
        {
            legacySystem->payAmount(double(amount));
        }
};


int main()
{
    ModernLegacyAdapter m(make_unique<LegacyPaymentSystem>());
    m.pay(100);

}
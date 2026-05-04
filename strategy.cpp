#include<iostream>
#include<memory>
using namespace std;

class PaymentStrategy
{
    public:
        virtual void pay(int amount) = 0;
        virtual ~PaymentStrategy() = default;
};

class UPI: public PaymentStrategy
{
    public:
        void pay(int amount) override
        {
            cout<<"Payment of rs "<<amount<<" done via UPI"<<endl;
        }
};

class DebitCard: public PaymentStrategy
{
    public:
        void pay(int amount) override
        {
            cout<<"Payment of rs "<<amount<<" done via Debit Card"<<endl;
        }
};

class CreditCard: public PaymentStrategy
{
    public:
        void pay(int amount) override
        {
            cout<<"Payment of rs "<<amount<<" done via Credit Card"<<endl;
        }
};

class PaymentContext
{
    private:
        unique_ptr<PaymentStrategy> payMethod;
    public:
        void makePayment(int amount)
        {
            if(payMethod != nullptr)
            {
              payMethod->pay(amount);
            }
            else
            {
                cout<<"Please select a payment method first"<<endl;
            }
        }
        void setContext(unique_ptr<PaymentStrategy> payMethod)
        {
            this->payMethod = std::move(payMethod);
        }

};


class PaymentFactory
{
    public:
        virtual unique_ptr<PaymentStrategy> createPaymentMethod() = 0;
        virtual ~PaymentFactory() = default;
};

class UPIFactory: public PaymentFactory
{
    public:
        unique_ptr<PaymentStrategy> createPaymentMethod() override
        {
              return make_unique<UPI>();
        }
};

class CreditFactory: public PaymentFactory
{
    public:
        unique_ptr<PaymentStrategy> createPaymentMethod() override
        {
              return make_unique<CreditCard>();
        }
};

class DebitFactory: public PaymentFactory
{
    public:
        unique_ptr<PaymentStrategy> createPaymentMethod() override
        {
              return make_unique<DebitCard>();
        }
};

int main()
{
    PaymentContext context;
    UPIFactory upi;
    context.setContext(upi.createPaymentMethod());
    context.makePayment(100);
}
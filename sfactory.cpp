#include<iostream>
#include<memory>
using namespace std;

class Notification
{
    public:
        virtual void sendMessage(string msg) = 0;
        virtual ~Notification() = default;
};

class SMS: public Notification
{
    public:
        void sendMessage(string msg) override
        {
           cout<<"Msg send via sms"<<endl;
           cout<<msg<<endl;
        }
};

class Email: public Notification
{
    public:
        void sendMessage(string msg) override
        {
           cout<<"Msg send via email"<<endl;
           cout<<msg<<endl;
        }
};

class Push: public Notification
{
    public:
        void sendMessage(string msg) override
        {
           cout<<"Msg send via push"<<endl;
           cout<<msg<<endl;
        }
};

class NotificationFactory
{
    public:
        unique_ptr<Notification> createNotification(string type)
        {
               if(type=="sms") return make_unique<SMS>();
               if(type=="email") return make_unique<Email>();
               if(type=="push") return make_unique<Push>();
               return nullptr;
        }
};

int main()
{
    NotificationFactory factory;
    unique_ptr<Notification> sms = factory.createNotification("sms");
    sms->sendMessage("hello");
}
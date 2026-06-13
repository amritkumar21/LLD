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
       virtual unique_ptr<Notification> createNotification() = 0;
       virtual ~NotificationFactory() = default;
};

class SmsFactory: public NotificationFactory
{
    public:
        unique_ptr<Notification> createNotification()override
        {
            return make_unique<SMS>();
        }

};

class EmailFactory: public NotificationFactory
{
    public:
        unique_ptr<Notification> createNotification()override
        {
            return make_unique<Email>();
        }

};

class PushFactory: public NotificationFactory
{
    public:
        unique_ptr<Notification> createNotification() override
        {
            return make_unique<Push>();
        }

};

int main()
{
    EmailFactory emailFactory;
    unique_ptr<Notification> email = emailFactory.createNotification();
    email->sendMessage("Hi hello there");
}
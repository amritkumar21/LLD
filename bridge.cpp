#include<iostream>
#include<memory>
using namespace std;

//Implementation
class DeliveryChannel
{
    public:
        virtual void sendMessage(string msg) = 0;
        virtual ~DeliveryChannel() = default;
};

//Abstraction
class Notification
{
    protected:
        shared_ptr<DeliveryChannel> channel;
    public:
        Notification(shared_ptr<DeliveryChannel> channel)
        {
            this->channel = channel;
        }
        virtual void sendNotification(string msg) = 0;
        virtual ~Notification() = default;
};

class BasicNotification: public Notification
{
    public:
        BasicNotification(shared_ptr<DeliveryChannel> channel):Notification(channel) {}
        virtual void sendNotification(string msg) override
        {
           cout<<"Send Basic notification"<<endl;
           channel->sendMessage(msg);
        }
};

class UrgentNotification: public Notification
{
    public:
        UrgentNotification(shared_ptr<DeliveryChannel> channel):Notification(channel) {}
        virtual void sendNotification(string msg) override
        {
           cout<<"Send Urgent notification"<<endl;
           channel->sendMessage(msg);
        }
};

class ScheduledNotification: public Notification
{
    public:
        ScheduledNotification(shared_ptr<DeliveryChannel> channel):Notification(channel) {}
        virtual void sendNotification(string msg) override
        {
           cout<<"Send Scheduled notification"<<endl;
           channel->sendMessage(msg);
        }
};

class Email:public DeliveryChannel
{
    public:
        void sendMessage(string msg) override
        {
            cout<<"Msg sent via email : "<<msg<<endl;
        }
};

class SMS:public DeliveryChannel
{
    public:
        void sendMessage(string msg) override
        {
            cout<<"Msg sent via sms : "<<msg<<endl;
        }
};


class Push:public DeliveryChannel
{
    public:
        void sendMessage(string msg) override
        {
            cout<<"Msg sent via push notification : "<<msg<<endl;
        }
};

int main()
{
    shared_ptr<DeliveryChannel> sms = make_shared<SMS>();
    shared_ptr<DeliveryChannel> email = make_shared<Email>();

    unique_ptr<Notification> basic = make_unique<BasicNotification>(sms);
    unique_ptr<Notification> urgent = make_unique<UrgentNotification>(email);

    basic->sendNotification("Hello how are you");
    urgent->sendNotification("PC crashed");

}
#include<iostream>
#include<memory>
using namespace std;

class Platform
{
    public:
        virtual string selectPlatform() = 0;
        virtual ~Platform() = default;
};

class Windows: public Platform
{
    public:
        string selectPlatform()
        {
            return "Windows";
        }
};

class Mac: public Platform
{
    public:
        string selectPlatform()
        {
            return "Mac";
        }
};

class Linux: public Platform
{
    public:
        string selectPlatform()
        {
            return "Linux";
        }
};

class Player
{
    protected:
        unique_ptr<Platform> p;
    public:
        Player(unique_ptr<Platform> player):p(std::move(player)){}
        virtual void createPlayer() = 0;
        virtual ~Player() = default;
};

class MP4: public Player
{
    public:
        MP4(unique_ptr<Platform> player):Player(std::move(player)){}
        void createPlayer() override
        {
            cout<<"MP4"<<p->selectPlatform()<<"player"<<endl;
        }
};

class AVI: public Player
{
    public:
        AVI(unique_ptr<Platform> player):Player(std::move(player)){}
        void createPlayer() override
        {
            cout<<"AVI"<<p->selectPlatform()<<"player"<<endl;
        }
};

class MKV: public Player
{
    public:
       MKV(unique_ptr<Platform> player):Player(std::move(player)){}
        void createPlayer() override
        {
            cout<<"MKV"<<p->selectPlatform()<<"player"<<endl;
        }
};

int main()
{
    unique_ptr<Player> p = make_unique<MP4>(make_unique<Windows>());
    p->createPlayer();

}


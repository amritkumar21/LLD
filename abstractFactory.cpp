#include<iostream>
#include<memory>
using namespace std;


class GUI
{
    public:
        virtual void render() = 0;
        virtual ~GUI() = default;
};

class WindowButton: public GUI
{
    public:
        void render() override
        {
            cout<<"Windows button created"<<endl;
        }
};

class MacButton: public GUI
{
    public:
        void render() override
        {
            cout<<"Mac button created"<<endl;
        }
};


class WindowTextBox: public GUI
{
    public:
        void render() override
        {
            cout<<"Windows textbox created"<<endl;
        }
};

class MacTextBox: public GUI
{
    public:
        void render() override
        {
            cout<<"Mac textbox created"<<endl;
        }
};

class WindowCheckBox: public GUI
{
    public:
        void render() override
        {
            cout<<"Windows checkbox created"<<endl;
        }
};

class MacCheckBox: public GUI
{
    public:
        void render() override
        {
            cout<<"Mac checkbox created"<<endl;
        }
};


class GUIFactory
{
    public:
        virtual unique_ptr<GUI> createButton() = 0;
        virtual unique_ptr<GUI> createTextbox() = 0;
        virtual unique_ptr<GUI> createCheckbox() = 0;
        virtual ~GUIFactory() = default;
};


class WindowFactory: public GUIFactory
{
    public:
        unique_ptr<GUI> createButton() override
        {
            return make_unique<WindowButton>();
        }
        unique_ptr<GUI> createTextbox() override
        {
            return make_unique<WindowTextBox>();
        }
        unique_ptr<GUI> createCheckbox() override
        {
            return make_unique<WindowCheckBox>();
        }
};

class MacFactory: public GUIFactory
{
    public:
        unique_ptr<GUI> createButton() override
        {
            return make_unique<MacButton>();
        }
        unique_ptr<GUI> createTextbox() override
        {
            return make_unique<MacTextBox>();
        }
        unique_ptr<GUI> createCheckbox() override
        {
            return make_unique<MacCheckBox>();
        }
};

int main()
{
    WindowFactory wf;
    auto button = wf.createButton();
    auto checkbox = wf.createCheckbox();
    auto textbox = wf.createTextbox();

    button->render();
    checkbox->render();
    textbox->render();
}


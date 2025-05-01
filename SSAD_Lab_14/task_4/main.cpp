#include <iostream>
#include <vector>

using namespace std;

class Button
{
public:
    virtual void paint() = 0;
};

class WinButton : virtual public Button
{
public:
    WinButton() = default;
    void paint() {
        cout << "Win Button" << endl;
    }
};

class MacButton : virtual public Button
{
public:
    MacButton() = default;
    void paint() {
        cout << "Mac Button" << endl;
    }
};

class Checkbox
{
public:
    virtual void paint() = 0;
};

class WinCheckbox : virtual public Checkbox
{
public:
    WinCheckbox() = default;
    void paint() {
        cout << "Win Checkbox" << endl;
    }
};

class MacCheckbox : virtual public Checkbox
{
public:
    MacCheckbox() = default;
    void paint() {
        cout << "Mac Checkbox" << endl;
    }
};

class GUIFactory
{
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual string getName() = 0;
};

class WinFactory : virtual public GUIFactory
{
private:
    string name = "Win UI";
public:
    Button* createButton() override {
        return new WinButton();
    }
    Checkbox* createCheckbox() override {
        return new WinCheckbox();
    }
    string getName() override {
        return name;
    }
};

class MacFactory : virtual public GUIFactory
{
private:
    string name = "Mac UI";
public:
    Button* createButton() override {
        return new MacButton();
    }
    Checkbox* createCheckbox() override {
        return new MacCheckbox();
    }
    string getName() override {
        return name;
    }
};

class Application
{
private:
    GUIFactory* factory;
    Button* button;
    Checkbox* checkbox;
public:
    Application(GUIFactory* f) {
        this->factory = f;
    }
    void createUI() {
        button = factory->createButton();
        checkbox = factory->createCheckbox();
    }
    void paint() {
        cout << factory->getName() << ":" << endl;
        cout << "    -";
        button->paint();
        cout << "    -";
        checkbox->paint();
    }
};

int main() {
    GUIFactory* factory = new MacFactory();
    Application* application = new Application(factory);
    application->createUI();
    application->paint();
}
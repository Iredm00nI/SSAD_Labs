#include <iostream>
#include <vector>

using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal (string name, int age) {
        this->name = name;
        this->age = age;
    }
    virtual void makeSound() = 0;
};

class LandAnimal : virtual public Animal {
public:
    LandAnimal(string name, int age) : Animal(name, age) {};
    virtual void walk() = 0;
    void makeSound() override {
        cout << "Land animal make sound:" << endl;
    }
};

class WaterAnimal : virtual public Animal {
public:
    WaterAnimal(string name, int age) : Animal (name, age) {};
    virtual void swim() = 0;
    void makeSound() override {
        cout << "Water animal make sound:" << endl;
    }
};

class Lion : public LandAnimal{
public:
    Lion(string name, int age) : LandAnimal(name, age), Animal (name, age) {};
    void makeSound() override {
        LandAnimal::makeSound();
        cout << "    - Lion says: ROAR" << endl;

    }
    void walk() override {
        cout << "Lion walks" << endl;
    }
};

class Dolphin : public WaterAnimal {
public:
    Dolphin(string name, int age) : WaterAnimal(name, age), Animal (name, age) {};
    void makeSound() override {
        WaterAnimal::makeSound();
        cout << "    - Dolphin says: CLICK" << endl;
    }
    void swim() override {
        cout << "Dolphin swims" << endl;
    }
};

class Frog : public WaterAnimal, public LandAnimal {
public:
    Frog(string name, int age) : WaterAnimal(name, age), LandAnimal(name, age), Animal (name, age) {};
    void makeSound() override {
        LandAnimal::makeSound();
        WaterAnimal::makeSound();
        cout << "    - Frog says: CROAK" << endl;
    }
    void walk() override {
        cout << "Frog walks" << endl;
    }
    void swim() override {
        cout << "Frog swims" << endl;
    }
};

int main()
{
    vector<Animal*> zoo;
    zoo.push_back(new Lion("Lion", 5));
    zoo.push_back(new Dolphin("Dolphin", 21));
    zoo.push_back(new Frog("Frog", 18));
    for(int i=0; i<zoo.size(); i++) {
        zoo[i]->makeSound();

    }

    return 0;
}

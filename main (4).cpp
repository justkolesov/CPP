#include <iostream>
#include <memory>
#include <vector>
using namespace std;



struct Fruit{
    int health = 0;
    string type = "Fruit";
};
struct Apple : public Fruit{
    Apple()
    {
        health = 10;
        type = "Apple";
    }
};

struct Orange : public Fruit{
    Orange()
    {
        health = 5;
        type = "Orange";
    }
};

struct Pineaplle:public Fruit{
    Pineaplle()
    {
        health = 8;
        type = "pineapple";
    }
};


class Animal{
public:
    Animal(const string&t):type_(t){}  
    void Eat(const Fruit& fruit){
        cout << type_ << "  eats  " << fruit.type << endl;
    }
    virtual void Voice() const{}
private:
    const string type_;
};



class Cat : public Animal{
public:
    Cat():Animal("cat"){
        
    }
    void Voice() const override
    {
        cout << "meow!!"<<endl;
    }
    
};

class Dog : public Animal{
public:
    Dog():Animal("dog"){
    }
    
    void Voice() const override
    {
        cout << " whaf!! " << endl;
    }
};

class Parrot: public Animal{
public:
    Parrot(const  string& name): Animal("parrot"),name_(name){}
    void Voice() const override
    {
        cout << name_ << " is good!" << endl;
    }
private:
    const string name_;
};

void MakeSound(const Animal& a)
{
    a.Voice();
}

 

int main()
{
    Cat c;
    Dog d;
    Parrot p("kesha");
    vector<shared_ptr<Animal>> animals = {
        make_shared<Cat>(),
        make_shared<Dog>(),
        make_shared<Parrot>("Kesha")
    };
    
    for(shared_ptr<Animal> x:animals){
        MakeSound(*x);
    }
    return 0;
}
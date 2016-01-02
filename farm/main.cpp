#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <sstream>
#include <iostream>

class Utils {
    public:
        std::string intToString (int);
        const char * intToConstCharPointer (int);
        std::string floatToString (float);
        const char * floatToConstCharPointer (float);
};

std::string Utils::intToString (int a) {
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

const char * Utils::intToConstCharPointer (int a) {
    std::string temp_string = intToString(a);
    return temp_string.c_str();
}

std::string Utils::floatToString (float a) {
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

const char * Utils::floatToConstCharPointer (float a) {
    std::string temp_string = floatToString(a);
    return temp_string.c_str();
}

class Animal : public Utils {
    protected:
        int p_health, p_hunger, p_mood, p_weight, p_meat;
        float p_repro_rate;
    public:
        Animal (int health=100, int hunger=0, int mood=80, int weight=200, 
            int meat=150, float repro_rate=1.1);  
        int getHealth (void) {return p_health;};
        int getHunger (void) {return p_hunger;};
        int getMood (void) {return p_mood;};
        int getWeight (void) {return p_weight;};
        int getMeat (void) {return p_meat;};
        float getReproductionRate(void) {return p_repro_rate;};
        const char * getHealthAsString (void) {return intToConstCharPointer(p_health);};
        const char * getHungerAsString (void) {return intToConstCharPointer(p_hunger);};
        const char * getMoodAsString (void) {return intToConstCharPointer(p_mood);};
        const char * getWeightAsString (void) {return intToConstCharPointer(p_weight);};
        const char * getMeatAsString (void) {return intToConstCharPointer(p_meat);};
        const char * getReproductionRateAsString (void) {return floatToConstCharPointer(p_repro_rate);};
        void feed (int);
};

Animal::Animal (int health, int hunger, int mood, int weight, 
            int meat, float repro_rate) {

    p_health = health;
    p_hunger = hunger;
    p_mood = mood;
    p_weight = weight;
    p_meat = meat;
    p_repro_rate = repro_rate;

}

class Cow : public Animal {
    protected:
        float p_milk = 2.0;
    public:
        float getMilk (void) {return p_milk;};
};

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
 
    Cow cow;
    const char * weight = cow.getReproductionRateAsString();
    QPushButton button (weight);
    button.show();
 
    return app.exec();
}
#include <utils.h>

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
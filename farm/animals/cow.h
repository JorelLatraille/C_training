#include <animal.h>

class Cow : public Animal {
    protected:
        float p_milk = 2.0;
    public:
        float getMilk (void) {return p_milk;};
};
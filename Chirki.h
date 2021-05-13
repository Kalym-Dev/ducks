#include "Duck.h"
#ifndef GRISHA_CHIRKI_H
#define GRISHA_CHIRKI_H

class Chirki: public Duck{
private:
    int m_health;
    string m_beak_color;

public:
    Chirki(string name, int weight, string beak_color, int health, int what_can = 4): Duck(name, weight, what_can), m_beak_color(beak_color), m_health(health){

    }

    int getHealth();
    string getBeakcolor();

    void setHealth(int health);
    void setBeakcolor(string color);

    virtual void tellAboutYourself() override;

};

#endif //GRISHA_CHIRKI_H

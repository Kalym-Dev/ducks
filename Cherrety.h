#include "Duck.h"
#ifndef GRISHA_CHERRETY_H
#define GRISHA_CHERRETY_H

class Cherrety: public Duck{
private:
    string m_beak_color;
    int m_paw_size;

public:
    Cherrety(string name, int weight, string beak_color, int paw_size, int what_can = 2): Duck(name, weight, what_can), m_beak_color(beak_color), m_paw_size(paw_size){

    }

    string getBeakcolor();
    int getPawsize();

    void setBeakcolor(string color);
    void setPawsize(int paw_size);

    virtual void tellAboutYourself() override;

};

#endif //GRISHA_CHERRETY_H

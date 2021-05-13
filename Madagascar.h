#include "Duck.h"
#ifndef GRISHA_MADAGASCAR_H
#define GRISHA_MADAGASCAR_H

class Madagascar: public Duck{
private:
    int m_beak_size;
    int m_dex;

public:
    Madagascar(string name, int weight, int beak_size, int dex, int what_can = 2): Duck(name, weight, what_can), m_beak_size(beak_size), m_dex(dex){

    }

    int getBeaksize();
    int getDex();

    void setBeaksize(int beak_size);
    void setDex(int dex);

    virtual void tellAboutYourself() override;

};

#endif //GRISHA_MADAGASCAR_H

#include "Duck.h"
#ifndef GRISHA_MARBLE_H
#define GRISHA_MARBLE_H

class Marble: public Duck{
private:
    string m_hobby;
    int m_wingspan;

public:
    Marble(string name, int weight, string hobby, int wingspan, int what_can = 1): Duck(name, weight, what_can), m_hobby(hobby), m_wingspan(wingspan){

    }

    string getHobby();
    int getWingspan();

    void setHobby(string hobby);
    void setWingspan(int wingspan);

    virtual void tellAboutYourself() override;

};

#endif //GRISHA_MARBLE_H

#include "Duck.h"
#ifndef GRISHA_LAYAING_H
#define GRISHA_LAYAING_H

class Layaing: public Duck{
private:
    int m_age;
    string m_hobby;

public:
    Layaing(string name, int weight, string hobby, int age, int what_can = 2): Duck(name, weight, what_can), m_age(age), m_hobby(hobby){

    }

    string getHobby();
    int getAge();

    void setHobby(string hobby);
    void setAge(int age);

    virtual void tellAboutYourself() override;
};

#endif //GRISHA_LAYAING_H

#include "Duck.h"
#ifndef GRISHA_PEGANKY_H
#define GRISHA_PEGANKY_H

class Peganky: public Duck{
private:
    int m_stamina;
    string m_form;

public:
    Peganky(string name, int weight, string form, int stamina, int what_can = 3): Duck(name, weight, what_can), m_stamina(stamina), m_form(form){

    }

    string getForm();
    int getStamina();

    void setForm(string form);
    void setStamina(int stamina);

    virtual void tellAboutYourself() override;
};

#endif //GRISHA_PEGANKY_H

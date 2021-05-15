#include "Peganky.h"

string Peganky::getForm() {
    return m_form;
}

int Peganky::getStamina() {
    return m_stamina;
}

void Peganky::setForm(string form) {
    m_form = form;
}

void Peganky::setStamina(int stamina) {
    m_stamina = stamina;
}

void Peganky::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 3)
    {
        temp_str += "Migratinon";
    }

    temp_str += " Stamina: " + to_string(m_stamina) + " Form: " + m_form;
    std::cout << temp_str;
}
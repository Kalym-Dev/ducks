#include "Chirki.h"

int Chirki::getHealth() {
    return m_health;
}

string Chirki::getBeakcolor() {
    return m_beak_color;
}

void Chirki::setHealth(int health) {
    m_health = health;
}

void Chirki::setBeakcolor(string beak_color) {
    m_beak_color = beak_color;
}

void Chirki::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 2)
    {
        temp_str += "Nothing";
    }

    temp_str += " Health: " + to_string(m_health) + " Beak color: " + m_beak_color;
    std::cout << temp_str;
}
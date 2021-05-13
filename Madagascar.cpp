#include "Madagascar.h"

int Madagascar::getBeaksize() {
    return m_beak_size;
}

int Madagascar::getDex() {
    return m_dex;
}

void Madagascar::setBeaksize(int beak_size) {
    m_beak_size = beak_size;
}

void Madagascar::setDex(int dex) {
    m_dex = dex;
}

void Madagascar::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 2)
    {
        temp_str += "Swim";
    }

    temp_str += " Dex: " + to_string(m_dex) + " Beak size: " + to_string(m_beak_size);
    std::cout << temp_str;
}
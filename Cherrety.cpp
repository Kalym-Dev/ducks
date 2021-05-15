#include "Cherrety.h"

string Cherrety::getBeakcolor() {
    return m_beak_color;
}

int Cherrety::getPawsize() {
    return m_paw_size;
}

void Cherrety::setBeakcolor(string color) {
    m_beak_color = color;
}

void Cherrety::setPawsize(int paw_size) {
    m_paw_size = paw_size;
}

void Cherrety::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 2)
    {
        temp_str += "Swim";
    }

    temp_str += " Paw size: " + to_string(m_paw_size) + " Beak color: " + m_beak_color;
    std::cout << temp_str;
}
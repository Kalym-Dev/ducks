#include "Marble.h"

string Marble::getHobby() {
    return m_hobby;
}

int Marble::getWingspan() {
    return m_wingspan;
}

void Marble::setHobby(string hobby) {
    m_hobby = hobby;
}

void Marble::setWingspan(int wingspan) {
    m_wingspan = wingspan;
}

void Marble::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 1)
    {
        temp_str += "Fly";
    }

    temp_str += " Hobby: " + m_hobby + " Wingspan: " + to_string(m_wingspan);
    std::cout << temp_str;
}
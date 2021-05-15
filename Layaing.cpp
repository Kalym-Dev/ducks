#include "Layaing.h"

string Layaing::getHobby() {
    return m_hobby;
}

int Layaing::getAge() {
    return m_age;
}

void Layaing::setHobby(string hobby) {
    m_hobby = hobby;
}

void Layaing::setAge(int age) {
    m_age = age;
}

void Layaing::tellAboutYourself() {
    string temp_str = "Name: " + getName() + " Weight: " + to_string(getWeight()) + " What can? ";
    if(getWhatcan() == 2)
    {
        temp_str += "Swim";
    }

    temp_str += " Age: " + to_string(m_age) + " Hobby: " + m_hobby;
    std::cout << temp_str;
}
#include "Duck.h"

Duck::Duck(string name, int weight, int what_can)
{
    m_name = name;
    m_weight = weight;
    m_what_can = what_can;
    m_home_address = nullptr;
    m_cur_address = nullptr;
    m_is_escapee = false;
}

string Duck::getName()
{
  return m_name;
}

int Duck::getWeight()
{
    return m_weight;
}

int Duck::getWhatcan() {
    return m_what_can;
}

void Duck::setName(string name)
{
    m_name = name;
}

void Duck::setWeight(int weight)
{
    m_weight = weight;
}

Lake* Duck::getHomeAddress()
{
    return m_home_address;
}

void Duck::setHomeAddress(Lake *home_address)
{
    m_home_address = home_address;
}

Lake* Duck::getCurAddress()
{
    return m_home_address;
}

void Duck::setCurAddress(Lake *cur_address)
{
    m_cur_address = cur_address;
}

void Duck::setWhatcan(int what_can) {
    m_what_can = what_can;
}

bool Duck::getIsescapee(){
    return m_is_escapee;
}
void Duck::setIsescapee(bool is_escapee){
    m_is_escapee = is_escapee;
}

void Duck::tellAboutYourself() {
    string temp_str = "Name: " + m_name + " Weight: " + to_string(m_weight) + " What can? ";
    if(m_what_can == 1)
    {
        temp_str += "Fly";
    }else if(m_what_can == 2){
        temp_str += "Swim";
    }else if(m_what_can == 3){
        temp_str += "Migrate";
    }else if(m_what_can == 4){
        temp_str += "Nothing";
    }

    std::cout << temp_str;
}
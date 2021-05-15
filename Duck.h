#include <string>
#include <iostream>

using std::to_string;

using std::string;

#ifndef GRISHA_DUCK_H
#define GRISHA_DUCK_H

class Lake;

class Duck{
private:
    string m_name;
    int m_weight;
    Lake* m_home_address;
    Lake* m_cur_address;
    int m_what_can; // 1 - летать, 2 - плавать, 3 - мигрировать, 4 - безьдельничать // 5 - неуловимый
    bool m_is_escapee;

public:
    Duck(string name, int weight, int what_can);

    string getName();
    int getWeight();
    int getWhatcan();

    void setName(string name);
    void setWeight(int weight);
    void setWhatcan(int what_can);

    Lake* getHomeAddress(); //домашний адрес утки
    Lake* getCurAddress(); //функция будет возвращать указатель на озеро в котором находится утка
    //адреса по умолчанию в нуле
    void setHomeAddress(Lake* home_address);
    void setCurAddress(Lake* cur_address);

    bool getIsescapee();
    void setIsescapee(bool is_escapee);

    virtual void tellAboutYourself();
};


#endif //GRISHA_DUCK_H

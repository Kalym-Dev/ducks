#include "Lake.h"

#ifndef GRISHA_FARM_H
#define GRISHA_FARM_H

class Farm: public Lake{
private:
    int m_escape_type_ability;
public:
    Farm(int escape_type_ability): Lake(), m_escape_type_ability(escape_type_ability){

    }

    Farm(int length, int escape_type_ability): Lake(length), m_escape_type_ability(escape_type_ability){

    }

    int getEscapetype(){ return m_escape_type_ability;}
    void setEscapetype(int escape_type){ m_escape_type_ability = escape_type;}

};

#endif //GRISHA_FARM_H

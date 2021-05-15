#include "Lake.h"

#ifndef GRISHA_FARM_H
#define GRISHA_FARM_H

class Farm: public Lake{
private:
    int m_escape_type_ability;
    bool m_ducks_knows_where_live;
public:
    Farm(int escape_type_ability, bool ducks_knows_where_live): Lake(), m_escape_type_ability(escape_type_ability), m_ducks_knows_where_live(ducks_knows_where_live){

    }

    Farm(int length, int escape_type_ability, bool ducks_knows_where_live): Lake(length), m_escape_type_ability(escape_type_ability), m_ducks_knows_where_live(ducks_knows_where_live){

    }

    int getEscapetype(){ return m_escape_type_ability;}
    void setEscapetype(int escape_type){ m_escape_type_ability = escape_type;}

};

#endif //GRISHA_FARM_H

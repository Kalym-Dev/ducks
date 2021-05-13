#include "Hunter.h"

int Hunter::getMaxduckquantity() {
    return m_max_duck_quantity;
}

int Hunter::getMinduckquantity() {
    return m_min_duck_quantity;
}

void Hunter::setMaxduckquantity(int max_duck_quantity) {
    m_max_duck_quantity = max_duck_quantity;
}

void Hunter::setMinuckquantity(int min_duck_quantity) {
    m_min_duck_quantity = min_duck_quantity;
}

int Hunter::getHuntingquantity() {
    srand(time(0));
    int temp_len = m_max_duck_quantity - m_min_duck_quantity;
    temp_len++;
    return m_min_duck_quantity + rand() % temp_len;
}
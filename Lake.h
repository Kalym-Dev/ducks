#include <iostream>
#include "Duck.h"

#ifndef GRISHA_LAKE_H
#define GRISHA_LAKE_H

class Lake{
private:
    int m_length;
    Duck** m_data;

public:
    Lake()
    {
        m_length = 0;
        m_data = nullptr;
    }

    Lake(int length)
    {
        if(length > 0)
        {
            m_length = length;
            m_data = new Duck*[length];
        }else{
            //error
        }
    }

    ~Lake()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    Duck* operator[](int key)
    {
        if(key < 0 || key >= m_length)
        {
            return nullptr;
        }
        return m_data[key];
    }

    void rellocate(int length)
    {
        erase();

        if(length <= 0) return;

        m_data = new Duck*[length];
        m_length = length;
    }

    void resize(int length)
    {
        if(length == m_length) return;

        if(length <= 0)
        {
            erase();
            return;
        }
        Duck** data = new Duck*[length];
        if(m_length > 0)
        {
            int elemsCopy = (length > m_length) ? m_length : length;
            for(int i = 0; i < elemsCopy; i++)
            {
                data[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = data;
        m_length = length;
    }

    void remove(int key)
    {
        if(key < 0 || key >= m_length)
        {

        }

        if(m_length == 1)
        {
            erase();
            return;
        }

        Duck** data = new Duck*[m_length - 1];
        for(int before = 0; before < key; before++)
        {
            data[before] = m_data[before];
        }

        for(int after = key + 1; after < m_length; after++)
        {
            data[after - 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        m_length--;
    }

    void addElemToKey(Duck *elem, int key)
    {
        if(key < 0 || key > m_length)
        {
            //error
        }

        Duck** data = new Duck*[m_length + 1];
        for(int i = 0; i < key; i++)
        {
            data[i] = m_data[i];
        }
        data[key] = elem;

        for(int after = key; after < m_length; after++)
        {
            data[after+1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        m_length++;
    }

    void addElemToEnd(Duck *elem)
    {
        addElemToKey(elem, m_length);
    }

    int getLength()
    {
        return m_length;
    }

};

#endif //GRISHA_LAKE_H

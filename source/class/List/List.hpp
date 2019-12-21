#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template<class T> class List;

#include "Item\Item.hpp"

template<class T> class Item;

template<class T> class List{
    public:
        //constructor
        List();
        //destructor
        virtual ~List();
        //static attribute
        //static member
        //member
        unsigned long size(void) const;
        T cursorData(void) const;
        void push_back(T setData);
        void push_front(T setData);
        T pop_back(void);
        T pop_front(void);
        void cursorDefault(void);
        void cursorBack(void);
        void cursorFront(void);
        void disp(void);
        //friendly operator
        //operator
    protected:
        //attribute
        unsigned long m_size;
        unsigned long m_position;
        Item<T>* m_first;
        Item<T>* m_cursor;
        //member
};

template class List<unsigned long long>;

#endif // LIST_HPP

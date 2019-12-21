#ifndef ITEM_HPP
#define ITEM_HPP

#include "..\List.hpp"

template<class T> class Item{
    public:
        //constructor
        Item(T setData);
        Item(T setData, Item<T>* setPrev, Item<T>* setNext);
        //destructor
        virtual ~Item();
        //friend
        friend class List<T>;
        //static attribute
        //static member
        //member
        //friendly operator
        //operator
    protected:
        //attribute
        T m_data;
        Item<T>* m_prev;
        Item<T>* m_next;
        //member
};

template class Item<unsigned long long>;

#endif /* ITEM_HPP */

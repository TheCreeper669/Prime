#include "Item.hpp"

//public:

//constructor


template<class T>
Item<T>::Item(T setData): m_data(setData), m_prev(nullptr), m_next(nullptr){
    //
}

template<class T>
Item<T>::Item(T setData, Item<T>* setPrev, Item<T>* setNext): m_data(setData), m_prev(setPrev), m_next(setNext){
    //
}

//destructor

template<class T>
Item<T>::~Item(){
    //
}

//static attribute
//static member
//member
//friendly operator
//operator

//protected:

//attribute
//member

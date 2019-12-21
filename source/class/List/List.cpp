#include "List.hpp"

//public:

//constructor

template<class T>
List<T>::List(): m_size(0), m_position(0), m_first(nullptr), m_cursor(nullptr){
    //
}

//destructor

template<class T>
List<T>::~List(){
    m_cursor = m_first;
    Item<T>* toDelete;
    for(unsigned long i = 0; i < m_size; i++){
        toDelete = m_cursor;
        cursorFront();
        delete toDelete;
    }
}

//static attribute
//static member
//member

template<class T>
unsigned long List<T>::size() const{
    return m_size;
}

template<class T>
T List<T>::cursorData() const{
    if(m_size > 0){
        return m_cursor->m_data;
    }
    return *(new T);
}

template<class T>
void List<T>::push_back(T setData){
    if(m_size == 0){
        m_first = new Item<T>(setData); //si error et donc m_first est pas null alors problème (peux rajouter un delete m_first avant pour régler)
        m_cursor = m_first;
        m_size++;
    }else if(m_size == 1){
        Item<T>* toPush = new Item<T>(setData, m_first, m_first);
        m_first->m_prev = toPush;
        m_first->m_next = toPush;
        m_size++;
    }else{
        Item<T>* toPush = new Item<T>(setData, m_first->m_prev, m_first);
        m_first->m_prev->m_next = toPush;
        m_first->m_prev = toPush;
        m_size++;
    }
}

template<class T>
void List<T>::push_front(T setData){
    if(m_size == 0){
        m_first = new Item<T>(setData); //si error et donc m_first est pas null alors problème (peux rajouter un delete m_first avant pour régler)
        m_cursor = m_first;
        m_size++;
    }else if(m_size == 1){
        Item<T>* toPush = new Item<T>(setData, m_first, m_first);
        m_first->m_prev = toPush;
        m_first->m_next = toPush;
        m_first = toPush;
        m_size++;
    }else{
        Item<T>* toPush = new Item<T>(setData, m_first->m_prev, m_first);
        m_first->m_prev->m_next = toPush;
        m_first->m_prev = toPush;
        m_first = toPush;
        m_size++;
    }
}

template<class T>
T List<T>::pop_back(void){
    if(m_size > 1){
        T toPopVal = m_first->m_prev->m_data;
        Item<T>* toPop = m_first->m_prev;
        m_first->m_prev = toPop->m_prev;
        toPop->m_prev->m_next = m_first;
        delete toPop;
        m_size--;
        return toPopVal;
    }else if(m_size == 1){
        T toPopVal = m_first->m_data;
        delete m_first;
        m_first = nullptr;
        m_size--;
        return toPopVal;
    }else{
        return T();
    }
}

template<class T>
T List<T>::pop_front(void){
    if(m_size > 1){
        T toPopVal = m_first->m_data;
        Item<T>* toPop = m_first;
        m_first->m_prev->m_next = m_first;
        m_first = m_first->m_next;
        m_first->m_prev = toPop->m_prev;
        delete toPop;
        m_size--;
        return toPopVal;
    }else if(m_size == 1){
        T toPopVal = m_first->m_data;
        delete m_first;
        m_first = nullptr;
        m_size--;
        return toPopVal;
    }else{
        return T();
    }
}

template<class T>
void List<T>::cursorDefault(){
    m_cursor = m_first;
}

template<class T>
void List<T>::cursorBack(){
    if(m_size > 1){
        m_cursor = m_cursor->m_prev;
        m_position--;
    }
}

template<class T>
void List<T>::cursorFront(){
    if(m_size > 1){
        m_cursor = m_cursor->m_next;
        m_position--;
    }
}

template<class T>
void List<T>::disp(void){
    for(uint64_t i = 0; i < m_size; i++){
        std::cout << m_position << ": '" << m_first->m_data << "'" << std::endl;
        cursorFront();
    }
}

//friendly operator
//operator

//protected:

//attribute
//member

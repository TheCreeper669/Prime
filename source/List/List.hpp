#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
//
#include "./Item/Item.hpp"

template<class T>
class List {
    public:
        //constructor
        List();
        List(const List<T>& other);
        //destructor
        virtual ~List();
        //static attribute
        //static member
        //member
        T& cursorData(void);
        void push_back(const T& data);
        void push_front(const T& data);
        T pop_back(void);
        T pop_front(void);
        void cursorDefault(void);
        void cursorBack(void);
        void cursorFront(void);
        void disp(void);
        //
        unsigned long get_size(void) const;
        unsigned long get_position(void) const;
        Item<T>* get_first(void) const;
        Item<T>* get_cursor(void) const;
        //friendly operator
        //operator
        void operator=(const List<T>& other);
    protected:
        //attribute
        unsigned long m_size;
        unsigned long m_position;
        Item<T>* m_first;
        Item<T>* m_cursor;
        //member
};

//public:

//constructor

template<class T>
List<T>::List():
    m_size(0),
    m_position(0),
    m_first(nullptr),
    m_cursor(nullptr)
{
    //
}

template<class T>
List<T>::List(const List<T>& other):
    m_size(other.get_size()),
    m_position(other.get_position()),
    m_first(other.get_first()),
    m_cursor(other.get_cursor())
{
    //
}

//destructor

template<class T>
List<T>::~List() {
    m_cursor = m_first;
    Item<T>* toDelete;
    for (unsigned long i = 0; i < m_size; i++) {
        toDelete = m_cursor;
        cursorFront();
        delete toDelete;
    }
}

//static attribute
//static member
//member

template<class T>
T& List<T>::cursorData(void) {
    return m_cursor->get_data();
}

template<class T>
void List<T>::push_back(const T& data) {
    if(m_size == 0){
        m_first = new Item<T>(data);
        m_cursor = m_first;
        m_size++;
    }else if(m_size == 1){
        Item<T>* toPush = new Item<T>(data, m_first, m_first);
        m_first->set_prev(toPush);
        m_first->set_next(toPush);
        m_size++;
    }else{
        Item<T>* toPush = new Item<T>(data, m_first->get_prev(), m_first);
        m_first->get_prev()->set_next(toPush);
        m_first->set_prev(toPush);
        m_size++;
    }
}

template<class T>
void List<T>::push_front(const T& data) {
    if(m_size == 0){
        m_first = new Item<T>(data);
        m_cursor = m_first;
        m_size++;
    }else if(m_size == 1){
        Item<T>* toPush = new Item<T>(data, m_first, m_first);
        m_first->m_prev = toPush;
        m_first->m_next = toPush;
        m_first = toPush;
        m_size++;
    }else{
        Item<T>* toPush = new Item<T>(data, m_first->m_prev, m_first);
        m_first->m_prev->m_next = toPush;
        m_first->m_prev = toPush;
        m_first = toPush;
        m_size++;
    }
}

template<class T>
T List<T>::pop_back(void) {
    if(m_size > 1){
        T toPopVal = m_first->get_prev()->get_data();
        Item<T>* toPop = m_first->get_prev();
        m_first->set_prev(toPop->get_prev());
        toPop->get_prev()->set_next(m_first);
        delete toPop;
        m_size--;
        return toPopVal;
    }else if(m_size == 1){
        T toPopVal = m_first->get_data();
        delete m_first;
        m_first = nullptr;
        m_size--;
        return toPopVal;
    }
    //
    std::cout << std::endl;
    std::cout << "template<class T> T List<T>::pop_back(void) ==> error ==> m_size <= 1" << std::endl;
    return T();
}

template<class T>
T List<T>::pop_front(void) {
    if(m_size > 1){
        T toPopVal(m_first->get_data());
        Item<T>* toPop = m_first;
        m_first->get_prev()->set_next(m_first);
        m_first = m_first->get_next();
        m_first->set_prev(toPop->get_prev());
        delete toPop;
        m_size--;
        return toPopVal;
    }else if(m_size == 1){
        T toPopVal(m_first->get_data());
        delete m_first;
        m_first = nullptr;
        m_size--;
        return toPopVal;
    }
    //
    std::cout << std::endl;
    std::cout << "template<class T> T List<T>::pop_front(void) ==> error ==> m_size <= 1" << std::endl;
    return T();
}

template<class T>
void List<T>::cursorDefault() {
    m_cursor = m_first;
}

template<class T>
void List<T>::cursorBack() {
    if(m_size > 1){
        m_cursor = m_cursor->m_prev;
        m_position--;
    }
}

template<class T>
void List<T>::cursorFront() {
    if(m_size > 1){
        m_cursor = m_cursor->get_next();
        m_position--;
    }
}

template<class T>
void List<T>::disp(void) {
    for (uint64_t i = 0; i < m_size; i++) {
        std::cout << m_position << ": '" << m_first->get_data() << "'" << std::endl;
        cursorFront();
    }
}

template<class T>
unsigned long List<T>::get_size(void) const {
    return m_size;
}

template<class T>
unsigned long List<T>::get_position(void) const {
    return m_position;
}

template<class T>
Item<T>* List<T>::get_first(void) const {
    return m_first;
}

template<class T>
Item<T>* List<T>::get_cursor(void) const {
    return m_cursor;
}

//friendly operator
//operator

template<class T>
void List<T>::operator=(const List<T>& other) {
    m_size = other.get_size();
    m_position = other.get_position();
    m_first = other.get_first();
    m_cursor = other.get_cursor();
}

//protected:

//attribute
//member


#endif /* LIST_HPP */

#ifndef SCP_LIST_HPP
#define SCP_LIST_HPP

// C++ libs
#include <iostream>
// scp libs
#include "scp/containers/list/item.hpp"
#include "scp/exception.hpp"

namespace scp {

template<class T>
class List {
    public:
        // Typedefs //
        typedef unsigned long long size_type;
        // Constructors //
        List(void);
        List(const List<T>& other);
        // Destructor //
        virtual ~List();
        // Members //
        // clear
        void clear(void);
        // push
        void push_back(const T& data);
        void push_front(const T& data);
        // pop
        T pop_back(void);
        T pop_front(void);
        // Getters //
        // size
        size_type size(void) const;
        // front
        list::Item<T>& front(void);
        const list::Item<T>& front(void) const;
        // back
        list::Item<T>& back(void);
        const list::Item<T>& back(void) const;
        //friendly operator
        // Operators //
        // assignement
        void operator=(const List<T>& other);
    protected:
        // Attributes //
        size_type m_size;
        list::Item<T>* m_front;
};

template<class T>
List<T>::List(void):
    m_size(0),
    m_front(nullptr)
{
    //
}

template<class T>
List<T>::List(const List<T>& other):
    List()
{
    *this = other;
}

//destructor

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
void List<T>::clear(void) {
    while (m_size != 0)
        pop_back();
}

template<class T>
void List<T>::push_back(const T& data) {
    list::Item<T>* toPush = new list::Item<T>(data);
    if (m_size > 1) {
        toPush->prev(m_front->prev());
        toPush->next(m_front);
        m_front->prev().next(toPush);
        m_front->prev(toPush);
    } else if (m_size == 1) {
        toPush->prev(m_front);
        toPush->next(m_front);
        m_front->prev(toPush);
        m_front->next(toPush);
    } else {
        m_front = toPush;
        m_front->prev(m_front);
        m_front->next(m_front);
    }
    m_size++;
}

template<class T>
void List<T>::push_front(const T& data) {
    list::Item<T>* toPush = new list::Item<T>(data);
    if (m_size == 0) {
        m_front = toPush;
        m_front->prev(m_front);
        m_front->next(m_front);
    } else if (m_size == 1) {
        toPush->prev(m_front);
        toPush->next(m_front);
        m_front->prev(toPush);
        m_front->next(toPush);
        m_front = toPush;
    } else {
        toPush->prev(m_front->prev());
        toPush->next(m_front);
        m_front->prev().next(toPush);
        m_front->prev(toPush);
        m_front = toPush;
    }
    m_size++;
}

template<class T>
T List<T>::pop_back(void) {
    if (m_front == nullptr)
        throw Exception("out_of_range", "T List<T>::pop_back(void)", "list is empty and can not be popped");
    //
    if(m_size > 1){
        T toPopVal(m_front->prev().data());
        list::Item<T>* toPop(&m_front->prev());
        m_front->prev(toPop->prev());
        toPop->prev().next(m_front);
        delete toPop;
        m_size--;
        return toPopVal;
    } else {
        T toPopVal(m_front->data());
        delete m_front;
        m_front = nullptr;
        m_size--;
        return toPopVal;
    }
}

template<class T>
T List<T>::pop_front(void) {
    if (m_front == nullptr)
        throw Exception("out_of_range", "T List<T>::pop_front(void)", "list is empty and can not be popped");
    //
    if (m_size > 1) {
        T toPopVal(m_front->data());
        list::Item<T>* toPop(m_front);
        m_front->prev().next(m_front);
        m_front = &m_front->next();
        m_front->prev(toPop->prev());
        delete toPop;
        m_size--;
        return toPopVal;
    } else {
        T toPopVal(m_front->data());
        delete m_front;
        m_front = nullptr;
        m_size--;
        return toPopVal;
    }
}

template<class T>
typename List<T>::size_type List<T>::size(void) const {
    return m_size;
}

template<class T>
list::Item<T>& List<T>::front(void) {
    if (m_front == nullptr)
        throw Exception("nullptr", "Item<T>& List<T>::front(void)", "m_front == nullptr");
    //
    return *m_front;
}

template<class T>
const list::Item<T>& List<T>::front(void) const {
    if (m_front == nullptr)
        throw Exception("nullptr", "const Item<T>& List<T>::front(void) const", "m_front == nullptr");
    //
    return *m_front;
}

template<class T>
list::Item<T>& List<T>::back(void) {
    if (m_front == nullptr)
        throw Exception("nullptr", "Item<T>& List<T>::back(void)", "m_front == nullptr");
    //
    return m_front->prev();
}

template<class T>
const list::Item<T>& List<T>::back(void) const {
    if (m_front == nullptr)
        throw Exception("nullptr", "const Item<T>& List<T>::back(void) const", "m_front == nullptr");
    //
    return m_front->prev();
}

template<class T>
void List<T>::operator=(const List<T>& other) {
    list::Item<T> item = other.front();
    for (uint64_t i = 0; i < other.size(); ++i) {
        push_back(item.data());
        item = item.next();
    }
}

} // closing namespace scp

#endif /* SCP_LIST_HPP */

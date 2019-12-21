#ifndef LIST_HPP
#define LIST_HPP

// C++ libs
#include <iostream>
// my libs
#include "./Item/Item.hpp"
#include "./Exception/exception.hpp"

namespace scp {
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
            void clear(void);
            //
            void push_back(const T& data);
            //
            void push_front(const T& data);
            //
            T pop_back(void);
            T pop_front(void);
            //
            const uint64_t& size(void) const;
            //
            Item<T>& front(void);
            const Item<T>& front(void) const;
            //
            Item<T>& back(void);
            const Item<T>& back(void) const;
            //friendly operator
            //operator
            void operator=(const List<T>& other);
        protected:
            //attribute
            uint64_t m_size;
            Item<T>* m_front;
            //member
    };

    //public:

    //constructor

    template<class T>
    List<T>::List():
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

    //static attribute
    //static member
    //member

    template<class T>
    void List<T>::push_back(const T& data) {
        Item<T>* toPush = new Item<T>(data);
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
        Item<T>* toPush = new Item<T>(data);
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
            throw scp::Exception("out_of_range", "T List<T>::pop_back(void)", "size <= 1");
        //
        if(m_size > 1){
            T toPopVal(m_front->prev().data());
            Item<T>* toPop(&m_front->prev());
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
            throw scp::Exception("out_of_range", "T List<T>::pop_front(void)", "size <= 1");
        //
        if (m_size > 1) {
            T toPopVal(m_front->data());
            Item<T>* toPop(m_front);
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
    const uint64_t& List<T>::size(void) const {
        return m_size;
    }

    template<class T>
    Item<T>& List<T>::front(void) {
        if (m_front == nullptr)
            throw scp::Exception("nullptr", "Item<T>& List<T>::front(void)", "m_front == nullptr");
        //
        return *m_front;
    }

    template<class T>
    const Item<T>& List<T>::front(void) const {
        if (m_front == nullptr)
            throw scp::Exception("nullptr", "const Item<T>& List<T>::front(void) const", "m_front == nullptr");
        //
        return *m_front;
    }

    template<class T>
    Item<T>& List<T>::back(void) {
        if (m_front == nullptr)
            throw scp::Exception("nullptr", "Item<T>& List<T>::back(void)", "m_front == nullptr");
        //
        return m_front->prev();
    }

    template<class T>
    const Item<T>& List<T>::back(void) const {
        if (m_front == nullptr)
            throw scp::Exception("nullptr", "const Item<T>& List<T>::back(void) const", "m_front == nullptr");
        //
        return m_front->prev();
    }

    //friendly operator
    //operator

    template<class T>
    void List<T>::operator=(const List<T>& other) {
        Item<T> item = other.front();
        for (uint64_t i = 0; i < other.size(); ++i) {
            push_back(item.data());
            item = item.next();
        }
    }

    //protected:

    //attribute
    //member
}

#endif /* LIST_HPP */

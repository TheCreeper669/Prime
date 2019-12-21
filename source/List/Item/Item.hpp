#ifndef ITEM_HPP
#define ITEM_HPP

namespace scp {
    template<class T>
    class Item {
        public:
            //constructor
            Item(const T& data = T(), Item<T>* prev = nullptr, Item<T>* next = nullptr);
            Item(Item<T>& other);
            Item(const Item<T>& other);
            //destructor
            virtual ~Item();
            //static attribute
            //static member
            //member
            Item<T>& prev(void);
            const Item<T>& prev(void) const;
            void prev(Item* prev);
            void prev(Item& prev);
            //
            Item<T>& next(void);
            const Item<T>& next(void) const;
            void next(Item* next);
            void next(Item& next);
            //
            T& data(void);
            const T& data(void) const;
            void data(const T& data);
            //friendly operator
            //operator
            void operator=(const Item<T>& other);
        protected:
            //attribute
            T m_data;
            Item<T>* m_prev;
            Item<T>* m_next;
            //member
    };

    //public:

    //constructor

    template<class T>
    Item<T>::Item(const T& data, Item<T>* prev, Item<T>* next):
        m_data(data),
        m_prev(prev),
        m_next(next)
    {
        //
    }

    template<class T>
    Item<T>::Item(Item<T>& other):
        Item()
    {
        *this = other;
    }

    template<class T>
    Item<T>::Item(const Item<T>& other):
        m_prev(nullptr),
        m_next(nullptr),
        m_data(other.get_data())
    {
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

    template<class T>
    Item<T>& Item<T>::prev(void) {
        return *m_prev;
    }

    template<class T>
    const Item<T>& Item<T>::prev(void) const {
        return *m_prev;
    }

    template<class T>
    void Item<T>::prev(Item* prev) {
        m_prev = prev;
    }

    template<class T>
    void Item<T>::prev(Item& prev) {
        m_prev = &prev;
    }

    template<class T>
    Item<T>& Item<T>::next(void) {
        return *m_next;
    }

    template<class T>
    const Item<T>& Item<T>::next(void) const {
        return *m_next;
    }

    template<class T>
    void Item<T>::next(Item* next) {
        m_next = next;
    }

    template<class T>
    void Item<T>::next(Item& next) {
        m_next = &next;
    }

    template<class T>
    T& Item<T>::data(void) {
        return m_data;
    }

    template<class T>
    const T& Item<T>::data(void) const {
        return m_data;
    }

    template<class T>
    void Item<T>::data(const T& data) {
        m_data = data;
    }
    //friendly operator
    //operator

    template<class T>
    void Item<T>::operator=(const Item<T>& other) {
        m_prev = other.get_prev();
        m_next = other.get_next();
        m_data = other.get_data();
    }

    //protected:

    //attribute
    //member
}

#endif /* ITEM_HPP */

#ifndef ITEM_HPP
#define ITEM_HPP

template<class T>
class Item {
    public:
        //constructor
        Item(const T& data);
        Item(const T& data, Item<T>* prev, Item<T>* next);
        Item(const Item<T>& other);
        //destructor
        virtual ~Item();
        //static attribute
        //static member
        //member
        Item<T>* get_prev(void);
        void set_prev(Item* prev);
        //
        Item<T>* get_next(void);
        void set_next(Item* next);
        //
        T& get_data(void);
        void set_data(const T& data);
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
Item<T>::Item(const T& data):
    m_data(data),
    m_prev(nullptr),
    m_next(nullptr)
{
    //
}

template<class T>
Item<T>::Item(const T& data, Item<T>* prev, Item<T>* next):
    m_data(data),
    m_prev(prev),
    m_next(next)
{
    //
}

template<class T>
Item<T>::Item(const Item<T>& other):
    m_prev(other.get_prev()),
    m_next(other.get_next()),
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
Item<T>* Item<T>::get_prev(void) {
    return m_prev;
}

template<class T>
void Item<T>::set_prev(Item* prev) {
    m_prev = prev;
}

template<class T>
Item<T>* Item<T>::get_next(void) {
    return m_next;
}

template<class T>
void Item<T>::set_next(Item* next) {
    m_next = next;
}

template<class T>
T& Item<T>::get_data(void) {
    return m_data;
}

template<class T>
void Item<T>::set_data(const T& data) {
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

#endif /* ITEM_HPP */

#ifndef SCP_LIST_ITEM_HPP
#define SCP_LIST_ITEM_HPP

namespace scp {
namespace list {

template<class T>
class Item {
    public:
        // Constructors //
        Item(const T& data = T(), Item<T>* prev = nullptr, Item<T>* next = nullptr);
        Item(Item<T>& other);
        Item(const Item<T>& other);
        // Destructor //
        virtual ~Item();
        // Getters & Setters //
        // prev
        Item<T>& prev(void);
        const Item<T>& prev(void) const;
        void prev(Item* prev);
        void prev(Item& prev);
        // next
        Item<T>& next(void);
        const Item<T>& next(void) const;
        void next(Item* next);
        void next(Item& next);
        // data
        T& data(void);
        const T& data(void) const;
        void data(const T& data);
        // Operators //
        void operator=(const Item<T>& other);
    protected:
        // Attributes //
        T m_data;
        Item<T>* m_prev;
        Item<T>* m_next;
};

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

template<class T>
Item<T>::~Item(){
    //
}

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

template<class T>
void Item<T>::operator=(const Item<T>& other) {
    m_prev = other.get_prev();
    m_next = other.get_next();
    m_data = other.get_data();
}

}} // closing namespace scp::list

#endif /* SCP_LIST_ITEM_HPP */

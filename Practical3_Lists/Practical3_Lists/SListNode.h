#ifndef SLISTNODE_H
#define SLISTNODE_H

// Forward references.
template <typename T> class Container;

template <typename T>
class SListNode {

public:    
    SListNode(T element, Container<T>* pContainer=0);
    
    T & element();
    const Container<T>* container() const;
    void setElement(T element);
        
    void setNext(SListNode<T>* next);    
    SListNode<T>* next() const;
     
    
private:
    T m_element;                // The data field - notice it's a generic type
    SListNode<T>* m_pNext;      // A pointer to the next node
    Container<T>* m_pContainer; // A pointer to the container of which this node belongs   
};

template <typename T>
SListNode<T>::SListNode(T element, Container<T>* pContainer) :
    m_element(element), 
    m_pContainer(pContainer), 
    m_pNext(0) 
    {}


template <typename T>
T & SListNode<T>::element() {
    return m_element;    
}

template <typename T>
const Container<T>* SListNode<T>::container() const {
    return m_pContainer;   
}

template <typename T>
void SListNode<T>::setElement(T element) {
   m_element = element;
}


template <typename T>
void SListNode<T>::setNext(SListNode<T>* next) {
    m_pNext = next;
}

template <typename T>
SListNode<T>* SListNode<T>::next() const {
    return m_pNext;
}

#endif


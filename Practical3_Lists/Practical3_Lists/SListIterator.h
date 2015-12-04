#include <iostream>

#ifndef SLISTITERATOR_H
#define SLISTITERATOR_H

template <typename T>class SListNode;  // Forward reference.

//using namespace std;

template <typename T>
class SListIterator : public std::iterator<std::forward_iterator_tag, T> { 
public:
    SListIterator(SListNode<T>* pInitialNode = 0) {
        m_pCurrent = pInitialNode; 
    }
        
    T & operator *() const { 
	    return (*m_pCurrent).element();  
    } 
    
	SListNode<T>* ptr() {
		return m_pCurrent;
	}

	SListIterator<T>& operator ++(); // Prefix ++
	SListIterator<T> operator ++(int); // Postfix ++	
	bool operator ==(SListIterator<T> other) const; 
	bool operator !=(SListIterator<T> other) const; 
    T & operator [](int index) ;
	

private:
	SListNode<T>* m_pCurrent;
};

template <typename T>
SListIterator<T>& SListIterator<T> :: operator ++() { 
     m_pCurrent = m_pCurrent->next();
     return *this;
}
	
template <typename T>
SListIterator<T> SListIterator<T> :: operator ++(int) {
     SListIterator<T> original(m_pCurrent);
     m_pCurrent = m_pCurrent->next();
     return original;      	  
}

template <typename T>
bool SListIterator<T> :: operator ==(const SListIterator<T> other) const { 
     return m_pCurrent == other.m_pCurrent;  
}
	
template <typename T>
bool SListIterator<T> :: operator !=(const SListIterator<T> other) const {
     return m_pCurrent != other.m_pCurrent;   
}

template <typename T>
T & SListIterator<T> :: operator [](int index) {
	for (int i = 0; i < index; i++) {
		m_pCurrent = m_pCurrent->next();		
	}
	return m_pCurrent->element();
}



#include "SListNode.h"

#endif 

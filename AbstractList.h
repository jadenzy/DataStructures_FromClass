#ifndef ABSTRACT_LIST_H
#define ABSTRACT_LIST_H

template<class T> 

struct AbstractList{

    virtual void append(T) = 0;
    virtual void prepend(T) = 0;


    virtual ~AbstractList(){};
};
 
#endif
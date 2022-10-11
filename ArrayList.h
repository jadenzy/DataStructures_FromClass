#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <ostream>
#include <stdexcept>

template<class T> 
struct ArrayList{
    T* data;
    int count;
    int capacity; 

public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity]; 
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){
            int oldcapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];
            for(int i = 0; i < count; i++){
                temp[i] = data[i]; 
            }
            T *oldLocation = data; 
            data = temp;
            delete[] oldLocation; 
        }
    }

    void prepend(T value){
        append(value);
        for(int i = count - 1; i > 0; i--){
            data[i] = data[i - 1];
        } 

        data[0] = value; 
    }

    void removeFirst(){
        if(count > 0){
            count --;
            for(int i = 0; i < count; i ++){
                data[i] = data[i+1];
            }
        }
        if(count < capacity /2){
            capacity /=2;
            T* temp = new T[capacity];
            for(int i = 0; i < count; i++){
                temp[i] = data[i]; 
            }

            T* oldData = data;
            data = temp;
            delete[] oldData; 
        }
    }

    void removeLast(){
        if(count > 1){
            count--;
            data[count] = 0;
            if(count < capacity /2){
                capacity /= 2;
                int* temp = new int[capacity];

                for(int i = 0; i < count; i++){
                    temp[i] = data[i]; 
                }

                int* oldData = data; 
                data = temp;
                delete oldData; 
            }
        }
    }

    T get(int index){
        if(index < count && index >= 0){
            return data[index];
        }
        else{
            throw std::logic_error("Index out of range"); 
        }
    }

    void insert(T value, int index){
        if(index < 0 || index > count){
            throw std::logic_error("Index out of range"); 
        }
        else{
            append(value);
            int j = count - 1;
            while(j > index){
                data[j] = data[j - 1];
                j--;
            }
            data[index] = value; 
        }
    }

    T mid(){
        if(count == 0){
            throw std::logic_error("No middle element in an empty list");
        }
        return data[count/2];
    }


    ~ArrayList(){
        delete[] data;
    }
}; 

template<class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for(int i = 0; i < list.count; i++){
        os << list.data[i] << " ";
    }
    return os; 
}
#endif
#include <ostream>
// This is a list struct 
template <class S> 
struct Container{
    S* contents;
    int count;
    int capacity;

    Container(){
        capacity = 1;
        count = 0;
        contents = new S[capacity];
    }

    //copy constructor 
    Container(const Container& other){
        count = other.capacity;
        capacity = other.capacity;
        contents = new S[capacity];
        for(int i = 0; i< count; i++){
            contents[i] = other.contents[i];
        }
    }

    //equal operator 
    Container& operator=(const Container& other){
        count = other.count;
        if(capacity == other.capacity){
            for(int i = 0; i < count; i++){
                contents[i] = other.contents[i]; 
            }
        }
        else{
            capacity = other.capacity; 
            contents = new S[capacity];
            for(int i = 0; i < count; i++){
                contents[i] = other.contents[i]; 
            }
            delete[] old; 
        }
        
    }
};



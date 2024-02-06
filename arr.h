#include <iostream>
#include <string>
using namespace std;

#ifndef GET_HUP_ARR_H
#define GET_HUP_ARR_H

class arr_full{};
class arr_empty{};
template <typename T>
class Array {
private:
    T *my_itm;
    int siz,lnth;
public:
    explicit Array(int sz);
    void Fill(int n);
    void print ();
    int get_size();
    int get_length();
    int Search (T key);
    void append (T n);
    void Insert(int dx , T tm);
    void Delete (int index);
    void enLarge (int newSize);
    void merge(Array & another);
    ~Array() ;

};


#endif //GET_HUP_ARR_H

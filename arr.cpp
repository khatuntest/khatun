#include <iostream>
#include "arr.h"
using namespace std;

template <typename T>
Array<T>::Array(int sz) {
    my_itm = new T [sz];
    lnth=0;
    siz=sz;
}
template <typename t>
void Array<t> ::  Fill(int sz) {
    if (sz > siz){
        cout<<"The size of Array smaller than this \n";
        return;
    }
    else{
        cout<<"enter items\n";
        for (int i=0 ; i<sz ; ++i){
            cin>>my_itm[i];
        }
        lnth +=sz;
    }
}
template <typename m>
void Array<m> ::  print (){
    for (int i=0 ; i<lnth ; ++i)
        cout<<my_itm[i]<<" ";
    cout<<"\n";
}
template <typename T>
int Array<T> :: get_size(){
    return siz;
}
template <typename T>
int Array <T>:: get_length(){
    return lnth ;
}
template <typename T>
int Array<T> :: Search (T key){
    for (int i=0 ; i<lnth ; ++i){
        if (my_itm[i] == key)
            return i;
    }
    return -1;
}
template <typename T>
void Array<T> :: append (T n){
    if (lnth < siz){
        my_itm[lnth]=n;
        lnth++;
    }
    else
        throw arr_full() ;
}
template <typename T>
void Array<T> :: Insert(int dx , T tm){
    if (dx >= siz)
        throw arr_full();
    else {
        for (int i=lnth+1 ; i>dx ; --i){
            my_itm[i]=my_itm[i-1];
        }
        my_itm[dx]=tm;
    }
}
template <typename T>
void Array <T>:: Delete (int index){
    if (lnth == 0)
        throw arr_empty();
    else if (index > lnth )
        cout<<"index is empty\n";
    else {
        for (int i=index ; i<lnth-1 ; ++i){
            my_itm[i]=my_itm[i+1];
        }
        lnth--;
    }
}
template <typename T>
void Array<T> :: enLarge (int newSize){
    T *newArr = new T[newSize];
    for (int i = 0; i < lnth; ++i) {
        newArr[i] = my_itm[i];
    }

    delete[] my_itm;
    my_itm = newArr;
    siz = newSize;
}
template <typename T>
void Array<T> :: merge(Array & another){
    int n=siz + another.siz;
    T *ptr = my_itm ;
    my_itm =new T[n];
    int i,j;
    for ( i=0 ; i<lnth ; ++i){
        my_itm[i]=ptr[i];

    }
    for (j=0 ; j<another.lnth ; ++j){
        my_itm[i]=another.my_itm[j];
        i++;
    }
    lnth+=another.lnth;

}
template < typename T>
Array <T> :: ~ Array() {
    delete[] my_itm ;
}

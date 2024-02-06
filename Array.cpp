#include <iostream>
#include <string>
#include "arr.cpp"
using namespace std ;
int main(){
    cout<<"Welcome in system array \n"
          "Please enter the size of array \n ";
    int size_of_array , Option , length_to_Fill;
    cin>>size_of_array ;
    Array<string > object (size_of_array) ;
    cout<<"If you want to Fill Array enter 1\n"
          "If you want to Know the size of Array enter 2\n"
          "If you want to Know the length of Array  enter 3\n"
          "If you want to Search in Array  enter 4\n"
          "If you want to Append in Array enter 5\n"
          "If you want to Insert in Array  enter 6\n"
          "If you want to Delete item in Array  enter 7\n"
          "If you want to EnLarge Array  enter 8\n"
          "If you want to Merger 2 Arrays  enter 9\n"
          "If you want to Print Array  enter 10\n"
          "If you want to Stop the Array  enter 11\n";
    try {
        while (Option != 11){
            cout<<"Enter your order \n";
            cin>>Option ;
            if (Option == 1){
                cout<<"Enter Length You want to Fill \n";
                cin>>length_to_Fill ;
                object.Fill(length_to_Fill ) ;
            }
            if (Option == 2){
                cout<<object.get_size()<<"\n";
            }
            if (Option == 3){
                cout<<object.get_length() <<"\n";
            }
            if (Option == 4){
                cout<<"Enter the item you want to Know \n";
                string item ;
                cin>>item;
                int n=object.Search(item);
                if (n == -1)
                    cout<<"The item don't found \n";
                else
                    cout<<"The item in index  "<<n<<"\n";
            }
            if (Option == 5){
                cout<<"Enter item\n ";
                string itm;
                cin>>itm;
                object.append(itm) ;
            }
            if (Option == 6){
                cout<<"Enter the index and the item \n";
                int index;
                string itm;
                cin>>index>>itm;
                object.Insert(index , itm);
            }
            if (Option == 7){
                cout<<"Enter the index\n";
                int index1;
                cin>>index1 ;
                object.Delete(index1);
            }
            if (Option == 8){
                cout<<"Enter new_size\n";
                int newSize;
                cin>>newSize ;
                object.enLarge(newSize ) ;
            }
            if (Option == 9){
                cout<<"Enter the size of new array , the num of length and the items \n";
                int sz,len;
                cin>>sz>>len;
                Array<string> another_object(sz);
                another_object.Fill(len);
                object.merge(another_object );
            }
            if (Option == 10){
                object.print() ;
            }

        }
    }
    catch (arr_full ){
        cout<<"array is full \n";
    }
    catch (arr_empty){
        cout<<"array is empty\n";
    }

    return 0;
}
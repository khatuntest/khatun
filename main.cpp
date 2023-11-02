#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
bool srt_scnd(pair<string,int> &a , pair<string , int>&b){
    return (a.second >= b.second);
}


class option {
private:
    string f_line,name,fil1,fil2 ;
    int scor;
    vector <string >line;
    vector <pair<string ,int>>net;
    vector <int>scr,str;
public:
    void get_line(vector<string> ln){
        line = ln;
    }
    void chk_convert(){
        for (int  i=0 ; i<line.size() ; ++i){
            string tm ;
            tm = line[i];
            if (tm == "him" || tm == "Him")
                f_line +=tm + " or her ";
            else if (tm == "he" ||tm == "He")
                f_line+=tm + " or she ";
            else if (tm == ".")
                f_line.pop_back(),f_line+=tm+" ";
            else if (tm == "His" || tm == "his")
                f_line+=tm +" or her ";
            else if (tm == "himself" || tm == "Himself")
                f_line +=tm + " or herself";
            else
                f_line +=tm+" ";
        }

    }
    void print_line () {
        for (int i=0 ; i<f_line.size() -1; ++i)
            cout<<f_line[i];
        cout<<f_line [f_line.size()-1]<<"\n";
    }
    void get_op(string nam, int sco){
        name =nam;
        scor =sco;
        net.push_back({name , scor});
    }
    void srt(){
        sort (net.begin() , net.end() , srt_scnd);
    }
    void print_player_list(){
        int n;
        if (net.size() >= 10)
            n=10;
        else n=net.size();
        for (int i=0 ; i<n ; ++i){
            cout<<net[i].first<<" "<<net[i].second<<"\n";
        }
    }
    void check(string chk){
        bool test=false ;
        int fond;
        int n;
        if (net.size() >= 10)
            n=10;
        else n=net.size();
        for (int  f=0 ; f<n ; ++f){
            if (net[f].first == chk)
                test=true,fond =net[f].second;
        }
        if (test)
            cout<<fond<<"\n";
        else {
            for (auto k : net  ){
                if (k.first  == chk)
                    test=true;
            }
            if (test)
                cout<<"This player's name  is not in the top 10.\n";
            else
                cout<<"This play's name has not been input.\n";

        }
    }
    void  Fractal (int t, int sps){
        int sz=2*(t-1)+1,sk_po=1,val_po=0,cnt=0;
        str.resize(sz) ;
        while (cnt < sz){
            int val=pow(2 ,val_po );
            int skp=pow(2,sk_po);
            for (int i=val-1 ; i<sz; i+=skp){
                str[i]=val;
                cnt++;
            }
            val_po++,sk_po++;
        }
        int spces=sps;
        for (int i=0 ; i<sz ; ++i){
            int num=str[i];
            if (i==0)
                for (int j=0 ; j<sps ; ++j)
                    cout<<" ";
            else {
                if (num > 1){
                    int m=spces-(num-1);
                    if (m < 0)
                        m=0;
                    for (int k=0 ; k<m ; ++k)
                        cout<<" ";
                }
                else
                    for (int r=0 ; r<spces ; ++r)
                        cout<<" ";
            }
            for (int p=0 ; p<num ; ++p)
                cout<<'*'<<" ";
            cout<<"\n";
            spces++;
        }

    }
    void com_char(string fil1 , string fil2){}
    void com_char (string fil1 , string fil2){
        fstream fle1,fle2;
        ifstream in;
        char str1 , str2;
        fle1.open(fil1);
        fle2.open(fil2);
        while (true){
            str1=fle1.get();
           str2 = fle2.get();
            cout<<str1<<" "<<str2;
           if (str1 == EOF || str2 == EOF )
               return;
        }
    }
};
int main() {
    option ob ;
    string s;
    cin>>s;
    if (s == "2"){
        string lin;
        getline( cin , lin);
        vector <string>vc;
        string tm="";
        for (int i=1 ; i<lin.size() ; ++i){
            char c=lin[i];
            if (c == '.'){
                if (!tm.empty())
                    vc.push_back(tm);
                tm="";
                tm+=c;
            }
            else if (c != ' ')
                tm+=c;
            else {
                vc.push_back(tm);
                tm="";
            }
        }
        if (!tm.empty())
            vc.push_back(tm);
        ob.get_line (vc);
        ob.chk_convert() ;
        ob.print_line() ;
    }
    else if (s == "5"){
        string ord;
        cout<<"Please enter your order \n";
        cin>>ord;
        while (cin >> ord){
            if (ord == "add"){
                string h;
                int n;
                cin>>h>>n;
                ob.get_op(h,n);
                ob.srt();
            }
            if (ord == "print")
                ob.print_player_list();
            if (ord  == "check"){
                string ply;
                cin>>ply;
                ob.check(ply);
            }
            if (ord == "end")
                return 0;
        }
    }
    else if (s == "8"){
        int n,i;
        cin>>n>>i;
        ob.Fractal(n,i);
    }
    else if (s == "11"){
        cout<<"Please enter names of files\n";
        string fl1 ,fl2;
        cin>>fl1>>fl2;
        cout<<"You want to compare word or char ?\n";
        string ch;
        cin>>ch;
        if (ch == "word"){
            ob.com_word(fl1 ,fl2);
        }
        else if (ch == "char"){
            ob.com_char (fl1 ,fl2 );
        }
    }
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Linker{
    private:
        vector<string> text;

    public:
        Linker(){
            string txt="#!/bin/sh";
            text.push_back(txt);
        }

        void add_link_file(string &location){
            string start="wine ";
            start=start+"\""+location+"\"";
            text.push_back(start);
        }

        void createfile(string &f){

            //open file
            ofstream file(f.c_str(),ios_base::out);

            //writing to file
            for(string &s:text){
                file<<s<<"\n";
            }
            file.close();
            string cmd="chmod +x "+f;
            string cmd2="mv ./"+f+" ~/bin/"+f;
            system(cmd.c_str());
            system(cmd2.c_str());


        }
};

int main(){
    Linker links;
    cout<<"Enter text to location of exe file"<<endl;
    string location;
    getline(cin,location);

    links.add_link_file(location);

    cin.clear();

    cout<<"Enter name of link file"<<endl;
    string file;
    getline(cin,file);

    cout<<"Creating file......."<<endl;

    links.createfile(file);

    cout<<"Done creating file... "<<endl;
    return 0;
}

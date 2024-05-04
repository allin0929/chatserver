#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

string func1(){
    json js;
    js["msg_type"]=2;
    js["from"]="zhang san";
    js["to"]="li si";
    js["msg"]="hello world";
    //cout<<js<<endl;

    string sendbuf = js.dump();
    return sendbuf;
}
string func2(){
    json js;
    js["id"]={1,2,3,4,5};
    js["name"]="zhang san";
    js["msg"]["zhang san"]="hello world";
    js["msg"]["li si"]="hello China";
    string sendbuf = js.dump();
    return sendbuf;
}

string func3(){
    json js;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    js["list"]=vec;
    map<int,string> mp;
    mp.insert({1,"黄山"});
    mp.insert({2,"泰山"});
    mp.insert({3,"峨眉山"});
    js["path"]=mp;
    string sendbuf = js.dump();
    return sendbuf;
}

int main(){
    string recebuf = func3();
    json jsbuf = json::parse(recebuf);
    /*cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["msg"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;*/
    /*auto id = jsbuf["id"];
    auto msgjs = jsbuf["msg"];
    cout<<id<<endl;
    cout<<msgjs["li si"]<<endl;*/
    vector<int> list = jsbuf["list"];
    for(int &v : list){
        cout<<v<<" ";
    }
    cout<<endl;
    map<int,string> mp=jsbuf["path"];
    for (auto &p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

template<class RandomIt>
string SliceElement(const string& msg,RandomIt str_iter){
   string query = "";
   for(int k = 0; k < msg.size(); ++k){
            query += *str_iter;
            str_iter = next(str_iter);
    } 
    return query;
}


template<class RandomIt>
pair<RandomIt,RandomIt> Func(RandomIt range_begin,RandomIt range_end, const string& msg){
    //
    auto iter = find_if(range_begin, range_end, [msg](const string& slovo)
    {
        auto it = begin(slovo);
        return SliceElement(msg,it) == msg;
    });
    //
    auto re_iter = iter;
    bool logistic = true;
    while(logistic == true){
        string query ="";
        re_iter = next(re_iter);
        string word = *re_iter;
        auto str_iter = begin(word);
         
        if(SliceElement(msg,str_iter) != msg){
            logistic = false;
        }
    }
    //
    return make_pair(iter,re_iter);
}

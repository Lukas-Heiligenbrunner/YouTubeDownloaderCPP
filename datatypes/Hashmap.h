//
// Created by lukas on 07.04.19.
//

#ifndef QT5PROJECT_HASHMAP_H
#define QT5PROJECT_HASHMAP_H


#include <iostream>
#include <vector>

template <class keytype,class valuetype> class Hashmap {
public:
    void add(keytype key,keytype value);
    keytype getKey(int position);
    valuetype getValue(int position);

    int size();

private:
    std::vector<keytype> keys;
    std::vector<valuetype> values;
};

template<class keytype, class valuetype>
void Hashmap<keytype, valuetype>::add(keytype key, keytype value) {
    keys.push_back(key);
    values.push_back(value);
}

template<class keytype, class valuetype>
keytype Hashmap<keytype, valuetype>::getKey(int position) {
    return keys.at(position);
}

template<class keytype, class valuetype>
valuetype Hashmap<keytype, valuetype>::getValue(int position) {
    return values.at(position);
}

template<class keytype, class valuetype>
int Hashmap<keytype, valuetype>::size() {
    return keys.size();
}


#endif //QT5PROJECT_HASHMAP_H

//
// Created by Jiahao FENG on 10/1/2021.
//

#include "../include/utils/Dictionary.h"
#include <iostream>

using namespace Utils;

Dictionary::Dictionary(int wordSize)
: m_values(), m_valuePositions(), m_adjacencyList(), m_wordSize(wordSize){

}

const std::vector<std::vector<bool>> & Dictionary::adjList() {
    return m_adjacencyList;
}

int Dictionary::size() const {
    return m_values.size();
}

Dictionary & Dictionary::operator=(const Dictionary &p) {
    if(&p != this){
        m_adjacencyList = p.m_adjacencyList;
        m_valuePositions = p.m_valuePositions;
        m_values = p.m_values;
        m_wordSize = p.m_wordSize;
    }

    return *this;
}

bool Dictionary::diffByOne(const std::string &a, const std::string &b) {
    if(a.size() != b.size())
        return false;
    int ndiff = 0;
    for(int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i])
            ndiff++;
    }
    return ndiff == 1;
}

bool Dictionary::contains(const std::string &s) {
    return m_valuePositions.find(s) != m_valuePositions.end();
}

int Dictionary::elemPostion(const std::string &s) {
    return m_valuePositions[s];
}

void Dictionary::addElement(const std::string &s) {
    if(s.size() != m_wordSize)
        throw std::runtime_error("invalid string size");

    m_values.push_back(s);
    m_valuePositions[s] = m_values.size() - 1;
    std::cout << " added " << s << std::endl;
}

std::string Dictionary::elemAtPos(int i) {
    return m_values[i];
}

void Dictionary::buildAdjancencyMatrx() {
    m_adjacencyList.clear();
    int n = m_values.size();
    for(int i = 0; i < n; ++i){
        m_adjacencyList.emplace_back(n);
        for(int j = 0; j < n; ++j){
            if(diffByOne(m_values[i], m_values[j])){
                m_adjacencyList[i][j] = true;
            }
        }
    }
}


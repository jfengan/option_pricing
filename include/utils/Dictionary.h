//
// Created by Jiahao FENG on 9/1/2021.
//

#ifndef OPTION_PRICING_DICTIONARY_H
#define OPTION_PRICING_DICTIONARY_H

#include <string>
#include <vector>
#include <map>

namespace Utils{
    class Dictionary{
    public:
        Dictionary(int wordSize);
        ~Dictionary();
        Dictionary &operator=(const Dictionary &p);

    private:
        Dictionary(const Dictionary &p);

    public:
        void addElement(const std::string &s);
        void buildAdjancencyMatrx();
        bool contains(const std::string &s);
        const std::vector<std::vector<bool>> & adjList();
        int elemPostion(const std::string &s);
        int size() const;
        std::string elemAtPos(int i);
        static bool diffByOne(const std::string &a, const std::string &b);

    private:
        std::vector<std::string> m_values;
        std::map<std::string, int> m_valuePositions;
        std::vector<std::vector<bool>> m_adjacencyList;
        int m_wordSize;
    };
}

#endif //OPTION_PRICING_DICTIONARY_H

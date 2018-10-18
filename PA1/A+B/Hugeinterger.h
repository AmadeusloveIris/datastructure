//
// Created by amadeus on 18-10-17.
//

#ifndef MULT_HUGEINTERGER_H
#define MULT_HUGEINTERGER_H

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

class InputIllegal {};

class Hugeinterger {
private:
    std::string _content;
    std::string Addmachine(const std::string &a, const std::string &b);
    void Check(const std::string &a);
    std::string Multmachine(const std::string &a, const std::string &b);
    int Normal(const std::string &a, const std::string &b, std::string &aout, std::string &bout);
    void Normul(const std::string &a, const std::string &b, std::string &aout, std::string &bout);
    void Removezero(std::string &a);
public:
    Hugeinterger(std::string cont);
    Hugeinterger operator+ (Hugeinterger &b);
    Hugeinterger operator* (Hugeinterger &b);
    friend std::ostream&operator<< (std::ostream& out, const Hugeinterger &a);


};


#endif //MULT_HUGEINTERGER_H

//
// Created by amadeus on 18-10-17.
//

#include "Hugeinterger.h"


Hugeinterger::Hugeinterger(std::string cont) {
    Check(cont);
    std::reverse(cont.begin(),cont.end());
    _content=cont;
}

std::string Hugeinterger::Addmachine(const std::string &a, const std::string &b) {
    std::string result,aout,bout;
    int length = Normal(a,b,aout,bout);
    int carry = 0;
    for (int i = 0; i < length; ++i){
        int temp = (int)aout.at(i) + (int)bout.at(i) - 2 * (int)'0' + carry;
        result.append(1,(char)(temp%10+'0'));
        carry = temp / 10;
        if (i == length -1 && carry)
            result.append(1,'1');
    }
    return result;
}

void Hugeinterger::Check(const std::string &a) {
    if (a.empty())
        throw InputIllegal();
    else {
        for (int i = 0; i < a.length(); ++i) {
            if (a.at(i) > '9' || a.at(i) < '0') {
                throw InputIllegal();
            }
        }
    }
}

void Hugeinterger::Removezero(std::string &a) {
    for (int i = a.length()-1; i >= 0; --i){
        if(a.at(i)!='0')
            break;
        else
            a.pop_back();
    }
}

int Hugeinterger::Normal(const std::string &a, const std::string &b, std::string &aout, std::string &bout) {
    int length= a.length() > b.length() ? a.length() : b.length();
    aout = a; bout = b;
    Removezero(aout);
    Removezero(bout);
    length = aout.length() > bout.length() ? aout.length() : bout.length();
    if (int tmp = length-aout.length())
        aout.append(tmp,'0');
    else if (int tmp = length-bout.length())
        bout.append(tmp,'0');
    return length;
}

std::string Hugeinterger::Multmachine(const std::string &a, const std::string &b){
    if (a.length() == 1 || b.length() == 1){
        int result = ((int)a.back() - '0') * ((int)b.back() - '0');
        std::string content;
        content.append(std::to_string(result));
        std::reverse(content.begin(),content.end());
        return content;
    }
    std::string a1 = a.substr(floor(a.length()/2));
    std::string a0 = a.substr(0,floor(a.length()/2));
    std::string b1 = b.substr(floor(a.length()/2));
    std::string b0 = b.substr(0,floor(a.length()/2));
    std::string c2,c1,c0,result;
    c2 = Multmachine(a1,b1);
    c1 = Addmachine(Multmachine(a0,b1),Multmachine(a1,b0));
    c0 = Multmachine(a0,b0);
    c1.insert(c1.begin(),floor(a.length()/2),'0');
    c2.insert(c2.begin(),floor(a.length()),'0');
    result = Addmachine(c2,Addmachine(c0,c1));
    return result;
}

Hugeinterger Hugeinterger::operator+(Hugeinterger &b) {
    std::string result = Addmachine(_content, b._content);
    std::reverse(result.begin(),result.end());
    return Hugeinterger(result);
}

void Hugeinterger::Normul(const std::string &a, const std::string &b, std::string &aout, std::string &bout) {
    int leng = Normal(a,b,aout,bout);
    int length = pow(2,ceil(log2(aout.length())));
    if (int tmp = length-leng) {
        aout.append(tmp, '0');
        bout.append(tmp, '0');
    }
}

Hugeinterger Hugeinterger::operator*(Hugeinterger &b) {
    std::string result,aout,bout;
    Normul(_content,b._content,aout,bout);
    result = Multmachine(aout, bout);
    std::reverse(result.begin(),result.end());
    return Hugeinterger(result);
}

std::ostream& operator<<(std::ostream& out, const Hugeinterger &a) {
    std::string content = a._content;
    std::reverse(content.begin(),content.end());
    out << content;
    return out;
}
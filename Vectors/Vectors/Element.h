#pragma once

#ifndef Element_hpp
#define Element_hpp

#include <iostream>
#include <queue>
#include <string>
#include <string>

class Element {
public:
    virtual std::ostream& ins(std::ostream&) const; 
    virtual std::istream& ext(std::istream&);
    std::queue<std::string> _Commands;
    std::vector<std::string> getOutputs();
    void pushtToOutputs(std::string output);
    void setOutputs(std::vector<std::string> outputs);
    virtual std::string get_data();

private:
    std::vector<std::string> _Outputs;
};

std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);

#endif

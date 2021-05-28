#pragma once

#ifndef Element_hpp
#define Element_hpp

#include <iostream>

class Element {
public:
    virtual std::ostream& ins(std::ostream&) const; 
    virtual std::istream& ext(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Element&);
std::istream& operator>>(std::istream&, Element&);

#endif

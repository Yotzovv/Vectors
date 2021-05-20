#include "Element.h"

std::ostream& Element::ins(std::ostream& out) const
{
    return out;
}

std::istream& Element::ext(std::istream& in)
{
    return in;
}

std::ostream& operator<<(std::ostream& out, const Element& rhs)
{
    return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, Element& rhs)
{
    return rhs.ext(in);
}

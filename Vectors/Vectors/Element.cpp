#include "Element.h"

std::ostream& Element::ins(std::ostream& out) const
{
    return out;
}

std::istream& Element::ext(std::istream& in)
{
    return in;
}

std::vector<std::string> Element::getOutputs()
{
    return _Outputs;
}

void Element::pushtToOutputs(std::string output)
{
    _Outputs.push_back(output);
}

void Element::setOutputs(std::vector<std::string> outputs)
{
    _Outputs = outputs;
}

std::string Element::get_data()
{
    return std::string();
}

std::ostream& operator<<(std::ostream& out, const Element& rhs)
{
    return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, Element& rhs)
{
    return rhs.ext(in);
}

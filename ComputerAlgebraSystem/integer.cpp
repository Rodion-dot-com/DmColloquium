#include "integer.h"

integer::integer():
    quantity_(1), digits_(new int), sign_(true)
{
    digits_[0] = 0;
}

integer::integer(const std::string &str)
{
    int shift = 0;
    sign_ = true;
    if(str[0] == '-') {
        shift = 1;
        sign_ = false;
    }
    quantity_ = str.size() - shift;
    digits_ = new int[quantity_];
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = str[i + shift] - '0';
    }
}

integer::integer(const integer &other):
    quantity_(other.quantity_), digits_(new int[quantity_]),
    sign_(other.sign_)
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = other.digits_[i];
    }
}

integer::integer(const int quantity, const int *digits, const bool sign):
    quantity_(quantity), digits_(new int[quantity_]), sign_(sign)
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = digits[i];
    }
}

integer::integer(const natural &other):
    quantity_(other.get_quantity()), digits_(new int[quantity_]),
    sign_(true)
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = other.get_digits()[i];
    }
}

integer & integer::operator=(const integer &other)
{
    if(digits_ == other.digits_)
        return *this;
    if(digits_)
        delete[] digits_;
    quantity_ = other.quantity_;
    sign_ = other.sign_;
    digits_ = new int[quantity_];
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = other.digits_[i];
    }
    return *this;
}

integer::~integer()
{
    if(digits_)
        delete[] digits_;
}

void integer::print()
{
    if(!sign_)
        std::cout << '-';
    for(int i = 0; i < quantity_; ++i)
    {
        std::cout << digits_[i];
    }
    std::cout << std::endl;
}

int integer::get_quantity() const
{
    return quantity_;
}

int* integer::get_digits() const
{
    return digits_;
}

bool integer::get_sign() const
{
    return sign_;
}
#include "natural.h"

natural::natural(const std::string &str):
    quantity_(str.size()), digits_(new int [quantity_])
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[quantity_ - 1 - i] = (str[i] - '0');
    }
}

natural::natural():
    quantity_(1), digits_(new int)
{
    digits_[0] = 0;
}

natural::natural(const natural &other):
    quantity_(other.quantity_), digits_(new int [quantity_])
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = other.digits_[i];
    }
}

natural::natural(int quantity, const int *digits):
    quantity_(quantity), digits_(new int[quantity_])
{
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = digits[i];
    }
}

natural::~natural()
{
    if(digits_)
        delete[] digits_;
}

int natural::get_quantity() const
{
    return quantity_;
}

int* natural::get_digits() const
{
    return digits_;
}

natural & natural::operator=(const natural &other)
{
    if(digits_ == other.digits_)
        return *this;
    if(digits_)
        delete[] digits_;
    quantity_ = other.quantity_;
    digits_ = new int [quantity_];
    for(int i = 0; i < quantity_; ++i)
    {
        digits_[i] = other.digits_[i];
    }
    return *this;
}

bool natural::operator==(const natural &other)
{
    if(quantity_ != other.quantity_)
        return false;
    for(int i = 0; i < quantity_; ++i)
    {
        if(digits_[i] != other.digits_[i])
            return false;
    }
    return true;
}

void natural::print()
{
    for(int i = quantity_ - 1; i >= 0; --i){
        std::cout << digits_[i];
    }
    std::cout << std::endl;
}

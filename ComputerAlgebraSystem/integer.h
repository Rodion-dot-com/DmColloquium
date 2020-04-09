#ifndef COMPUTERALGEBRASYSTEM_INTEGER_H
#define COMPUTERALGEBRASYSTEM_INTEGER_H


class integer {
public:
    integer();
    integer(const std::string& str);
    integer(const integer& other);
    integer(const int quantity, const int* digits, const bool sign);
    integer(const natural& other);
    integer & operator=(const integer& other);
    ~integer();
    void print();
    int get_quantity() const;
    int * get_digits() const;
    bool get_sign() const;
private:
    int quantity_;
    int* digits_;
    bool sign_;
};


#endif //COMPUTERALGEBRASYSTEM_INTEGER_H

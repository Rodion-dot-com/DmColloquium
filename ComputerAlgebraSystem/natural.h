#ifndef COMPUTERALGEBRASYSTEM_NATURAL_H
#define COMPUTERALGEBRASYSTEM_NATURAL_H


class natural {
public:
    natural();
    natural(const std::string& str);
    natural(const natural& other);
    natural(const int quantity, const int* digits);
    ~natural();
    natural & operator=(const natural& other);
    bool operator==(const natural& other);
    void print();
    int get_quantity() const;
    int* get_digits() const;
private:
    int quantity_;
    int* digits_;
};


#endif //COMPUTERALGEBRASYSTEM_NATURAL_H

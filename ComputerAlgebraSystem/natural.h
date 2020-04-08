#ifndef COMPUTERALGEBRASYSTEM_NATURAL_H
#define COMPUTERALGEBRASYSTEM_NATURAL_H


class natural {
public:
    natural();
    natural(const std::string& str);
    natural(const natural& other);
    ~natural();
    natural& operator= (const natural& other);
    bool operator== (const natural& other);
    void print();
private:
    int quantity_;
    int* digits_;
};


#endif //COMPUTERALGEBRASYSTEM_NATURAL_H

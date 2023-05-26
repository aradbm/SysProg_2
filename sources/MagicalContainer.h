#pragma once
#include <list>

class MagicalContainer
{
private:
    std::list<int> container;

public:
    MagicalContainer();
    ~MagicalContainer();
    int size();
    void addElement(int element);
    void removeElement(int element);
};

class BaseIterator
{
protected:
    const MagicalContainer &container;

public:
    BaseIterator(const MagicalContainer &container);
    virtual ~BaseIterator() {}
    BaseIterator(const BaseIterator &other);
    BaseIterator &operator=(const BaseIterator &other);
    virtual BaseIterator &operator++();
    virtual bool operator==(const BaseIterator &other) const;
    virtual bool operator!=(const BaseIterator &other) const;
    virtual int operator*() const;
    virtual BaseIterator &begin();
    virtual BaseIterator &end();
};

class AscendingIterator : public BaseIterator
{
public:
    AscendingIterator(const MagicalContainer &container);
};

class SideCrossIterator : public BaseIterator
{
public:
    SideCrossIterator(const MagicalContainer &container);
};

class PrimeIterator : public BaseIterator
{
public:
    PrimeIterator(const MagicalContainer &container);
};

#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <set>

namespace ariel
{
    class Iterator
    {
    protected:
        int *current;

    public:
        // constructors
        Iterator() : current(nullptr) {}
        virtual ~Iterator() = default;
        virtual int *begin() = 0;
        virtual int *end() = 0;

        // operators
        virtual Iterator &operator++() = 0;
        virtual bool operator==(int *other) const
        {
            if (current == nullptr && other == nullptr)
                return true;
            else if (current == nullptr || other == nullptr)
                return false;
            return *current == *other;
        }
        virtual bool operator==(const Iterator &other) const
        {
            if (current == nullptr || other.current == nullptr)
                return false;
            return *current == *other.current;
        }
        virtual bool operator!=(int *other) const { return !(*this == other); }
        virtual bool operator!=(const Iterator &other) const { return !(*this == other); }
        virtual bool operator<(const Iterator &other) const { return current < other.current; }
        virtual bool operator>(const Iterator &other) const { return current > other.current; }
        virtual int &operator*() { return *current; }
    };

    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        MagicalContainer() = default;
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator : public Iterator
    {
    private:
        MagicalContainer &container;

    public:
        AscendingIterator(MagicalContainer &container);
        int *begin() override;
        int *end() override;
        Iterator &operator++() override;
        AscendingIterator &operator=(const AscendingIterator &other)
        {
            if (this != &other)
                current = other.current;
            return *this;
        }
    };

    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        MagicalContainer &container;
        int currentIndex;
        bool isReversed;

    public:
        SideCrossIterator(MagicalContainer &container);
        int *begin() override;
        int *end() override;
        Iterator &operator++() override;
        SideCrossIterator &operator=(const SideCrossIterator &other)
        {
            if (this != &other)
                current = other.current;
            return *this;
        }
    };

    class MagicalContainer::PrimeIterator : public Iterator
    {
    private:
        MagicalContainer &container;

    public:
        PrimeIterator(MagicalContainer &container);
        bool isPrime(int number);
        int *begin() override;
        int *end() override;
        Iterator &operator++() override;

        PrimeIterator &operator=(const PrimeIterator &other)
        {
            if (this != &other)
                current = other.current;
            return *this;
        }
    };
}

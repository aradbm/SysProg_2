#pragma once
#include <vector>

namespace ariel
{
    class Iterator
    {
    public:
        virtual int *begin() = 0;
        virtual int *end() = 0;
        virtual ~Iterator() = default;
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
    };

    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        MagicalContainer &container;

    public:
        SideCrossIterator(MagicalContainer &container);
        int *begin() override;
        int *end() override;
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
    };
}

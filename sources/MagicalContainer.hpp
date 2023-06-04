#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <set>

namespace ariel
{
    class MagicalContainer;

    class Iterator
    {

    public:
        // constructors
        Iterator() = default;
        virtual ~Iterator() = default;

        // operators
        virtual int &operator*() const = 0;
        virtual bool operator==(const Iterator &other) const = 0;
        virtual bool operator!=(const Iterator &other) const = 0;

        // vitual methods
        virtual Iterator &operator++() = 0;
        virtual bool operator<(const Iterator &other) const = 0;
        virtual bool operator>(const Iterator &other) const = 0;
    };

    class MagicalContainer
    {
    protected:
        std::vector<int> elements;
        std::vector<const int *> acc_pointers;
        std::vector<const int *> side_cross_pointers;
        std::vector<const int *> prime_pointers;

    public:
        MagicalContainer() = default;
        void addElement(int element);
        void removeElement(int element);
        int getElement(int index) { return elements[index]; }
        int size() const;

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };
    //----------------------------------------------------------------------------------------------
    class MagicalContainer::AscendingIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        AscendingIterator(MagicalContainer &container);
        AscendingIterator(MagicalContainer &container, size_t index);
        int &operator*() const override;
        bool operator==(const Iterator &other) const override;
        bool operator!=(const Iterator &other) const override;
        Iterator &operator++() override;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;
        AscendingIterator begin() const
        {
            return AscendingIterator(container, 0);
        }
        AscendingIterator end()
        {
            return AscendingIterator(container, container.size());
        }
    };
    //----------------------------------------------------------------------------------------------
    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        SideCrossIterator(MagicalContainer &container);
        int &operator*() const override;
        virtual bool operator==(const Iterator &other) const = 0;
        virtual bool operator!=(const Iterator &other) const = 0;

        Iterator &operator++() override;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;
    };
    //----------------------------------------------------------------------------------------------
    class MagicalContainer::PrimeIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        PrimeIterator(MagicalContainer &container);
        bool isPrime(int number);
        int &operator*() const override;
        virtual bool operator==(const Iterator &other) const = 0;
        virtual bool operator!=(const Iterator &other) const = 0;
        Iterator &operator++() override;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;
    };
    //----------------------------------------------------------------------------------------------
}

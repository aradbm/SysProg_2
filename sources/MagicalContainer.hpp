#pragma once
#include <set>
#include <vector>
#include <stdexcept>
using namespace std;

namespace ariel
{
    class Iterator
    {
    public:
        // constructors
        Iterator() = default;
        virtual ~Iterator() = default;

        // operators
        virtual int operator*() const = 0;
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
        set<int> elements;
        vector<const int *> acc_pointers;
        vector<const int *> side_cross_pointers;
        vector<const int *> prime_pointers;

    public:
        MagicalContainer()
        {
            elements = set<int>();
            acc_pointers = vector<const int *>();
            side_cross_pointers = vector<const int *>();
            prime_pointers = vector<const int *>();
        };
        void addElement(int element);
        void removeElement(int element);
        int size() const;

        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
        static bool isPrime(int num)
        {
            if (num <= 1)
            {
                return false;
            }
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    };
    //----------------------------------------------------------------------------------------------
    class MagicalContainer::AscendingIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        // ctor & dtor
        AscendingIterator(MagicalContainer &container);
        AscendingIterator(MagicalContainer &container, size_t index);
        ~AscendingIterator() override = default;

        // copy, move & assign operators
        AscendingIterator(const AscendingIterator &other);
        AscendingIterator(AscendingIterator &&other);
        AscendingIterator &operator=(const AscendingIterator &other);
        AscendingIterator &operator=(AscendingIterator &&other);

        // operators
        Iterator &operator++() override;
        int operator*() const override;
        bool operator==(const Iterator &other) const override;
        bool operator!=(const Iterator &other) const override;
        bool operator==(const AscendingIterator &other) const;
        bool operator!=(const AscendingIterator &other) const;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;

        // methods
        AscendingIterator begin() const
        {
            return AscendingIterator(container, 0);
        }
        AscendingIterator end()
        {
            return AscendingIterator(container, container.acc_pointers.size());
        }
    };
    //----------------------------------------------------------------------------------------------
    class MagicalContainer::SideCrossIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        // ctor & dtor
        SideCrossIterator(MagicalContainer &container);
        SideCrossIterator(MagicalContainer &container, size_t index);
        ~SideCrossIterator() override = default;

        // copy, move & assign operators
        SideCrossIterator(const SideCrossIterator &other);
        SideCrossIterator(SideCrossIterator &&other);
        SideCrossIterator &operator=(const SideCrossIterator &other);
        SideCrossIterator &operator=(SideCrossIterator &&other);

        // operators
        Iterator &operator++() override;
        int operator*() const override;
        bool operator==(const Iterator &other) const override;
        bool operator!=(const Iterator &other) const override;
        bool operator==(const SideCrossIterator &other) const;
        bool operator!=(const SideCrossIterator &other) const;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;
        SideCrossIterator begin() const
        {
            return SideCrossIterator(container, 0);
        }
        SideCrossIterator end()
        {
            return SideCrossIterator(container, container.side_cross_pointers.size());
        }
    };
    // //----------------------------------------------------------------------------------------------
    class MagicalContainer::PrimeIterator : public Iterator
    {
    private:
        size_t currentIndex;
        MagicalContainer &container;

    public:
        // ctor & dtor
        PrimeIterator(MagicalContainer &container);
        PrimeIterator(MagicalContainer &container, size_t index);
        ~PrimeIterator() override = default;

        // copy, move & assign operators
        PrimeIterator(const PrimeIterator &other);
        PrimeIterator(PrimeIterator &&other);
        PrimeIterator &operator=(const PrimeIterator &other);
        PrimeIterator &operator=(PrimeIterator &&other);

        // operators
        Iterator &operator++() override;
        int operator*() const override;
        bool operator==(const Iterator &other) const override;
        bool operator!=(const Iterator &other) const override;
        bool operator==(const PrimeIterator &other) const;
        bool operator!=(const PrimeIterator &other) const;
        bool operator<(const Iterator &other) const override;
        bool operator>(const Iterator &other) const override;

        // methods
        PrimeIterator begin() const
        {
            return PrimeIterator(container, 0);
        }
        PrimeIterator end() const
        {
            return PrimeIterator(container, container.prime_pointers.size());
        }
    };
}
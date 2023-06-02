#include "MagicalContainer.hpp"

namespace ariel
{
    void MagicalContainer::addElement(int element)
    {
    }

    void MagicalContainer::removeElement(int element)
    {
    }

    int MagicalContainer::size() const
    {
        return 0;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container)
    {
    }

    int *MagicalContainer::AscendingIterator::begin()
    {
        int *temp = 0;
        return temp;
    }

    int *MagicalContainer::AscendingIterator::end()
    {
        int *temp = 0;
        return temp;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container)
    {
    }

    int *MagicalContainer::SideCrossIterator::begin()
    {
        int *temp = 0;
        return temp;
    }

    int *MagicalContainer::SideCrossIterator::end()
    {
        int *temp = 0;
        return temp;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container)
    {
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number)
    {
        return false;
    }

    int *MagicalContainer::PrimeIterator::begin()
    {
        int *temp = 0;
        return temp;
    }

    int *MagicalContainer::PrimeIterator::end()
    {
        int *temp = 0;
        return temp;
    }
}

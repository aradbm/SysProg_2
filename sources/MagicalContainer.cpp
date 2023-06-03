#include "MagicalContainer.hpp"

namespace ariel
{
    // MagicalContainer

    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        auto position = std::find(elements.begin(), elements.end(), element);
        if (position != elements.end())
        {
            elements.erase(position);
        }
        else
        {
            throw std::runtime_error("Element not found in the container.");
        }
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }

    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container)
    {
        if (!container.elements.empty())
        {
            std::sort(container.elements.begin(), container.elements.end());
            current = container.elements.data();
        }
        else
        {
            current = nullptr;
        }
    }

    int *MagicalContainer::AscendingIterator::begin()
    {
        return container.elements.empty() ? nullptr : &container.elements.front();
    }

    int *MagicalContainer::AscendingIterator::end()
    {
        return container.elements.empty() ? nullptr : &container.elements.back() + 1;
    }

    Iterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (current == nullptr)
            throw std::runtime_error("Iterator is not initialized.");
        if (current == end())
            throw std::runtime_error("Iterator is at the end of the container.");
        if (current != nullptr)
        {
            ++current;
            if (current == end())
            {
                current = end();
            }
        }
        return *this;
    }
    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container)
    {
        if (!container.elements.empty())
        {
            current = container.elements.data();
        }
        else
        {
            current = nullptr;
        }
    }

    int *MagicalContainer::SideCrossIterator::begin()
    {
        return container.elements.empty() ? nullptr : container.elements.data();
    }

    int *MagicalContainer::SideCrossIterator::end()
    {
        return container.elements.empty() ? nullptr : container.elements.data() + container.size();
    }

    Iterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (current == nullptr)
            throw std::runtime_error("Iterator is not initialized.");

        if (current == end())
            throw std::runtime_error("Iterator is at the end of the container.");

        if (current != nullptr)
        {
            if (current == container.elements.data())
            {
                current++;
            }
            else if (current == container.elements.data() + container.size() - 1)
            {
                current--;
            }
            else
            {
                int distanceFromBegin = current - container.elements.data();
                int distanceFromEnd = (container.elements.data() + container.size() - 1) - current;

                if (distanceFromBegin <= distanceFromEnd)
                {
                    current = container.elements.data() + container.size() - 1 - distanceFromBegin;
                }
                else
                {
                    current = container.elements.data() + distanceFromEnd + 1;
                }
            }
        }
        return *this;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container)
    {
        current = begin();
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number)
    {
        if (number <= 1)
            return false;
        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    int *MagicalContainer::PrimeIterator::begin()
    {
        for (int *p = container.elements.data(); p != end(); p++)
        {
            if (isPrime(*p))
                return p;
        }
        return end();
    }

    int *MagicalContainer::PrimeIterator::end()
    {
        return container.elements.data() + container.size();
    }

    Iterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (current == nullptr)
            throw std::runtime_error("Iterator is not initialized.");
        if (current == end())
            throw std::runtime_error("Iterator is at the end of the container.");

        current++;
        while (current != end() && !isPrime(*current))
        {
            current++;
        }
        return *this;
    }

}

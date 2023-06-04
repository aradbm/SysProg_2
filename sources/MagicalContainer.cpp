#include "MagicalContainer.hpp"

namespace ariel
{
    void MagicalContainer::addElement(int element)
    {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element)
    {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end())
        {
            elements.erase(it);
        }
    }

    int MagicalContainer::size() const
    {
        return elements.size();
    }
    //----------------------------------------------------------------------------------------------
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container), currentIndex(0) {}

    int &MagicalContainer::AscendingIterator::operator*() const
    {
        return container.elements[currentIndex];
    }

    bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const
    {
        const AscendingIterator *other_iter = dynamic_cast<const AscendingIterator *>(&other);
        if (other_iter == nullptr)
        {
            throw std::runtime_error("Cannot compare iterators of different types");
        }
        if (&container != &other_iter->container)
        {
            throw std::runtime_error("Cannot compare iterators of different containers");
        }
        return currentIndex == other_iter->currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const
    {
        return !(*this == other);
    }

    Iterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (currentIndex < container.size())
        {
            ++currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator<(const Iterator &other) const
    {
        const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);
        if (other_ptr == nullptr)
        {
            throw std::runtime_error("Cannot compare iterators of different types");
        }
        if (&container != &other_ptr->container)
        {
            throw std::runtime_error("Cannot compare iterators of different containers");
        }
        return currentIndex < other_ptr->currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator>(const Iterator &other) const
    {
        return !(*this < other) && !(*this == other);
    }

    //----------------------------------------------------------------------------------------------
}

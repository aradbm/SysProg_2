#include "MagicalContainer.hpp"

using namespace ariel;
//--------------------------------- MagicalContainer ------------------------------------------
void MagicalContainer::addElement(int element)
{
    elements.insert(element);                      // insert element to elements set
    auto new_int_pointer = elements.find(element); // find element in elements set, get pointer

    // adding to acc_pointers
    acc_pointers.push_back(&(*new_int_pointer));
    // sort acc_pointers
    for (auto i = 0u; i < acc_pointers.size(); i++)
    {
        for (auto j = 0u; j < acc_pointers.size() - i - 1; j++)
        {
            if (*(acc_pointers[j]) > *(acc_pointers[j + 1]))
            {
                auto temp = acc_pointers[j];
                acc_pointers[j] = acc_pointers[j + 1];
                acc_pointers[j + 1] = temp;
            }
        }
    }
    // adding to side_cross_pointers
    side_cross_pointers.clear();
    size_t start = 0;
    int end = size() - 1;

    if (size() <= 1)
    {
        side_cross_pointers.push_back(acc_pointers.at(0));
    }
    else
    {
        while (start <= static_cast<size_t>(end) && end >= 0)
        {
            side_cross_pointers.push_back(acc_pointers.at(start));

            if (start != static_cast<size_t>(end))
            {
                side_cross_pointers.push_back(acc_pointers.at(static_cast<std::vector<int>::size_type>(end)));
            }
            start++;
            end--;
        }
    }
    // ading to prime_pointers
    if (isPrime(element))
    {
        prime_pointers.push_back(&(*new_int_pointer));
    }
}

void MagicalContainer::removeElement(int element)
{
    if (elements.empty())
    {
        throw runtime_error("empty container");
    }
    // check if element exists
    auto index = -1u;
    for (auto i = 0u; i < elements.size(); i++)
    {
        if (elements.find(element) != elements.end())
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        throw runtime_error("element not found");
    // remove element from elements set
    elements.erase(element);
    // remove element from pointer vectors
    for (auto i = 0u; i < acc_pointers.size(); i++)
    {
        if (*(acc_pointers[i]) == element)
        {
            acc_pointers.erase(acc_pointers.begin() + i);
            break;
        }
    }
    for (auto i = 0u; i < prime_pointers.size(); i++)
    {
        if (*(prime_pointers[i]) == element)
        {
            prime_pointers.erase(prime_pointers.begin() + i);
            break;
        }
    }
    for (auto i = 0u; i < side_cross_pointers.size(); i++)
    {
        if (*(side_cross_pointers[i]) == element)
        {
            side_cross_pointers.erase(side_cross_pointers.begin() + i);
            break;
        }
    }
}

int MagicalContainer::size() const
{
    return elements.size();
}
//--------------------------------- AscendingIterator ------------------------------------------
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container), currentIndex(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index) : container(container), currentIndex(index) {}

// copy, move & assign operators
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::AscendingIterator::AscendingIterator(AscendingIterator &&other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{

    if (this != &other)
    {
        // runtime error if the iterators with different containers
        if (&container != &other.container)
        {
            throw runtime_error("Cannot compare iterators of different containers");
        }
        currentIndex = other.currentIndex;
    }
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(AscendingIterator &&other)
{
    if (this != &other)
    {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

// iterator operators

Iterator &MagicalContainer::AscendingIterator::operator++()
{
    if (currentIndex >= container.acc_pointers.size())
    {
        throw runtime_error("Iterator out of range");
    }
    if (currentIndex < container.size())
    {
        currentIndex++;
    }
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() const
{
    if (currentIndex >= container.acc_pointers.size())
    {
        throw runtime_error("Iterator out of range");
    }
    return *(container.acc_pointers.at(currentIndex));
}

bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const
{
    const AscendingIterator *other_iter = dynamic_cast<const AscendingIterator *>(&other);
    if (other_iter == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_iter->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex == other_iter->currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const Iterator &other) const
{
    const AscendingIterator *other_ptr = dynamic_cast<const AscendingIterator *>(&other);
    if (other_ptr == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_ptr->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex < other_ptr->currentIndex;
}

bool MagicalContainer::AscendingIterator::operator>(const Iterator &other) const
{
    return !(*this < other) && !(*this == other);
}
//--------------------------------- SideCrossIterator ------------------------------------------

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container), currentIndex(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index) : container(container), currentIndex(index) {}

// copy, move & assign operators
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(SideCrossIterator &&other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        // runtime error if the iterators with different containers
        if (&container != &other.container)
        {
            throw runtime_error("Cannot compare iterators of different containers");
        }
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(SideCrossIterator &&other)
{
    if (this != &other)
    {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

Iterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (currentIndex >= container.side_cross_pointers.size())
    {
        throw runtime_error("Iterator out of range");
    }
    if (currentIndex < container.size())
    {
        ++currentIndex;
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const
{
    return *(container.side_cross_pointers[currentIndex]);
}

bool MagicalContainer::SideCrossIterator::operator==(const Iterator &other) const
{
    const SideCrossIterator *other_iter = dynamic_cast<const SideCrossIterator *>(&other);
    if (other_iter == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_iter->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex == other_iter->currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(*this == other);
}
bool MagicalContainer::SideCrossIterator::operator<(const Iterator &other) const
{
    const SideCrossIterator *other_ptr = dynamic_cast<const SideCrossIterator *>(&other);
    if (other_ptr == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_ptr->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex < other_ptr->currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const Iterator &other) const
{
    return !(*this < other) && !(*this == other);
}

//--------------------------------- PrimeIterator ------------------------------------------

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container), currentIndex(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index) : container(container), currentIndex(index) {}

// copy, move & assign operators

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator &&other) : container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        // runtime error if the iterators with different containers
        if (&container != &other.container)
        {
            throw runtime_error("Cannot compare iterators of different containers");
        }
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(PrimeIterator &&other)
{
    if (this != &other)
    {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

Iterator &MagicalContainer::PrimeIterator::operator++()
{
    if (currentIndex >= container.prime_pointers.size())
    {
        throw runtime_error("Iterator out of range");
    }
    else if (currentIndex < container.size())
    {
        ++currentIndex;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    return *(container.prime_pointers[currentIndex]);
}

bool MagicalContainer::PrimeIterator::operator==(const Iterator &other) const
{
    const PrimeIterator *other_iter = dynamic_cast<const PrimeIterator *>(&other);
    if (other_iter == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_iter->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex == other_iter->currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(*this == other);
}
bool MagicalContainer::PrimeIterator::operator<(const Iterator &other) const
{
    const PrimeIterator *other_ptr = dynamic_cast<const PrimeIterator *>(&other);
    if (other_ptr == nullptr)
    {
        throw runtime_error("Cannot compare iterators of different types");
    }
    if (&container != &other_ptr->container)
    {
        throw runtime_error("Cannot compare iterators of different containers");
    }
    return currentIndex < other_ptr->currentIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const Iterator &other) const
{
    return !(*this < other) && !(*this == other);
}

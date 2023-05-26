#include "MagicalContainer.h"

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

int MagicalContainer::size() { return 0; }

void MagicalContainer::addElement(int element) {}

void MagicalContainer::removeElement(int element) {}

BaseIterator::BaseIterator(const MagicalContainer &container)
    : container(container) {}

BaseIterator::BaseIterator(const BaseIterator &other)
    : container(other.container) {}

BaseIterator &BaseIterator::operator=(const BaseIterator &other) { return *this; }

BaseIterator &BaseIterator::operator++() { return *this; }

bool BaseIterator::operator==(const BaseIterator &other) const { return false; }

bool BaseIterator::operator!=(const BaseIterator &other) const { return true; }

int BaseIterator::operator*() const { return 0; }

BaseIterator &BaseIterator::begin() { return *this; }

BaseIterator &BaseIterator::end() { return *this; }

AscendingIterator::AscendingIterator(const MagicalContainer &container)
    : BaseIterator(container) {}

SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
    : BaseIterator(container) {}

PrimeIterator::PrimeIterator(const MagicalContainer &container)
    : BaseIterator(container) {}

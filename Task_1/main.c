/**
 * Demo program for ADT exercise.
 *
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
	pbook book1 = creat_book("home", 12345);
	pbook book2 = creat_book("home2", 45678);
	PAdptArray mybooks = CreateAdptArray(copy_book, delete_book, print_book);

	SetAdptArrayAt(mybooks, -1, book1); // Does not accept a negative number
	SetAdptArrayAt(mybooks, 2, book1);
	SetAdptArrayAt(mybooks, 23, book2);

	printf("the size is %d\n", GetAdptArraySize(mybooks)); // should print 24
	pbook p = GetAdptArrayAt(mybooks, 4);				   // should return null;
	assert(p == NULL);									   // check doesn't fail
	p = GetAdptArrayAt(mybooks, 2);
	printf("the book is %s\n", p->name); // should print "home"
	PrintDB(mybooks);

	int sizeBook = GetAdptArraySize(mybooks);
	printf("%d", sizeBook);

	DeleteAdptArray(mybooks);
	delete_book(book1);
	delete_book(book2);

	return 0;
}
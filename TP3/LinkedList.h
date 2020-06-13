/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
//LINKEDLIST
/** \brief create a new list in linkedlist
 *
 * \param void
 * \return LinkedList* returns the pointer to the created list
 *
 */
LinkedList* ll_newLinkedList(void);

/** \brief show the size of the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \return int returns the size of the linkedlist
 *
 */
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief add a new item to the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \param pElement void* receive the item to save in the linkedlist
 * \return int  returns whether the item could be saved or not
 *
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief get an item from the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \param index int receives the element index
 * \return void* return the item to the linkedlist
 *
 */
void* ll_get(LinkedList* this, int index);

/** \brief remove an item from the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \param index int receive the element index to eliminate
 * \return int returns whether the item could be removed or not
 *
 */
int ll_remove(LinkedList* this,int index);

/** \brief remove all the elements created in the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \return int returns whether the item could be removed or not
 *
 */
int ll_clear(LinkedList* this);

/** \brief remove previously created linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \return int returns whether the item could be removed or not
 *
 */
int ll_deleteLinkedList(LinkedList* this);

/** \brief get the index where an item is stored
 *
 * \param this LinkedList* receive the linkedlist
 * \param pElement void* you receive the item to get your index
 * \return int return the index
 *
 */
int ll_indexOf(LinkedList* this, void* pElement);

/** \brief shows if the linkedlist is empty
 *
 * \param this LinkedList* receive the linkedlist
 * \return int returns if the linkedlist is empty or not
 *
 */
int ll_isEmpty(LinkedList* this);

/** \brief sort the employees
 *
 * \param LinkedList* receive the linkedlist
 * \param recieve a function
 * \param int receive the order
 * \return int returns if it could be ordered or not
 *
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);


/** \brief replace one linkedlist item with another
 *
 * \param this LinkedList* receive the linkedlist
 * \param index int receive a index
 * \param pElement void* receive the item to replace
 * \return int returns whether or not it could be replaced
 *
 */
int ll_set(LinkedList* this, int index,void* pElement);

/** \brief create a new element inside the linkedlist without replacing any
 *
 * \param this LinkedList* receive the linkedlist
 * \param index int receive the index
 * \param pElement void* you receive the item you want to add
 * \return int return whether the item could be added or not
 *
 */
int ll_push(LinkedList* this, int index, void* pElement);

/** \brief remove an item from the linkedlist and return it
 *
 * \param this LinkedList* receive the linkedlist
 * \param index int receive the index
 * \return void* returns the deleted item
 *
 */
void* ll_pop(LinkedList* this,int index);

/** \brief returns if an item is contained within the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \param pElement void* receive the element
 * \return int returns if the item is contained in the linkedlist or not
 *
 */
int ll_contains(LinkedList* this, void* pElement);

/** \brief shows if a linkedlist is contained in another
 *
 * \param this LinkedList* receive the first linkedlist
 * \param this2 LinkedList* receive the second linkedlist
 * \return int returns whether the list is contained within another or not
 *
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);

/** \brief gets a piece of the linkedlist
 *
 * \param this LinkedList* receive the linkedlist
 * \param from int receive from that index grab
 * \param to int recive until index grab
 * \return LinkedList* return the space of the linked list obtained
 *
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief make a copy of a linkedlist
 *
 * \param this LinkedList* receive linkedlist
 * \return LinkedList* return a new linkedlist
 *
 */
LinkedList* ll_clone(LinkedList* this);



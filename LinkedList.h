//
// Created by Toby Dragon on 10/30/18.
//

#ifndef LAB8SOLN_LINKEDLIST_H
#define LAB8SOLN_LINKEDLIST_H


#include "List.h"
#include "LinkedNode.h"

class LinkedList : public List{
private:
    LinkedNode* end;
    LinkedNode* front;
    int currItemCount;

    //Private to disable copying and assigning from outside class, don't implement these methods
    LinkedList(const LinkedList& arrayListToCopy);
    LinkedList& operator=(const LinkedList& arrayListToCopy);
public:
    /**
     * Constructor
     */
    LinkedList();

    //Destructor
    ~LinkedList();

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    virtual void insertAtEnd(int itemToAdd);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    int getValueAt(int index);

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(int numToFind);

    /**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    int findLast(int numToFind);

    /**
     * finds the largest value in the array
     * @return the first index of the maximum value
     * @throws out_of_range exception if there is no item to remove
     */
    int findMaxIndex();

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(int itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(int itemToAdd, int index);

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    int removeValueAtEnd();

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    int removeValueAtFront();

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    int removeValueAt(int index);

};


#endif //LAB8SOLN_LINKEDLIST_H

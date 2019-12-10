//
// Created by Forrest on 9/30/16.
//

#ifndef COMP220_ARRAYLIST_H
#define COMP220_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "SongList.h"
#include "Song.h"
//#include "List.h"


class SongArrayList { //public List {
private:
    //pointer to the start of the array
    Song* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

public:
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    SongArrayList(int initialCapacity);

    //Copy Constructor
    SongArrayList(const SongArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    SongArrayList& operator=(const SongArrayList& arrayListToCopy);

    //Destructor
    ~SongArrayList();

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(Song itemToAdd);

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song getValueAt(int index);

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
    int find(std::string songToFind);

    /**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    int findLast(std::string songToFind);

    /**
     * finds the largest value in the array
     * @return the first index of the maximum value
     * @throws out_of_range exception if there is no item to remove
     */
    //int findMaxIndex();

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(Song itemToAdd);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(Song itemToAdd, int index);

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeValueAtEnd();

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    Song removeValueAtFront();

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song removeValueAt(int index);
    Song* getSong(std::string songToFind);

    int getSongCount();
};


#endif //COMP220_ARRAYLIST_H

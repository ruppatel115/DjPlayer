/**@file SongList.h
 * Interface for generic list class for songs
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef COMP220_LIST_H
#define COMP220_LIST_H

#include <stdexcept>
#include <string>
#include "Song.h"

class SongList {
private:
    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    virtual void doubleCapacity()=0;

public:

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    virtual void insertAtEnd(Song itemToAdd)=0;

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual Song* getValueAt(int index)=0;

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    virtual std::string toString()=0;

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    virtual int itemCount()=0;

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    virtual void clearList()=0;

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    virtual int find(std::string songTitleToFind)=0;

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    virtual void insertAt(Song itemToAdd, int index)=0;

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    virtual Song removeValueAt(int index)=0;

    /**
     * Gets a pointer to song with given title
     * @param songToFind the title of the song to get
     * @return a pointer to the song
     */
    virtual Song* getSong(std::string songToFind)=0;

    /**
     * Gets the number of songs in the array list, or currItemCount
     * @return number of songs in the arraylist, currItemCount
     */
    virtual int getSongCount()=0;
};



#endif //COMP220_LIST_H

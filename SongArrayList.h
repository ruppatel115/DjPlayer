/**@file SongArrayList.h
 * Interface for an Arraylist of songs using SongList.h
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef COMP220_ARRAYLIST_H
#define COMP220_ARRAYLIST_H

#include <stdexcept>
#include <string>
#include "SongList.h"
#include "Song.h"



class SongArrayList : public SongList{
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

    SongArrayList& operator=(const SongArrayList& arrayListToCopy);

public:
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    SongArrayList();

    //Copy Constructor
    SongArrayList(const SongArrayList& arrayListToCopy);

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
    Song* getValueAt(int index);

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
    int find(std::string songTitleToFind);

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(Song itemToAdd, int index);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    Song removeValueAt(int index);

    /**
     * Gets a pointer to song with given title
     * @param songToFind the title of the song to get
     * @return a pointer to the song
     */
    Song* getSong(std::string songToFind);

    /**
     * Gets the number of songs in the array list, or currItemCount
     * @return number of songs in the arraylist, currItemCount
     */
    int getSongCount();
};


#endif //COMP220_ARRAYLIST_H

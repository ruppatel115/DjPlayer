/**@file PlaylistArrayList.h
 * Interface for an Arraylist of playlists (from PlaylistList.h)
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#ifndef COMP220_PLAYLISTARRAYLIST_H
#define COMP220_PLAYLISTARRAYLIST_H

#include <stdexcept>
#include <string>
#include "PlaylistList.h"


class PlaylistArrayList  {
private:
    //pointer to the start of the array
    Playlist** array;
    //count of the number of valid playlists currently stored in the array
    int currPlaylistCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within PlaylistArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity();

public:
    PlaylistArrayList();
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    PlaylistArrayList(int initialCapacity);

    //Copy Constructor
    PlaylistArrayList(const PlaylistArrayList& arrayListToCopy);

    //Overloaded Assignment Operator
    PlaylistArrayList& operator=(PlaylistArrayList *arrayListToCopy);

    //Destructor
    ~PlaylistArrayList();

    /**
     * appends the new playlist to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(Playlist* playlistToAdd);

    /**
     * gets a playlist from the list
     * @param index the location from which to get the value
     * @return a copy of the playlist at index
     * @throws out_of_range exception if index is invalid
     */
    Playlist* getValueAt(int index);

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

    /**
     * checks if there are any valid playlists in the list
     * @return true if there are no valid playlists in the list, false otherwise
     */
    bool isEmpty();

    /**
     * returns a count of valid playlists currently in the list
     * @returns the number of valid playlists in the list
     */
    int playlistCount();

    /**
     * makes the list empty of valid playlists
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList();

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(std::string playlistToFind);

    /**
     * removes the playlist at index from the list, and returns a copy of that playlist
     * @param index the location from which to get the value
     * @post the playlist at index is removed from the list, everything else is shifted down one
     * @return a copy of the playlist at index
     * @throws out_of_range exception if index is invalid
     */
    void removeAt(int index);

    Playlist** getArray();

};


#endif //COMP220_PLAYLISTARRAYLIST_H

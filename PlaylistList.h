/**@file PlaylistList.h
 * Interface for a generic list of playlists (see playlist.h)
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef COMP220_PLAYLISTLIST_H
#define COMP220_PLAYLISTLIST_H

#include <stdexcept>
#include <string>
#include "Playlist.h"

class PlaylistList {
private:
    //Private to disable copying and assigning from outside class, don't implement these methods
    PlaylistList(const PlaylistList& listToCopy);
    PlaylistList& operator=(const PlaylistList& listToCopy);

public:
    //constructor
    PlaylistList() {}

    //Destructor
    virtual ~PlaylistList() {}

    /**
     * appends the new playlist to the end of the list
     * @post the list has an additional value/playlist in it, at the end
     */
    virtual void insertAtEnd(Playlist* playlistToAdd)=0;

    /**
     * gets the playlist/playlist name
     * @param index the location from which to get the name
     * @return a pointer to the playlist at index
     * @throws out_of_range exception if index is invalid
     */
    virtual Playlist* getValueAt(int index)=0;

    /**
     * gives a string representation of the current list
     */
    virtual std::string toString()=0;

    /**
     * checks if there are any valid playlists in the list
     * @return true if there are no valid playlists in the list, false otherwise
     */
    virtual bool isEmpty()=0;

    /**
     * returns a count of valid playlists currently in the list
     * @returns the number of valid playlists in the list
     */
    virtual int playlistCount()=0;

    /**
     * makes the list empty of valid playlists
     * @post the list is empty, such that isEmpty() == true
     */
    virtual void clearList()=0;

    /**
     * Searches the list for a certain playlist
     * @return the index of the first occurrence of playlistToFind if it is present, otherwise returns -1
     */
    virtual int find(std::string playlistToFind)=0;

    /**
     * removes the playlist at index from the list, and returns a copy of that playlist
     * @param index the location from which to get the playlist
     * @post the playlist at index is removed from the list, everything else is shifted down one
     * @return a copy of the playlist at index
     * @throws out_of_range exception if index is invalid
     */
    virtual void removeAt(int index)=0;
    /**
     * @return pointer to the list/array
     */
    virtual Playlist** getArray()=0;

};


#endif //COMP220_PLAYLISTLIST_H

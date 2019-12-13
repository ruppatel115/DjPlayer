/**@file Playlist.h
 * Interface for Playlist object/class
 * Each Playlist is a linked list of songs using List.h and LinkedNode.h
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef DJPLAYER_PLAYLIST_H
#define DJPLAYER_PLAYLIST_H

#include <string>
#include "LinkedNode.h"
#include <iostream>
#include "List.h"

class Playlist{

private:

    LinkedNode *front;
    LinkedNode *end;
    //Playlist(const Playlist& playlistToCopy);
    //Playlist& operator=(const Playlist& playlistToCopy);
    std::string title;
    int numOfSongs;
    int duration;

public:
    //Playlist(const Playlist& playlistToCopy);
    //Playlist& operator=(const Playlist* playlistToCopy);
    /**
    * Default Constructor
    * Initializes front and end to nullptr, title of playlist to 'Untitled Playlist', numOfSongs and Duration to 0
    */
    Playlist();
    /**
     * Constructor with an actual title, everything else same as default
     * @param title
     */
    Playlist(std::string title);

    /**
     * Destructor
     * Deletes each node of the linkedlist and the songs in those nodes
     */
    ~Playlist();

    virtual std::string getTitle();
    /**
     * Gets the total duration of the playlist. Duration is changed when songs are added or removed.
     * @return int duration (in seconds)
     */
    virtual int getDuration();
    /**
    * gives a string representation of the current list
    * @returns a string representing the given list in the exact format shown
    *{0: here comes the sun (Artist: beatles; Length: 212 secs; Year: 1967), 1: Billie Jean (Artist: Michael Jackson; Length: 356 secs; Year: 1980)}
    */
    virtual std::string toString();
    /**
    * Searches a playlist based on the title of the song and artist of the song
    * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
    */
    virtual int findSong(std::string title, std::string artist);
/**
 * returns a count of valid items currently in the list
 * @return the number of valid items in the list
 */
    virtual int getNumSongs(); //O(n) must run through all items of list
/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
    virtual bool isEmpty();
/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
    virtual std::string removeSong(int index); //returns song information
/**
 * appends the new item to the end of the playlist
 * @post the playlist has an additional song in it, at the end
 */
    virtual void insertAtEnd(Song* songStr);
/**
 * Gets the song at the given index of the linked list
 * @param index
 * @return  pointer to the song at the specified index
 */
    virtual Song* getSong(int index);

    virtual LinkedNode* getFront();

};



#endif //DJPLAYER_PLAYLIST_H

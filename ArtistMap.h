/**@file ArtistMap.h
 * Interface for an ArtistMap using ArtistMapNodes (artist keys and SongArrayList values)
 * This is essentially used to hold all the songs and artists in the library
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 * Mostly done by Forrest
 */

#ifndef DJPLAYER_ARTISTMAP_H
#define DJPLAYER_ARTISTMAP_H

#include <iostream>
#include <algorithm>
#include "ArtistMapNode.h"

using namespace std;


class ArtistMap{
private:
    ArtistMapNode* front; //pointer to the front node of the map linked list
    int songCount; //total number of songs in the map
    int artistCount; //total number of artists in the map
public:
    //TODO function comments
    /**
     * Used by put to see where a new song should go
     * @param song
     * @param node
     */
    void checkNext(Song song, ArtistMapNode* node);
    /**
     * Destructor
     */
    ~ArtistMap();
    /**
     * Default constructor
     */
    ArtistMap();
    /**
     * turns the map into a string
     * @return a string of all the artists and songs in the map
     */
    std::string toString();
    /**
     * Removes everything from the map
     */
    void removeAll();
    /**
     *
     * @param song
     */
    void put(Song song);
    void remove(string artist, string title);
    ArtistMapNode* getArtist(std::string artist);
    ArtistMapNode* getFront();
    Song* getSong(std::string title, std::string artist);

    int getArtistCount();

    ArtistMapNode *getArtistAt(int index);
};

#endif //DJPLAYER_ARTISTMAP_H

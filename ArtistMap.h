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
     * @post map will have no artists and no songs (no nodes)
     */
    void removeAll();
    /**
     * puts a new song (and a new node/artist if needed) into the map. sorts alphabetically by artist and song
     * @param song
     * @post new song in the map
     */
    void put(Song song);
    /**
     * removes a song from the map
     * @param artist
     * @param title
     * @post a song is removed from the song array list in node for artist
     */
    void remove(string artist, string title);
    /**
     * Looks for the given artist in the map
     * @param artist
     * @return map node for the given artist
     */
    ArtistMapNode* getArtist(std::string artist);
    /**
     * gets the front node of the map
     * @return
     */
    ArtistMapNode* getFront();
    /**
     * gets the specified song
     * @param title
     * @param artist
     * @return pointer to the song if found, nullptr otherwise
     */
    Song* getSong(std::string title, std::string artist);
    /**
     * gets the number of artists (number of nodes) in the map
     * @return number of artists/nodes (an int)
     */
    int getArtistCount();
    /**
     * gets the artist node at the given index
     * @param index
     * @return pointer to the node
     */
    ArtistMapNode *getArtistAt(int index);
};

#endif //DJPLAYER_ARTISTMAP_H

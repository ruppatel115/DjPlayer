/**@file ArtistMapNode.h
 * Interface for nodes of a map with string artists as keys and an arraylist of songs as values/items
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 * Mostly done by Forrest
 */

#ifndef DJPLAYER_ARTISTMAPNODE_H
#define DJPLAYER_ARTISTMAPNODE_H
#include "SongArrayList.h"
#include <iostream>


class ArtistMapNode{
private:
    ArtistMapNode* next; //pointer to the next map node
    std::string artist; //the name of the artist of the songs in songlist, this is the node's key
    SongList* songList; //array list of songs made by the artist
public:
    /**
     * Destructor
     * @post songlist is deleted from memory and next is nullptr
     */
    ~ArtistMapNode();
    /**
     * Constructor
     * @param song
     * Sets the artist key to the given song's artist, inits next as nullptr and the songlist, then adds the  song to the list
     */
    ArtistMapNode(Song song);
    /**
     * uses SongArrayList toString
     * @return string of all the songs in the node
     */
    std::string toString();
    /**
     * gets the artist name (key)
     * @return artist (a string)
     */
    std::string getArtist();
    /**
     * gets the song array list object
     * @return songarraylist pointer
     */
    SongList* getSongList();
    /**
     * Adds a song to the song list
     * @param song object
     */
    void addSong(Song song);
    /**
     * gets the node that next is pointing to
     * @return node pointer
     */
    ArtistMapNode* getNext();
    /**
     * sets the next pointer of this node to point to given node pointer
     * @param nextNode pointer
     */
    void setNext(ArtistMapNode* nextNode);
    /**
     * gets the number of songs in the node/songlist
     * @return an int, songcount of the songlist
     */
    int getSongCount();


};
#endif //DJPLAYER_ARTISTMAPNODE_H

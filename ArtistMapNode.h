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
    ArtistMapNode* next;
    std::string artist;
    SongArrayList* songList;
public:
    //TODO function comments
    ~ArtistMapNode();
    ArtistMapNode(Song song);
    std::string toString();
    std::string getArtist();
    SongArrayList* getSongList();
    void addSong(Song song);
    ArtistMapNode* getNext();
    void setNext(ArtistMapNode* nextNode);
    int getSongCount();
    //Song getSong();


};
#endif //DJPLAYER_ARTISTMAPNODE_H

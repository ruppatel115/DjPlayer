//
// Created by Forrest Wargo on 11/24/19.
//

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

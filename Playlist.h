//
// Created by Rup Patel on 11/18/19.
//

#ifndef DJPLAYER_PLAYLIST_H
#define DJPLAYER_PLAYLIST_H

#include <string>
#include "Song.h"
#include "LinkedList.h"
#include <iostream>

class Playlist{

private:
    LinkedNode *front;
    LinkedNode *end;
    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);




public:

    Playlist();

    ~Playlist();

    virtual std::string getTitle()=0;

    virtual void calcDuration()=0;

    virtual std::string playNext()=0; //after next song is played will call remove song

    virtual int itemCount()=0; //O(n) must run through all items of list

    virtual bool isEmpty()=0;

    virtual std::string removeSong(int index)=0; //returns song information

    virtual void insertAtEnd(Song &songStr)=0;









};



#endif //DJPLAYER_PLAYLIST_H

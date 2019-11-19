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
    std::string title;
    std::string artist;
    int duration;
    int year;

    Playlist(const Playlist& playlistToCopy);
    Playlist& operator=(const Playlist& playlistToCopy);


//testing commit rup
//need to change linkedlist/list ?

public:

    Playlist(std::string titleIn, std::string artistIn, int durationIn, int yearIn);

    ~Playlist();

    virtual std::string getTitle()=0;

    virtual void calcDuration()=0;

    virtual std::string playNext()=0; //after next song is played will call remove song


    virtual bool isEmpty()=0;

    virtual std::string removeSong()=0; //returns song information

    virtual void insertAtEnd(Song &songStr)=0;









};



#endif //DJPLAYER_PLAYLIST_H

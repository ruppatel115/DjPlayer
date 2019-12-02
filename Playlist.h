//
// Created by Rup Patel on 11/18/19.
//

#ifndef DJPLAYER_PLAYLIST_H
#define DJPLAYER_PLAYLIST_H

#include <string>
#include "Song.h"
#include "LinkedNode.h"
#include <iostream>

class Playlist{

private:


    LinkedNode *front;
    LinkedNode *end;
    //Playlist(const Playlist& playlistToCopy);
    //Playlist& operator=(const Playlist& playlistToCopy);
    std::string title;




public:

    Playlist();
    Playlist(std::string title);

    ~Playlist();

    virtual std::string getTitle();

    virtual int calcDuration();
    //Displays all the songs in the playlist
    virtual std::string toString();

    virtual std::string playNext(); //after next song is played will call remove song

    virtual int findSong(std::string title);   //looks for the index of the song with given name

    virtual int itemCount(); //O(n) must run through all items of list

    virtual bool isEmpty();

    virtual std::string removeSong(int index); //returns song information

    virtual void insertAtEnd(Song songStr);









};



#endif //DJPLAYER_PLAYLIST_H

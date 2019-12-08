//
// Created by Rup Patel on 11/18/19.
//

#ifndef DJPLAYER_PLAYLIST_H
#define DJPLAYER_PLAYLIST_H

#include <string>
//#include "Song.h"
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
    double duration;






public:

    Playlist();

    Playlist(std::string title);

    ~Playlist();

    Playlist getDuration();
    virtual std::string getTitle();

    virtual int calcDuration();
    //Displays all the songs in the playlist
    virtual std::string toString();

    virtual std::string playNext(); //after next song is played will call remove song

    virtual int findSong(std::string title, std::string artist);   //looks for the index of the song with given name

    virtual int itemCount(); //O(n) must run through all items of list

    virtual bool isEmpty();

    virtual std::string removeSong(int index); //returns song information

    virtual void insertAtEnd(Song songStr);




    virtual Song getSong(int index);


    void insertAtEnd(Song *song);
};



#endif //DJPLAYER_PLAYLIST_H

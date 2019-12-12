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
    //Playlist(const Playlist& playlistToCopy); //TODO we need to make these
    //Playlist& operator=(const Playlist& playlistToCopy);
    std::string title;
    int numOfSongs;
    double duration;

public:
    //TODO function comments
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

    virtual void insertAtEnd(Song* songStr);

    virtual Song getSong(int index);

};



#endif //DJPLAYER_PLAYLIST_H

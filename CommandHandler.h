//
// Created by Forrest Wargo on 11/19/19.
//

#ifndef DJPLAYER_COMMANDHANDLER_H
#define DJPLAYER_COMMANDHANDLER_H
#include <iostream>
#include "SongList.h"
#include "SongArrayList.h"
#include "ArtistMap.h"

class CommandHandler {
private:
ArtistMap* songLibrary;
public:
    CommandHandler();
    void promptUser();
    void help();
    void library();
    void displayArtist(std::string  artist);
    void song(std::string song);
    void import(std::string fileName);
    void discontinue(std::string fileName);
    void listPlaylists();
    void playlist(std::string  name);
    void newPlaylist(std::string  name);
    void addToPlaylist(std::string  playlis, std::string  title, std::string  artist);
    void removeFromPlaylist(std::string  playlis, std::string  title, std::string  artist);
    void playNext(std::string  name);
    void newRandomPlaylist(std::string  name);


};

#endif //DJPLAYER_COMMANDHANDLER_H

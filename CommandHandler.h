//
// Created by Forrest Wargo on 11/19/19.
//

#ifndef DJPLAYER_COMMANDHANDLER_H
#define DJPLAYER_COMMANDHANDLER_H
#include <iostream>
#include "SongList.h"
#include "SongArrayList.h"
#include "ArtistMap.h"
#include "Library.h"

class CommandHandler {
private:
ArtistMap* songLibrary;
    Library* mainLibrary;
public:
    CommandHandler();
    void promptUser();
    CommandHandler(Library* mainLibrary);
    void help();
    void library();
    void displayArtist(std::string  artist);
    void song(std::string artist, std::string title);
    void import(std::string fileName);
    void discontinue(std::string fileName);
    void listPlaylists();
    void playlist(std::string  name);
    void newPlaylist(std::string  name);
    void addToPlaylist(std::string  playlist, std::string  title, std::string  artist);
    void removeFromPlaylist(std::string  playlist, std::string  title, std::string  artist);
    void playNext(std::string  name);
    ArtistMap *getSongLibrary();
    void quit();


};

#endif //DJPLAYER_COMMANDHANDLER_H

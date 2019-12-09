//
// Created by Forrest Wargo on 11/19/19.
//

#ifndef DJPLAYER_COMMANDHANDLER_H
#define DJPLAYER_COMMANDHANDLER_H
#include <iostream>
//#include "SongList.h"
//#include "SongArrayList.h"
#include "ArtistMap.h"
#include "PlaylistArrayList.h"

class CommandHandler {
private:
    ArtistMap* songLibrary;
    //Library* mainLibrary;
    PlaylistArrayList PlaylistList;
    int numOfPlaylists;
    int numOfSongs;
    int length;

public:
    //CommandHandler(Library *pLibrary);
    void promptUser();
    CommandHandler();
    void help();
    void library();
    void displayArtist(std::string  artist);
    Song * song(std::string artist, std::string title);
    void import(std::string fileName);
    void discontinue(std::string fileName);


    void listPlaylists();
    /**
    * Displays all songs left in the given playlist and its duration
    * @param name of the playlist
    */
    void playlist(std::string  name);
    /**
    * Creates a new playlist with
    * @param name of the new playlist
    */
    void newPlaylist(std::string  name);
    void addToPlaylist(std::string  playlist, std::string  title, std::string  artist);
    void removeFromPlaylist(std::string playlist, std::string title, std::string artist);
    void playNext(std::string playlist);
    ArtistMap *getSongLibrary();
    void quit();
    void createRandomPlaylistStart(int playDuration, std::string playlistName);

    void createRandomPlaylist(int playDuration, std::string playlistName);
};

#endif //DJPLAYER_COMMANDHANDLER_H

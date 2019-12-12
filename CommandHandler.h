/**@file CommandHandler.h
 * Interface for a CommandHandler which handles commands from a user interface for a DJ Music Player
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#ifndef DJPLAYER_COMMANDHANDLER_H
#define DJPLAYER_COMMANDHANDLER_H
#include <iostream>
#include "ArtistMap.h"
#include "PlaylistArrayList.h"

class CommandHandler {
private:
    ArtistMap* songLibrary;
    PlaylistArrayList* PlaylistList;
    int numOfPlaylists;
    int numOfSongs;
    int length;
    void readSaveFiles();

public:
    //TODO function comments? destructor
    //void promptUser();
    CommandHandler();
    void help();
    void library();
    void displayArtist(std::string  artist);
    void song(std::string artist, std::string title);
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
    //void createRandomPlaylistStart(int playDuration, std::string playlistName);

    void createRandomPlaylist(int playDuration, std::string playlistName);
};

#endif //DJPLAYER_COMMANDHANDLER_H

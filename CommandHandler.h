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
    PlaylistList* PlaylistList;
    int numOfPlaylists;
    int numOfSongs;
    int length;
    void readSaveFiles();

public:
    /**
     * Default constructor
     */
    CommandHandler();
    /**
     * Provides a summary of all available commands.
     */
    void help();
    /**
     * Display all songs in alphabetical order by artist (within artist alphabetical by song)
     */
    void library();
    /**
     * Display all songs for the given artist.
     * @param artist
     */
    void displayArtist(std::string artist);
    /**
     * Display all information for the given song.
     * @param artist
     * @param title
     */
    void song(std::string artist, std::string title);
    /**
     * Add all songs from the given file to the library. Print message to the user of any songs that already existed (do not add duplicates)
     * uses ../<filename> for import files in this directory
     * @param fileName
     * @post songs from the file are added to the artistmap
     */
    void import(std::string fileName);
    /**
     * Remove all songs from the given file from the library. Also remove these songs from any playlist in which they occur.
     * Print message to the user of any songs that were not present (couldn't be removed).
     * @param fileName
     * @post songs from the file are removed from the artistmap and playlists (if needed)
     */
    void discontinue(std::string fileName);
    /**
     * display the names of all playlists and their durations
     */
    void listPlaylists();
    /**
    * Displays all songs left in the given playlist and its duration
    * @param name of the playlist
    */
    void playlist(std::string  name);
    /**
    * Creates a new playlist with
    * @param name of the new playlist
     * @post new playlist obj is added to playlist arraylist
    */
    void newPlaylist(std::string  name);
    /**
     * Add the given song to the end of the given playlist
     * @param playlist
     * @param title
     * @param artist
     * @post A song pointer is added to the playlist (at end)
     */
    void addToPlaylist(std::string playlist, std::string title, std::string artist);
    /**
     * remove the given song from the playlist
     * @param playlist
     * @param title
     * @param artist
     * @post given song pointer is removed from the playlist
     */
    void removeFromPlaylist(std::string playlist, std::string title, std::string artist);
    /**
     * Print all information about the next song to be played from the given playlist to the screen.
     * Remove that song from the given playlist. Add to the playcount for that song in the library.
     * If the playlist is now empty, it should be removed.
     * @param playlist
     * @post removes first song from given playlist, increments its playcount, and removes the playlist if needed.
     */
    void playNext(std::string playlist);
    /**
     * Returns a pointer to the song library/artist map. Mostly used for testing.
     * @return
     */
    ArtistMap *getSongLibrary();
    /**
     *Make a new playlist with the given name, and populate it with a random group of songs
     * that do not repeat (within this playlist) and are in some shuffled order (i.e., if the same random songs were
     * chosen for another playlist, they should not play in the same order each time).  the playlist should have as
     * many songs as can fit without going over the the given duration.
     * @param playDuration
     * @param playlistName
     * @post new  playlist is added to the list of playlists
     */
    void createRandomPlaylist(int playDuration, std::string playlistName);
    /**
     * Save the library and all playlists and terminate execution.
     * @post Save.txt and savedPlaylists.txt are updated to reflect the current artistmap/songlibrary and playlistlist
     */
    void quit();
////TEST VERSIONS=========================================
/**
 * These functions are all used for automatic testing. When adding a bool to the end of the call, it will change to returning a string
 * which is useful for printAssertEquals(str,str)
 */
    string library(bool test);
    string displayArtist(std::string  artist, bool test);
    string song(std::string artist, std::string title, bool test);

    string listPlaylists(bool test);

    string playlist(std::string  name, bool test);

    string newPlaylist(std::string  name, bool test);

    string addToPlaylist(std::string  playlist, std::string title, std::string artist, bool test);
    string removeFromPlaylist(std::string playlist, std::string title, std::string artist, bool test);
    string playNext(std::string playlist, bool);
    //ArtistMap *getSongLibrary();
    //void quit();

};

#endif //DJPLAYER_COMMANDHANDLER_H

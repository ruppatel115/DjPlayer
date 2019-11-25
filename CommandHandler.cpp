//
// Created by Forrest Wargo on 11/19/19.
//
#include "CommandHandler.h"
#include "Library.h"

CommandHandler::CommandHandler(Library* mainLibrary){
    this->mainLibrary = mainLibrary;
}

void CommandHandler::help(){
    std::cout << "*** ALL AVAILABLE COMMANDS ***" << std::endl;
    std::cout << "help: displays this" << std::endl;
    std::cout << "library: displays all songs in the library" << std::endl;
    std::cout << "artist: input an artist after prompt to display all songs by that artist" << std::endl;
    std::cout << "song: input artist and title after respective prompts to display all info for that song" << std::endl;
    std::cout << "import: input a filename after prompt to import all songs from the file into library" << std::endl;
    std::cout << "discontinue: input a filename after prompt to remove all songs from the file from the library " << std::endl;
    std::cout << "list playlists: displays all available playlists" << std::endl;
    std::cout << "playlist: input a playlist name after prompt to display all songs in that playlist and its total duration" << std::endl;
    std::cout << "new: input a name after prompt to make a new empty playlist with that name" << std::endl;
    std::cout << "add: input name, artist, title after respective prompts to add a new song to library with that info" << std::endl;
    std::cout << "remove: input name, artist, title after respective prompts to remove the song from the library with that info" << std::endl;
    std::cout << "playnext: input a playlist name after prompt to display all info about the next song to be played from it, \n"
                 "\t and removes that song and the playlist if it is now empty" << std::endl;
    std::cout << "newrandom: input a playlist name and duration after respective prompts to create a shuffled playlist with random songs\n"
                 "\t from the library until given duration is reached" << std::endl;
    std::cout << "quit: Save all playlists and library to file and end program" << std::endl;
    std::cout << "*** END OF HELP ***" << std::endl;
}

void CommandHandler::library(){
    std::cout << "List of song in library" << std::endl;
}

void CommandHandler::displayArtist(std::string artist){
    std::cout << mainLibrary->getArtistSongs(artist) << std::endl;
}

void CommandHandler::song(std::string artist, std::string title){}

void CommandHandler::import(std::string fileName){}

void CommandHandler::discontinue(std::string fileName){}

void CommandHandler::listPlaylists(){}

void CommandHandler::playlist(std::string  name){}

void CommandHandler::newPlaylist(std::string  name){}

void CommandHandler::addToPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::removeFromPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::playNext(std::string  name){}

void CommandHandler::newRandomPlaylist(std::string name, std::string duration){}

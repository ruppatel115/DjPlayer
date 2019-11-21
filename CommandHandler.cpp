//
// Created by Forrest Wargo on 11/19/19.
//
#include "CommandHandler.h"

CommandHandler::CommandHandler(){
    songLibrary = new SongArrayList(10);
}

void CommandHandler::help(){}

void CommandHandler::library(){}

void CommandHandler::displayArtist(std::string  artist){}

void CommandHandler::song(std::string song){}

void CommandHandler::import(std::string fileName){}

void CommandHandler::discontinue(std::string fileName){}

void CommandHandler::listPlaylists(){}

void CommandHandler::playlist(std::string  name){}

void CommandHandler::newPlaylist(std::string  name){}

void CommandHandler::addToPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::removeFromPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::playNext(std::string  name){}

void CommandHandler::newRandomPlaylist(std::string  name){}

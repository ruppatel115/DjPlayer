//
// Created by Forrest Wargo on 11/19/19.
//
#include "CommandHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArtistMap.h"
#include "Library.h"
CommandHandler::CommandHandler(){
    songLibrary = new ArtistMap();
    PlaylistList = new PlaylistArrayList(20);


    //promptUser();
}
//CommandHandler::CommandHandler(Library* mainLibrary){
//    this->mainLibrary = mainLibrary;
//}

ArtistMap *CommandHandler::getSongLibrary(){
    return songLibrary;
}

void CommandHandler::promptUser(){

    std::string mystr = "empty";
    while(mystr != "done") {
        std::cout << "Enter your command or help:";
        getline(std::cin, mystr);
        std::cout << mystr<<'\n';


        if(mystr == "help"){
        }else if(mystr == "library"){
            std::cout << "in library";

            this->library();
        }else if(mystr == "artist"){
            //handler->displayArtist("holder");


        }else if(mystr == "song"){
            //handler->song();


        }else if(mystr == "import"){
            std::cout << "Enter file name:";
            getline(std::cin, mystr);
            this->import(mystr);

        }else if(mystr == "discontinue"){
            //handler->discontinue();

        }else if(mystr == "list playlists"){
            //handler->listPlaylists();

        }else if(mystr == "playlist"){
            //handler->playlist();

        }else if(mystr == "newPlaylist"){
            //handler->newPlaylist();

        }else if(mystr == "addToPlaylist"){
            //handler->addToPlaylist();

        }else if(mystr == "remove"){

        }else if(mystr == "play next"){
            //handler->playNext();

        }else if(mystr == "new random"){
            //handler->newRandomPlaylist();

        }else{
            std::cout<<"I have know idea what you trynna do, why dont you try that again "<<'\n';
        }

    }
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
    std::cout << songLibrary->toString() << std::endl;
}

void CommandHandler::displayArtist(std::string artist){
    //std::cout << mainLibrary->getArtistSongs(artist) << std::endl;
    if(songLibrary->getArtist(artist) == nullptr){
        std::cout<<"artist not found\n";
    }else {
        std::cout << songLibrary->getArtist(artist)->toString() << std::endl;
    }
}

void CommandHandler::song(std::string artist, std::string title){
    ArtistMapNode* artistNode = songLibrary->getArtist(artist);
    if(artistNode != nullptr){
       int songIndex = artistNode->getSongList()->find(artist);
       if(songIndex >-1){
           Song song = artistNode->getSongList()->getValueAt(songIndex);
           std::cout<<song.getTitle()<<", "<<song.getArtist()<<", "<<song.getLength()<<", "<<song.getLength()<<std::endl;
       }else{
           std::cout<<"Song not found for that artist\n";
       }

    }else{
        std::cout<<"Artist not found for that artist\n";

    }
}

void CommandHandler::import(std::string fileName){
    std::ifstream infile(fileName);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if(strInput != "") {
                songLibrary->put(*new Song(strInput));
                std::cout << strInput << std::endl;
            }
        }
    }
    else {
        std::cerr << fileName<< " not found." << std::endl;
    }
}

void CommandHandler::discontinue(std::string fileName){
    //TODO
}

void CommandHandler::listPlaylists(){
    std::cout << PlaylistList.toString() << std::endl;

}
/**
 * Displays all songs left in the given playlist and its duration
 * @param name of the playlist
 */
void CommandHandler::playlist(std::string name){
    int index = PlaylistList.find(name);
     Playlist temp = PlaylistList.getValueAt(index);
     std::cout << "Playlist" +  name + ": \nDuration: " + std::to_string(temp.calcDuration()) << std::endl;
     std::cout << "Songs: " + temp.toString();

}

/**
 * Creates a new empty playlist with name and adds it to the list of playlists
 * @param name of the new playlist
 */
void CommandHandler::newPlaylist(std::string name){
    Playlist* newPlaylist = new Playlist(name);

    PlaylistList.insertAtEnd(*newPlaylist); //TODO does this work?

    std::cout << "Added new playlist "+name+"." << std::endl;
}

void CommandHandler::addToPlaylist(std::string playlist, std::string title, std::string artist){

    int index = PlaylistList.find(playlist);
    Playlist temp = PlaylistList.getValueAt(index);
    std::string songStr = title +", " + artist +", , "; //TODO still need the error handler for missing info in Song
    temp.insertAtEnd(songStr);
    std::cout << "Added new song "+title+"." << std::endl;
}

void CommandHandler::removeFromPlaylist(std::string playlist, std::string title, std::string artist){
    int playlistIndex = PlaylistList.find(playlist);
    Playlist temp = PlaylistList.getValueAt(playlistIndex);
    int songIndex = temp.findSong(title);
    temp.removeSong(songIndex);

    std::cout << "Removed song "+title+"." << std::endl;
}


void CommandHandler::playNext(std::string playlist) {
    int playlistIndex = PlaylistList.find(playlist);
    Playlist temp = PlaylistList.getValueAt(playlistIndex);
    temp.getSong(0).incrementPlaycount();
    std::cout << "Next song to be played: " + temp.removeSong(0) << std::endl;
    if (temp.isEmpty()){
        PlaylistList.removeAt(playlistIndex);
    }

}


void CommandHandler::quit(){
    std::string fileName = "/Users/forrest/Google Drive/College Fall 2019/Data Structures/DjPlayer/Save.txt";
    std::ofstream outf(fileName);
    if (outf){
        ArtistMapNode* holder = songLibrary->getFront();
        while(holder != nullptr){
            for(int i=0; i<holder->getSongList()->itemCount();i++) {
                Song song = holder->getSongList()->getValueAt(i);
                outf << song.getTitle()+","+song.getArtist()+","+std::to_string(song.getLength())+","+std::to_string(song.getYear())+'\n';
            }
            holder = holder->getNext();
        }
        outf.close();
    }
    else {// Print an error and exit
        std::cerr << "Can't write to file" << std::endl;
    }
}
//TODO
//void CommandHandler::newRandomPlaylist(std::string name, std::string duration){}

//
// Created by Forrest Wargo on 11/19/19.
//
#include "CommandHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArtistMap.h"

CommandHandler::CommandHandler(){
    songLibrary = new ArtistMap();


    //promptUser();
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
}

void CommandHandler::library(){

}

void CommandHandler::displayArtist(std::string  artist){}

void CommandHandler::song(std::string song){}

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

void CommandHandler::discontinue(std::string fileName){}

void CommandHandler::listPlaylists(){}

void CommandHandler::playlist(std::string  name){}

void CommandHandler::newPlaylist(std::string  name){}

void CommandHandler::addToPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::removeFromPlaylist(std::string  playlis, std::string  title, std::string  artist){}

void CommandHandler::playNext(std::string  name){}

void CommandHandler::newRandomPlaylist(std::string  name){}

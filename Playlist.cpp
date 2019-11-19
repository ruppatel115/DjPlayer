//
// Created by Elias on 11/19/2019.
//
#include "Playlist.h"

Playlist::Playlist(std::string titleIn, std::string artistIn, int durationIn, int yearIn) {
    title=titleIn;
    artist=artistIn;
    duration=durationIn;
    year=yearIn;

}
Playlist::~Playlist() {

}

std::string Playlist::getTitle(){
    return "test";
}

void Playlist::calcDuration(){

}
std::string Playlist::playNext() { //after next song is played will call remove song
return "";
}
bool Playlist::isEmpty(){
    return true;
}

std::string Playlist::removeSong() { //returns song information
return "";
}
void Playlist::insertAtEnd(Song &songStr){

}



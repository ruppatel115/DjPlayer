//
// Created by Elias on 11/19/2019.
//
#include "Playlist.h"

Playlist::Playlist(std::string titleIn, std::string artistIn, int durationIn, int yearIn) {
    title=titleIn;
    artist=artistIn;
    duration=durationIn;
    year=yearIn;
    //hello
}
Playlist::~Playlist() {
    while(front != nullptr){
        LinkedNode* temp = front;
        front=front->getNext();
        delete temp;
    }
    front = nullptr;
}

std::string Playlist::getTitle(){
    return "test";
}

void Playlist::calcDuration(){
    int duration = 0;
    while(front->getNext() != nullptr){
        duration+=front->getSong().getLength();
    }



}
std::string Playlist::playNext() { //after next song is played will call remove song
return "";
}

bool Playlist::isEmpty(){
    return true;
}

std::string Playlist::removeSong() { //returns song information
    //throw exceptions if playlist empty


return "";
}



void Playlist::insertAtEnd(Song &songStr){
    LinkedNode *newNode = new LinkedNode(songStr);
    newNode->setSong(songStr);
    newNode->setNext(nullptr);

    if (front == nullptr) {
        front = newNode;

    } else {
        LinkedNode *temp = front;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);


    }
}





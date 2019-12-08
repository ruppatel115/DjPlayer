//
// Created by Elias on 11/19/2019.
//
#include "Playlist.h"

Playlist::Playlist() {
    front = nullptr;
    end = nullptr;
    title = "Untitled Playlist";
    numOfSongs = 0;


}

Playlist::Playlist(std::string titleIn) {
    front = nullptr;
    end = nullptr;
    title = titleIn;
    numOfSongs = 0;

}

Playlist::~Playlist() {
    while(front != nullptr){
        LinkedNode* temp = front;
        delete temp;
        front=front->getNext();
    }
    front = nullptr;
}

std::string Playlist::getTitle(){
    return title;
}

std::string Playlist::toString() {
    std::string result = "{";
    LinkedNode* temp = front;
    int i = 1;
    while (temp != end){
        if (temp->getNext() != end){
        result += std::to_string(i)+": " + temp->getSong().getTitle() + "(Artist: "+temp->getSong().getArtist()+"; "
         "Length: "+std::to_string(temp->getSong().getLength())+"; Year: "+std::to_string(temp->getSong().getYear())+"), ";
        }
        else{ //no comma at the end
            result += std::to_string(i)+": " + temp->getSong().getTitle() + "(Artist: "+temp->getSong().getArtist()+"; "
            "Length: "+std::to_string(temp->getSong().getLength())+"; Year: "+std::to_string(temp->getSong().getYear())+")";
        }
        temp->getNext();
        i++;

    }
    result+="}";
    return result;
}

int Playlist::calcDuration(){
    int duration = 0;
    while(front->getNext() != nullptr){
        duration+=front->getSong().getLength();
    }
    return duration;

}

std::string Playlist::playNext() {//after next song is played will call remove song
return "";
}

int Playlist::findSong(std::string title, std::string artist) { //TODO songs can have the same name? currently finds first occurrence
    if (isEmpty()){
        return -1;
    }
    LinkedNode* temp = front;
    int i = 0;
    while (temp->getNext() != end){
        if (temp->getSong().getTitle() == title&& temp->getSong().getArtist()==artist){
            return i;
        }
        else{
            i++;
            temp=temp->getNext();
        }
    }

    return -1; //returns -1 by default if nothing found

}

bool Playlist::isEmpty() {
    if(front == nullptr){
        return true;
    }
}

int Playlist::itemCount(){//O(n) must run through all items of list
    LinkedNode *temp = front;
    int count = 0;
    while(temp != nullptr) {
        count++;
        temp = temp->getNext();
    }

    return count;



}

std::string Playlist::removeSong(int index) { //returns song information
    //throw exceptions if playlist empty
    if (itemCount() < index +1 || index < 0 || front == nullptr) {
        throw std::out_of_range("out of range");
    }

    if (index == 0) {
        LinkedNode *node = front;
        end = nullptr;
        std::string item = node->getSong().getTitle() + ", " + node->getSong().getArtist() + ", " +
                           std::to_string(node->getSong().getLength()) + ", " +
                           std::to_string(node->getSong().getYear());

        delete node;
        front = nullptr;
        return item;
    }
    if (index == 1) {
        LinkedNode *node = front->getNext();
        front = node->getNext();
        std::string item = node->getSong().getTitle() + ", " + node->getSong().getArtist() + ", " +
                           std::to_string(node->getSong().getLength()) + ", " +
                           std::to_string(node->getSong().getYear());
        delete node;

        return item;

    }

    else {
        LinkedNode *node = front;

        for (int i = 0; i < index ; i++) {
            node = node->getNext();
        }
        LinkedNode *temp = node->getNext();
        std::string item = node->getSong().getTitle() + ", " + node->getSong().getArtist() + ", " +
                           std::to_string(node->getSong().getLength()) + ", " +
                           std::to_string(node->getSong().getYear());

        delete temp;
        node->setNext(temp->getNext());
        return item;
    }

}




void Playlist::insertAtEnd(Song song) {
    LinkedNode *newNode = new LinkedNode(song);
    newNode->setSong(song);
    if (front == nullptr) {
        newNode->setNext(front);
        front = newNode;

    } else {
        LinkedNode *temp = front;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setNext(nullptr);

    }
}



Song Playlist::getSong(int index){
    LinkedNode *temp = front;
    int i = 0;
    while (temp->getNext() != nullptr) {
        if (i == index) {
            return temp->getSong();
        }
        else {
            temp = temp->getNext();
        }
    }
}










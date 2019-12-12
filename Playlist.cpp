/**@file Playlist.cpp
 * Implementation of Playlist.h to create Playlist objects
 * Each Playlist is a LinkedList of Songs
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#include "Playlist.h"

Playlist::Playlist() {
    front = nullptr;
    end = nullptr;
    title = "Untitled Playlist";
    numOfSongs = 0;
    duration=0;


}

Playlist::Playlist(std::string titleIn) {
    front = nullptr;
    end = nullptr;
    title = titleIn;
    numOfSongs = 0;
    duration=0;

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
    if (isEmpty()){
        return "{}";
    }
    std::string result = "{";
    LinkedNode* temp = front;
    int i = 0;
    while (temp->getNext() != nullptr){
        if (temp != nullptr){
        result += std::to_string(i)+": " + temp->getSong()->getTitle() + "(Artist: "+temp->getSong()->getArtist()+"; "
         "Length: "+std::to_string(temp->getSong()->getLength())+"; Year: "+std::to_string(temp->getSong()->getYear())+"), ";
        }
        else{ //no comma at the end
            result += std::to_string(i)+": " + temp->getSong()->getTitle() + "(Artist: "+temp->getSong()->getArtist()+"; "
            "Length: "+std::to_string(temp->getSong()->getLength())+" secs; Year: "+std::to_string(temp->getSong()->getYear())+")";
        }
        temp = temp->getNext();
        i++;

    }
    result+="}";
    return result;
}

int Playlist::getDuration(){
    return duration;
}

int Playlist::findSong(std::string title, std::string artist) {
    if (isEmpty()){
        return -1;
    }
    LinkedNode* temp = front;
    int i = 0;
    while (temp->getNext() != nullptr){
        if (temp->getSong()->getTitle() == title && temp->getSong()->getArtist()==artist){
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
    if(numOfSongs == 0){
        return true;
    }
}

int Playlist::getNumSongs(){
    return numOfSongs;
}

std::string Playlist::removeSong(int index) { //returns song information
    //throw exceptions if playlist empty
    if (getNumSongs() < index +1 || index < 0 || front == nullptr) {
        throw std::out_of_range("no song to remove");
    }

    if (index == 0) {
        LinkedNode *node = front;
        end = nullptr;
        std::string item = node->getSong()->getTitle() + ", " + node->getSong()->getArtist() + ", " +
                           std::to_string(node->getSong()->getLength()) + ", " +
                           std::to_string(node->getSong()->getYear());

        delete node;
        front = nullptr;
        duration-=node->getSong()->getLength();
        numOfSongs--;
        return item;
    }
    if (index == 1) {
        LinkedNode *node = front->getNext();
        front = node->getNext();
        std::string item = node->getSong()->getTitle() + ", " + node->getSong()->getArtist() + ", " +
                           std::to_string(node->getSong()->getLength()) + ", " +
                           std::to_string(node->getSong()->getYear());
        delete node;
        duration-=node->getSong()->getLength();
        numOfSongs--;
        return item;

    }

    else {
        LinkedNode *node = front;

        for (int i = 0; i < index ; i++) {
            node = node->getNext();
        }
        LinkedNode *temp = node->getNext();
        std::string item = node->getSong()->getTitle() + ", " + node->getSong()->getArtist() + ", " +
                           std::to_string(node->getSong()->getLength()) + ", " +
                           std::to_string(node->getSong()->getYear());

        delete temp;
        node->setNext(temp->getNext());
        duration-=node->getSong()->getLength();
        numOfSongs--;
        return item;
    }

}




void Playlist::insertAtEnd(Song* song) {

    LinkedNode *newNode = new LinkedNode(song);
    if (front == nullptr) {
        front=newNode;
        end=newNode;
    } else {
        LinkedNode *temp = end;
        temp->setNext(newNode);
        end=newNode;
//        while (temp->getNext() != nullptr) {
//            temp = temp->getNext();
//        }
//        temp->setNext(newNode);
//        newNode->setNext(nullptr);

    }
    duration+=end->getSong()->getLength();
    numOfSongs++;
}



Song* Playlist::getSong(int index){
    if (this->isEmpty()){
        throw std::out_of_range("playlist is empty");
    }

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










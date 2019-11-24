//
// Created by Elias on 11/19/2019.
//
#include "Playlist.h"

Playlist::Playlist() {
    front = nullptr;
    end = nullptr;

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
std::string Playlist::playNext() {//after next song is played will call remove song
return "";
}

bool Playlist::isEmpty() {
    if (front == nullptr) {
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
    if (itemCount() < index + 1 || index < 0) {
        throw std::out_of_range("out of range");
    }
    LinkedNode *node = front;
    if (index == 0) {
        if (front == end) {
            end = nullptr;
            delete front;
            front = nullptr;
        }
        LinkedNode *node = front;
        front = front->getNext();
        std::string item = node->getSong().getTitle();

        delete node;
        return item;
    }
    if (index == 1) {
        front = node->getNext();
        std::string item = node->getSong().getTitle();
        delete node;
        return item;
    } else {
        for (int i = 0; i < index - 1; i++) {
            node = node->getNext();
        }
        LinkedNode *temp = node->getNext();
        node->setNext(temp->getNext());
        std::string item = temp->getSong().getTitle();
        return item;
    }
}





void Playlist::insertAtEnd(Song &songStr){
    LinkedNode *newNode = new LinkedNode(songStr);
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





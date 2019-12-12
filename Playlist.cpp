/**@file Playlist.cpp
 * Implementation of Playlist.h to create Playlist objects
 * Each Playlist is a LinkedList of Songs
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#include "Playlist.h"


/**
     * Default Constructor
     */
Playlist::Playlist() {
    front = nullptr;
    end = nullptr;
    title = "Untitled Playlist";
    numOfSongs = 0;
    duration=0;


}
/**
     * Constructor
     */
Playlist::Playlist(std::string titleIn) {
    front = nullptr;
    end = nullptr;
    title = titleIn;
    numOfSongs = 0;
    duration=0;

}

//Destructor

Playlist::~Playlist() {
    LinkedNode* temp = front;

    while(temp != nullptr){
        LinkedNode *temp2 = temp;
        temp = temp->getNext();
        delete temp2;
    }
    front = nullptr;
    end = nullptr;
}

std::string Playlist::getTitle(){
    return title;
}


/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown
 *{0: here comes the sun (Artist: beatles; Length: 212 secs; Year: 1967), 1: Billie Jean (Artist: Michael Jackson; Length: 356 secs; Year: 1980)}
 */
std::string Playlist::toString() { //TODO this prints an extra comma with multiple items
    if (isEmpty()){
        return "{}";
    }
    std::string result = "{";
    LinkedNode* temp = front;
    if (temp == end){
        result += std::to_string(0)+": " + temp->getSong()->getTitle() + " (Artist: "+temp->getSong()->getArtist()+"; "
          "Length: "+std::to_string(temp->getSong()->getLength())+" secs; Year: "+std::to_string(temp->getSong()->getYear())+")}";
        return result;
    }
    int i = 0;
    while (temp!= nullptr){
        if (temp != nullptr && temp!=end){
        result += std::to_string(i)+": " + temp->getSong()->getTitle() + " (Artist: "+temp->getSong()->getArtist()+"; "
         "Length: "+std::to_string(temp->getSong()->getLength())+" secs; Year: "+std::to_string(temp->getSong()->getYear())+"), ";
        }
        else{ //no comma at the end
            result += std::to_string(i)+": " + temp->getSong()->getTitle() + " (Artist: "+temp->getSong()->getArtist()+"; "
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



/**
 * Searches a playlist based on the title of the song and artist of the song
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int Playlist::findSong(std::string title, std::string artist) {
    if (isEmpty()){
        return -1;
    }
    LinkedNode* temp = front;
    if (temp == end){
        if(temp->getSong()->getTitle() == title && temp->getSong()->getArtist()==artist){
            return 0;
        }
        else{
            return -1;
        }
    }
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

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
bool Playlist::isEmpty() {
    return numOfSongs == 0;
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int Playlist::getNumSongs(){
    return numOfSongs;
}


/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */

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



/**
 * appends the new item to the end of the playlist
 * @post the playlist has an additional song in it, at the end
 */

void Playlist::insertAtEnd(Song* song) {

    LinkedNode *newNode = new LinkedNode(song);
    if (front == nullptr) {
        front=newNode;
        end=newNode;
    } else {
        LinkedNode *temp = front;
        while(temp->getNext() != nullptr){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
        end=newNode;


    }
    duration+=end->getSong()->getLength();
    numOfSongs++;


}
/**
 *
 * @param index
 * @return gets pointer to the song at the specified index
 */


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
    return temp->getSong();
}










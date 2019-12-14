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
    LinkedNode *temp = front;

    while (front != nullptr) {
        LinkedNode *temp = front;
        front = front->getNext();
        delete temp;

    }
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
std::string Playlist::toString() {
    if (isEmpty()){
        return "{}";
    }
    std::string result = "{duration = ";
    result+= std::to_string(duration);
    result+= " seconds, songs left: ";

    LinkedNode* temp = front;
    for(int i=0; i<numOfSongs-1; i++){
        result += temp->getSong()->getTitle();
        result += ", ";
        temp = temp->getNext();

    }
    result += temp->getSong()->getTitle();

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

    int index = 0;
    LinkedNode *temp;
    temp = front;

    while(temp != nullptr) {
        if (temp->getSong()->getTitle() == title && temp->getSong()->getArtist() == artist) {
            return index;
        } else {
            temp = temp->getNext();
            index++;
        }
    }
    return -1;
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

 */

std::string Playlist::removeSong(int index) { //returns song information
    if (this->isEmpty()){
        return "no songs";
    }
    if(index >= numOfSongs || index <0){
        return "out of bounds";
    }
    if(index ==0){
        LinkedNode* temp = front;
        duration -= front->getSong()->getLength();
        front = front->getNext();
        delete temp;
        numOfSongs--;
        return "song deleted";

    }
    LinkedNode* temp = front;
    LinkedNode* tempBefore;

    for(int i=0; i<index; i++){
        tempBefore = temp;
        temp = temp->getNext();
    }
    tempBefore->setNext(temp->getNext());
    duration -= temp->getSong()->getLength();
    delete temp;
    numOfSongs--;
    return "song deleted";

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
        duration+=song->getLength();

    } else {
        LinkedNode *temp = front;
        while(temp->getNext() != nullptr){
            temp=temp->getNext();
        }
        temp->setNext(newNode);
        end=newNode;

        duration+=song->getLength();
    }
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
    if(index >= numOfSongs || index <0){
        return nullptr;
    }
    LinkedNode* temp = front;

    for(int i=0; i<index; i++){
        temp = temp->getNext();
    }
    return temp->getSong();
}


LinkedNode* Playlist::getFront() {
    return front;
}








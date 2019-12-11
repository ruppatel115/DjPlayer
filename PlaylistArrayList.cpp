/**@file PlaylistArrayList.cpp
 * Implementation of PlaylistArrayList.h to hold a bunch of Playlist objects
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#include "PlaylistArrayList.h"
#include <iostream>

PlaylistArrayList::PlaylistArrayList() { //default constructor defaults to size of 20
    this->array = new Playlist[20];
    this->currPlaylistCount=0;
    this->currCapacity=20;
}

//Constructor
PlaylistArrayList::PlaylistArrayList(int initialCapacity) {
    if (initialCapacity < 1){
        throw std::invalid_argument ("Initial capactity must be greater than 0 ");
    }
    this->array = new Playlist[initialCapacity];
    this->currPlaylistCount=0;
    this->currCapacity=initialCapacity;

}
//Copy Constructor
PlaylistArrayList::PlaylistArrayList(const PlaylistArrayList &arrayListToCopy) {
    this->array = new Playlist[arrayListToCopy.currCapacity];
    for (int i = 0; i < arrayListToCopy.currPlaylistCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
    this->currPlaylistCount=arrayListToCopy.currPlaylistCount;
    this->currCapacity=arrayListToCopy.currCapacity;
}

PlaylistArrayList& PlaylistArrayList::operator=(PlaylistArrayList *arrayListToCopy) {
    this->currCapacity = arrayListToCopy->currCapacity;
    this->currPlaylistCount = arrayListToCopy->currPlaylistCount;
    this->array = new Playlist[currCapacity];
    for(int i=0; i<currPlaylistCount; i++) {
        this->array[i] = arrayListToCopy->array[i];
    }
    return *this;
}

//destructor
PlaylistArrayList::~PlaylistArrayList() {
    delete[] array; //TODO what happens to the playlists?
}

void PlaylistArrayList::doubleCapacity() {
    currCapacity = currCapacity*2;
    Playlist* holder = new Playlist[currCapacity];
    for(int i=0; i<currPlaylistCount-1; i++){
        holder[i] = this->array[i];
    }
    delete[] array;
    array = holder;

}


void PlaylistArrayList::insertAtEnd(Playlist& playlistToAdd) {
    if (currPlaylistCount>=currCapacity) {      //if the arraylist is full
        doubleCapacity();
    }
    array[currPlaylistCount] = playlistToAdd;
    currPlaylistCount++;

}

Playlist PlaylistArrayList::getValueAt(int index) {
    if (index > currPlaylistCount || index < 0 || isEmpty()){
        throw std::out_of_range ("Bad index given to getValueAt: " + std::to_string(index));
    }
    return array[index];
}

std::string PlaylistArrayList::toString() { //Prints a list of the names of all the playlists and their durations
    if (currPlaylistCount <= 0){
        return "{}";
    }
    std::string result = "{";
    for (int i = 0; i < currPlaylistCount; i++) {
        if (!array[i].isEmpty()) {
            if (i < currPlaylistCount - 1) {
                result += array[i].getTitle() + "(duration: " + std::to_string(array[i].calcDuration()) + "), ";
            } else { //No comma at the end
                result += array[i].getTitle() + "(duration: " + std::to_string(array[i].calcDuration()) + ")";
            }
        }
        else{ //if the playlist at the current index of the arraylist is empty, do this instead
            if (i < currPlaylistCount - 1) {
                result += array[i].getTitle() + " (empty playlist), ";
            }
            else{
                result += array[i].getTitle() + " (empty playlist)";
            }
        }
    }
    result+="}";
    return result;
}

bool PlaylistArrayList::isEmpty() {
   return currPlaylistCount == 0;
}

int PlaylistArrayList::playlistCount() {
    return currPlaylistCount;
}

void PlaylistArrayList::clearList() {
    currPlaylistCount=0;
}

int PlaylistArrayList::find(std::string playlistToFind) {
    for (int i = 0; i < currPlaylistCount; i++){
        if (array[i].getTitle() == playlistToFind){
            return i;
        }
    }
    return -1;
}

int PlaylistArrayList::findLast(std::string playlistToFind) {
    int indexTemp = -1;

    for (int i = 0; i < currPlaylistCount; i++){
        if (array[i].getTitle() == playlistToFind){
            indexTemp = i;
        }
    }
    return indexTemp;
}

//void PlaylistArrayList::insertAtFront(Playlist playlistToAdd) {
//    if(currPlaylistCount >= currCapacity){
//        doubleCapacity();
//    }
//
//    Playlist * tempArr = new Playlist[currCapacity];
//    for (int i = 0;i<currPlaylistCount;i++){    //store array into a temp array for copying later
//        tempArr[i] = array[i];
//    }
//    array = new Playlist[currCapacity];          //array reinitialized, now empty
//    array[0] = playlistToAdd;                   //playlistToAdd inserted at front
//    currPlaylistCount++;
//    for (int i = 1;i<currPlaylistCount;i++){    //put tempArr data back into Array, shifted over one
//        array[i] = tempArr[i-1];
//    }
//
//    delete[]tempArr;
//
//
//}

//void PlaylistArrayList::insertAt(Playlist playlistToAdd, int index) {
//    if (index > currPlaylistCount || index < 0){
//        throw std::out_of_range ("Bad index given to insertAt: " + std::to_string(index));
//    }
//    if(currPlaylistCount >= currCapacity){
//        doubleCapacity();
//    }
//    Playlist * tempArr = new Playlist[currCapacity];
//    int j = 0;
//    for (int i = index;i<currPlaylistCount;i++){
//        tempArr[j] = array[i];
//        j++;
//    }
//    array[index] = playlistToAdd;
//    currPlaylistCount++;
//    j=0;
//    for (int i =index+1; i <currPlaylistCount;i++){
//        array[i] = tempArr[j];
//        j++;
//    }
//
//
//
//
//}

Playlist PlaylistArrayList::removeAtEnd() {
    if (currPlaylistCount == 0){
        throw std::out_of_range("No playlists to remove");
    }
    Playlist removedPlaylist = array[currPlaylistCount-1];

    currPlaylistCount--;

    return removedPlaylist;
}

Playlist PlaylistArrayList::removeAtFront() {
    if (currPlaylistCount == 0){
        throw std::out_of_range("No playlists to remove");
    }
    Playlist removedPlaylist = array[0];

    Playlist * tempArr = new Playlist[currCapacity];
    int j = 0;
    for(int i = 1; i < currPlaylistCount; i++){
        tempArr[j] = array[i];
        j++;
    }
    currPlaylistCount--;
    for(int i = 0; i < currPlaylistCount;i++){
        array[i] = tempArr[i];
    }

    return removedPlaylist;
}

Playlist PlaylistArrayList::removeAt(int index) {
    if (index > currPlaylistCount || index < 0){
        throw std::out_of_range ("Bad index given to removeValueAt: " + std::to_string(index));
    }
    Playlist removedPlaylist = array[index];

    Playlist * tempArr = new Playlist[currCapacity];
    int j = 0;
    for (int i = index+1;i<currPlaylistCount;i++){
        tempArr[j] = array[i];
        j++;
    }

    currPlaylistCount--;
    j=0;
    for (int i = index; i< currPlaylistCount;i++){
        array[i]=tempArr[j];j++;

    }

    return removedPlaylist;
}



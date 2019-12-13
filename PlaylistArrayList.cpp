/**@file PlaylistArrayList.cpp
 * Implementation of PlaylistArrayList.h to hold a bunch of Playlist objects
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */

#include "PlaylistArrayList.h"
#include <iostream>


PlaylistArrayList::PlaylistArrayList() { //default constructor defaults to size of 20
    //Playlist** array = new Playlist*[20];
    this->array = new Playlist*[20];
    this->currPlaylistCount=0;
    this->currCapacity=20;
}

//Constructor
PlaylistArrayList::PlaylistArrayList(int initialCapacity) {
    if (initialCapacity < 1){
        throw std::invalid_argument ("Initial capactity must be greater than 0 ");
    }
    this->array = new Playlist*[initialCapacity];
    this->currPlaylistCount=0;
    this->currCapacity=initialCapacity;

}
/***
 * allows us to make deep copies of playlist array list
 * @param arrayListToCopy
 */
//Copy Constructor
PlaylistArrayList::PlaylistArrayList(const PlaylistArrayList &arrayListToCopy) {
    this->array = new Playlist*[arrayListToCopy.currCapacity];
    for (int i = 0; i < arrayListToCopy.currPlaylistCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
    this->currPlaylistCount=arrayListToCopy.currPlaylistCount;
    this->currCapacity=arrayListToCopy.currCapacity;
}

/***
 *
 * @param arrayListToCopy
 * @return new copy of the playlist arraylist
 */
PlaylistArrayList& PlaylistArrayList::operator=(PlaylistArrayList *arrayListToCopy) {
    this->currCapacity = arrayListToCopy->currCapacity;
    this->currPlaylistCount = arrayListToCopy->currPlaylistCount;
    this->array = new Playlist*[currCapacity];
    for(int i=0; i<currPlaylistCount; i++) {
        this->array[i] = arrayListToCopy->array[i];
    }
    return *this;
}

//destructor
PlaylistArrayList::~PlaylistArrayList() {
    delete [] array;
}

/***
 * if list of playlist is full, we must double capacity to hold more playlist
 * returns an Arraylist with double the capacity
 */
void PlaylistArrayList::doubleCapacity() {
    currCapacity = currCapacity*2;
    Playlist** holder = new Playlist*[currCapacity];
    for(int i=0; i<currPlaylistCount; i++){
        holder[i] = this->array[i];
    }
    delete[] array;
    array = holder;

}

/***
 * inserts playlist at the end of the list of playlists
 * @param playlistToAdd
 * count should be increased by 1
 */
void PlaylistArrayList::insertAtEnd(Playlist* playlistToAdd) {
    if(find(playlistToAdd->getTitle()) == -1) {
        if (currPlaylistCount >= currCapacity) {      //if the arraylist is full
            doubleCapacity();
        }
        array[currPlaylistCount] = playlistToAdd;
        currPlaylistCount++;
    }
}

/***
 *
 * @param index
 * @return playlist at specified index
 */
Playlist* PlaylistArrayList::getValueAt(int index) {
    //std::cout<<"index = "<<index<<" current count = "<<currPlaylistCount<<"\n";


    if (index > currPlaylistCount-1 || index < 0 || isEmpty()){
        return nullptr;
        throw std::out_of_range ("Bad index given to getValueAt: " + std::to_string(index));
    }
    return array[index];
}

/***
 * takes lists of playlist and turns it into a string with each playlist listed and its duration
 * @return name of each playlist and its duration
 */
std::string PlaylistArrayList::toString() { //Prints a list of the names of all the playlists and their durations
    if (currPlaylistCount <= 0){
        return "[]";
    }
    std::string result = "[";
    for (int i = 0; i <playlistCount(); i++) {

        if(i!= 0){
            result+=", ";
        }
        if (!array[i]->isEmpty()) {
//            if (i < currPlaylistCount-1) {
              result += array[i]->getTitle() + " "+array[i]->toString();//array[i]->getTitle() + "(duration: " + std::to_string(array[i]->getDuration()) + "), ";
//            } else { //No comma at the end
//                result += array[i]->getTitle() + "(duration: " + std::to_string(array[i]->getDuration()) + ")";
//            }
        }else{ //if the playlist at the current index of the arraylist is empty, do this instead
            if (i < currPlaylistCount - 1) {
                result += array[i]->getTitle() + " {empty playlist}";
            }
            else{
                result += array[i]->getTitle() + " {empty playlist}";
            }
        }
    }
    result+="]";
    return result;
}

/***
 * checks if list of playlists is empty
 * @return true if empty, false if playlist exists
 */
bool PlaylistArrayList::isEmpty() {
   return currPlaylistCount == 0;
}
/***
 *
 * @return amount of playlist
 */
int PlaylistArrayList::playlistCount() {
    return currPlaylistCount;
}

/***
 * clears list of playlists
 */
void PlaylistArrayList::clearList() {
    for(int i=0;i<currPlaylistCount; i++){
        delete array[i];
    }
    currPlaylistCount=0;
}
/**
 *
 * @param playlistToFind
 * @return where the playlist was found in the list of playlists or returns -1 if not found
 */
int PlaylistArrayList::find(std::string playlistToFind) {
   //std::cout<<currPlaylistCount<<"in find\n";
    for (int i = 0; i < currPlaylistCount; i++){
        //std::cout<<currPlaylistCount<<i<<"\n";
        if (array[i]->getTitle() == playlistToFind){
            return i;
        }
    }
    //std::cout<<"about to return -1 "<<"\n";

    return -1;
}

/***
 *@param index at location of where we  want to remove the specified playlist
 * @return playlist that was removed
 */
void PlaylistArrayList::removeAt(int index) {
    if (index > currPlaylistCount-1 || index < 0 || isEmpty()){

    }else{
        delete array[index];
        if(index != currPlaylistCount-1){
            for(int i=index; i<currPlaylistCount-1; i++){
                array[i] = array[i+1];
            }
        }
        currPlaylistCount--;
    }
    /*
    if (index > currPlaylistCount-1 || index < 0){
        throw std::out_of_range ("Bad index given to removeValueAt: " + std::to_string(index));
    }
    Playlist* removedPlaylist = array[index];

    Playlist * tempArr = new Playlist[currCapacity];
    int j = 0;
    for (int i = index+1;i<currPlaylistCount;i++){
        tempArr[j] = array+i;
        j++;
    }

    currPlaylistCount--;
    j=0;
    for (int i = index; i< currPlaylistCount;i++){
        array[i]=tempArr[j];
        j++;

    }

    return removedPlaylist;
     */


}
Playlist** PlaylistArrayList::getArray() {
    return array;
}



//
// Created by Forrest Wargo on 10/15/19.
//
#include <iostream>
#include <string>
#include "SongArrayList.h"


void SongArrayList::doubleCapacity() {
    currCapacity = currCapacity*2;
    Song* holder = new Song[currCapacity];
    for(int i=0; i<currItemCount-1; i++){

        holder = &array[i];
    }
    delete[] array;
    array = holder;

}

SongArrayList::SongArrayList(int initialCapacity) {
    if(initialCapacity<=0){
        throw std::invalid_argument ("exception if size < 1");
    }
    this->currCapacity = initialCapacity;
    this-> array = new Song[currCapacity];
    this->currItemCount =0;

}

SongArrayList::SongArrayList(const SongArrayList &arrayListToCopy) {


}

SongArrayList& SongArrayList::operator=(const SongArrayList &arrayListToCopy) {
    this->currCapacity = arrayListToCopy.currCapacity;
    this->currItemCount = arrayListToCopy.currItemCount;
    this->array = new Song[currCapacity];
    for(int i=0; i<currItemCount; i++) {
        this->array[i] = arrayListToCopy.array[i];
    }
    return *this;
}

SongArrayList::~SongArrayList() {
    delete[] array;
    array = nullptr;

}

int SongArrayList::getSongCount(){
    return currItemCount;
}

void SongArrayList::insertAtEnd(Song itemToAdd) {
    currItemCount+=1;
    if(currItemCount>currCapacity){
        doubleCapacity();
    }
    array[currItemCount-1] = itemToAdd;


}

Song* SongArrayList::getValueAt(int index) {

    if(index>=currItemCount || index<0){
        throw std::out_of_range("Exception");
    }
    //array[index];
    //Song* song = &song1;
    return array+index;
}

std::string SongArrayList::toString() {
    std::string arrayString = "{";

    for(int i=0; i<this->currItemCount; i++){
        arrayString += (array[i].getTitle());
        if(i <currItemCount-1) {
            arrayString += ", ";
        }
    }
    arrayString += "}";
    return arrayString;

}

bool SongArrayList::isEmpty() {
    if(currItemCount == 0){
        return true;
    }
    return false;
}

int SongArrayList::itemCount() {
    return currItemCount;
}

void SongArrayList::clearList() {
    currItemCount =0;
}

int SongArrayList::find(std::string numToFind) {
    for(int i=0;i<currItemCount; i++){
        if(array[i].getTitle() ==numToFind){
            return i;
        }
    }

    return -1;
}

int SongArrayList::findLast(std::string numToFind) {
    for(int i=currItemCount-1;i>-1; i--){
        if(array[i].getTitle() ==numToFind){
            return i;
        }
    }

    return -1;
}
Song* SongArrayList::getSong(std::string songToFind) {
    for(int i=0;i<currItemCount; i++){
        if(array[i].getTitle() == songToFind){
            return &array[i];
        }
    }

    return nullptr;
}
/*
int SongArrayList::findMaxIndex() {
    if(currItemCount <1){
        throw std::out_of_range("Exception");
    }

    int maxNum = array[0];
    int maxIndex = 0;

    for(int i=0; i<currItemCount; i++){

        if(array[i] > maxNum){
            maxNum = array[i];
            maxIndex = i;
        }
    }
    return maxIndex;



    return maxIndex;
}
*/
void SongArrayList::insertAtFront(Song itemToAdd) {
    currItemCount+=1;
    if(currItemCount > currCapacity){
        doubleCapacity();
}
    Song* holder = new Song[currCapacity];
    for(int i=1;i<currItemCount;i++){
        holder[i]=array[i-1];
    }
    delete[] array;
    holder[0]=itemToAdd;
    array =holder;
    holder = nullptr;
}

void SongArrayList::insertAt(Song itemToAdd, int index) {

    if(index <0 || index > currItemCount){
        throw std::out_of_range("Exception");
    }
    currItemCount+=1;

    if(currItemCount > currCapacity){

        doubleCapacity();

    }

    Song* holder = new Song[currCapacity];

    int arrayIdx =0;

    for(int i=0;i<currCapacity;i++){
        if(i == index){
            holder[i] = itemToAdd;
        }else{
            holder[i]=array[arrayIdx];
            arrayIdx++;
        }

    }
    for(int i=0;i<currCapacity;i++){
        array[i] = holder[i];
    }
    holder = nullptr;


}

Song SongArrayList::removeValueAtEnd() {
    if(currItemCount == 0) {
        throw std::out_of_range("Exception");
    }
    currItemCount--;
    return array[currItemCount];

}

Song SongArrayList::removeValueAtFront() {
    if(currItemCount == 0){
        throw std::out_of_range("Exception");
    }
    currItemCount--;
    Song numToReturn = array[0];
    Song* holder = new Song[currCapacity];
    for(int i=1; i<currItemCount+1;i++){
        holder[i-1] = array[i];
    }
    delete[] array;
    array = holder;

    holder = nullptr;
    return numToReturn;

}

Song SongArrayList::removeValueAt(int index) {

    currItemCount--;
    Song numToReturn = array[index];
    int aIndex =0;
    for(int i=0; i<currItemCount+1;i++){
        if(i == index) {
            aIndex++;
        }
        array[i] = array[aIndex];
        aIndex++;
    }



    return numToReturn;
}

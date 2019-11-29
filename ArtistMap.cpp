//
// Created by Forrest Wargo on 11/24/19.
//
#include "ArtistMap.h"
using namespace std;
#include "LinkedNode.h"

ArtistMap::ArtistMap(){
    this->front = nullptr;
}

void ArtistMap::checkNext(Song song, ArtistMapNode* node){
    if(node->getNext() == nullptr){
        node->setNext(new ArtistMapNode(song));
        //cout<<"***this should never be seen***";
    }else if(node->getNext()->getArtist() == song.getArtist()){
        node->getNext()->addSong(song);
    }else if(song.getArtist().compare(node->getNext()->getArtist())<0) {
        ArtistMapNode *newNode = new ArtistMapNode(song);
        newNode->setNext(node->getNext());
        node->setNext(newNode);
    }else{
        checkNext(song, node->getNext());
    }
}
void ArtistMap::put(Song song) {
    if(front == nullptr) {
        front = new ArtistMapNode(song);
    }else if (front->getArtist() == song.getArtist()){
        front->addSong(song);
    }else if(song.getArtist().compare(front->getArtist())<0){
        ArtistMapNode *newNode = new ArtistMapNode(song);
        newNode->setNext(front->getNext());
        front->setNext(newNode);
    }else{
        checkNext(song, front);
    }
}

void ArtistMap::removeAll(){
    ArtistMapNode *node = front;
    while(node != nullptr){
        front = front->getNext();
        delete node;
    }
    node->setNext(nullptr);
}

ArtistMapNode* ArtistMap::getArtist(std::string artist) {
    ArtistMapNode* holder = front;
    while (holder != nullptr){
        if(holder->getArtist() == artist){
            return holder;
        }
        holder = holder->getNext();
    }
    return nullptr;
}

ArtistMapNode* ArtistMap::getFront() {
    return front;
}
string toString( ArtistMapNode* node){
    if(node->getNext() == nullptr){
        return  node->getArtist()+": "+node->tooString()+"\n";
    }
    return node->getArtist() + ": " + node->tooString() + "\n" + toString( node->getNext());

}
string ArtistMap::toString() {
    string songString = "[";
    if(front == nullptr){
        songString += "}";
        return songString;
    }
    songString+="\n";
    songString +=::toString( front);
    songString+="]";
    return  songString;


}

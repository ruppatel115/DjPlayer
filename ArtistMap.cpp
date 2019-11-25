//
// Created by Forrest Wargo on 11/24/19.
//
#include "ArtistMap.h"

ArtistMap::ArtistMap(){
    this->front = nullptr;
}
void checkNext(Song song, ArtistMapNode &node){
    if(node.getNext() == nullptr){
        node.setNext(new ArtistMapNode(song));
    }else if(node.getArtist() == song.getArtist()){
        node.addSong(song);
    }else{
        checkNext(song, *node.getNext());
    }
}
void ArtistMap::put(Song song) {
    if(front == nullptr){
        front = new ArtistMapNode(song);
    }else{
        checkNext(song, *front);
    }


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

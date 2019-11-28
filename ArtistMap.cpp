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
    //Todo this needs to be node.getnext == null ptr but it still needs to check the last ndoe
    if(node == nullptr){
        node->setNext(new ArtistMapNode(song));
        cout<<"a node is needed\n";
    }else if(node->getArtist() == song.getArtist()){
        node->addSong(song);
    }else if(song.getArtist().compare(node->getArtist())<0) {
        ArtistMapNode *newNode = new ArtistMapNode(song);
        newNode->setNext(node->getNext());
        node->setNext(newNode);
    }else{
        checkNext(song, node->getNext());
    }
}
void ArtistMap::put(Song song) {
    if(front == nullptr){
        front = new ArtistMapNode(song);
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

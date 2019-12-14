/**@file ArtistMapNode.cpp
 * Implementation of ArtistMapNode.h
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 * Mostly done by Forrest
 */
#include "ArtistMapNode.h"
using namespace std;


ArtistMapNode::~ArtistMapNode(){
    delete songList;
    next = nullptr;
}


ArtistMapNode::ArtistMapNode(Song song){
    this->next = nullptr;
    this->artist = song.getArtist();
    this->songList  = new SongArrayList();
    songList->insertAtEnd(song);
}
SongList* ArtistMapNode::getSongList() {
    return songList;
}
std::string ArtistMapNode::getArtist() {
    return artist;
}
void ArtistMapNode::addSong(Song song){
bool songAdded = false;
    for(int i=0; i<songList->itemCount();i++){
        int comparison = song.getTitle().compare(songList->getValueAt(i)->getTitle());
        if(comparison < 0){
            songList->insertAt(song,i);
            songAdded = true;
            break;

        }else if (comparison == 0){

            cout<<"duplicate song: "<< song.getTitle()<<endl;
            songAdded = true;
            break;
        }
    }
    if(!songAdded) {
        songList->insertAtEnd(song);
    }


}
void ArtistMapNode::setNext(ArtistMapNode* nextNode) {
    next = nextNode;

}
ArtistMapNode* ArtistMapNode::getNext() {
    return next;
}

std::string ArtistMapNode::toString(){
    return songList->toString();
}
int ArtistMapNode::getSongCount() {
    return songList->getSongCount();
}

//
// Created by Forrest Wargo on 11/24/19.
//
#include "ArtistMapNode.h"
#include "SongList.h"
using namespace std;


ArtistMapNode::ArtistMapNode(Song song){
    this->next = nullptr;
    this->artist = song.getArtist();
    this->songList  = new SongArrayList(2);
    songList->insertAtFront(song);
}
SongArrayList ArtistMapNode::getSongList() {
    return *songList;
}
std::string ArtistMapNode::getArtist() {
    return artist;
}
void ArtistMapNode::addSong(Song song){

    for(int i=0; i<songList->itemCount();i++){
        int comparison = song.getTitle().compare(songList->getValueAt(i).getArtist());
        if(comparison > 0){
            songList->insertAt(song,i);

            break;

        }else if (comparison == 0){
            cout<<"duplicate song"<< song.getTitle()<<endl;
            break;
        }
    }

}
void ArtistMapNode::setNext(ArtistMapNode* nextNode) {
    next = nextNode;

}
ArtistMapNode* ArtistMapNode::getNext() {
    return next;
}

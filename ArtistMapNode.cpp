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
//cout<<songList->itemCount()<<endl;
    for(int i=0; i<songList->itemCount();i++){
        //cout<<song.getTitle()<<endl;
        int comparison = song.getTitle().compare(songList->getValueAt(i).getTitle());
        //cout<<"comparison: "<<comparison<< song.getTitle()<<songList->getValueAt(i).getArtist()<<endl;
        if(comparison > 0){
            songList->insertAt(song,i);

            break;

        }else if (comparison == 0){
            cout<<"duplicate song: "<< song.getTitle()<<endl;
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

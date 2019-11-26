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
SongArrayList* ArtistMapNode::getSongList() {
    return songList;
}
std::string ArtistMapNode::getArtist() {
    return artist;
}
void ArtistMapNode::addSong(Song song){
    //cout<<this->toString()<<endl;
    //TODO make it work with caps
//cout<<songList->itemCount()<<endl;
bool songAdded = false;
    for(int i=0; i<songList->itemCount();i++){
        //cout<<song.getTitle()<<endl;
        int comparison = song.getTitle().compare(songList->getValueAt(i).getTitle());
        //cout<<"comparison: "<<comparison<<" "<< song.getTitle()<<" "<<songList->getValueAt(i).getTitle()<<endl;
        if(comparison < 0){
            //cout<<song.getTitle()<<" orgininal: "<<songList->getValueAt(i).getTitle()<<endl;
            songList->insertAt(song,i);
            songAdded = true;
            break;

        }else if (comparison == 0){
            //cout<<"in duplicate "<<song.getTitle()<<" orgininal: "<<songList->getValueAt(i).getTitle()<<endl;

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

std::string ArtistMapNode::tooString(){

    std::string songString = "{";
    for(int i=0; i<songList->itemCount(); i++){
        //std::cout<<"here\n";
        songString += " "+songList->getValueAt(i).getTitle();
        //std::cout<<songString;
        if(i+1 < songList->itemCount()){
            songString+=",";
        }
    }
    songString += "}";
    return songString;

}

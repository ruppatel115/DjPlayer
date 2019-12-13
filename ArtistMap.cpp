/**@file ArtistMap.cpp
 * Implementation of ArtistMap.h, this is the library
 * @authors Forrest Wargo, Rup Patel, Elias Platt
 */
#include "ArtistMap.h"
using namespace std;

ArtistMap::ArtistMap(){
    this->front = nullptr;
    this->artistCount = 0;
}
ArtistMap::~ArtistMap(){
    removeAll();
    front = nullptr;
}

int ArtistMap::getArtistCount(){
    return artistCount;
}

void ArtistMap::checkNext(Song song, ArtistMapNode* node){

    if(node->getNext() == nullptr){

        node->setNext(new ArtistMapNode(song));
        artistCount++;

    }else if(node->getNext()->getArtist() == song.getArtist()){
        node->getNext()->addSong(song);
    }else{
        string s1 = song.getArtist();
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        string s2 = node->getNext()->getArtist();
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if(s1.compare(s2)<0) {

        ArtistMapNode *newNode = new ArtistMapNode(song);
        artistCount++;
        newNode->setNext(node->getNext());
        node->setNext(newNode);
        }else {
            checkNext(song, node->getNext());
        }
    }
}
void ArtistMap::put(Song song) {
    string s1 = song.getArtist();
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);

    if(front == nullptr) {

        front = new ArtistMapNode(song);
        artistCount++;

    }else if (front->getArtist() == song.getArtist()){//if the first node is the one we want to put in

        front->addSong(song);

    }else {

        string s1 = song.getArtist();
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        string s2 = front->getArtist();
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if (s1.compare(s2) < 0) {

            ArtistMapNode *newNode = new ArtistMapNode(song);
            newNode->setNext(front);
            front = newNode;
            artistCount++;
        } else {
            checkNext(song, front);
        }
    }
}

void ArtistMap::remove(string title, string artist){

    ArtistMapNode* artistNode = this->getArtist(artist);
    if(artistNode != nullptr){
        int songIndex = artistNode->getSongList()->find(title);
        if(songIndex >-1){
            artistNode->getSongList()->removeValueAt(songIndex);
        }else{
            cout<<title<<" not found from artist, "<<artist<<"\n";
        }

    }else{
        cout<<"artist "<<artist<<" not found"<<"\n";

    }

}

void ArtistMap::removeAll(){

    while (front != nullptr){
        ArtistMapNode* holder = front->getNext();
        delete front;
        front = holder;
        artistCount--;
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

ArtistMapNode* ArtistMap::getArtistAt(int index){
    if (index >= artistCount || index <0){
        throw std::out_of_range ("invalid index");
    }

    ArtistMapNode* holder = front;
    for (int i = 0; i < index;i++){
        holder=holder->getNext();
    }
    return holder;
}

ArtistMapNode* ArtistMap::getFront() {
    return front;
}
string toString( ArtistMapNode* node){
    if(node->getNext() == nullptr){
        return  node->getArtist()+": "+node->toString()+"\n";
    }
    return node->getArtist() + ": " + node->toString() + "\n" + toString( node->getNext());

}
string ArtistMap::toString() {
    string songString = "[";
    if(front == nullptr){
        songString += "]";
        return songString;
    }
    songString+="\n";
    songString +=::toString( front);
    songString+="]\n";
    return  songString;


}
Song* ArtistMap::getSong(std::string title, std::string artist){
    ArtistMapNode* artistNode = this->getArtist(artist);
    if(artistNode != nullptr){
        int songIndex = artistNode->getSongList()->find(title);

        if(songIndex >-1){
            Song* song = artistNode->getSongList()->getValueAt(songIndex);
            return song;
        }else{

            return nullptr;
        }

    }else{
        return nullptr;

    }
}

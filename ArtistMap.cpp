//
// Created by Forrest Wargo on 11/24/19.
//
#include "ArtistMap.h"
using namespace std;
#include "LinkedNode.h"

ArtistMap::ArtistMap(){
    this->front = nullptr;
}
ArtistMap::~ArtistMap(){
    while (front != nullptr){
        ArtistMapNode* holder = front->getNext();
        delete front;
        front = holder;
    }
}


void ArtistMap::checkNext(Song song, ArtistMapNode* node){

    if(node->getNext() == nullptr){
        //cout<<"here all the time\n";
        node->setNext(new ArtistMapNode(song));
        //cout<<"***this should never be seen***";
    }else if(node->getNext()->getArtist() == song.getArtist()){
        node->getNext()->addSong(song);
    }else{
        string s1 = song.getArtist();
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        string s2 = node->getNext()->getArtist();
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if(s1.compare(s2)<0) {
        //cout<<song.getArtist()<<" "<<node->getNext()->getArtist()<<endl;
        ArtistMapNode *newNode = new ArtistMapNode(song);
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

    //cout<<"in put\n";
    if(front == nullptr) {
        //cout<<"first time \n";
        front = new ArtistMapNode(song);
    }else if (front->getArtist() == song.getArtist()){
        //cout<<"same artist\n";
        front->addSong(song);
    }else {
        string s1 = song.getArtist();
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        string s2 = front->getArtist();
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if (s1.compare(s2) < 0) {
            //cout << "in put " << song.getArtist() << " " << front->getArtist() << endl;
            ArtistMapNode *newNode = new ArtistMapNode(song);
            newNode->setNext(front);
            front = newNode;
        } else {
            checkNext(song, front);
        }
    }
}

void ArtistMap::remove(Song song){
    ArtistMapNode *node = front;
    while(node != nullptr){
        if (node->getSongList()->getSong(song.getTitle())->getTitle() == song.getTitle()){  //looks for the song in the library
            if (node == front){
                ArtistMapNode *temp = node;
                temp = node->getNext();
                delete node;
                front = temp;
            }
            else {
                delete node;
            }
        }
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
        return  node->getArtist()+": "+node->toString()+"\n";
    }
    return node->getArtist() + ": " + node->toString() + "\n" + toString( node->getNext());

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
Song* ArtistMap::getSong(std::string title, std::string artist){
    ArtistMapNode* artistNode = this->getArtist(artist);
    if(artistNode != nullptr){
        int songIndex = artistNode->getSongList()->find(artist);
        if(songIndex >-1){
            Song song = artistNode->getSongList()->getValueAt(songIndex);
            return &song;
        }else{
            std::cout<< title<<" not found for"<<artist<<"\n";
            return nullptr;
        }

    }else{
        std::cout<<artist<<" not found in library\n";
        return nullptr;

    }
}

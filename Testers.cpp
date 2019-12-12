#include "Song.h"
#include "TestLib.h"
#include "ArtistMapNode.h"
#include "SongArrayList.h"


//
// Created by Forrest Wargo on 12/11/19.
//
void songTesters(){
    Song* song1 = new Song("eminem", "rap god");
    Song* song2 = new Song("beatles", "hey jude");
    Song* song3 = new Song("jay z", "welcome to the jungle");
    Song* song4 = new Song("beatles", "some song");

    printAssertEquals("rap god",song1->getTitle());
    //song1->getLength();
    printAssertEquals("eminem",song1->getArtist());
    printAssertEquals("beatles",song2->getArtist());
    printAssertEquals("hey jude",song2->getTitle());

}


void ArtistMapTesters(){}
void artistMapNodeTesters(){


}
void songArrayListTesters(){
    Song* song1 = new Song("eminem", "rap god");
    Song* song2 = new Song("beatles", "hey jude");
    Song* song3 = new Song("jay z", "welcome to the jungle");
    Song* song4 = new Song("beatles", "some song");

    SongArrayList* songList = new SongArrayList(20);
    printAssertEquals(true,songList->isEmpty());
    songList->insertAtEnd(*song1);
    songList->insertAtEnd(*song2);
    songList->insertAtEnd(*song3);
    printAssertEquals(3, songList->itemCount());
    songList->insertAtEnd(*song4);
    printAssertEquals(4,songList->itemCount());
    printAssertEquals(song3,songList->getValueAt(2));
    printAssertEquals("{rap god, hey jude, welcome to the jungle, some song}", songList->toString());
    printAssertEquals(0, songList->find("rap god"));
    printAssertEquals(3, songList->find("some song"));
    songList->removeValueAt(2);
    printAssertEquals(3,songList->itemCount());
    songList->clearList();
    printAssertEquals(0, songList->itemCount());









}
void playlistTesters(){}
void playListArrayListTesters(){}
int main(){
    songArrayListTesters();
    return 0;
}

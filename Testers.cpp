#include "Song.h"
#include "TestLib.h"
#include "ArtistMapNode.h"
#include "SongArrayList.h"


//
// Created by Forrest Wargo on 12/11/19.
//

using namespace std;
/*
here comes the sun, beatles, 3:32, 1967
Billie Jean, Michael Jackson, 5:56, 1980
rap god, eminem, 5:09, 2013
lucy in thr sky with diamonds, beatles, 3:45, 1967
a hard days night, beatles, 3:02, 1964
loose yourself, eminem, 5:00, 2013
 */
void songTesters(){
    std::cout << "=======SONG TEST=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    printAssertEquals("here comes the sun",testSong->getTitle());
    printAssertEquals("beatles",testSong->getArtist());
    printAssertEquals(212,testSong->getLength());

    printAssertEquals(1967,testSong->getYear());

    std::cout << "=======DONE=======" <<endl;







}



void ArtistMapTesters(){}
void artistMapNodeTesters(){


}
void songArrayListTesters(){

    std::cout << "=======SONGARRAYLIST TEST=======" <<endl;
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

    std::cout << "=======DONE=======" <<endl;
}


void playlistTesters(){}
void playListArrayListTesters(){}
int main(){
    songTesters();
    songArrayListTesters();
    return 0;
}

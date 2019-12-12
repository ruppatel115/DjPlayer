#include "Song.h"
#include "TestLib.h"
#include "ArtistMapNode.h"
#include "SongArrayList.h"
#include "Playlist.h"


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



void ArtistMapTesters(){



}
void artistMapNodeTesters(){


}
void songArrayListTesters(){

    std::cout << "=======SONGARRAYLIST TEST=======" <<endl;
    Song* song1 = new Song("eminem", "rap god");
    Song* song2 = new Song("beatles", "hey jude");
    Song* song3 = new Song("jay z", "welcome to the jungle");
    Song* song4 = new Song("beatles", "some song");

    SongArrayList* songList = new SongArrayList();
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

    std::cout << "======DONE======" <<endl;
}


void playlistTesters(){
    std::cout << "=======PLAYLIST TEST=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:32, 1980";
    string song3 = "rap god, eminem, 5:12, 2013";
    string song4 = "b lucy in thr sky with diamonds, beatles, 3:39, 1967";
    string song5 = "c  hey jude, beatles, 3:01, 1968";
    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    Song* testSong5 = new Song(song5);
    Playlist playList;
    printAssertEquals(true, playList.isEmpty());
    playList.insertAtEnd(testSong1);
    printAssertEquals(false, playList.isEmpty());
    printAssertEquals(1, playList.itemCount());
    playList.insertAtEnd(testSong2);
    playList.insertAtEnd(testSong3);
    printAssertEquals(3, playList.itemCount());
    //playList.removeSong(2);
    //printAssertEquals(2, playList.itemCount());
    playList.insertAtEnd(testSong3);
    playList.insertAtEnd(testSong3);
    //printAssertEquals(4, playList.itemCount());
    std::cout<<playList.toString()<<std::endl;

    std::cout << "======DONE======" <<endl;









}
void playListArrayListTesters(){}
int main(){
    songTesters();
    songArrayListTesters();
    playlistTesters();
    return 0;
}

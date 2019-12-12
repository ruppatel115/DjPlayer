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
    cout<<"=====SONG TESTS=======\n";
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    printAssertEquals("here comes the sun",testSong->getTitle());
    printAssertEquals("beatles",testSong->getArtist());
    printAssertEquals(212,testSong->getLength());
    printAssertEquals(1967,testSong->getYear());
    cout<<"=====DONE=======\n";


}



void ArtistMapTesters(){}

void songArrayListTesters(){
    cout<<"=====SONG ARRAY LIST TESTS=======\n";
    SongArrayList testList = SongArrayList();
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";



    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    cout<<"-----testing item count ------\n";
    printAssertEquals(0,testList.itemCount());
    testList.insertAtEnd(*testSong1);
    printAssertEquals(1,testList.itemCount());
    testList.insertAtEnd(*testSong2);
    printAssertEquals(2,testList.itemCount());
    testList.insertAtEnd(*testSong3);
    printAssertEquals(3,testList.itemCount());

    cout<<"-----testing get value at and insert at end------\n";
    printAssertEquals("here comes the sun",testList.getValueAt(0)->getTitle());

    printAssertEquals("Billie Jean",testList.getValueAt(1)->getTitle());
    printAssertEquals("rap god",testList.getValueAt(2)->getTitle());
    cout<<"-----testing get song------\n";
    //testList.insertAtEnd(song1);
    printAssertEquals("here comes the sun",testList.getSong("here comes the sun")->getTitle());
    cout<<"-----testing find------\n";
    printAssertEquals(0,testList.find("here comes the sun"));
    printAssertEquals(1,testList.find("Billie Jean"));
    cout<<"-----testing remove value at and is empty------\n";
    printAssertEquals("Billie Jean",testList.removeValueAt(1).getTitle());
    printAssertEquals(2,testList.itemCount());
    printAssertEquals("here comes the sun",testList.removeValueAt(0).getTitle());
    printAssertEquals("rap god",testList.removeValueAt(0).getTitle());
    printAssertEquals(0,testList.itemCount());
    printAssertEquals(true,testList.isEmpty());
    cout<<"-----testing insert at ------\n";
    testList.insertAtEnd(*testSong1);
    testList.insertAtEnd(*testSong2);
    testList.insertAt(*testSong3,1);
    printAssertEquals("rap god",testList.getValueAt(1)->getTitle());
    cout<<"-----testing clear list------\n";
    testList.clearList();
    printAssertEquals(true,testList.isEmpty());
    printAssertEquals(0,testList.itemCount());
    cout<<"-----testing tostring------\n";
    printAssertEquals("{}",testList.toString());

    testList.insertAtEnd(*testSong1);
    testList.insertAtEnd(*testSong2);
    testList.insertAtEnd(*testSong3);
    printAssertEquals("{here comes the sun, Billie Jean, rap god}",testList.toString());
    cout<<"=====DONE=======\n";
    //todo add testers for destructor and coy constructor



}
void songArrayListTesters2(){

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
void artistMapNodeTesters(){
    std::cout << "=======Artist Map Node TESTS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    ArtistMapNode* testNode = new ArtistMapNode(*testSong1);
    cout<<"-----testing toString and i guess get song list------\n";
    printAssertEquals("{here comes the sun}",testNode->toString());
    testNode->getSongList()->clearList();
    printAssertEquals("{}",testNode->toString());
    cout<<"-----testing add song-----\n";
    testNode->addSong(song1);
    testNode->addSong(song2);
    testNode->addSong(song3);
    printAssertEquals("{Billie Jean, here comes the sun, rap god}",testNode->toString());
    cout<<"-----testing get artist-----\n";
    printAssertEquals("beatles",testNode->getArtist());
    cout<<"-----set and get next-----\n";
    ArtistMapNode* testNode2 = new ArtistMapNode(*testSong2);
    testNode->setNext(testNode2);
    printAssertEquals("Michael Jackson",testNode->getNext()->getArtist());

    std::cout << "======DONE======" <<endl;


}

void playlistTesters(){}
void playListArrayListTesters(){}
int main(){
    //songTesters();
    //songArrayListTesters();
    artistMapNodeTesters();
    return 0;
}

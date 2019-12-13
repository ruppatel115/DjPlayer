#include <fstream>
#include "Song.h"
#include "TestLib.h"
#include "CommandHandler.h"


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
    cout << "=======SONG TESTERS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    Song* testSong = new Song(song1);
    printAssertEquals("here comes the sun",testSong->getTitle());
    printAssertEquals("beatles",testSong->getArtist());
    printAssertEquals(212,testSong->getLength());
    printAssertEquals(1967,testSong->getYear());
    string song2 = "here comes the sun, beatles, 212, 1967";
    Song* testSong2 = new Song(song2);
    printAssertEquals("here comes the sun",testSong2->getTitle());
    printAssertEquals("beatles",testSong2->getArtist());
    printAssertEquals(212,testSong2->getLength());
    printAssertEquals(1967,testSong2->getYear());


    delete testSong;

    cout << "=======DONE=======" << endl;

}




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
    //todo add testers for destructor and copy constructor



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
    cout<<"expecting 'duplicate song: here comes the sun' actual: ";
    testNode->addSong(song1);
    testNode->addSong(song2);
    testNode->addSong(song3);
    printAssertEquals("{Billie Jean, here comes the sun, rap god}",testNode->toString());
    cout<<"-----testing get artist-----\n";
    printAssertEquals("beatles",testNode->getArtist());
    cout<<"-----testing set and get next-----\n";
    ArtistMapNode* testNode2 = new ArtistMapNode(*testSong2);
    testNode->setNext(testNode2);
    printAssertEquals("Michael Jackson",testNode->getNext()->getArtist());

    std::cout << "======DONE======" <<endl;


}

void ArtistMapTesters(){
    std::cout << "=======ARTIST MAP TESTS=======" <<endl;
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);


    ArtistMap* mapTest = new ArtistMap();


    cout<<"-----testing put and tostring-----\n";
    mapTest->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun}\n]\n",mapTest->toString());
    cout<<"expecting 'duplicate song: here comes the sun' actual: ";
    mapTest->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun}\n]\n",mapTest->toString());
    mapTest->put(*testSong2);
    printAssertEquals("[\nbeatles: {here comes the sun}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->put(*testSong4);
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());


    cout<<"-----testing remove-----\n";
    mapTest->remove("here comes the sun", "beatles");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->remove("here comes the sun", "Michael Jackson");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());
    mapTest->remove("here comes the sun", "fake");
    printAssertEquals("[\nbeatles: {lucy in thr sky with diamonds}\nMichael Jackson: {Billie Jean}\n]\n",mapTest->toString());




    cout<<"-----testing get artist count-----\n";
    delete mapTest;
    mapTest = new ArtistMap();
    printAssertEquals(0,mapTest->getArtistCount());
    //printAssertEquals(0,mapTest->getSongCount());
    mapTest->put(*testSong1);
    printAssertEquals(1,mapTest->getArtistCount());
    //printAssertEquals(1,mapTest->getSongCount());
    mapTest->put(*testSong2);
    printAssertEquals(2,mapTest->getArtistCount());
    //printAssertEquals(2,mapTest->getSongCount());
    mapTest->put(*testSong3);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(3,mapTest->getSongCount());
    //testing with a duplicate song
    mapTest->put(*testSong3);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(3,mapTest->getSongCount());
    //testing with a song from an artist already in map
    mapTest->put(*testSong4);
    printAssertEquals(3,mapTest->getArtistCount());
    //printAssertEquals(4,mapTest->getSongCount());

    cout<<"-----testing removeAll-----\n";
    mapTest->removeAll();
    printAssertEquals("[]",mapTest->toString());
    printAssertEquals(0,mapTest->getArtistCount());
    mapTest->removeAll();
    printAssertEquals("[]",mapTest->toString());
    printAssertEquals(0,mapTest->getArtistCount());

    cout<<"-----testing getArtist-----\n";
    mapTest->put(*testSong1);
    mapTest->put(*testSong2);
    mapTest->put(*testSong3);
    mapTest->put(*testSong4);
    ArtistMapNode* testNode = mapTest->getArtist("beatles");
    printAssertEquals("{here comes the sun, lucy in thr sky with diamonds}",testNode->toString());
    testNode = mapTest->getArtist("the beatles");
    //printAssertEquals(nullptr,testNode);


    cout<<"-----testing getArtistAt-----\n";
    testNode = mapTest->getArtistAt(0);
    printAssertEquals("{here comes the sun, lucy in thr sky with diamonds}",testNode->toString());
    try{
        mapTest->getArtistAt(-1);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    try{
        mapTest->getArtistAt(3);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    try{
        mapTest->getArtistAt(10000);
        cout << "FAIL: removeSong did not throw exception when index was negative" <<endl;
    }
    catch(out_of_range& e){
        printAssertEquals("invalid index",e.what());
    }
    testNode = mapTest->getArtistAt(2);
    printAssertEquals("{Billie Jean}",testNode->toString());

    cout<<"-----testing getSong-----\n";
    delete mapTest;
    mapTest = new ArtistMap();
    mapTest->put(*testSong1);
    mapTest->put(*testSong2);
    mapTest->put(*testSong3);
    mapTest->put(*testSong4);
    printAssertEquals("rap god",mapTest->getSong("rap god", "eminem")->getTitle());
    printAssertEquals("eminem",mapTest->getSong("rap god", "eminem")->getArtist());
    printAssertEquals("here comes the sun",mapTest->getSong("here comes the sun", "beatles")->getTitle());
    printAssertEquals("here comes the sun",mapTest->getSong("here comes the sun", "beatles")->getTitle());



    delete testSong1; delete testSong2; delete testSong3; delete testSong4;
    std::cout << "======DONE======" <<endl;


}

void wipeFile(string fileName){
    std::ofstream outf(fileName);
    if (outf){
        outf.close();
    }else{
        cout<<"file "<<fileName<<" cant be found \n";
    }
}
void commandHandlerTesters(){



    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    std::cout << "======TESTING COMMAND HANDLER ======" <<endl;
    wipeFile("../Save.txt");
    wipeFile("../savedPlaylists.txt");
    CommandHandler* testHandler = new CommandHandler();//constructor calls save files
    cout<<"\n-----testing Library-----\n\n";
    testHandler->getSongLibrary()->put(*testSong1);
    testHandler->getSongLibrary()->put(*testSong2);
    testHandler->getSongLibrary()->put(*testSong3);
    testHandler->getSongLibrary()->put(*testSong4);
    testHandler->getSongLibrary()->put(*testSong1);
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\neminem: {rap god}\nMichael Jackson: {Billie Jean}\n]\n",testHandler->getSongLibrary()->toString());
    cout << "Testing list playlists when empty: "; testHandler->listPlaylists();
    cout<<"\n-----testing import-----\n\n";
    std::ofstream outf("../Save.txt");
    if (outf){
        outf << testSong1->getTitle()+", "+testSong1->getArtist()+", "+std::to_string(testSong1->getLength())+", "+std::to_string(testSong1->getYear())+'\n';
        outf << testSong2->getTitle()+", "+testSong2->getArtist()+", "+std::to_string(testSong2->getLength())+", "+std::to_string(testSong2->getYear())+'\n';
        outf << testSong3->getTitle()+", "+testSong3->getArtist()+", "+std::to_string(testSong3->getLength())+", "+std::to_string(testSong3->getYear())+'\n';
        outf << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';
        outf << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';



        outf.close();
    }else{
        cout<<"file "<<"Save.txt"<<" cant be found \n";
    }
    testHandler->getSongLibrary()->removeAll();
    testHandler->import("../Save.txt");
    printAssertEquals("[\nbeatles: {here comes the sun, lucy in thr sky with diamonds}\neminem: {rap god}\nMichael Jackson: {Billie Jean}\n]\n",testHandler->getSongLibrary()->toString());

    cout<<"\n-----testing create random playlist-----\n\n";
    CommandHandler* testHandlerRand = new CommandHandler();
    testHandlerRand->getSongLibrary()->put(*testSong2);
    testHandlerRand->getSongLibrary()->put(*testSong4);
    try {
        testHandlerRand->createRandomPlaylist(0, "noDurationPlaylist");
    } catch (invalid_argument& e){
        printAssertEquals("playDuration must be greater than 0", e.what());
    }
    testHandlerRand->createRandomPlaylist(1,"oneDurationPlaylist");
    printAssertEquals("[oneDurationPlaylist {empty playlist}]",testHandlerRand->listPlaylists(true));

    testHandlerRand->createRandomPlaylist(500,"testRandPlaylist1");
    testHandlerRand->listPlaylists();
    testHandlerRand->createRandomPlaylist(1500,"testRandPlaylist2");
    testHandlerRand->listPlaylists();   //TODO something wrong with songs being added but otherwise it works, just can't find the other songs

    cout<<"\n-----testing display artist-----\n\n";
    // the actual get artist function was tested in artist map
    //cout<<"expecting 'artist not found' actual: ";
    //testHandler->displayArtist("not an artist");
    printAssertEquals("artist not found\n", testHandler->displayArtist("not an artist", true));
    printAssertEquals("{here comes the sun, lucy in thr sky with diamonds}\n", testHandler->displayArtist("beatles", true));
    printAssertEquals("{rap god}\n", testHandler->displayArtist("eminem", true));

    // cout << "Expected: playlist not found. Actual: ";
 //   testHandler->addToPlaylist("nonexistentplaylist","blah","beep");

    cout<<"\n-----testing song (displays song with given artist and title)-----\n\n";
    testHandler->getSongLibrary()->removeAll();
    testHandler->import("../Save.txt");
    printAssertEquals("rap god, by eminem, 309 seconds, came out in 2013\n",testHandler->song("eminem","rap god", true));
    //cout<<"Expecting: rap god, by eminem, 309 seconds, came out in 2013, actual: ";
    //testHandler->song("eminem","rap god");


    cout<<"\n-----testing newPlaylist-----\n\n";
    testHandler->getSongLibrary()->removeAll();
    testHandler->import("../Save.txt");
    testHandler->newPlaylist("TestPlaylist1");
    //printAssertEquals("TestPlaylist1", testHandler->listPlaylists());
    //TODO not done?

    cout<<"\n-----testing discontinue-----\n\n";
    /*
    CommandHandler* testHandlerD = new CommandHandler();
    testHandlerD->import("../importTest.txt"); //TODO fix file path?
    testHandlerD->newPlaylist("testList");
    testHandlerD->library();
    testHandlerD->addToPlaylist("testList","rap god", "eminem");
    testHandlerD->addToPlaylist("testList","here comes the sun", "beatles");
    testHandlerD->discontinue("../discontinueTest.txt"); //TODO file path working?
    testHandlerD->library();
     */
    //TODO
    wipeFile("../Save.txt");
    wipeFile("../savedPlaylists.txt");
    std::ofstream outf2("../Save.txt");
    if (outf2){
        outf2 << testSong1->getTitle()+", "+testSong1->getArtist()+", "+std::to_string(testSong1->getLength())+", "+std::to_string(testSong1->getYear())+'\n';
        outf2 << testSong2->getTitle()+", "+testSong2->getArtist()+", "+std::to_string(testSong2->getLength())+", "+std::to_string(testSong2->getYear())+'\n';
        outf2 << testSong3->getTitle()+", "+testSong3->getArtist()+", "+std::to_string(testSong3->getLength())+", "+std::to_string(testSong3->getYear())+'\n';
        outf2 << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';
        outf2 << testSong4->getTitle()+", "+testSong4->getArtist()+", "+std::to_string(testSong4->getLength())+", "+std::to_string(testSong4->getYear())+'\n';
        outf.close();
    }else{
        cout<<"file "<<"Save.txt"<<" cant be found \n";
    }

    CommandHandler* testHandler3 = new CommandHandler();
    testHandler->library();
    testHandler3->discontinue("../discontinueTest.txt");
    printAssertEquals("idk",testHandler3->library(true));

    //printAssertEquals("TestPlaylist1",
    //Playlist("TestPlaylist1").insertAtEnd(testSong2);
    testHandler->listPlaylists();

    cout<<"\n-----testing list playlists-----\n\n";


    printAssertEquals("[TestPlaylist1 {empty playlist}]",testHandler->listPlaylists(true));
    testHandler->newPlaylist("listplaylist1");
    testHandler->addToPlaylist("listplaylist1", "rap god", "eminem");
    printAssertEquals("[TestPlaylist1 {empty playlist}, listplaylist1 {duration = 309 seconds, songs left: rap god}]",testHandler->listPlaylists(true));

    testHandler->addToPlaylist("listplaylist1", "Billie Jean", "Michael Jackson");

    printAssertEquals("[TestPlaylist1 {empty playlist}, listplaylist1 {duration = 665 seconds, songs left: rap god, Billie Jean}]",testHandler->listPlaylists(true));
    testHandler->newPlaylist("playlist3");
    printAssertEquals("[TestPlaylist1 {empty playlist}, listplaylist1 {duration = 665 seconds, songs left: rap god, Billie Jean}, playlist3 {empty playlist}]",testHandler->listPlaylists(true));

    cout<<"\n-----testing playlist (displays playlist with given name)-----\n\n";
        cout << "Expected: playlist not found. Actual: ";
        testHandler->playlist("testDisplayPlaylist1");
        testHandler->newPlaylist("testDisplayPlaylist1");
        cout << "Expected: Playlist testDisplayPlaylist1: Duration: 0 \nSongs: {}, Actual: ";
        testHandler->playlist("testDisplayPlaylist1");
        testHandler->addToPlaylist("testDisplayPlaylist1","here comes the sun","beatles");
        testHandler->addToPlaylist("testDisplayPlaylist1","rap god","eminem");
        cout << "Expected: Playlist testDisplayPlaylist1: Duration: 521 \nSongs: {duration = 521 seconds, songs left: here comes the sun, rap god}, Actual: " <<endl;
        testHandler->playlist("testDisplayPlaylist1");

    cout<<"\n-----testing add to playlist-----\n\n";
        cout << "Expected: song not found, actual: ";
        //testHandler->addToPlaylist("testDisplayPlaylist1","blah","beep");

        testHandler->newPlaylist("tester");
        testHandler->listPlaylists();


    cout<<"\n-----testing remove from playlist-----\n\n";
    CommandHandler* testHandler5 = new CommandHandler();
    testHandler5->newPlaylist("tester1");
    testHandler5->newPlaylist("tester2");
    testHandler5->addToPlaylist("tester2", "rap god", "eminem");
    testHandler5->addToPlaylist("tester2", "Billie Jean", "Michael Jackson");
    testHandler5->listPlaylists();
    testHandler5->removeFromPlaylist("tester2","Billie Jean", "Michael Jackson");
    testHandler5->listPlaylists();



    //TODO

    cout<<"-----testing play next-----\n\n";
    //TODO
    CommandHandler* testHandler4 = new CommandHandler();
    testHandler4->newPlaylist("test5");
    testHandler4->newPlaylist("test7");
    testHandler4->addToPlaylist("test5", "rap god", "eminem");
    testHandler4->addToPlaylist("test5", "Billie Jean", "Michael Jackson");
    testHandler4->addToPlaylist("test5", "lucy in thr sky with diamonds", "beatles");
    testHandler4->listPlaylists();
    testHandler4->playNext("test5");
    testHandler4->playNext("test5");

    testHandler4->listPlaylists();





    cout<<"-----testing create random playlist-----\n\n";
    //TODO

    cout<<"-----testing quit-----\n\n";
    //TODO

    std::cout << "======DONE======" <<endl;

}
void forrestPlaylistTests(){
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    std::cout << "======forrest playlsit tests======\n\n" <<endl;
    cout<<"-----testing insert at end-----\n";

    Playlist* testlist = new Playlist("testList1");
    testlist->insertAtEnd(testSong1);
    printAssertEquals("here comes the sun",testlist->getFront()->getSong()->getTitle());
    testlist->insertAtEnd(testSong2);
    printAssertEquals("here comes the sun",testlist->getFront()->getSong()->getTitle());
    printAssertEquals("Billie Jean",testlist->getFront()->getNext()->getSong()->getTitle());
    testlist->insertAtEnd(testSong3);
    printAssertEquals("rap god",testlist->getFront()->getNext()->getNext()->getSong()->getTitle());
    cout<<"-----testing to string-----\n";
    printAssertEquals("{duration = 877 seconds, songs left: here comes the sun, Billie Jean, rap god}",testlist->toString());
    Playlist* testlist2 = new Playlist("testList2");
    printAssertEquals("{}",testlist2->toString());
    cout<<"-----testing calc duration-----\n";
    printAssertEquals(0,testlist2->getDuration());
    printAssertEquals(877,testlist->getDuration());
    cout<<"-----testing find song-----\n";
    printAssertEquals(0,testlist->findSong("here comes the sun", "beatles"));
    printAssertEquals(1,testlist->findSong("Billie Jean", "Michael Jackson"));
    printAssertEquals(2,testlist->findSong("rap god", "eminem"));
    printAssertEquals(-1,testlist->findSong("rap god", "fake artist"));
    printAssertEquals(-1,testlist->findSong("fake song ", "eminem"));
    printAssertEquals(-1,testlist2->findSong("here comes the sun", "beatles"));

    cout<<"-----testing get number of songs-----\n";
    printAssertEquals(0,testlist2->getNumSongs());
    printAssertEquals(3,testlist->getNumSongs());

    cout<<"-----testing get song-----\n";
    printAssertEquals("rap god",testlist->getSong(2)->getTitle());
    printAssertEquals("Billie Jean",testlist->getSong(1)->getTitle());
    printAssertEquals("here comes the sun",testlist->getSong(0)->getTitle());
    printAssertEquals(false,testlist->getSong(4));
    printAssertEquals(false,testlist->getSong(-1));

    cout<<"-----testing remove song -----\n";
    printAssertEquals("song deleted", testlist->removeSong(2));
    printAssertEquals("out of bounds", testlist->removeSong(2));
    printAssertEquals("out of bounds", testlist->removeSong(-1));
    printAssertEquals("{duration = 568 seconds, songs left: here comes the sun, Billie Jean}",testlist->toString());
    printAssertEquals("song deleted", testlist->removeSong(1));

    std::cout << "======DONE======" <<endl;
}
void forrestPlaylistArrayListTest(){
    string song1 = "here comes the sun, beatles, 3:32, 1967";
    string song2 = "Billie Jean, Michael Jackson, 5:56, 1980";
    string song3 = "rap god, eminem, 5:09, 2013";
    string song4 = "lucy in thr sky with diamonds, beatles, 3:45, 1967";

    Song* testSong1 = new Song(song1);
    Song* testSong2 = new Song(song2);
    Song* testSong3 = new Song(song3);
    Song* testSong4 = new Song(song4);
    std::cout << "======forrest playlsit arraylist tests======" <<endl;
    PlaylistArrayList* testArraylist = new PlaylistArrayList();
    cout<<"-----testing insert at end-----\n";
    Playlist* testPlaylist = new Playlist("testlist1");
    testPlaylist->insertAtEnd(testSong1);
    //cout<<testPlaylist->toString()<<endl;

    Playlist* testPlaylist2 = new Playlist("testlist2");
    Playlist* testPlaylist3 = new Playlist("testlist3");

    testArraylist->insertAtEnd(testPlaylist);
    //cout<<testPlaylist->toString()<<endl;
    printAssertEquals("{duration = 212 seconds, songs left: here comes the sun}",testArraylist->getArray()[0]->toString());
    testArraylist->insertAtEnd(testPlaylist2);
    printAssertEquals("{duration = 212 seconds, songs left: here comes the sun}",testArraylist->getArray()[0]->toString());
    printAssertEquals("{}",testArraylist->getArray()[1]->toString());
    testArraylist->getArray()[0]->insertAtEnd(testSong2);
    printAssertEquals("{duration = 568 seconds, songs left: here comes the sun, Billie Jean}",testArraylist->getArray()[0]->toString());
    testArraylist->insertAtEnd(testPlaylist3);
    printAssertEquals("{}",testArraylist->getArray()[2]->toString());
    //cout<<testArraylist->getArray()[2]->getTitle();



    std::cout << "-----testing tostring------" <<endl;
    PlaylistArrayList* testArraylist2 = new PlaylistArrayList();
    printAssertEquals("[testlist1 {duration = 568 seconds, songs left: here comes the sun, Billie Jean}, testlist2 {empty playlist}, testlist3 {empty playlist}]",testArraylist->toString());
    printAssertEquals("[]",testArraylist2->toString());
    testArraylist->insertAtEnd(testPlaylist2);
    printAssertEquals("[testlist1 {duration = 568 seconds, songs left: here comes the sun, Billie Jean}, testlist2 {empty playlist}, testlist3 {empty playlist}]",testArraylist->toString());


    std::cout << "-----testing getValueAt------" <<endl;
    printAssertEquals("{duration = 568 seconds, songs left: here comes the sun, Billie Jean}",testArraylist->getValueAt(0)->toString());
    printAssertEquals("{}",testArraylist->getValueAt(1)->toString());
    printAssertEquals("{}",testArraylist->getValueAt(2)->toString());
    printAssertEquals(false,testArraylist->getValueAt(3));

    std::cout << "-----testing remove at------" <<endl;
    testArraylist->removeAt(1);
    printAssertEquals("[testlist1 {duration = 568 seconds, songs left: here comes the sun, Billie Jean}, testlist3 {empty playlist}]",testArraylist->toString());
    testArraylist->removeAt(-1);
    printAssertEquals("[testlist1 {duration = 568 seconds, songs left: here comes the sun, Billie Jean}, testlist3 {empty playlist}]",testArraylist->toString());
    testArraylist->removeAt(2);
    printAssertEquals("[testlist1 {duration = 568 seconds, songs left: here comes the sun, Billie Jean}, testlist3 {empty playlist}]",testArraylist->toString());

    std::cout << "-----testing clear list------" <<endl;
    testArraylist->clearList();
    printAssertEquals("[]",testArraylist->toString());

    std::cout << "======DONE======" <<endl;

}


int main(){
//    forrestPlaylistTests();
//    forrestPlaylistArrayListTest();
//   songTesters(); //working
//    artistMapNodeTesters(); //working
//    ArtistMapTesters(); //working
//    songArrayListTesters(); //working
    commandHandlerTesters();


    return 0;
}

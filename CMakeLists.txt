cmake_minimum_required(VERSION 3.14)
project(DjPlayer)

set(CMAKE_CXX_STANDARD 14)

add_executable(DjPlayer main.cpp Song.cpp Song.h Playlist.h List.h  LinkedList.h LinkedNode.cpp LinkedNode.h Playlist.cpp CommandHandler.h CommandHandler.cpp ArtistMap.cpp ArtistMap.h ArtistMapNode.cpp ArtistMapNode.h LinkedList.h )
project(SOCKET)

set(SRC_LIB .\src\lib\src)
set(INCLUDE .\src\include)
set(SRC .\src)

add_library(mySocket ${SRC_LIB}/mySocket.cpp)
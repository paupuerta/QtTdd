SET(CMAKE_PROJECT_NAME "Pasarela")
PROJECT(${CMAKE_PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

INCLUDE (qtMake)
#SET(PATH_SUSE /opt/suse11.2)
# Configuracion de las QT
#SET (QT_QMAKE_EXECUTABLE ${PATH_SUSE}/opt/qt-4.8.4/bin/qmake )
#SET (QT_MOC_EXECUTABLE ${PATH_SUSE}/opt/qt-4.8.4/bin/moc )
#SET (QT_UI_EXECUTABLE ${PATH_SUSE}/opt/qt-4.8.4/bin/uic )
#SET (QT_QRC_EXECUTABLE ${PATH_SUSE}/opt/qt-4.8.4/bin/rcc )
FIND_PACKAGE(Qt4 4.8.4 REQUIRED QtCore QtNetwork QtTest)

# this one is important
set(CMAKE_SYSTEM_NAME Linux)
#this one not so much
set(CMAKE_SYSTEM_VERSION 1)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# specify the cross compiler
#
#SET(CMAKE_LIBRARY_PATH ${PATH_SUSE}/usr/lib/ ${PATH_SUSE}/lib ${PATH_SUSE}/lib/cross)
#   SET(CMAKE_SYSTEM_LIBRARY_PATH ${PATH_SUSE}/usr/lib/ ${PATH_SUSE}/lib ${PATH_SUSE}/lib/cross)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH ${CMAKE_LIBRARY_PATH})
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

   #	SET(CMAKE_C_COMPILER   ${PATH_SUSE}/usr/bin/gcc)
   #	SET(CMAKE_CXX_COMPILER ${PATH_SUSE}/usr/bin/g++)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
# Compilamos los proyectos
ADD_DEFINITIONS (-DNDEBUG -DQTONLY -pipe -Wno-deprecated -Wno-write-strings -Wall ${QT_DEFINITIONS} )


ADD_DEFINITIONS(-DSOCKET_CLOSE_ON_EXEC)

IF (NOT DEFINED BUILD)
   SET (BUILD "${CMAKE_SOURCE_DIR}/bin")
ENDIF()
MESSAGE (">> Carpeta destino para binarios : ${BUILD}.")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD} )
SET(LIBRARY_OUTPUT_PATH ${BUILD})
SET(EXECUTABLE_OUTPUT_PATH ${BUILD})

INCLUDE (${QT_USE_FILE})
INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/src )


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Seccion de test ClntWebSrv
set (SRC_TEST_CLNT_WEB_SRV src/TestRunner.cpp)
set (SRC_TEST_CLNT_WEB_H_MOC src/TestRunner.h)
set (SRC_TEST_CLNT_WEB_MOC_GEN "src/autogen")

IF (NOT EXISTS ${SRC_TEST_CLNT_WEB_MOC_GEN})
   execute_process (COMMAND mkdir -p ${SRC_TEST_CLNT_WEB_MOC_GEN})
ENDIF()

gen_moc (TEST_CLNT_WEB_MOC
        ${SRC_TEST_CLNT_WEB_MOC_GEN}
        ${SRC_TEST_CLNT_WEB_H_MOC})

MESSAGE ("TEST_CLNT_WEB_MOC ${TEST_CLNT_WEB_MOC}")


ADD_EXECUTABLE ( testClntWebSrv ${SRC_TEST_CLNT_WEB_SRV} ${TEST_CLNT_WEB_MOC}
                                ${PROJECT_SOURCE_DIR}/src/testClntWebSrv.cpp)

SET_TARGET_PROPERTIES ( testClntWebSrv PROPERTIES COMPILE_FLAGS "${CXX_FLAGS} -m64" LINK_FLAGS -m64 )
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libnnz12.so  )
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libclntsh.so)
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libclntshcore.so.12.1)
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libociei.so)
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libclntshcore.so.12.1)
#${QT_QTTEST_LIBRARY}
TARGET_LINK_LIBRARIES ( testClntWebSrv ${QT_LIBRARIES} )
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/usr/lib/libX11.so)
#target_link_libraries(  testClntWebSrv /usr/lib/libX11.so)
#target_link_libraries(  testClntWebSrv ${PATH_SUSE}/lib/libons.so)
ADD_TEST( NAME TestClnt COMMAND testClntWebSrv )


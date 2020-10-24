CMAKE_MINIMUM_REQUIRED( VERSION 3.16 )
PROJECT( FILE_MANAGER )
# 프로젝트 이름 및 버전
PROJECT ( "parallel" )
SET ( STUDENT_ID 47987)

SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)

# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Debug )
SET ( CMAKE_VERBOSE_MAKEFILE true )

# 빌드 대상 바이너리 파일명 및 소스파일 목록
SET ( OUTPUT_ELF 
        "st_player.out"
        )
SET ( SRC_FILES
        src/st_player.c
        )
SET ( MULTI_THREAD_SRC 
        src/mt_player.c
        )
SET ( SHARED_PLAYER1_SRC 
        src/sm_player1.c
        )
SET ( SHARED_PLAYER2_SRC 
        src/sm_player2.c
        )

# Custom Options
OPTION (CROSS_COMPILE "ARM Cross Compile" OFF)
 
# 공통 헤더 파일 Include 디렉토리 (-I)
INCLUDE_DIRECTORIES ( include )
 
# 공통 컴파일 옵션, 링크 옵션
ADD_COMPILE_OPTIONS ( -g -Wall )
SET ( CMAKE_EXE_LINKER_FLAGS "-static -Wl,--gc-sections" )
 
# 공통 링크 라이브러리 (-l)
LINK_LIBRARIES( pthread )
 
# 공통 링크 라이브러리 디렉토리 (-L)
#LINK_DIRECTORIES ( <디렉토리> <디렉토리> ... )
 
# "Debug" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_DEBUG "-DDEBUG -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "-DDEBUG -DLINKER_FLAGS" )
 
# "Release" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_RELEASE "-DRELEASE -DC_FLAGS" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-DRELEASE -DLINKER_FLAGS" )
 
# 출력 디렉토리
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
 
# 빌드 대상 바이너리 추가
ADD_EXECUTABLE( ${STUDENT_ID}-${OUTPUT_ELF} 	${SRC_FILES} )
ADD_EXECUTABLE( ${STUDENT_ID}-mt_player.out 	${MULTI_THREAD_SRC} )
ADD_EXECUTABLE( ${STUDENT_ID}-sm_player1.out 	${SHARED_PLAYER1_SRC} )
ADD_EXECUTABLE( ${STUDENT_ID}-sm_player2.out 	${SHARED_PLAYER2_SRC} )

TARGET_LINK_LIBRARIES(${STUDENT_ID}-mt_player.out  PRIVATE Threads::Threads)


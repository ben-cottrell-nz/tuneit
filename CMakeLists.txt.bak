cmake_minimum_required(VERSION 3.14)

project(TuneIt VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Gui Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Gui Xml)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        assets.qrc
        fftfilterprocessor.cpp
        appsettings.cpp
)
if (NOT DEFINED FFTW3_ROOT_DIR)
  set(FFTW3_ROOT_DIR /home/ben/Downloads/fftw-3.3.10)
endif()
if (${ANDROID})
    add_compile_definitions(USING_POSIX_THREADS=1)
    set(OBOE_DIR /home/ben/Documents/git-repos/oboe)
    include(oboe.cmake)
    set(AUDIO_API_LIBS oboe)
    set(PROJECT_SOURCES audiobufferrecorder_oboe.cpp ${PROJECT_SOURCES})
    set(CMAKE_EXE_LINKER_FLAGS -fuse-ld=mold)

    include(fftw-sources.cmake)
    include_directories(${FFTW3_ROOT_DIR} ${FFTW3_ROOT_DIR}/api ${OBOE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})
    add_library(fftw3api STATIC ${FFTW3_API_SOURCES})
    add_library(fftw3kernel STATIC  ${FFTW3_KERNEL_SOURCES})
    add_library(fftw3threads STATIC  ${FFTW3_THREADS_SOURCES})
    add_library(fftw3reodft STATIC  ${FFTW3_REODFT_SOURCES})
    add_library(fftw3dft STATIC  ${FFTW3_DFT_SOURCES})
    add_library(fftw3rdft STATIC  ${FFTW3_RDFT_SOURCES})
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_compile_definitions(__LINUX_ALSA__=1 __LINUX_PULSE__=1 USING_POSIX_THREADS=1)
	set(RTAUDIO_SOURCES RtAudio.cpp)
    add_library(rtaudio STATIC ${RTAUDIO_SOURCES})
    set(AUDIO_API_LIBS asound rtaudio pulse pulse-simple)
    set(PROJECT_SOURCES audiobufferrecorder_rtaudio.cpp ${PROJECT_SOURCES})
    if (NOT DEFINED NO_MOLD)
      set(CMAKE_EXE_LINKER_FLAGS -fuse-ld=mold)
    endif()
    include(fftw-sources.cmake)
    include_directories(${FFTW3_ROOT_DIR} ${FFTW3_ROOT_DIR}/api ${CMAKE_CURRENT_SOURCE_DIR})
    add_library(fftw3api STATIC ${FFTW3_API_SOURCES})
    add_library(fftw3kernel STATIC  ${FFTW3_KERNEL_SOURCES})
    add_library(fftw3threads STATIC  ${FFTW3_THREADS_SOURCES})
    add_library(fftw3reodft STATIC  ${FFTW3_REODFT_SOURCES})
    add_library(fftw3dft STATIC  ${FFTW3_DFT_SOURCES})
    add_library(fftw3rdft STATIC  ${FFTW3_RDFT_SOURCES})
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	add_compile_definitions(__WINDOWS_WASAPI__=1)
	set(RTAUDIO_SOURCES RtAudio.cpp)
	add_library(rtaudio STATIC ${RTAUDIO_SOURCES})
	set(AUDIO_API_LIBS rtaudio)
	set(PROJECT_SOURCES audiobufferrecorder_rtaudio.cpp
	${PROJECT_SOURCES})
  if (NOT DEFINED FFTW3_ROOT_DIR)
    set(FFTW3_ROOT_DIR E:/Downloads/fftw-3.3.5-dll64)
  endif()
	include_directories(${FFTW3_ROOT_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
        #Needed when linking against static Qt libraries, MSVC2019
	set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreadedDLL)
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TuneIt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TuneIt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TuneIt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TuneIt
          ${PROJECT_SOURCES}
        )
    endif()
endif()

if (${ANDROID})
    target_include_directories(fftw3api PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
    target_include_directories(fftw3kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
    target_include_directories(fftw3threads PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
    target_include_directories(fftw3reodft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
    target_include_directories(fftw3dft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
    target_include_directories(fftw3rdft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
        target_include_directories(fftw3api PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
        target_include_directories(fftw3kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
        target_include_directories(fftw3threads PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
        target_include_directories(fftw3reodft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
        target_include_directories(fftw3dft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
        target_include_directories(fftw3rdft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config-linux)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	target_link_directories(TuneIt PUBLIC ${FFTW3_ROOT_DIR}) 
endif()

if (ANDROID)
    set_property(TARGET TuneIt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
                     ${CMAKE_CURRENT_SOURCE_DIR}/android)
    target_link_libraries(TuneIt
            PRIVATE
      fftw3api
      fftw3kernel
      fftw3threads
      fftw3reodft
      fftw3dft
      fftw3rdft
      ${AUDIO_API_LIBS}
            Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Xml
    )
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	target_link_libraries(TuneIt
		PRIVATE
	  fftw3api
	  fftw3kernel
	  fftw3threads
	  fftw3reodft
	  fftw3dft
	  fftw3rdft
	  ${AUDIO_API_LIBS}
                Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Xml
	)
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	target_link_libraries(TuneIt
		PRIVATE
	  libfftw3-3
	  libfftw3l-3
	  libfftw3f-3
	  ${AUDIO_API_LIBS}
                Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Xml
	)
	add_custom_command(TARGET TuneIt
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${FFTW3_ROOT_DIR}/libfftw3-3.dll ${FFTW3_ROOT_DIR}/libfftw3l-3.dll ${FFTW3_ROOT_DIR}/libfftw3f-3.dll ${CMAKE_CURRENT_BINARY_DIR})
endif()
set_target_properties(TuneIt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.bgcottrell.tuneit
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

#qt_add_qml_module(TuneIt
#    URI com.bgcottrell.tuneit.qmlcomponents
#    VERSION 1.0)

install(TARGETS TuneIt
    BUNDLE DESTINATION ${CMAKE_BINARY_DIR}
    LIBRARY DESTINATION ${CMAKE_BINARY_DIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(TuneIt)
    qt_finalize_executable(TuneIt)
endif()

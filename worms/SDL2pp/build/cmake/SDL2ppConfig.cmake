find_package(SDL2 REQUIRED)

if(ON)
	include("${CMAKE_CURRENT_LIST_DIR}/FindSDL2_image.cmake")
endif()

if(ON)
	include("${CMAKE_CURRENT_LIST_DIR}/FindSDL2_ttf.cmake")
endif()

if(ON)
	include("${CMAKE_CURRENT_LIST_DIR}/FindSDL2_mixer.cmake")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/SDL2ppTargets.cmake")

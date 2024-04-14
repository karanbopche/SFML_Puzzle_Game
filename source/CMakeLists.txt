cmake_minimum_required(VERSION 3.16)

set(
    SOURCE_FILES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio sfml-system sfml-window)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM
    )
endif()

set(ASSETS "${PROJECT_SOURCE_DIR}/assets")
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different ${ASSETS} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets"
    DEPENDS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets"
    COMMENT "Copy assets folder from ${ASSETS} => ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

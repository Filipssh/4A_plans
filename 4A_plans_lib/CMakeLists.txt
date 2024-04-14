project(4A_plans)

set(HEADER_FILES
        plans.h
        )

set(SOURCE_FILES
        plans.cpp
        )

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
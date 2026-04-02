cmake_minimum_required(VERSION 3.15)
project(MyCppLib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependency Management via Distro (apt) ---
# Example: If you installed libcurl-dev in Dockerfile, find it here
# find_package(CURL REQUIRED) 

add_executable(myapp src/main.cpp)

# --- Optimization & Linking ---
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Targeting Windows (Cross-Compile)
    message(STATUS "Building for Windows (MinGW)")
    
    # Static Linking for "No Dependencies"
    # This bundles libgcc and libstdc++ into the .exe
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    
    # Optimization
    add_compile_options(-O3 -DNDEBUG)
else()
    # Targeting Linux (Dev)
    message(STATUS "Building for Linux (Native)")
    
    # Debug symbols for Dev
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g -O0)
    endif()
endif()

# Install target to copy binary to dist folder
install(TARGETS myapp DESTINATION /app/dist)

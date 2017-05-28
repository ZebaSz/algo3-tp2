set(DATA_FILES grafGen.cpp DataGenerator.cpp)

add_executable(generarData ${DATA_FILES})
target_link_libraries (generarData algo3-tp2-base)

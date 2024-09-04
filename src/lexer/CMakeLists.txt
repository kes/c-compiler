add_library(lexer lexer.cpp tokenizer.cpp)

target_include_directories(lexer PUBLIC ${PROJECT_SOURCE_DIR}/src/util)
target_link_libraries(lexer util)
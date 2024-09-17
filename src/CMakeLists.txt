add_library(game STATIC Game.cpp player.cpp enemy.cpp)
target_include_directories(game PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(game STATIC BouncyBallGame.cpp bouncyballfactory.cpp bouncyball.cpp)
target_include_directories(game PUBLIC ${PROJECT_SOURCE_DIR}/include)

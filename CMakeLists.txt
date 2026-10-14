cmake_minimum_required(VERSION 3.20)

project(yoo0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(yoo0
	src/main.cpp
	src/Player2D.cpp
	src/Gun.cpp
	src/Bullet.cpp
	src/Red.cpp
	src/Game2D.cpp
	src/Menu.cpp
	src/Button.cpp
	src/Death.cpp
	src/Sandbox3D.cpp
	src/Player3D.cpp
	src/Sandbox2D.cpp
)

target_include_directories(yoo0 PRIVATE
	include
	raylib/include
)

target_link_libraries(yoo0 PRIVATE
	/home/mirak/Documents/yoo0/raylib/lib/libraylib.a
)

#run mingw32-make.exe to compile

#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/entities/sprite.cpp src/entities/player.cpp src/entities/map.cpp src/audio.cpp src/window.cpp src/game.cpp vendors/imgui/imgui.cpp vendors/imgui/imgui_demo.cpp vendors/imgui/imgui_widgets.cpp vendors/imgui/imgui_tables.cpp vendors/imgui/imgui_draw.cpp vendors/imgui/imgui_impl_sdl.cpp vendors/imgui/imgui_impl_opengl3.cpp 

#CC specifies which compiler we're using
CC = g++ -std=c++17 #-D GLEW_STATIC

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\libs\sdl_32\include\SDL2 -IC:\libs\glew-2.2.0-win32\glew-2.2.0\include\GL 

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -lopengl32 -LC:\libs\glew-2.2.0-win32\glew-2.2.0\lib\Release\Win32 -LC:\libs\sdl_32\lib 

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image #  -static-libgcc -static-libstdc++  -lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc -lSDL2_mixer -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = project.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)



# compile: gcc main.cpp -IC:\libs\sdl_32\include\SDL2 -LC:\libs\sdl_32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o project -lstdc++
# dll: gcc sample.cpp -o -shared project -lstdc++
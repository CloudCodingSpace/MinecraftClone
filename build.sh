cpps=$(find . -type f -name "*.cpp")
cs=$(find . -type f -name "*.c")

includep="-Idependencies/include"
libp="-Ldependencies/lib"
libflags="-lglfw3dll -lassimp.dll"
defines=""

g++ -g $defines $includep $libp $cpps $cs $libflags -o ./bin/MinecraftClone
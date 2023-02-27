g++ -c ./src/main.cpp -o ./src/main.o -I./include -Wall -pedantic -W -O3
g++ -c ./src/dp.cpp -o ./src/dp.o -I./include -Wall -pedantic -W -O3
g++ ./src/main.o ./src/dp.o -o ./src/main -Llib -lopenal32 -lsfml-graphics -lsfml-window -lsfml-system -s
.\src\main
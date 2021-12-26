hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/UcBoyutluNokta.o -c ./src/UcBoyutluNokta.cpp
	g++ -I ./include -o ./lib/KuyrukDugum.o -c ./src/KuyrukDugum.cpp
	g++ -I ./include -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp
	g++ -I ./include -o ./lib/AgacDugum.o -c ./src/AgacDugum.cpp
	g++ -I ./include -o ./lib/AVLAgac.o -c ./src/AVLAgac.cpp
	g++ -I ./include -o ./bin/Program ./lib/UcBoyutluNokta.o ./lib/KuyrukDugum.o ./lib/DogruKuyrugu.o ./lib/AgacDugum.o ./lib/AVLAgac.o ./src/Program.cpp

calistir:
	./bin/program
make:
	clang++ main.cpp tasks.cpp date.cpp -lraylib -lGL -lm -lpthread -lXrandr -ldl -lrt -lX11 -o cprod
	clang++ popup.cpp -lraylib -lGL -lm -lpthread -lXrandr -ldl -lrt -lX11 -O3 -o popup
	./cprod

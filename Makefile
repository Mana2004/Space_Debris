CXX = g++
CXXFLAGS = -std=c++11
TARGET = main
SRC = main.cpp

all: run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)
	python3 visualizer.py

clean:
	rm -f $(TARGET) graph_data.txt

CXX = clang++
STD = -std=c++11
CXXFLAGS = -Wall -Wpedantic -Wextra -Wc++11-extensions
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = a.out
#
.PHONY: all
all:$(TARGET)

%.o: %.cpp  
	$(CXX) $(CXXFLAGS) $(STD) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX)  $^ -o $@ 

.PHONY: clean
clean:
	rm $(TARGET) $(OBJS)

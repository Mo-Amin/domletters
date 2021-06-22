CXXFLAGS = -g -Wall -Werror
TARGET = domletters
SRCS = main.cpp
OBJS = main.o

$(TARGET): $(OBJS)
	g++ $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	-rm -f $(TARGET) $(OBJS)

src = $(wildcard *.cpp)

CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -D_GLIBCXX_DEBUG -fsanitize=adress -fsanitize=undefined
CXXRLFLAGS = -O2 -std=c++11 -Wall -Wextra -Wshadow -pedantic

main: $(src)
	$(CXX) -o $@ $(CXXFLAGS) $^

.PHONY
	$(CXX) -o main $(CXXRLFLAGS) $(src)
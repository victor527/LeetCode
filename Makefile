SRC = main.cpp RepeatedSubstringPattern.cpp
HDR = RepeatedSubstringPattern.h

leetcode: $(SRC) $(HDR)
	g++ -ggdb -o $@ $(SRC)

clean:
	rm -f leetcode leetcode.exe *.o
